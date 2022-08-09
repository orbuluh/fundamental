class Solution {
  public:
    /*
    [2, 4, 5, 10, 40]
    ->  2: [2]
    ->  4: [4], [4 2 2]
    ->  5: [5]
    -> 10: [10], (res[2]) x (res[5]), (res[5]) x res[2])
    -> 40: [40], (res[4]) x (res[10]), (res[10]) x res[4]
    */
    static constexpr int mod = 1'000'000'007;
    int numFactoredBinaryTrees(vector<int>& arr) {
        std::sort(arr.begin(), arr.end());
        std::unordered_map<int, int> treeCnt;
        int res = 0;
        for (int i = 0; i < arr.size(); ++i) {
            auto& cnt = treeCnt[arr[i]];
            cnt += 1;
            for (int j = 0; j < i; ++j) {
                if (arr[i] % arr[j] != 0) {
                    continue;
                }
                const auto factor = arr[i] / arr[j];
                auto it = treeCnt.find(factor);
                if (it != treeCnt.end()) {
                    cnt = (long(treeCnt[arr[j]]) * it->second + cnt) % mod;
                }
            }
            res = (long(cnt) + res) % mod;
        }
        return res;
    }
};