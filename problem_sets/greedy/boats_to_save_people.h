/*
Greedy in a way that you always take the bigger one
and to include the smaller one as left option
*/
class Solution {
 public:
  int numRescueBoats(vector<int>& people, int limit) {
    std::sort(people.begin(), people.end());
    int sz = people.size();
    int l = 0;
    int r = sz - 1;
    int boat = 0;
    while (l <= r) {
      // greedy - always try to consume one large
      boat++;
      const int remaining = limit - people[r--];
      if (r >= 0 && remaining >= people[r]) {
        r--;
      } else if (remaining >= people[l]) {
        l++;
      }
    }
    return boat;
  }
};