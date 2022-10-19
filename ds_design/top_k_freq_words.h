/*
Your original buckets of (ordered)set is much slower than the simple scan first,
build the freq map and then put into priority queue method... 2 pass might just
be quicker.
*/

class Solution {
 public:
  vector<string> topKFrequent(vector<string>& words, int k) {
    std::unordered_map<std::string_view, int> freq;
    for (std::string_view sv : words) {
      freq[sv]++;
    }

    using FreqSv = std::pair<int, std::string_view>;

    auto comp = [](const FreqSv& fsv1, const FreqSv& fsv2) {
      return fsv1.first < fsv2.first ||
             (fsv1.first == fsv2.first && fsv1.second > fsv2.second);
    };

    std::priority_queue<FreqSv, std::vector<FreqSv>, decltype(comp)> pq(comp);

    for (const auto& [sv, f] : freq) {
      pq.emplace(std::make_pair(f, sv));
    }
    std::vector<std::string> res;
    while (k-- != 0) {
      res.emplace_back(std::string(pq.top().second));
      pq.pop();
    }
    return res;
  }
};

/*class Solution {
  // hashmap std::string (word) -> int (count)
  // words.length is just 500, we could do a bucket like structure for a fixed
  // size 501 each bucket represents one freq -> a ordered set (as we want to
  // sort it)

 public:
  vector<string> topKFrequent(vector<string>& words, int k) {
    std::unordered_map<std::string_view, int> freq;
    std::vector<std::set<std::string_view>> freqBuckets(
        501, std::set<std::string_view>{});
    for (std::string_view sv : words) {
      freqBuckets[freq[sv]++].erase(sv);
      freqBuckets[freq[sv]].insert(sv);
    }
    std::vector<std::string> res;
    for (int freq = 500; freq >= 0 && k > 0; --freq) {
      for (auto sv : freqBuckets[freq]) {
        res.emplace_back(std::string(sv));
        if (--k == 0) {
          break;
        }
      }
    }
    return res;
  }
};*/