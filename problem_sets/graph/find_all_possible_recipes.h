/*

A recipe can only be made if all its ingredients is supplied but ingredients
could contain other recipe.

So overall it should be like a graph, represents in adjacency matrix like:

recipe    itemNeeded
r1     -> [r2, i1, i2 ...]
r2     -> [i3, i2, i4]
...etc


Say we do a DFS and maintains a madeItem set.
All the supplies are by default in the madeItem set.

We dfs the whole itemNeeded for each recipe a recipe can be made
if all dfs(itemNeeded) return true

one thing to note is there could be r1 depends on r2, and eventually r2 depends
on r1 (cyclic). In such case - you need to keep track of what has been checked
while dfs'ing
*/

class Solution {
  std::unordered_set<std::string_view> madeItem;
  std::unordered_map<std::string_view, int> recipeIdx;

 public:
  vector<string> findAllRecipes(vector<string>& recipes,
                                vector<vector<string>>& ingredients,
                                vector<string>& supplies) {
    for (std::string_view supply : supplies) {
      madeItem.insert(supply);
    }
    for (int i = 0; i < recipes.size(); ++i) {
      recipeIdx[recipes[i]] = i;
    }
    std::vector<std::string> res;
    for (std::string_view r : recipes) {
      std::unordered_set<std::string_view> visited;
      if (canMake(ingredients, r, visited)) {
        res.emplace_back(std::string(r));
      }
    }
    return res;
  }

  bool canMake(const vector<vector<string>>& ingredients, std::string_view item,
               std::unordered_set<std::string_view>& visited) {
    if (visited.count(item))
      return false;  // cyclic in the recipe and ingredient
    visited.emplace(item);
    if (madeItem.count(item))
      return true;  // a made recipe, or simply one of supply
    auto it = recipeIdx.find(item);
    if (it == recipeIdx.end())
      return false;  // an ingredient that is not in supplies nor other recipes
    int idx = it->second;
    for (std::string_view subitem : ingredients[idx]) {
      if (madeItem.count(subitem)) continue;
      if (!canMake(ingredients, subitem, visited)) {
        return false;
      }
    }
    madeItem.insert(item);
    return true;
  }
};