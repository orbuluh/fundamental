/*
Idea from https://leetcode.com/problems/range-module/discuss/244194/Python-solution-using-bisect_left-bisect_right-with-explanation

check out your notes as put in description.

But the keep observation:
- We use a tracking array `ranges`. The array consists of a number of sorted pairs of start and end values.
    - So, it always has an even number of elements.
    - Even idx 0, 2, 4 ... must represent start of a range.
    - Odd idx must 1, 3, 5 ... must represent end of a range.
- addRange [left, right):
    - In `ranges`, the first element >= left will be the place to put the new start it.
    - In `ranges`, the first element > right will be the place to put the new end it.
    - Key (check note picture): if such element's index is even, we need to insert the new value.
- removeRange [left, right):
    - Similarly
    - Key (check note picture): if such element's index is odd, we need to insert the new value.
- queryRange [left, right):
    - if a range [left, right) is in some other range ... then the first element > left
      must be overlapped with the first point >= right. (a range must be adjacent).
    - And such element must be an end point - e.g. idx is odd
*/
class RangeModule {
    std::vector<int> ranges;
public:
    RangeModule() = default;

    inline int idx(std::vector<int>::iterator iter) {
        return iter - ranges.begin();
    }

    void addRange(int left, int right) {
        auto startIt = std::lower_bound(ranges.begin(), ranges.end(), left);
        auto endIt = std::upper_bound(ranges.begin(), ranges.end(), right);
        std::vector<int> newRange;
        if (idx(startIt) % 2 == 0) newRange.push_back(left);
        if (idx(endIt) % 2 == 0) newRange.push_back(right);
        ranges.erase(startIt, endIt);
        ranges.insert(startIt, newRange.begin(), newRange.end());  
    }

    void removeRange(int left, int right) {
        auto startIt = std::lower_bound(ranges.begin(), ranges.end(), left);
        auto endIt = std::upper_bound(ranges.begin(), ranges.end(), right);
        std::vector<int> newRange;
        if (idx(startIt) % 2) newRange.push_back(left);
        if (idx(endIt) % 2) newRange.push_back(right);
        ranges.erase(startIt, endIt);
        ranges.insert(startIt, newRange.begin(), newRange.end());
    }

    bool queryRange(int left, int right) {
        auto startIt = std::upper_bound(ranges.begin(), ranges.end(), left);
        auto endIt = std::lower_bound(ranges.begin(), ranges.end(), right);
        return startIt == endIt && (idx(startIt) % 2 == 1);
    }
};