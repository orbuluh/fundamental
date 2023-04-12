class Solution {
 public:
  string simplifyPath(string path) {
    const auto sz = path.size();
    size_t i = 0;
    std::vector<std::string_view> folder;
    while (i < sz) {
      // read slash-------------------------
      while (i < sz && path[i] == '/') {
        i++;
      }
      // read dot---------------------------
      int tokenStart = i;
      while (i < sz && path[i] == '.') {
        i++;
      }
      if (i >= sz || path[i] == '/') {
        if (i - tokenStart == 1) {
          continue;
        }
        if (i - tokenStart == 2) {
          if (!folder.empty()) {
            folder.pop_back();
          }
          continue;
        }
      }
      // read folder name--------------------
      while (i < sz && path[i] != '/') {
        i++;
      }
      if (i - tokenStart == 0) {
        continue;
      }
      // stack the folder
      folder.emplace_back(
          std::string_view{path.data() + tokenStart, i - tokenStart});
    }
    std::string res;
    for (auto sv : folder) {
      res += (std::string{'/'} + std::string(sv));
    }
    return !res.empty() ? res : "/";
  }
};