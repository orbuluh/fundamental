class Solution {
  public:
    int maxResult(vector<int>& nums, int k) {
        // Note: initially at index 0, index 0 must be taken
        std::deque<int> monoQ;
        // note: monoQ has to store index, as in each step, you
        // could pop several number out to maintain the monoQ
        // you can't just size of monoQ or index you are traversing
        // to decide the time to pop for keep the k size window
        monoQ.push_back(0);
        for (int i = 1; i < nums.size(); ++i) {
            // dp[i] is basically the max dp[j] where j = [i - k -> i - 1]
            // monoQ front is always the index of max of previous i - k step
            nums[i] += nums[monoQ.front()];

            /*  0 1 2 3
               [a b c d]

            say at i = 3(d), k = 2
            maximally we can go from i - k = 1(b) to i = 3(d)
            only other hand, when you insert 3(d),
            you will need to pop 1(b),
            e.g. if index <= i - k, shouldn't keep in the pq*/
            if (monoQ.front() <= i - k) {
                monoQ.pop_front();
            }

            // then as long as the number in monoQ is smaller than the new
            // number that we are pushing, it means the new number must be
            // the larger value in the size k window. Also, because we do
            // this removal before we push a new number, we know that what
            // is in the monoQ must be decreasing. Just think [1,2,3,4]
            // and window size 2, we store [1], [2], [3], [4] separately.
            // And [4, 3, 2, 1], we store [4], [4,3], [3,2], [2,1]
            while (!monoQ.empty() && nums[monoQ.back()] <= nums[i]) {
                monoQ.pop_back();
            }
            monoQ.push_back(i);
        }
        return nums.back();
    }
};