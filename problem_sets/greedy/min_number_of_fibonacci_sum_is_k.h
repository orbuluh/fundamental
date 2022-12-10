/*
The question is ... why greedy works?

Modified from:
https://leetcode.com/problems/find-the-minimum-number-of-fibonacci-numbers-whose-sum-is-k/solutions/1106690/greedy-explained-and-proved/

 FN = fibonacci number
 1. Let the max FN less than k be f, after this operation, problem becomes
    (k - f).
 2. Let it takes M steps to solve (k - f).
 3. Suppose there is another FN f' that can produces a better result.
 4. Because f is max FN less than k, f' must be < f, supposed delta of f and f'
    = f - f' = fx, then after using f', the problem is (k - f') = (k + fx - f)
 5. Assume it takes M' steps to solve (k + fx - f), where M' < M (so f' can be
    a better operation as you assume.)
 6. So overall it's saying you are trying to use fewer numbers (as M' < M),
    to sum to a bigger result k + fx - f (> k - f). This is just not possible.
*/

class Solution {
public:
    static std::vector<int> fibos;
    int findMinFibonacciNumbers(int k) {
        while (fibos.back() <= k) {
            fibos.push_back(fibos.back() + fibos[fibos.size() - 2]);
        }
        auto idx = std::lower_bound(fibos.begin(), fibos.end(), k) - fibos.begin();
        if (fibos[idx] == k) {
            return 1;
        }
        int cnt = 0;
        while (k > 0) {
            while (fibos[idx] > k) {
                idx--;
            }
            k -= fibos[idx];
            cnt++;
        }
        return cnt;
    }
};

std::vector<int> Solution::fibos = {1, 1};