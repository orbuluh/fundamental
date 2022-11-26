/*


Imagine top-down dfs way:
- If we sort all the jobs by start time, we can formulate a dfs search where
  in each recursion, we basically choose to take a job[i] or not.
- And because we know the jobs has sorted with starting time, the deeper of the
  recursion should only take jobs that happens in the same or latter time.
- At the bottom of such dfs search, it should be something like only one job
  left to consider, so it has a deterministic return.

Reverse this to think bottom-up approach:

Say dp[i] record the max profit we can get starting from dfs'ing jobs[i]

- If we take the job[i], the next job[j] we can take can only be something
  having job[j].start >= job[i].end, where j > i
- this give us certain recursion intuition:
    --> dp[i] = profit[i] + dp[j], where j > i and job[j].start >= job[i].end
- If we don't take the job[i], then dp[i] should equal to dp[i + 1], e.g. if
  you don't take job[i], then the max profit you can get starting from i
  should be equal to the max profit you can get starting from i + 1
- at the bottom of the recursion, where there is no j > i, so the maximum is
  just the profit of i = jobs.size() - 1 itself.
*/
class Solution {
  struct Job {
    int start = 0;
    int end = 0;
    int profit = 0;
  };

 public:
  int jobScheduling(vector<int>& startTime, vector<int>& endTime,
                    vector<int>& profit) {
    auto jobs = convertInput(startTime, endTime, profit);
    const int sz = jobs.size();
    std::vector<int> dp(sz, 0);
    int maxProfit = 0;
    dp[sz - 1] = jobs.back().profit;
    for (int i = sz - 2; i >= 0; i--) {
      int nextAvailProfit = [&]() {
        for (int j = i + 1; j < sz; j++) {
          if (jobs[j].start >= jobs[i].end) {
            return dp[j];
          }
        }
        return 0;
      }();
      dp[i] = std::max(jobs[i].profit + nextAvailProfit,  // you take jobs[i]
                       dp[i + 1]  // you don't take jobs[i]
      );
    }
    return dp[0];
  }

  std::vector<Job> convertInput(const vector<int>& startTime,
                                const vector<int>& endTime,
                                const vector<int>& profit) {
    std::vector<Job> input;
    for (int i = 0; i < startTime.size(); ++i) {
      input.emplace_back(Job{startTime[i], endTime[i], profit[i]});
    }
    std::sort(input.begin(), input.end(), [](const Job& d1, const Job& d2) {
      return (d1.start < d2.start);
    });
    return input;
  }
};