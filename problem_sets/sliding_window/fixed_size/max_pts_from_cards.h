class Solution {
  public:
    int maxScore(vector<int>& cpts, int k) {
        // taking min of window with size n - k
        // then full sum - min of windowSum == max sum of selected
        const auto n = cpts.size();
        int windowSum = std::accumulate(cpts.begin(), cpts.begin() + n - k, 0);
        int fullSum = windowSum;
        int minWindowSum = windowSum;
        for (int i = n - k; i < n; ++i) {
            fullSum += cpts[i];
            // pop first in the window and insert the new one
            windowSum += (-cpts[i - (n - k)] + cpts[i]);
            minWindowSum = std::min(minWindowSum, windowSum);
        }
        return fullSum - minWindowSum;
    }
};