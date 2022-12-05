/*
[Idea 1: need to run it backwards]
-> the max must be the last change and the max must be the previous sum
-> [9, 3, 5] -> max = prevSum = 9.
             -> run backward, prevVal + 3 + 5 = prevSum = 9, prevVal = 1
             -> so previously it looks like ...
-> [1, 3, 5] -> max = prevSum = 5, same, prevVal + 1 + 3 = 5, prevVal = 1
-> [1, 3, 1] -> max = prevSum = 3, preVal = 3 - 1 - 1 = 1
-> [1, 1, 1]

-> or you can derive ... prevVal + others = max
                         others + max = sum
                         prevVal = max - others = 2 * max - sum

[Idea 2: speedup the case like...]

-> [3, 5, 33] -> [3, 5, 25] -> [3, 5, 17] -> [3, 5, 9] -> [3, 5, 1]
 -> [3, 1, 1] -> [1, 1, 1]

-> e.g. say in several run, the max is always at the same position
-> you will always end up substracting max with the same number
-> so the optimization is do a % (other elements sum) instead

-> [3, 5, 33] -> [3, 5, 33 % (3+5)] = [3, 5, 1] --> much faster in 1 step

-> e.g. prevVal = maxVal % (other) = maxVal % (sum - maxVal)


[Idea 3] Other corner cases...

(a) case like [1, 1, 1, 2], prevVal = 2 % 3 = 2
    this infinite loop indicate an infinite backward step
    that won't give you the result.
(b) case like [1, 1, 2], prevVal = 2 % 2 = 0
(c) [1, 100], 100 % 1 = 1, must be able to form answer


[Time: Complexity]
- heapify the pq / get the sum took 2 * O(n)
- maxA = max(target), we have O(maxA) loops, but as the modulo behavior, like
  gcd ... the loop should be O(log maxA)
- each loop, we insert an element into heap, O(log n)
- Overall: O((log maxA)(log n)) + 2 * O(n) ~= O((log maxA)(log n))

[Space] to store pq - O(n)
*/

class Solution {

  public:
    bool isPossible(vector<int>& target) {
        std::priority_queue<int> maxPQ(target.begin(), target.end());
        long sum = std::accumulate(target.begin(), target.end(), 0L);
        while (!maxPQ.empty() && maxPQ.top() != 1) {
            const int maxVal = maxPQ.top();
            maxPQ.pop();
            const long otherSum = sum - maxVal;
            // if otherSum == 0 ... it can't create from all 1s...
            if (!otherSum)
                return false;
            // corner case (c)
            if (otherSum == 1)
                return true;
            const int prevVal = maxVal % otherSum;
            // corner cases (a) / (b)
            if (prevVal == maxVal || prevVal == 0)
                return false;
            maxPQ.push(prevVal);
            sum = otherSum + prevVal;
        }
        return true;
    }
};
