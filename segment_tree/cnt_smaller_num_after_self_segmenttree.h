/*
Idea, segment tree is for range query

for segment represents range [i, i], we store "the occurrence of i"
then for segment with range [i, j], where i < j, it's the sum of occurrence
of value [i, j]

we update the segment-tree from the back of the nums, each time we insert a
value i, we check the segment tree to find the sum of occurrence from range
[0, i - 1], then we know how many times a smaller number appeared after i
*/
class SegmentTree {
  public:
    struct TreeNode {
        TreeNode(int i = 0, int l = 0, int r = MaxRange - 1)
            : idx(i), rangeL(l), rangeR(r), rangeMid(l + ((r - l) >> 1)) {}
        int leftIdx() const { return 2 * idx + 1; }
        int rightIdx() const { return 2 * idx + 2; }
        static TreeNode root() { return TreeNode(); }
        TreeNode leftNode() const {
            return TreeNode(leftIdx(), rangeL, rangeMid);
        }
        TreeNode rightNode() const {
            return TreeNode(rightIdx(), rangeMid + 1, rangeR);
        }
        int idx = 0;
        int rangeL = 0;
        int rangeR = 0;
        int rangeMid = 0;
    };
    void update(int val, TreeNode&& node = TreeNode::root()) {
        // for nodeIdx in segTree, represents
        // the sum of occurrence for value between [rangeL, rangeR]
        if (node.rangeL > val || node.rangeR < val) {
            return;
        }

        if (node.rangeL == node.rangeR) {
            // update the occurrence
            arr[node.idx]++; // l == r is only on segTree leaf node
            return;
        }
        // recursive update child
        (val <= node.rangeMid) ? update(val, node.leftNode())
                               : update(val, node.rightNode());
        // after child update, update root
        arr[node.idx] = arr[node.leftIdx()] + arr[node.rightIdx()];
    }

    int query(int queryL, int queryR, TreeNode&& node = TreeNode::root()) {
        if (queryL > queryR || queryL > node.rangeR || queryR < node.rangeL)
            return 0;
        // all the sibling nodes has non overlapping range
        // picking up those node range that is within query range and compose
        // them will eventually give us the answer
        if (queryL <= node.rangeL && queryR >= node.rangeR)
            return arr[node.idx];
        const int lVal = query(queryL, queryR, node.leftNode());
        const int rVal = query(queryL, queryR, node.rightNode());
        return lVal + rVal;
    }

  private:
    static constexpr int MaxRange = 20'001; // constraint after shift
    // note, node need more space then maxRange
    // as each node represents a range
    static constexpr int NodeArrSz = MaxRange * 4;
    std::array<int, NodeArrSz> arr = {};
};

class Solution {
  public:
    std::vector<int> countSmaller(std::vector<int>& nums) {
        SegmentTree segTree;
        for (int i = nums.size() - 1; i >= 0; i--) {
            const int shiftVal = 10'000 + nums[i];
            segTree.update(shiftVal);
            // min number -10'000 per constraints
            // shift each number with 10'000 so the range fall between [0,
            // 20'000]
            nums[i] = segTree.query(0, shiftVal - 1);
        }
        return nums;
    }
};