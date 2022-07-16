class Solution {
public:
    struct SeenChar {
        char c = '-';
        int combo = 0;
        std::string toStr() const { return std::string(combo, c); }
    };
    string removeDuplicates(string s, int k) {
        std::vector<SeenChar> seen;
        seen.push_back({}); // trick - at the end, we dump combo * c, so won't affect
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