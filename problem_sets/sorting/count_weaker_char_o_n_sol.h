class Solution {
 public:
  int numberOfWeakCharacters(vector<vector<int>>& properties) {
    const auto maxAttk = (*std::max_element(
        properties.begin(), properties.end(),
        [](const auto& a, const auto& b) { return a[0] < b[0]; }))[0];

    // we need maxAttk + 1 elements at least to store all the possible maxDef,
    // then we add another one for the final loop to check the strictly less
    std::vector<int> maxDefOfAtk(maxAttk + 2, 0);
    // find the max def of each attack value first
    for (const auto& p : properties) {
      maxDefOfAtk[p[0]] = std::max(p[1], maxDefOfAtk[p[0]]);
    }

    for (int i = maxAttk; i >= 0; --i) {
      // The trick is that we can just update max def from larger
      // attack character to the previous one, as we know if it exists,
      // it would must be a better candidate to be stronger than even smaller
      // attack character
      maxDefOfAtk[i] = std::max(maxDefOfAtk[i + 1], maxDefOfAtk[i]);
    }

    int count = 0;
    for (const auto& p : properties) {
      // as we made maxAttk + 2 for our whole vector, we are sure
      // p[0] + 1 is always valid here
      count += p[1] < maxDefOfAtk[p[0] + 1];
    }
    return count;
  }
};