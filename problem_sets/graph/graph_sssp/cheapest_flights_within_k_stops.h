/*
You can't solve this with pure Dijkstra ... because there is an extra constraint
of k stops. Imagine you can use more hops but much less price to arrive a point.
In normal Dijkstra, it should have been updated to that smaller price.

Overall, this is more like a Bellmon-Ford using Dijkstra's style to implement
*/

class Solution {
 public:
  int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst,
                        int k) {
    std::vector<std::vector<std::pair<int, int>>> adjPrice(n);
    for (const auto& info : flights) {
      adjPrice[info[0]].emplace_back(info[1], info[2]);
    }
    constexpr auto unreachable = INT_MAX;
    std::vector<int> price(n, unreachable);
    price[src] = 0;
    std::queue<std::pair<int, int>> toTravel;
    toTravel.emplace(src, 0);
    for (int i = 0; i <= k; ++i) {
      std::queue<std::pair<int, int>> nxtTravel;
      while (!toTravel.empty()) {
        auto [node, px] = toTravel.front();
        toTravel.pop();
        for (const auto [nxt, travelPx] : adjPrice[node]) {
          const auto arrivePrice = px + travelPx;
          if (arrivePrice < price[nxt]) {
            nxtTravel.emplace(nxt, arrivePrice);
            price[nxt] = arrivePrice;
          }
        }
      }
      std::swap(toTravel, nxtTravel);
    }
    return price[dst] == unreachable ? -1 : price[dst];
  }
};

// Pure Bellmon-Ford solution
// Noted that you shouldn't modify price vector in-place, as we build up the
// price in each hop. If you change price in-place, it could be the case that
// "some node takes more hop but less price to a point" - and if you change it
// to the smaller price in place, it might further touch its neighbor to be
// smaller number
/*
class Solution {
 public:
  int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst,
                        int k) {
    constexpr auto unreachable = INT_MAX;
    std::vector<int> price(n, unreachable);
    price[src] = 0;
    // k = 1, including dest, there are 2 stops, overall needs k + 1 loop
    for (int i = 0; i <= k; ++i) {
      std::vector<int> nxtPrice = price;
      for (const auto& edgeInfo : flights) {
        const int s = edgeInfo[0];
        if (price[s] == unreachable) {
          continue;
        }
        const int t = edgeInfo[1];
        const int p = edgeInfo[2];
        nxtPrice[t] = std::min(price[s] + p, nxtPrice[t]);
      }
      std::swap(nxtPrice, price);
    }
    return price[dst] == unreachable ? -1 : price[dst];
  }
};
*/