/*

You need to maintain a curTime to know what's the candidate tasks.

And then at any given time, you either pick the one with minimum processing time
or the one with minimum index in original input.

So the candidate tasks doesn't sort with enqueue time - but the curTime will
decide what are the tasks that is okay to put into the candidate tasks.

If nothing in the taskQ yet, we can just set the curTime to the front of the
unprocessed task's enqueue time.

Whenever we execute one task, we can update the curTime accordingly.

So the idea is sort the whole input with enqueue time first. Then we maintain
a taskQ to represent the candidate list.

In each iteration, we scan through the sorted unprocessed tasks, and put all the
task with enqueue time <= curTime into the taskQ

Each iteration could push multiple tasks into taskQ, and execute 1 task, then
update the curTime to see if we will push more unprocessed task in the next run
*/
class Solution {
 public:
  vector<int> getOrder(vector<vector<int>>& tasks) {
    const int sz = tasks.size();
    for (int i = 0; i < sz; ++i) {
      tasks[i].push_back(i);  // add the original index so we can retrieve back
    }
    using Task = std::vector<int>;
    std::sort(tasks.begin(), tasks.end(),
              [](const Task& t1, const Task& t2) { return t1[0] < t2[0]; });
    auto comp = [](const Task& t1, const Task& t2) {
      // minPq with processing time or original idx
      return t1[1] > t2[1] || (t1[1] == t2[1] && t1[2] > t2[2]);
    };
    std::priority_queue<Task, std::vector<Task>, decltype(comp)> taskQ(comp);
    unsigned curTime = 0;
    int idx = 0;
    std::vector<int> res;
    res.reserve(sz);
    while (idx < sz || !taskQ.empty()) {
      if (taskQ.empty()) {
        curTime = std::max(curTime, unsigned(tasks[idx][0]));
      }
      while (idx < sz && tasks[idx][0] <= curTime) {
        taskQ.emplace(std::move(tasks[idx++]));
      }
      const auto& task = taskQ.top();
      res.emplace_back(task[2]);
      curTime += task[1];
      taskQ.pop();
    }
    return res;
  }
};