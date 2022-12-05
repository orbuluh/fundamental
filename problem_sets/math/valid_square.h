/*
The trick is not even considering the permutation of edges

if it's a square, just compute every edges between 2 nodes and there should only
be 2 kind of length with
- shorter one is edge length, with count 4
- longer one is diagonal, with count 2
Also edge case ... shorter one can't be 0
*/
class Solution {
 public:
  bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3,
                   vector<int>& p4) {
    std::map<int, int> counter;

    auto len = [&](const auto& pa, const auto& pb) {
      return pow(pa[0] - pb[0], 2) + pow(pa[1] - pb[1], 2);
    };

    counter[len(p1, p2)]++;
    counter[len(p1, p3)]++;
    counter[len(p1, p4)]++;
    counter[len(p2, p3)]++;
    counter[len(p2, p4)]++;
    counter[len(p3, p4)]++;

    auto shortEdgeIt = counter.begin();

    return counter.size() == 2 && shortEdgeIt->first != 0 &&
           shortEdgeIt->second == 4;
  }
};