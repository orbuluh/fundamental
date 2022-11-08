/*
sort with deadline - the earlier the deadline is, the earlier we
should check.

Then we keep a timeUsed and gradually taking class that
has a earlier deadline. If we can't take a course because
timeUsed + duration exceed the deadline, we check whether this
class has a smaller duration than all the courses taken so far.
If so, we must be able to fit this class in while having a smaller
timeUsed. So basically we keep the duration of courses taken into
a maxPQ.

[[100,200],[200,1290],[1000,1250],[2000,3200]]
-> sort by deadline
[[100,200],[1000,1250],[200,1290],[2000,3200]]
-> timeUsed = 0
-> took [100,  200], timeUsed = 0 + 100, pq = [100]
-> took [1000, 1250], timeUsed = 100 + 1000, pq = [1000, 100]
-> took [200, 1300], timeused = 1100 + 200 = 1300 > 1290
   -> pq.top == (1000), > 200, we can take this class and replace previous
   -> timeused - 1000 + 200 = 300, pq = [200, 100]
-> took [2000, 3200], timeused = 300 + 2000 = 2300, pq = [2000, 200, 100]
*/
class Solution {
  public:
    int scheduleCourse(vector<vector<int>>& courses) {
        std::sort(courses.begin(), courses.end(),
                  [](const auto& p1, const auto& p2) { return p1[1] < p2[1]; });
        int timeUsed = 0;
        std::priority_queue<int> durations;
        for (const auto& p : courses) {
            if (timeUsed + p[0] <= p[1]) {
                timeUsed += p[0];
                durations.push(p[0]);
            } else if (!durations.empty()) {
                if (durations.top() > p[0]) {
                    timeUsed += (p[0] - durations.top());
                    durations.pop();
                    durations.push(p[0]);
                }
            }
        }
        return durations.size();
    }
};