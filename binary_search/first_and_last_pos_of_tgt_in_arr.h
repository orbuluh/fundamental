class Solution {
    int firstOccur(const vector<int>& nums, int l, int r, int target) {
        while (l < r) {
            int mid = l + (r - l) / 2;
            // because l < r, mid will never equal to r (e.g. we bias to l)
            // so moving r = mid will always guarantee NOT to get infinite loop

            // and because we are guarantee to shrink thr right bound
            // doing this is suitable for finding the first occurance

            // how? we do it through shrinking whenever nums[mid] >= target
            // at the end, as we bias to l, mid will equal to l, we return l
            if (nums[mid] >= target) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }
    int lastOccur(const vector<int>& nums, int l, int r, int target) {
        while (l < r) {
            int mid = l + (r - l + 1) / 2;
            // here, we want to be guaranteed to shrink thr left bound
            // (so that we can find the right bound)
            // so contrast to firstOccur, we want to bias to r, how?
            // through calculating mid in a different way.

            // as l < r, plus we do a (r - l + 1)
            // mid will never equal to l, (as l < r, say l = r - 1, we get mid =
            // l + 1) so moving l = mid will always guarantee NOT to get
            // infinite loop

            // then when do we make l = mid? when nums[mid] <= target
            // at the end, as we bias to r, mid will equal to r, we return r
            if (nums[mid] <= target) {
                l = mid;
            } else {
                r = mid - 1;
            }
        }
        return r;
    }

  public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.empty())
            return {-1, -1};
        const int lastIdx = nums.size() - 1;
        int l = 0;
        int r = lastIdx;
        int firstIdx = firstOccur(nums, l, r, target);
        if (nums[firstIdx] != target) {
            return {-1, -1};
        }
        return {firstIdx, lastOccur(nums, firstIdx, lastIdx, target)};
    }
};