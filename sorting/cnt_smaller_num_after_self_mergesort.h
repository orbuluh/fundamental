class Solution {
    /*
    Merge sort idea -> when you do merge(leftArr, rightArr)
    leftArr is always has the smaller idx than rightArr

    So - when you merge and find that you need to take element
    from rightArr, it basically means there is a mis-position

                 [5, 2, 6, 1]
    partition->  [5, 2], [6,1]
    partition->  [5][2], [6][1]

    merge([5], [2]) --> need to take from right [2], misPos[5]++
                    --> nothing from right after take [5], result [2,5]
    merge([6], [1]) --> need to take from right [1], misPos[6]++
                    --> nothing from right after take [6], result [1,6]
    merge([2, 5], [1, 6])
                    --> need to take from right [1], misPos[2]++, misPos[5]++
                    --> take [2] from left
                    --> take [5] from left
                    --> take [6] from right while nothing in left
                    --> result [1, 2, 5, 6]
    at the end: msPos[5] = 2, misPos[2] = 1, misPos[6] = 1, misPos[0] = 0

    Side note O(n^2) -> O(n) merge key point

    say left: [3, 4, 7], right [1, 2, 6]
    if you do: take [1], misPos[3]++, misPos[4]++, misPos[7]++
               take [2], misPos[3]++, misPos[4]++, misPos[7]++
               take [3]
               take [4]
               take [6], misPos[7]++
               take [7]
    this becomes a O(^2) merging.
    Instead, you maintain a misCnt when you do merge
    if you do: take [1], misCnt++
               take [2], misCnt++
               take [3], misPos[3] += misCnt
               take [4], misPos[4] += misCnt
               take [6], misCnt++
               take [7], misPos[7] += misCnt
    then this becomes O(n)
    */
  public:
    std::vector<int> misPosCnt;
    vector<int> countSmaller(vector<int>& nums) {
        misPosCnt = std::vector(nums.size(), 0);
        auto res = mergeSort(nums, 0, nums.size() - 1);
        return misPosCnt;
    }
    struct ValPos {
        int val = 0;
        int pos = 0;
    };
    std::vector<ValPos> mergeSort(const vector<int>& nums, int i, int j) {
        if (i > j)
            return {};
        if (i == j)
            return {{nums[i], i}};
        const auto mid = i + (j - i) / 2;
        auto left = mergeSort(nums, i, mid);
        auto right = mergeSort(nums, mid + 1, j);
        const auto n = j - i + 1;
        // tried use list, actually TLE
        std::vector<ValPos> mergedVec(n, {0, 0});
        int leftIdx = 0;
        int rightIdx = 0;
        int misCnt = 0;
        for (int i = 0; i < n; ++i) {
            if (leftIdx >= left.size()) {
                mergedVec[i] = right[rightIdx++];
            } else if (rightIdx >= right.size()) {
                mergedVec[i] = left[leftIdx++];
                misPosCnt[mergedVec[i].pos] += misCnt;
            } else {
                if (left[leftIdx].val <= right[rightIdx].val) {
                    mergedVec[i] = left[leftIdx++];
                    misPosCnt[mergedVec[i].pos] += misCnt;
                } else {
                    mergedVec[i] = right[rightIdx++];
                    misCnt += 1;
                }
            }
        }
        return mergedVec;
    }
};