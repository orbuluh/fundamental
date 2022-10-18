class Solution {
 public:
  string countAndSay(int n) {
    if (n == 1) return "1";
    auto recursiveRes = countAndSay(n - 1);
    int i = 0;
    int sz = recursiveRes.size();
    std::string res;
    while (i < sz) {
      int count = 1;
      while (i + 1 < sz && recursiveRes[i + 1] == recursiveRes[i]) {
        count++;
        i++;
      }
      res += std::to_string(count);
      res += recursiveRes[i++];
    }
    return res;
  }
};