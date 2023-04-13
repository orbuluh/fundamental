/*
Easy to write in a non-clean way if you didn't think it clearly...
*/

class Solution {
 public:
  bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
    const int sz = pushed.size();
    std::vector<int> sim(sz);
    int nxtWrite = 0;
    int nxtPop = 0;
    for (auto n : pushed) {
      sim[nxtWrite++] = n;
      while (nxtPop < sz && nxtWrite - 1 >= 0 &&
             popped[nxtPop] == sim[nxtWrite - 1]) {
        nxtWrite--;
        nxtPop++;
      }
    }
    return nxtWrite == 0;
  }
};