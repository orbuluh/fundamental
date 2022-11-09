/*

[6, 2, 4]:

If we choose 6 and 2 as leaf nodes of left tree, the left subtree val is
6 * 2 = 12, and right subtree val is the leaf value 4.

As the value of each non-leaf node is equal to the product of the largest leaf
value in its left and right subtree - at the next level, nothing will be related
to the 2.

Same if you choose 2 and 4 as right subtree, the right subtree val is 2 * 4 = 8,
and left subtree val is the leaf value 6. At the next level, nothing will be
related to the 2.


So overall you can view this as shrinking the array while merge nodes into a
subtree, each time shrinking with removing the smaller number. And you basically
build the tree from bottom to top.

The tree is built by ...

    24
  12  4
 6  2

 [6 2 4] --> [6 4] --> [6]
          ^         ^
       cost = 12    |
                 cost = 24


    24
   6  8
     2 4

 [6 2 4] --> [6 4] --> [6]
          ^         ^
       cost = 8    |
                 cost = 24

So the problem can translated as following:

- Given an array arr, choose two adjacent number in the array A and B, we can
  remove the smaller one min(A, B) and the cost is A * B. Here, cost is
  basically the non-leaf node value while building to the top by left node A and
  right node B.

- The question becomes: what is the minimum sum of cost to remove the whole
  array until only one left? (E.g. everything become a binary tree)

- To remove a number A, it needs a cost A * B, where B >= a and B is adjacent to
  A. As we want to minimize this cost, we want to take min(A's left, A's right),
  if both A's left and A's right are larger than A.

- Also, to minimize the overall costs along the way, in each step we want to
  make A being the smallest number in the array. Then B should be either of its
  adjacent number.

- So we could do this in O(n^2), where each time we find one node with minimal
  cost with O(n) on the remaining elements in arr, and we need to iterate
  basically O(n) time to reduce arr to one element.

For example: [6,12,15,2,5]
--> smallest 2, with cost = min(15, 5) * 2 = 10, arr = [6 12 15 5]
--> smallest 5, with cost = 15 * 5 = 75, arr = [6 12 15]
--> smallest 6, with cost = 12 * 6 = 72, arr = [12 15]
--> smallest 12, with cost = 12 * 15 = 180, arr = [18]
--> total cost 10 + 75 + 72 + 180 = 337

An even better way - use monotonic decreasing queue to keep track of the
non-merged larger value. It's basically like we are considering size 3 window
in the array each time. Say window contains [x y z]
And we basically want to remove smallest among all, and leave the larger 2s.

How? [x y] will be the top 2 number in the monotonic decreasing queue, e.g.
x > y. If we find a new number z that is larger than y, we try to pop the y out,
(now y must be the smallest), with a cost being min(x, z), then we try to see if
x is smaller than z. If it is, x is something that should be popped as well.
Overall, stack can either only contain something that is larger than z, or
contain only z, so we are always building the view of 3 elements while removing
the smallest one.

For example: [6,12,15,2,5]
--> monoDecQ: [6]
--> monoDecQ: [12], pop 6 with cost 6 * 12
--> monoDecQ: [15], pop 12 with cost 15 * 12
--> monoDecQ: [15, 2]
--> monoDecQ: [15, 5], pop 2 with cost 5 * 2
--> monoDecQ: [15], pop 5 with cost 5 * 15
*/

class Solution {
 public:
  int mctFromLeafValues(vector<int>& arr) {
    int res = 0;
    std::stack<int> monoDecStk;
    monoDecStk.push(INT_MAX);
    auto topAndPop = [&monoDecStk]() {
      int val = monoDecStk.top();
      monoDecStk.pop();
      return val;
    };
    for (int a : arr) {
      while (monoDecStk.top() <= a) {
        int curMin = topAndPop();  // local min to remove
        // now, the top is basically the left of curMin,
        // and a is the right of curMin, we remove curMin through multiply the
        // smaller one
        res += curMin * min(monoDecStk.top(), a);
      }
      monoDecStk.push(a);
    }
    while (monoDecStk.size() > 2) {
      auto curMin = topAndPop();
      res += monoDecStk.top() * curMin;
    }
    return res;
  }
};