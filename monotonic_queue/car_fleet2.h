/*

Imagine there are 3 cars A, B, C from left to right

The observation is that

1. The hit time for a car won't be affected by the cars on its left.
- e.g. if B will hit C (implies B is faster than C) and A will hit B (implies A
is faster than B):
- then A won't affect B's hit time regardless if A hits B earlier than B hits C,
why? Because once A hits B, the speed will go down to the same as B. So overall
either B hit C or (A + B) hit C will derive the same result.


2. The hit time for a car will only be affected by the cars on its right. But
not all right cars could have. But what kind of right car/fleet that won't
affect the current car?

- If the right car/fleet has higher speed, or if right car/fleet has shorter
hit time (to its right), then the current car just can't hit such right car.
And if a car can't hit anything, it just become a "wall to form a fleet" to its
left car. And for next iteration, we will decide whether this wall would have
impact on the next (left) car, or the next (left) car becomes the new wall to
form a fleet.
*/
class Solution {
 public:
  double hitTime(const vector<int>& a, const vector<int>& b) {
    return static_cast<double>(a[0] - b[0]) / (b[1] - a[1]);
  }

  vector<double> getCollisionTimes(vector<vector<int>>& cars) {
    std::vector<double> res(cars.size(), -1);
    std::stack<int> fleetIdxes;
    for (int i = cars.size() - 1; i >= 0; --i) {
      while (!fleetIdxes.empty()) {
        int fleetIdx = fleetIdxes.top();
        // fleetIndexes.top maintains the index of a car that will be hit by the
        // current car. if current car just have smaller speed or have larger
        // hit time to the latest fleet - that latest fleet just have no way to
        // impact the car and all the cars left to it. So we could pop it.
        if (cars[i][1] <= cars[fleetIdx][1] ||
            hitTime(cars[i], cars[fleetIdx]) >= res[fleetIdx] &&
                res[fleetIdx] > 0) {
          fleetIdxes.pop();
        } else {
          break;
        }
      }
      // once we popped out all the fleet that the current car can't hit, the
      // top of the stack is just what the current car is going to hit.
      res[i] =
          fleetIdxes.empty() ? -1 : hitTime(cars[i], cars[fleetIdxes.top()]);
      // the current car could have become the fleet "wall" to its left. If it
      // can't be - it would just be popped out in the next iteration anyway
      fleetIdxes.push(i);
    }

    return res;
  }
};