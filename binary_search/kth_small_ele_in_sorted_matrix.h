/*
Check thread:
https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/discuss/1322101/C%2B%2BJavaPython-MaxHeap-MinHeap-Binary-Search-Picture-Explain-Clean-and-Concise

Observation: there is no guarantee that i+1, j-1 will be smaller than i, j
The only thing you know is that top-left must be the smallest, and bottom-right
must be the largest.

Idea: How to find the kth smallest element? It will be an element >= k - 1 other
elements. And to find how many elements are smaller than a specific value in
such sorted array is n * O(log n)

Say finding how many element <= 8?
1 3   7    --> upper_bound at the end, so +n
5 10 12    --> upper bound at idx 1, +1
6 10 15    --> upper bound at idx 1, +1 (and you can shrink begin)

So the critical part is you are binary search within the min val (top-left) and
max val (bottom-right). Trying to find the minimum number that >= k - 1
elements!

*/

class Solution {
    int n = 0;

  public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        n = matrix.size();
        int l = matrix[0][0];
        int r = matrix[n - 1][n - 1];

        while (l < r) {
            const int midVal = l + (r - l) / 2;
            if (countLE(matrix, midVal) < k) {
                l = midVal + 1;
            } else {
                r = midVal;
            }
        }
        return l;
    }

    int countLE(const vector<vector<int>>& matrix, int target) {
        int count = 0;
        for (int i = 0; i < n; ++i) {
            auto it =
                std::upper_bound(matrix[i].begin(), matrix[i].end(), target);
            if (it == matrix[i].begin())
                break;
            // upper bound is the first larger than,
            // say return idx i, it means there are i + 1 value > target
            // and we want to take the previous one, so there is i value <=
            // target.
            count += (it - matrix[i].begin());
        }
        return count;
    }
};