/*
Say we analyze and group with subarray ending at i-th element, and denote:

dp[i] = sum of min value of each subarray that ending at i-th element

end at idx=0:
[3]
-------------> dp[0] = 3

end at idx=1:
[3, 1]
[1]
-------------> dp[1] = 1 + 1

end at idx=2:
[3, 1, 2]
[1, 2]
[2]
-------------> dp[2] = 1 + 1 + 2

end at idx=3:
[3, 1, 2, 4]
[1, 2, 4]
[2, 4]
[4]
-------------> dp[3] = 1 + 1 + 2 + 4

so, the pattern here is,

if arr[idx] >= arr[idx - 1], dp[idx] = dp[idx - 1] + arr[idx]
    - as the new arr[idx] just won't introduce a smaller value to previous
      subarray

else
    - we need to see when the small arr[idx] should kick in ...

say we have [3 2 1]

end at idx=0:
[3]
-------------> dp[0] = 3

end at idx=1:
[3, 2]
[2]
-------------> dp[1] = 2 + 2

end at idx=2:
[3, 2, 1]
[2, 1]
[1]
-------------> dp[1] = 1 + 1 + 1

So if new value arr[idx] is just smaller than everything before it,
then dp[i] = (i - 0 + 1) * arr[idx]

    - e.g. it introduce a smaller value to every previous subarray


say we have [1 2 4 3]

end at idx=0:
[1]
-------------> dp[0] = 1

end at idx=1:
[1, 2]
[2]
-------------> dp[1] = 1 + 2

end at idx=2:
[1, 2, 4]
[2, 4]
[4]
-------------> dp[2] = 1 + 2 + 4

end at idx=3:
[1, 2, 4, 3]
[2, 4, 3]
[4, 3]
[3]
-------------> dp[3] = 1 + 2 + 3 + 3

Observe patten in dp[3]:
because arr[0] = 1 and arr[1] = 2 is smaller than arr[2] = 3, it won't affect
[1, 2, 4, 3] and [2, 4, 3] - those 2 still have smallest value 1 and 2
respectively. So we can basically reuse the dp before, dp[1] = 1 + 2
And overall:

dp[i] = dp[j] + (i - j) * arr[i]
- where j < i and j is the largest index having arr[j] < arr[i]

--> so above example, it's like j = 1, and dp[3] = dp[1] + (3 - 1) * 3

And how do we find such j efficiently?
We could maintain a monotonic increasing stack (storing index)!

so same example, [1 2 4 3], it's like (stk stores idx)

end at idx=0:
[1]
-------------> dp[0] = 1, stk = [0]

end at idx=1:
[1, 2]
[2]
-------------> dp[1] = 1 + 2, stk = [0, 1]

end at idx=2:
[1, 2, 4]
[2, 4]
[4]
-------------> dp[2] = 1 + 2 + 4, stk = [0, 1, 2]

end at idx=3:
[1, 2, 4, 3]
[2, 4, 3]
[4, 3]
[3]
-------------> dp[3] = dp[1] + 3 * (3 - 1), stk = [0, 1, 3]
... where dp[1]'s 1 is derived from the top of stack, (the index 2 was popped,
    and before pushing the new idx 3)
*/

class Solution {
 public:
  static constexpr int mod = 1'000'000'007;
  int sumSubarrayMins(vector<int>& arr) {
    const int sz = arr.size();
    std::vector<int> dp(sz, 0);
    std::stack<int> monoIncStk;
    monoIncStk.push(0);
    int sum = dp[0] = arr[0];
    for (int i = 1; i < sz; ++i) {
      if (arr[i] >= arr[i - 1]) {
        dp[i] = (dp[i - 1] + arr[i]) % mod;
      } else {
        while (!monoIncStk.empty() && arr[monoIncStk.top()] > arr[i]) {
          monoIncStk.pop();
        }
        if (monoIncStk.empty()) {
          // arr[i] introduce a new smallest value to all the previous subarray
          dp[i] = ((i + 1) * arr[i]) % mod;
        } else {
          // j is the largest previous index having arr[j] < arr[i]
          int j = monoIncStk.top();
          dp[i] = (dp[j] + (arr[i] * (i - j)) % mod) % mod;
        }
      }
      sum = (sum + dp[i]) % mod;
      monoIncStk.push(i);
    }
    return sum;
  }
};