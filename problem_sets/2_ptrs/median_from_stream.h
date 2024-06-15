/*
Check python solution for rationale
*/

class MedianFinder {
  std::priority_queue<int> first_half;  // c++ PQ is maxQ
  std::priority_queue<int, std::vector<int>, std::greater<int>> second_half;

 public:
  MedianFinder() = default;

  void addNum(int num) {
    second_half.push(num);
    const auto smallest_of_2nd_half = second_half.top();
    second_half.pop();
    first_half.push(smallest_of_2nd_half);

    if (second_half.size() < first_half.size()) {
      const auto t = first_half.top();
      first_half.pop();
      second_half.push(t);
    }
  }

  double findMedian() {
    if (first_half.size() == second_half.size()) {
      return (first_half.top() + second_half.top()) / 2.0;
    } else {
      return second_half.top();
    }
  }
};
