/*
Idea: keeping a stack about the last seen char
As long as we see a new char, we push new entry to the stack
Also we associate a combo count with the char, so we can quickly remove
the char that hits k combo. For example:
s=bdbd k = 2
we have stack [(b, 1), (d, 1), (b, 1), (d, 1)]
s=bbdd k = 2
we have [(b, 2)] -> [] -> [(d, 2)] -> []

The beautiful part is - through inserting a [('#', 0)] at the beginning
The whole algorithm becomes much more clean!
*/
class Solution {
  public:
    struct SeenChar {
        char c = '#';
        int combo = 0;
        std::string toStr() const { return std::string(combo, c); }
    };
    string removeDuplicates(string s, int k) {
        std::vector<SeenChar> seen;
        // trick - at the end, we dump combo * c, so won't affect
        seen.push_back({});
        for (char c : s) {
            if (seen.back().c == c) {
                seen.back().combo += 1;
                if (seen.back().combo == k)
                    seen.pop_back();
            } else {
                seen.push_back({c, 1});
            }
        }
        std::string res;
        for (const auto& seenChar : seen)
            res += seenChar.toStr();
        return res;
    }
};