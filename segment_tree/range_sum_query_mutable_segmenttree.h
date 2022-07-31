class NumArray {
    struct SegNode {
        SegNode(int nodeIdx, int rangeL, int rangeR)
            : idx(nodeIdx), left(2 * idx + 1), right(2 * idx + 2), l(rangeL),
              r(rangeR), mid(l + (r - l) / 2) {}
        int idx = 0;
        int left = 0;
        int right = 0;
        int l = 0;
        int r = 0;
        int mid = 0;
        SegNode leftNode() const { return SegNode(left, l, mid); }
        SegNode rightNode() const { return SegNode(right, mid + 1, r); }
    };
    class SegTree {
      public:
        void init(const std::vector<int>& nums) {
            n = nums.size();
            segData = std::vector(4 * n, 0);
            build({0, 0, n - 1}, nums);
        }

        void build(SegNode node, const vector<int>& nums) {
            if (node.l == node.r) {
                segData[node.idx] = nums[node.l];
                return;
            }
            build(node.leftNode(), nums);
            build(node.rightNode(), nums);
            segData[node.idx] = segData[node.left] + segData[node.right];
        }

        void update(SegNode node, int val, int valIdx) {
            if (node.r < valIdx || node.l > valIdx)
                return;
            if (node.l == node.r) {
                segData[node.idx] = val;
                return;
            }
            valIdx <= node.mid ? update(node.leftNode(), val, valIdx)
                               : update(node.rightNode(), val, valIdx);
            segData[node.idx] = segData[node.left] + segData[node.right];
        }

        int query(SegNode node, int queryL, int queryR) {
            if (node.l > queryR || node.r < queryL)
                return 0;
            if (queryL <= node.l && queryR >= node.r)
                return segData[node.idx];
            const int fromLeft = query(node.leftNode(), queryL, queryR);
            const int fromRight = query(node.rightNode(), queryL, queryR);
            return fromLeft + fromRight;
        };

      private:
        std::vector<int> segData = {};
        int n = 0;
    };

  public:
    NumArray(vector<int>& nums) {
        n = nums.size();
        segTree.init(nums);
    }

    void update(int index, int val) {
        segTree.update({0, 0, n - 1}, val, index);
    }

    int sumRange(int left, int right) {
        return segTree.query({0, 0, n - 1}, left, right);
    }

  private:
    int n;
    SegTree segTree;
};
