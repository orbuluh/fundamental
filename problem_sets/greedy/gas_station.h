/*

Say we have diff[i] = gas[i] - cost[i]

The key things are

1. if diff[i] itself is a negative value, it can't be a starting point.
2. for a consecutive ranges A to B inclusive, if sum of diff values are negative
   then A also can't be a starting point. (As, you won't be able to reach B)
3. if sum of whole diff array is 0, there must be an solution. (There are
   mathmatical proof in discussion, but it also okay intuitive.)

So we can sim to do a O(n) scan while collecting the full sum. Then at the end,
we can make sure full sum >= 0 for item 3.

And the for item 1, and item 2, we can do it this way:
- we keep a tank counter and a starting idx.
- we add the diff value to tank in each iteration. If tank is >= 0, it means
  the car can reach the next point, and we can keep scanning
- if tank + diff[i] < 0, it's basically item 2's case that current starting idx
  won't be the starting point. And in this case, we will have to reset the
  starting idx and reset our tank back to 0. (E.g. starting to find the next
  valid starting point.)
- you might ask, say sum of diff[candidate] -> diff[i] inclusive is negative,
  could diff[candidate + 1] -> diff[i] actually be positive?

  It can't be, because item 1, diff[candidate] must be positive itself,
  diff[candidate + 1] -> diff[i] must resolve to a even smaller number.

  Also because we reset once tank + diff[i] < 0, it means that
  sum of diff[candidate] -> diff[i - 1] must be positive. It must be the case
  that diff[i] is so negative that it makes candidate to i - 1 meaningless.
  So none of the idx between candidate to i can be the starting idx. The only
  possible startIdx must be i + 1.

Consider the case
idx  =  0 1  2 3
------------------
gas  =  5 8  2 8
cost =  6 5  6 6
------------------
diff = -1 3 -4 2

diff=3 (idx=1) can't be a starting point, as next is -4 (idx=2), which means
we have not enough gas to pass through idx=2, from idx=1.
Hence, the only viable starting idx=3.
*/

class Solution {
 public:
  int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    int allSum = 0;
    int tank = 0;
    int startingIdx = 0;

    for (int i = 0; i < gas.size(); ++i) {
      const auto diff = gas[i] - cost[i];
      allSum += diff;
      tank += diff;
      if (tank < 0) {
        tank = 0;
        startingIdx = i + 1;
      }
    }
    return allSum >= 0 ? startingIdx : -1;
  }
};