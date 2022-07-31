class NumArray {
    class BinaryIndexedTree {
      public:
        void init(const vector<int>& nums) {
            n = nums.size();
            bitArr = std::vector<int>(nums.size() + 1, 0);
            for (int i = 0; i < n; ++i) {
                update(i, nums[i]);
            }
        }

        // BIT details: we hide the idx++ in the update/query accordingly

        void update(int idx, int valDelta) {
            idx += 1; // bitArr starts from 1
            for (; idx <= n; idx += lsb(idx)) {
                bitArr[idx] += valDelta;
            }
        }

        int query(int idx) {
            idx += 1; // bitArr starts from 1
            int res = 0;
            for (; idx > 0; idx -= lsb(idx)) {
                res += bitArr[idx];
            }
            return res;
        }

      private:
        inline int lsb(int idx) { return idx & (-idx); }

        int n = 0;
        vector<int> bitArr;
    };

  public:
    NumArray(vector<int>& nums) {
        numsPtr = &nums;
        bitTree.init(nums);
    }

    void update(int index, int val) {
        // details - update with delta, so you need to update numsPtr as well
        // to make sure next time you are calculating delta correctly.
        const auto valDelta = val - (*numsPtr)[index];
        (*numsPtr)[index] = val;
        bitTree.update(index, valDelta);
    }

    int sumRange(int left, int right) {
        // details, we make the index++ in the query function
        return bitTree.query(right) - bitTree.query(left - 1);
    }

    BinaryIndexedTree bitTree;
    vector<int>* numsPtr;
};
