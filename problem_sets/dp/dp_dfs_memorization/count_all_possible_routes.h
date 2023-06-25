/*
0 1 4 2 3
2 3 4 6 8
  _     _


How do you do the brute force? From start you try to DFS to every point
except itself as long as fuel is still enough. Once you reach finish, you
have one more path.

You could arrive any point with any fuel left from different route,
but then the remaining will be overlapped subproblem. Hence, the dp will
be a 2D dp[city_idx][fuel_left]

And then, from TopDown, you can think of BottomUp. What's the base case?
Whenever we arrive finish, we have one extra route.


Hence dp[finish][:] = 1

Then when is overlapped problem show up again during TopDown? When you are
calculating the state of larger fuel, and meeting with a state with smaller
fuel that has been computed. Hence, when BottomUp, you do the reverse way, e.g.
you loop through smaller fuel to larger one, and build the whole thing
accordingly!

The optimized bottom up can be seen in https://github.com/lzl124631x/LeetCode/tree/master/leetcode/1575.%20Count%20All%20Possible%20Routes

...dang ... from the post...

left[i][f]: the count of routes whose last move is leftwards to location i with f fuel
right[i][f]: the count of routes whose last move is rightwards to location i with f fuel

left[j][f] = left[j+1][f-d(j, j+1)] + right[j+1][f-d(j, j+1)] // go to j + 1 first then j
            + left[j+2][f-d(j, j+2)] + right[j+2][f-d(j, j+2)] // go to j + 2 first then j
            + ...
            + left[j+k][f-d(j, j+k)] + right[j+k][f-d(j, j+2)] // go to j + k first then j

We can apply this equation recursively so that all the left are replaced with right in the right side of the equation.

left[j][f] = right[j+1][f-d(j, j+1)]
            + 2 * right[j+2][f-d(j, j+2)]
            + ...
            + 2^(k-1) * right[j+k][f-d(j, j+k)]

In the righthand-side, the 2nd to last terms can be expressed as 2 * left[j+1][f-d(j, j+1)] because

left[j+1][f] = right[j+2][f-d(j+1, j+2)]
              + 2 * right[j+3][f-d(j+1, j+3)]
              + ...
              + 2^(k-2) * right[j+1+k-1][f-d(j+1, j+1+k-1)]

left[j+1][f-d(j, j+1)] = right[j+2][f-d(j, j+2)]
                        + 2 * right[j+3][f-d(j, j+3)]
                        + ...
                        + 2^(k-2) * right[j+k][f-d(j, j+k)]
So we have this equation

left[j][f] = right[j+1][f-d(j, j+1)] + 2 * left[j+1][f-d(j, j+1)]
Symmetrically, we have

right[j][f] = left[j-1][f-d(j, j-1)] + 2 * right[j-1][f-d(j, j-1)]
*/

class Solution_TopDown {
  static constexpr int mod = 1e9 + 7;
  int n = 0;
  int end = 0;
  std::vector<std::vector<int>> dp;

 public:
  int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
    end = finish;
    n = locations.size();
    dp = std::vector<std::vector<int>>(n, std::vector<int>(fuel + 1, -1));
    return dfs(locations, start, fuel);
  }

  int dfs(vector<int>& locations, int idx, int fuelLeft) {
    if (fuelLeft < 0) {
      return 0;
    }
    if (dp[idx][fuelLeft] != -1) {
      return dp[idx][fuelLeft];
    }
    int res = (idx == end);
    for (int i = 0; i < n; ++i) {
      if (i == idx) {
        continue;
      }
      res = (res + dfs(locations, i,
                       fuelLeft - std::abs(locations[i] - locations[idx]))) %
            mod;
    }
    return dp[idx][fuelLeft] = res;
  }
};

class Solution_BottomUp {
  static constexpr int mod = 1e9 + 7;

 public:
  int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
    const int n = locations.size();
    auto dp = std::vector<std::vector<int>>(n, std::vector<int>(fuel + 1, 0));
    for (int f = 0; f <= fuel; ++f) {
      dp[finish][f] = 1;  // base case
    }
    for (int f = 1; f <= fuel; ++f) {
      for (int s = 0; s < n; ++s) {
        for (int e = 0; e < n; ++e) {
          if (s == e) {
            continue;
          }
          const int d = std::abs(locations[s] - locations[e]);
          if (d > f) {
            continue;
          }
          dp[s][f] = (dp[s][f] + dp[e][f - d]) % mod;
        }
      }
    }
    return dp[start][fuel];
  }
};

using Solution = Solution_BottomUp;
