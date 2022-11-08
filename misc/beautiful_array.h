/*

Brutal question ... from lee215's video ...
https://www.youtube.com/watch?v=9L6bPGDfyqo&ab_channel=PragmaticWorks

2 * nums[k] == nums[i] + nums[j]

means nums[k] is the average of nums[i] and nums[j]

and how do you make sure it can't happen?

say if nums[i] is some odd number, and nums[j] is some even number
then nums[i] + nums[j] must not be dividable by 2,
hence nums[k] to make it not beautiful must not exist

This seems to only apply to small array?
You can actually expand it through this:

say A is beautiful array, then

(1) 2 * A must be a beautiful array as well
   - because the equation still holds
     2 * (2 * nums[k]) != 2 * nums[i] + 2 * nums[j]

(2) A - 1 must be a beautiful array as well
   - because the equation still holds
     2 * (nums[k] - 1) != (nums[i] - 1) + (nums[j] - 1)

So you can expand from short beautiful array A to longer one, through
- B = odd array = 2 * A - 1
- C = even array = 2 * A
- then merge: [B C]  should be beautiful as well, because B and C
  are beautiful themselves. And any one element in B plus one element
  in C must not be dividable by 2....

So doing this, will basically grow the array size by 2,
but n is not always pow of 2, what to do?

Simple, just filter out value larger than n ....
As removing some elements from a beautiful array won't make it ugly...


for example:
n = 1: [1]
n = 2: odd: [1], even: [2], merge: [1 2]
n = 3 (build from n = 2): odd: [1 3], even: [2 4],
      merge: [1 3 2 4], filter > n, [1 3 2]
n = 4 (build from n = 2): [1 3 2 4]
n = 5 (build from n = 4): odd: [1 5 3 7], even: [2 6 4 8],
      merge [1 5 3 7 2 6 4 8], filter > n, [1 5 3 2 4]
n = 6 (build from n = 4):
      merge [1 5 3 7 2 6 4 8], filter > n, [1 5 3 2 6 4]
...
HOLY MOLLY...
*/
class Solution {
 public:
  vector<int> beautifulArray(int n) {
    std::vector<int> res = {1};
    while (res.size() < n) {
      std::vector<int> odd = res;
      std::transform(odd.begin(), odd.end(), odd.begin(),
                     [](int v) { return 2 * v - 1; });
      std::vector<int> even = res;
      std::transform(even.begin(), even.end(), even.begin(),
                     [](int v) { return 2 * v; });
      odd.insert(odd.end(), even.begin(), even.end());
      std::swap(res, odd);
    }
    res.erase(
        std::remove_if(res.begin(), res.end(), [&](int v) { return v > n; }),
        res.end());
    return res;
  }
};