/*
Idea: If you sort attack increasing and defense decreasing, then
you check from the back of the array while keeping track of max defense seen...

for example:

<-----------------------------------------<-------------checking order
 [2, 10], [2, 8], [2, 2], [2, 2], [3, 6], [4, 3], [5, 2]
i=   0       1       2       3       4      5       6

as you check from the back of the sorted attack, you know later
element has attack >= previous element.

When you see a smaller defense value than maxDefSeen, why can you always be sure
that you find a strictly less? e.g. when you see [2, 2] and maxDefSeen is 6, how
do you know this def 6 is not from some [2, 6]?

Because you know that if the attack is equal, you sort the defense in a
different order. So if there is a [2, 6], it would have been with a smaller i,
which you hasn't seen yet. So at this point, this 6 must be coming from a larger
i with some larger attack value. Hence you are sure you find a strictly less.

Then, when you see a bigger defense, you know nothing after this element could
be strictly larger than this one, so all later one won't be a better candidate
to constraint anything before this.

e.g. when you check i == 4, you see max defense is 6 now, and i == 5 or i == 6
just can't be better candidate to limit i == 0 to i == 3 anyway.
So you can just update the max defense seen and keep checking smaller i.

This is not the best solution but provides a nice way of this problem.
Check count_weaker_char_o_n_sol.h
*/
class Solution {
 public:
  int numberOfWeakCharacters(vector<vector<int>>& properties) {
    std::sort(properties.begin(), properties.end(),
              [](const vector<int>& a, const vector<int>& b) {
                // sort attack increaing
                // sort defense decreasing
                return a[0] < b[0] || (a[0] == b[0] && a[1] > b[1]);
              });

    int maxDefSeen = INT_MIN;
    int cnt = 0;
    for (int i = properties.size() - 1; i >= 0; --i) {
      cnt += properties[i][1] < maxDefSeen;
      maxDefSeen = std::max(maxDefSeen, properties[i][1]);
    }

    return cnt;
  }
};