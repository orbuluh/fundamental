/*
(your new python sol seems better explain)

https://leetcode.com/problems/greatest-common-divisor-of-strings/solutions/303759/my-4-lines-c-solution/?orderBy=most_votes

str1       str2
-----------------
"ABABAB"	"ABAB"
"AB"	    "ABAB"
"ABAB"	  "AB"
"AB"	    "AB"
""	      "AB"
"AB"	    ""

Proof by @bitcpf in discussion

Assume 2 strings are divided by T
Then:
str1 = nT
str2 = mT

n > m:
tempStr = str1-str2 = (n-m)T = kT
str2 - tempStr = (m-k)T = aT

...

At the end, there will be xT with one string, and empty with another string.
*/

class Solution {
 public:
  string gcdOfStrings(string str1, string str2) { return gcdImpl(str1, str2); }

  std::string gcdImpl(std::string_view str1, std::string_view str2) {
    // std::cout << "\"" << str1 << "\"\t\"" << str2 << "\"\n";
    if (str1.size() < str2.size()) return gcdImpl(str2, str1);
    if (str2.empty()) return std::string{str1};
    if (str1.substr(0, str2.size()) != str2) return "";
    return gcdImpl(std::string_view{str1.begin() + str2.size()}, str2);
  }
};

/* // Brute force solution... also quick enough

  string gcdOfStrings(string str1, string str2) {
    if (str1.size() < str2.size()) {
        std::swap(str1, str2);
    }
    const int sz1 = str1.size();
    const int sz2 = str2.size();

    auto dividable = [](std::string_view s, std::string_view divisor) {
        const int len = divisor.size();
        if (len == 0 || s.size() % len != 0) {
            return false;
        }
        bool found = true;
        const int cnt = s.size() / divisor.size();
        for (int i = 0; i < cnt; ++i) {
            if (s.substr(i * divisor.size(), divisor.size()) != divisor) {
                return false;
            }
        }
        return true;
    };

    for (int len = sz2; len > 0; len--) {
        auto divisor = std::string_view(str2.data(), len);
        if (!dividable(str2, divisor)
           || !dividable(str1, divisor)) {
            continue;
        }
        return std::string{divisor};
    }
    return "";
  }
*/