/*
- Call {0, 1, 6 , 8, 9} as "confusing digits"
- If a number contains any non-confusing-digits: it must not be confusing
- So we only need to find something only containing the confusing digits
- looping through 1 to n will be a waste of time, so the idea here is generating
  unique number that only contains confusing digits - as long as the generated
  number is <= n, we can just check whether it's confusing.

- How do you create unique number with only confusing digits? you can use DFS.
  In each iteration, you 10 * value_so_far, then add a confusing digits.

- for example:　169 can be created by ...
  curNum = 0, tryConfusingDigit = 1 -> curNum = 0 * 10 + 1
  curNum = 1, tryConfusingDigit = 6 -> curNum = 1 * 10 + 6
  curNum = 16, tryConfusingDigit = 9 -> curNum = 16 * 10 + 9

- The first digit in dfs shouldn't be 0, otherwise you will get an infinite loop
  when trying 0, 0, 0...
- Also we can just skip to try 0 in first level because we will try  to start
  with 1, 6, 8, 9 anyway.
*/
class Solution {
  static std::unordered_map<int, int> mapping;

 public:
  int isConfusing(int n) {
    // n should only contains 0,1,6,9,8
    // 1698
    // {8->8} -> {9->6} -> {6->9} -> {1->1}

    /*
    // non-optimizing way:
    const int oriNum = n;
    int rotateNum = 0;
    while (n > 0) {
      rotateNum = 10 * rotateNum + mapping[n % 10];
      n /= 10;
    }
    return rotateNum != oriNum;
    */

    // faster optimization from others
    int arr[10];
    int i = 0;
    while (n) {
      arr[i++] = n % 10;
      n /= 10;
    }
    for (int l = 0, r = i - 1; l <= r; l++, r--) {
      if (arr[l] != mapping[arr[r]]) return true;
    }
    return false;
  }

  int dfsConfusingDigits(int curNum, int n) {
    if (curNum > n) {
      return 0;
    }
    int res = isConfusing(curNum);
    for (int d : {0, 1, 6, 8, 9}) {
      // prevent overflow for curNum * 10 + d
      if (10L * curNum + d <= n) {
        res += dfsConfusingDigits(curNum * 10 + d, n);
      }
    }
    return res;
  }

  int confusingNumberII(int n) {
    int res = 0;
    for (int d : {1, 6, 8, 9}) {
      res += dfsConfusingDigits(d, n);
    }
    return res;
  }
};

std::unordered_map<int, int> Solution::mapping = {
    {0, 0}, {1, 1}, {6, 9}, {8, 8}, {9, 6}};