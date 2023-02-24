/*

The operations:
- Halve even number (multiple times till it's odd), or say decrease even num
- Double odd number once, or say, increase odd num

How do we reduce the max deviation?
- We can either reduce the max or increase the min
- Reduce can only through halve even, and increase can only through double odd

To simplify the search:

- Say, we double the odd numbers in the array, now we can no longer increase
any number in the array, as everything is even.

To reduce deviation, now we can only do this through halve max number.

For example:
[1, 8, 7]   -> original array
[2, 8, 14]  -> min 2, max 14, dev 12
[2, 7, 8]   -> min 2, max 8, dev 6
[2, 4, 7]   -> min 2, max 7, dev 5. We can no longer shrink max, nor can we
               reduce min, 5 must be answer.


However, along the way, if max/2 is smaller than current min, there is a chance
that the min becomes smaller. Could we get a smaller deviation accordingly? We
could through checking the
new max (which must be smaller than cur max) - new min. For example:

[3, 4] -> original array
[4, 6] -> current min 4, max 6  => dev = 2
[3, 4] -> max/2 = 3 < 4, 3 becomes min, 4 becomes max => dev = 1

This can just be captured by the fact that you are updating your min in each
iteration accordingly, plus you are removing the current max in each round.
So eventually, the new max (4) surface, and the new min is updated (3), and
you can still derive the answer.

We could use a priority queue to do this, or we could use an ordered set
*/
class Solution {
 public:
  int minimumDeviation(vector<int>& nums) {
    std::set<int> orderedNum;
    for (auto n : nums) {
      n = n % 2 ? n * 2 : n;
      orderedNum.insert(n);
    }
    int dev = INT_MAX;
    auto maxIt = std::prev(orderedNum.end());
    while ((*maxIt & 1) == 0) {
      const auto curMax = *maxIt;
      orderedNum.erase(maxIt);
      dev = std::min(dev, curMax - *orderedNum.begin());
      orderedNum.insert(curMax / 2);
      maxIt = std::prev(orderedNum.end());
    }
    return std::min(dev, *maxIt - *orderedNum.begin());
  }
};