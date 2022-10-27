// The main algorithm to rotate an array
// [1 2 3 4 5 6 7], k = 3
// rotate: [0: sz - k) --> [4 3 2 1 5 6 7]
// rotate: [sz - k:)   --> [4 3 2 1 7 6 5]
// rotate: [0: sz)     --> [5 6 7 1 2 3 4]

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
      const int sz = nums.size();
      k %= sz;
      std::reverse(nums.begin(), nums.begin() + sz - k);
      std::reverse(nums.begin() + sz - k, nums.end());
      std::reverse(nums.begin(), nums.end());
    }
};

// Same method but utilizing std::rotation
// std::rotation is actually left rotate
// second element is the element becomes head
// [1,2,3,4,5,6,7] k = 3, need to left rotate sz - k
/* class Solution {
 public:
  void rotate(vector<int>& nums, int k) {
    const int sz = nums.size();
    k %= sz;
    std::rotate(nums.begin(), nums.begin() + sz - k, nums.end());
  }
}; */

/*
/* Side question ... how do you right rotate 1?

a b c d  -> d a b c

so at the beginning ...
b is going to be replaced with a, we must keep track of b somehow
also in the next round, b is going to replace c, so b should be preserved
into next run, and will be what is going to switch to. So basically
- what is going to be switched from is what was kept in previous round
- what is going to be swiched to is what is kept in this round
So:

init tmp = nums[0]
....
cur = tmp          // what was kept previously
tmp = nums[i + 1]  // what is kept in this round
swap(cur, nums[i + 1]) // swap

class Solution {
public:
    void rotateOne(vector<int>& nums) {
      int tmp = nums[0];
      int cur = tmp;
      for (int i = 0; i < nums.size() - 1; ++i) {
        cur = tmp;
        tmp = nums[i + 1];
        std::swap(cur, nums[i + 1]);
      }
      nums[0] = tmp;
    }

    void rotate(vector<int>& nums, int k) {
      // slow but just as a demonstration
      for (int i = 0; i < k; ++i) {
        rotateOne(nums);
      }
    }
};
*/