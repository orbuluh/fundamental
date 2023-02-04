/*

Method without rebuilding from each row is worth practicing IMO

zigzag cycle is like:

P   | A   | H   | N
A P | L S | I I | G
Y   | I   | R

0   | 4   | 8   | 12
1 3 | 5 7 | 9 11| 13
2   | 6   | 10

so for each cycle, it contains (2 * numRows - 2) elements

0     6
1   5 7    11   => row = 4, cycleCnt = 2 * 4 - 2 = 6
2 4   8 10
3     9

what's the pattern? for row 0 and last row, it always appends char with
idx + cycleCnt, row = 4:

0 --> 6 --> 12 and
3 --> 9 --> 15 ...

And for rows in between, in each cycle, there are 2 chars pushed.

check row 1
1 --> 5 7 --> 11 13

1 --> 7 --> 13 is the normal idx + cycleCnt

What's the pattern for 5 and 11? It's the (start of next cycle) - rowIdx!


So, the standard index for any row are rowIdx + cycle * cycleCnt
and for rows in between, we also need to find the char that is rowIdx away of
the next start of cycle

E.g. say working on row 1 in resulting string.

cycle 0:
- standard: push: 1 + 0 * 6
- extra: push (0 + 1) * 6 - 1 (e.g. next start cycle and going back 1 element)
cycle 1:
- standard: push: 1 + 1 * 6
- extra: push (1 + 1) * 6 - 1 (e.g. next start cycle and going back 1 element)
*/
class Solution {
 public:
  string convert(string s, int numRows) {
    const int sz = s.size();
    if (numRows == 1 || sz <= numRows) {
      return s;
    }
    int cycleCnt = 2 * numRows - 2;
    std::string res;
    res.reserve(sz);
    for (int r = 0; r < numRows; ++r) {
      for (int cycle = 0; r + cycle < sz; cycle += cycleCnt) {
        res.push_back(s[r + cycle]);
        if (r != 0 && r != numRows - 1) {
          const int nxtCycleStart = cycle + cycleCnt;
          if (nxtCycleStart - r < sz) {
            res.push_back(s[nxtCycleStart - r]);
          }
        }
      }
    }
    return res;
  }
};

/* // your first implementation with rebuilding

class Solution {
 public:
  string convert(string s, int numRows) {
    const int sz = s.size();
    if (numRows == 1 || sz <= numRows) {
      return s;
    }
    int idx = 0;
    int r = 0;
    int rOffset = 1;
    std::vector<std::string> resVec(numRows);
    while (idx < sz) {
      resVec[r].push_back(s[idx++]);
      r += rOffset;
      if (r == numRows) {
        r = numRows - 2;
        rOffset = -1;
      } else if (r == -1) {
        r = 1;
        rOffset = 1;
      }
    }
    std::string res = std::move(resVec[0]);
    for (int i = 1; i < numRows; ++i) {
      res.append(resVec[i]);
    }
    return res;
  }
};

*/