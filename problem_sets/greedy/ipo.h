/*
Your w will always increase, so gradually you can take more and more tasks out
of the unfinished projects.

Out of the set of doable projects, you always want to do the one with max profit
So we use a maxQ to represent it. Each iteration we pick the doable accordingly.

Once we gain the w, we check whether there are new projects that can add to the
doable projects set. How to do this efficiently? Maintain a minQ such that
smaller capital of the project will be on the top of the heap. And just pop it
gradually so we only keep those job that have capital > w in the minQ.

Note that for the profit maxQ - we don't even need to keep its corresponding
capital, it doesn't matter. And for the capital minQ, we should keep the
corresponding index so that we can retrieve its profit information when it
becomes doable.
*/

class Solution {
 public:
  int findMaximizedCapital(int k, int w, vector<int>& profits,
                           vector<int>& capital) {
    std::priority_queue<int> doableProfitMaxQ;
    using P = std::pair<int, int>;
    std::priority_queue<P, std::vector<P>, std::greater<P>> waitListMinQ;
    const int sz = profits.size();
    for (int i = 0; i < sz; ++i) {
      if (capital[i] <= w) {
        doableProfitMaxQ.push(profits[i]);
      } else {
        waitListMinQ.emplace(capital[i], i);
      }
    }
    while (!doableProfitMaxQ.empty() && k--) {
      w += doableProfitMaxQ.top();
      doableProfitMaxQ.pop();
      while (!waitListMinQ.empty() && waitListMinQ.top().first <= w) {
        doableProfitMaxQ.push(profits[waitListMinQ.top().second]);
        waitListMinQ.pop();
      }
    }
    return w;
  }
};