class Solution {
  public:
    /*
    need to think this in a reversed way ... why?

    if target contains the stamp, then those substring should have
    been the last time the index got the stampped. So working
    backwardly, you can gradually recover what was last stampped.

    Noted that as earlier stamp will be wiped out by the later stamp
    when you do the reversed uncover, you can basically make those
    stamp to be wildcard, meaning it can match anything.

    stamp = "abca", target = "aabcaca"

       aabcaca
    -> a[abca]ca -> a****ca
    -> [a***]*ca -> *****ca
    -> ***[**ca] -> *******

    */
    static constexpr char wildcard = '*';
    std::string_view stampSv;
    vector<int> movesToStamp(string stamp, string target) {
        stampSv = stamp;
        std::vector<int> path;
        std::bitset<1000> visited;
        int replacedCnt = 0;
        int searchBound = target.size() - stamp.size() + 1;

        while (replacedCnt < target.size()) {
            bool foundReplace = false;
            for (int i = 0; i < searchBound; ++i) {
                if (visited.test(i))
                    continue;
                if (auto toReplaceCnt = checkReplace(i, target)) {
                    replacedCnt += toReplaceCnt;
                    visited.set(i);
                    path.push_back(i);
                    auto replaceBeginIt = target.begin() + i;
                    std::fill(replaceBeginIt, replaceBeginIt + stamp.size(),
                              wildcard);
                    foundReplace = true;
                    break;
                }
            }
            if (!foundReplace)
                return {};
        }
        std::reverse(path.begin(), path.end());
        return path;
    }

    int checkReplace(int idx, std::string_view target) {
        // return number of non wildcard match otherwise
        // out of bound
        // assert(idx + stampSv.size() <= target.size())
        int toReplaceCnt = 0;
        for (int i = 0; i < stampSv.size(); ++i) {
            if (target[idx + i] == wildcard)
                continue;
            if (target[idx + i] != stampSv[i])
                return 0;
            toReplaceCnt++;
        }
        return toReplaceCnt;
    }
};