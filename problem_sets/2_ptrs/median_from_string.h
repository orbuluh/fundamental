/*
The idea is that

Fix size (n/2) maxQ: store smaller portion
Fix size (n/2 or n/2 + 1) minQ , store larger portion

median should equal to minQ.top when n is odd
or (maxQ.top + minQ.top) / 2, when n is even

Slightly trick part is how to actually implement it

Easier way to think is what is the invariant?

1. maxQ.top <= minQ.top
2. maxQ.size is always at n / 2
3. minQ.size >= maxQ.size

As 3, when the first element is in, it should go to
minQ (larger portion).

Then you can actually always insert the value according
to 1, e.g. if new val is larger than min of larger portion
it should go to larger portion, otherwise it should go to
smaller portion

Then you tweak the size accordingly to 2

insert 4: M: [], m: [4]
insert 3: M: [3], m: [4]
insert 2: M: [2], m: [4, 3]
insert 1: M: [1, 2], m: [4, 3]

*/
class MedianFinder {
  int n = 0;
  std::priority_queue<int> smaller;
  std::priority_queue<int, std::vector<int>, std::greater<int>> larger;

 public:
  MedianFinder() = default;

  void addNum(int num) {
    if (n++ == 0) {
      larger.push(num);
      return;
    }

    if (larger.top() < num) {
      larger.push(num);
    } else {
      smaller.push(num);
    }

    if (smaller.size() != n / 2) {
      if (smaller.size() > larger.size()) {
        larger.push(smaller.top());
        smaller.pop();
      } else {
        smaller.push(larger.top());
        larger.pop();
      }
    }
  }

  double findMedian() {
    if (n % 2) {
      return larger.top();
    } else {
      return (smaller.top() + larger.top()) / 2.0;
    }
  }
};