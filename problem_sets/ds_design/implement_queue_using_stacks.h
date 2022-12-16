/*
We know pop from stk1 and insert to stk2, then stk2
basically have the reversed element order

The brilliant part from @StefanPochmann's idea

When do we need the actual queue order? peek and pop.
And when we insert, we actually don't really care about
the queue order.

So what we can do is keeping a "queue order stack" for
peak and pop, and overall if there is no peak nor pop
call, we can just keep things in the "stack order stack"
and when we pop/peak while realize "queue order stack"
is empty, we move element from "stack order stack" to it

insert a, b
stkOrderStk:    [a b]
queueOrderStk:  []

peak
stkOrderStk:    []
queueOrderStk:  [b a]

pop
stkOrderStk:    []
queueOrderStk:  [b]

insert c d e
stkOrderStk:    [c d e]
queueOrderStk:  [b]

pop
stkOrderStk:    [c d e]
queueOrderStk:  []

pop
stkOrderStk:    []
queueOrderStk:  [e d c] -> [e d]

By doing so, you always only move element between stacks once!!
*/

class MyQueue {
  std::stack<int> stkOrderStk;
  std::stack<int> queueOrderStk;
 public:
  void push(int x) { stkOrderStk.push(x); }

  int pop() {
    int val = peek();
    queueOrderStk.pop();
    return val;
  }

  int peek() {
    if (queueOrderStk.empty()) {
      while (!stkOrderStk.empty()) {
        queueOrderStk.push(stkOrderStk.top());
        stkOrderStk.pop();
      }
    }
    return queueOrderStk.top();
  }

  bool empty() { return queueOrderStk.empty() && stkOrderStk.empty(); }
};
