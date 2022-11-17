/*

[Idea]

- Say we have 2 type of wiggle subsequence, call them
  -> I seq: a wiggle seq whose last 2 element were increasing
  -> D seq: a wiggle seq whose last 2 element were decreasing
- I seq must be built from a D seq with a number larger than the last of D seq
- D seq must be build from a I seq with a number smaller than the last of I seq

[Key observation]

Think about the case [1, 2, 4, 3]
say we are at final 3, the previously valid I suq are:
    - [1,4]
    - [2,4]
    - [1,2]
you can see that [1,2] will never be a better choice than [1,4]. As when you are
building an I seq with an increasing last number, you will always want it to be
as big as possible, as this give you a better chance to get longer (higher
chance to be larger than the next value, so we wiggle.)

Vise-versa, when you are building a D seq, you will want the last number to be
as small as possible.

[Analyze]

Say we are building longest I sub `iSoFar` and longest D sub `dSoFar`.
What could happen for iSoFar' and dSoFar' when we see new element nums[i]?

- say before checking nums[i]:
    - iSoFar = [ ... N ]
    - dSoFar = [ ... M ]

--- Scenario 1: nums[i] == nums [i-1] ---
    - we basically won't update iSoFar nor dSoFar
    - e.g. iSoFar' = iSoFar, dSoFar' = dSoFar

--- Scenario 2: nums[i] > nums [i-1] ---
- 1. can iSoFar' = dSoFar + [nums[i]] = [ ... M, nums[i] ]? YES!
    - (a) if M is nums[i-1], we get iSoFar' = [..., nums[i-1], nums[i] ]
    - (b) if M is not nums[i-1], it must be something smaller than nums[i-1],
          we still get iSoFar' = [..., M, nums[i]]
- 2. can dSoFar' = iSoFar + [nums[i]] = [ ... N, nums[i] ]? NO!
    - (a) if N is nums[i-1], since nums[i] > nums[i-1], nums[i] must drop
    - (b) if N is not nums[i-1] ... (**The part you stuck originally!!**)
          since N is last element of I seq, N must > nums[i-1] - which means
          that X = { ... N, nums[i-1] } should have been a legit D seq ... and
          since nums[i] > nums[i-1], nums[i] would never be a better choice to
          form a D seq.
          Also, dSoFar itself should have consider whether X is the longest
          dSoFar when checking i-1

--- Scenario 3: nums[i] < nums [i-1] ---
- 3. can iSoFar' = dSoFar + [nums[i]] = [ ... M, nums[i] ]? NO!
    - (a) if M is nums[i-1], we can't build iSoFar' from it because
          nums[i] < nums[i-1]
    - (b) if M is not nums[i-1], since M is last element of D seq,
          M must < nums[i-1], e.g. Y = [... M, nums[i-1]] should have been a
          legit I sequence. Same reasoning as 2-(b), putting nums[i] at the end
          just won't be longer than iSoFar from i-1
  4. can dSoFar' = iSoFar + [nums[i]] = [ ... N, nums[i] ]? YES!
    - (a) if N is nums[i-1], we get dSoFar' = [ ... nums[i-1], nums[i] ]
    - (b) if N is not nums[i-1], since N is in I seq, N must > nums[i-1], we are
          guarantee to form dSoFar' as such as well!
*/
class Solution {
  public:
    int wiggleMaxLength(vector<int>& nums) {
        int lenISoFar = 1;
        int lenDSoFar = 1;
        for (int i = 1; i < nums.size(); ++i) {
            // basically the case if nums[i] == nums[i-1]
            int nextLenISoFar = lenISoFar;
            // basically the case if nums[i] == nums[i-1]
            int nextLenDSoFar = lenDSoFar;
            if (nums[i] > nums[i - 1]) {
                nextLenISoFar = lenDSoFar + 1;
            } else if (nums[i] < nums[i - 1]) {
                nextLenDSoFar = lenISoFar + 1;
            }
            lenISoFar = nextLenISoFar;
            lenDSoFar = nextLenDSoFar;
        }
        return std::max(lenISoFar, lenDSoFar);
    }
};