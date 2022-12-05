/*
The direct greedy way, try to loop through target, say with variable t.
In each loop, it's like a restart to match subsequence in source, say with
variable s. As long as char are the same target[t] == source[s], you find a
(partial) match of the subsequence in s that match t.

On the other hand, if after looping all s, you can't make t++, it means nothing
in source can match target, we early terminate.

Then after looping all s, the iteration is done, we use a subsequence of source
to match part of target. We go to next iteration and loop the source again.

Check shortest_way_to_form_string_sol2.h for theoretically faster solution
*/

class Solution {
 public:
  int shortestWay(string source, string target) {
    int t = 0;
    int tSz = target.size();
    int res = 0;
    while (t < tSz) {
      int oriT = t;
      for (int s = 0; s < source.size() && t < tSz; ++s) {
        if (source[s] == target[t]) {
          t++;
        }
      }
      if (oriT == t) {  // nothing in source can make t++
        return -1;
      }
      // otherwise you've greedy use subsequence of s to match target
      res++;
    }
    return res;
  }
};