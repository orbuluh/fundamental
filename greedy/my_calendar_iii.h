// Find the maximum number of concurrent ongoing event at any time.
// So we just use an ordered "event bucket" to record: If there is a start of an
// event or an end of an event. Then when we scan through the whole buckets of
// timing while accumulate the bucket event count, we basically know the ongoing
// events at each timing

class MyCalendarThree {
  std::map<int, int> eventBucket;

 public:
  MyCalendarThree() = default;

  int book(int start, int end) {
    eventBucket[start]++;
    eventBucket[end]--;
    int k = 0;
    int ongoing = 0;
    for (const auto& [_, count] : eventBucket) {
      k = std::max(k, ongoing += count);
    }
    return k;
  }
};
