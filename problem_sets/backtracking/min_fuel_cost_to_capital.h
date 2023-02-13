/*
You can imagine it's DFS of some sort, but you were stuck to think clearly what
to return from the backtracking...

Imagine seat is just 1 and path is a line:

0 <-- 1 <-- 2 <-- 3

The key to think about the recursion is to think about what happened in one
iteration. When node 3 goes to node 2, how many fuels needed? 1. Why? there
are only one city (people) on the path. When node 2 goes to node 1, how many
fuels needed? 2. Why? there are 2 cities (people) on the path, and the full seat
is only one, we need 2 cars, hence consume fuel 2.

So overall in each iteration, where you traverse back to parent city (and toward
capital) - what you need to know is how many people that we currently carry. And
the fuel needed to traverse back to parent city can be calculated accordingly.

E.g. fuel needed = ceil(peopleCarried / seatCnt)

And what DFS return should be how many people need to carried to capital at the
current city. (Not returning anything about fuel so far or some sort, you can
just calculate it on-the-fly.)

The other thing is how to record the visited node. Using a vector of bool can
work. But as there is no circle in the question, as long as we are not walking
back to previous node, we should not visit any visited node.
*/
class Solution {
  int fullCarSeat = 0;
  int64_t fuel = 0;
  std::vector<std::vector<int>> adjMat;

 public:
  long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
    fullCarSeat = seats;
    adjMat.resize(roads.size() + 1);
    for (const auto& r : roads) {
      adjMat[r[0]].push_back(r[1]);
      adjMat[r[1]].push_back(r[0]);
    }
    dfs(0, -1);
    return fuel;
  }

  int64_t dfs(int cur, int prev) {
    int64_t peopleToCarry = 1;
    for (auto nxt : adjMat[cur]) {
      peopleToCarry += (nxt != prev) ? dfs(nxt, cur) : 0;
    }
    fuel += (cur != 0)  // ceil of (ppl / seat)
                ? (peopleToCarry + fullCarSeat - 1) / fullCarSeat
                : 0;
    return peopleToCarry;
  }
};