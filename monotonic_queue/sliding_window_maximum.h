class Solution {
  public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        std::deque<int> deq;
        vector<int> res = {};
        for (int i = 0; i < nums.size(); ++i) {
            // NOTE: the critical part is, you store the index into deq, not the
            // value As except for index, there is no good way to know whether
            // you are still in the k size window. (As you might have popped
            // several smaller value in each round.)

            // say [3,2,1,0], and we are sliding to idx i == 3 this round,
            // when coming to the loop, deq.front() == 0 == 3 - 3 (i - k)
            // we know that we need to pop_front so we can insert i == 3 in this
            // round.
            if (deq.front() == i - k) {
                deq.pop_front();
            }
            // every time we are going to insert a value, we pop every value in
            // the queue from the back, as long as it's <= value to insert.
            //
            //           0 1 2 3 4 5 6
            // Consider [1 1 1 2 5 4 3], if window size is 3, we will keep:
            // i:  0      1      2      3      4        5        6
            //    [1] -> [1] -> [1] -> [2] -> [5] ->  [5 4] -> [5 4 3]
            // e.g. at index 3, we don't need to keep [1, 1, 2], because when we
            // see 2 we know that those [1] can't be better than 2. Similarly,
            // when index 4, we don't need to keep 2, because 5 is larger of the
            // queue. But index 5, we find that 5 is larger than the newly
            // insert value 4. We need to keep 5  as a result. Same for index 6.
            while (!deq.empty() && nums[deq.back()] < nums[i])
                deq.pop_back();
            deq.push_back(i);

            if (i >= k - 1) {
                // deq.front must be the current max in the window.
                res.push_back(nums[deq.front()]);
            }
        }

        return res;
    }
};