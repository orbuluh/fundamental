/*
from post: https://leetcode.com/problems/integer-to-roman/discuss/1293176/C%2B%2B-easy-solution-O(1)
*/

class Solution {
 public:
  string intToRoman(int num) {
    string ones[] = {"",  "I",  "II",  "III",  "IV",
                     "V", "VI", "VII", "VIII", "IX"};
    string tens[] = {"",  "X",  "XX",  "XXX",  "XL",
                     "L", "LX", "LXX", "LXXX", "XC"};
    string hrns[] = {"",  "C",  "CC",  "CCC",  "CD",
                     "D", "DC", "DCC", "DCCC", "CM"};
    string ths[] = {"", "M", "MM", "MMM"};

    return ths[num / 1000] + hrns[(num % 1000) / 100] + tens[(num % 100) / 10] +
           ones[num % 10];
  }
};

/* Compared to your original implementation ...

class Solution {
 public:
  string intToRoman(int num) {
    auto recursive = [&](int unit, char c) {
      return std::string(num / unit, c) + intToRoman(num % unit);
    };

    if (num >= 1000) {
      return recursive(1000, 'M');
    } else if (num >= 900) {
      return "CM" + intToRoman(num - 900);
    } else if (num >= 500) {
      return recursive(500, 'D');
    } else if (num >= 400) {
      return "CD" + intToRoman(num - 400);
    } else if (num >= 100) {
      return recursive(100, 'C');
    } else if (num >= 90) {
      return "XC" + intToRoman(num - 90);
    } else if (num >= 50) {
      return recursive(50, 'L');
    } else if (num >= 40) {
      return "XL" + intToRoman(num - 40);
    } else if (num >= 10) {
      return recursive(10, 'X');
    } else if (num >= 9) {
      return "IX" + intToRoman(num - 9);
    } else if (num >= 5) {
      return recursive(5, 'V');
    } else if (num >= 4) {
      return "IV" + intToRoman(num - 4);
    } else if (num >= 1) {
      return recursive(1, 'I');
    }

    return "";
  }
};
*/
