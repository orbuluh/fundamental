/*
k th largest -> keep a minPQ with size k, then the top is the kth largest
*/
class KthLargest {
  std::priority_queue<int, std::vector<int>, std::greater<int>> pq;
  int k;

 public:
  KthLargest(int k, vector<int>& nums) : k(k) {
    for (auto n : nums) {
      add(n);
    }
  };

  int add(int val) {
    pq.emplace(val);
    if (pq.size() > k) {
      pq.pop();
    }
    return pq.top();
  }
};
