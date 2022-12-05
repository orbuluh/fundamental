/*
idea: build the union-find for equal equations, and validate with nonequal
equations in the second pass
*/

class Solution {
  std::vector<int> ufParent;  //(26, -1);
 public:
  int find(int idx) {
    if (ufParent[idx] == -1) ufParent[idx] = idx;
    return (ufParent[idx] == idx) ? idx : ufParent[idx] = find(ufParent[idx]);
  }

  void join(int idx1, int idx2) {
    auto set1 = find(idx1);
    auto set2 = find(idx2);
    if (set1 != set2) {
      ufParent[set1] = set2;
    }
  }

  bool equationsPossible(vector<string>& equations) {
    ufParent = std::vector<int>(26, -1);
    for (std::string_view eq : equations) {
      if (eq[1] == '!') continue;
      join(eq[0] - 'a', eq[3] - 'a');
    }

    for (std::string_view eq : equations) {
      if (eq[1] == '=') continue;
      if (find(eq[0] - 'a') == find(eq[3] - 'a')) {
        return false;
      }
    }
    return true;
  }
};