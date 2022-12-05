    /*
    every time check with shortest

    [[7,0],[4,4],[7,1],[5,0],[6,1],[5,2]]
    sort by height,
    ->[[7,0],[7,1],[6,1],[5,0],[5,2],[4,4]]

    original thoughts: a recursive way

    idx: 5 ->  xxxx [4,4] x
                            /recur back from below: [5,0][7,0][5,2][6,1][4,4][7,1] (insert at pos 4)
    idx: 4 ->  xx [5,2] xxx
                            /recur back from below: [5,0][7,0][5,2][6,1][7,1] (insert at pos 2)
    idx: 3 ->  [5,0] xxx
                            /recur back from below: [5,0][7,0][6,1][7,1] (insert at pos 0)
    idx: 2 ->  x [6,1] x
                            /recur back from below: [7,0][6,1][7,1] (insert at pos 1)
    idx: 1 ->  x [7,1]
                            /recur back from below: [7,0][7,1] (insert at pos 1)
    idx: 0 -> [7,0]

    so overall, when you recur back, taller basically tell you which position the person
    should be. Below solution were transformed it to iterative.
    (Maybe I should have said it's more "partition" than "greedy"?)
    */
class Solution {
  public:
    std::vector<std::vector<int>> reconstructQueue(std::vector<std::vector<int>>>& ppl) {
        // after sorting, higher people must be in the front
        // so every time we do a dfs, we are checking taller people
        // and we also know how many people should be taller than current idx
        // so we know where the current index should be insert

        std::sort(ppl.begin(), ppl.end(), [](const auto& p1, const auto& p2) {
            // edge case, when 2 people with same height - then for fewer taller
            // ppl in front they must be more front (e.g. we consider them
            // taller) So we sort the original ppl vec with height in decreasing
            // order but taller_value in increasing order
            return p1[0] > p2[0] || (p1[0] == p2[0] && p1[1] < p2[1]);
        });

        std::deque<int> idxes;
        for (int i = 0; i < ppl.size(); ++i) {
            const auto& p = ppl[i];
            const int taller = p[1];
            idxes.insert(idxes.begin() + taller, i);
        }

        std::vector<std::vector<int>> ans;
        for (int i : idxes)
            ans.emplace_back(std::move(ppl[i]));
        return ans;
    }
};
