/*
Check the space-time graph in
https://leetcode.com/problems/car-fleet/discuss/255589/Python-Code-with-Explanations-and-Visualization-Beats-95

So the idea is that if you sort the car with its position in decreasing order:

Say there are only 2 cars, where
- carA: pos=p0, speed=s0,
- carB: pos=p1, speed=s1

Say p0 > p1:

supposed s1 > s0, and carB could have hit carA before target, then carB must be
merged into the same fleet as carA

supposed s0 > s1, it basically means carA will always arrive target earlier
than carB, which means carA itself would become a fleet, and then carB forms
another fleet. But then how do you deal with situation like s1 > s0 but carB
can't hit carA in time?

The idea is you calculate the time for each car to arrive target accordingly.
And with the fact that higher init pos is at the front, you can focus on the
timing for each car.


If there exists a car with smaller initial position but lower time to hit target
, it means it can catch up the car in front and they will merge.

On the other hand, say
    carA:  p0  t1 (time arrive target)
    carB:  p1  t2
    carC:  p2  t3

Say p0 > p1 and t1 < t2, carA is its fleet.
And even if t3 < t2, carC will only merge with carB, and because carB cannot
catch carA, we won't need to worry carC being merge into carA at all.

This basically give us a monotonic stack like of concept: following the order
where initial position has larger value. If time to target is larger than the
top, it has to form a new fleet, and every car before meeting the next fleet
will merge into the current fleet.
*/

class Solution {
 public:
  int carFleet(int target, vector<int>& position, vector<int>& speed) {
    using CarInfo = std::pair<int, double>;
    std::vector<CarInfo> carInfos;
    for (int i = 0; i < position.size(); ++i) {
      carInfos.emplace_back(
          position[i], static_cast<double>(target - position[i]) / speed[i]);
    }
    std::sort(carInfos.begin(), carInfos.end(),
              [](const CarInfo& c1, const CarInfo& c2) {
                return c1.first > c2.first ||
                       (c1.first == c2.first && c1.second < c2.second);
              });
    double curArrivalTime = -1;
    int fleet = 0;
    for (const auto& ci : carInfos) {
      if (curArrivalTime < ci.second) {
        curArrivalTime = ci.second;
        fleet++;
      }
    }
    return fleet;
  }
};

// cleaner but slower implementation (likely vector is more cache friendly?):
// use an (ordered) map where key is -pos[i] and value is time to target. Then
// you just traversed the map in order and add fleet count whenever you see a
// larger time to target

/*class Solution {
 public:
  int carFleet(int target, vector<int>& position, vector<int>& speed) {
    std::map<int, double> arrivalTime;
    for (int i = 0; i < position.size(); ++i) {
      arrivalTime[-1 * position[i]] =
          static_cast<double>(target - position[i]) / speed[i];
    }
    int fleet = 0;
    double curArrivalTime = -1;
    for (const auto& ci : arrivalTime) {
      if (ci.second > curArrivalTime) {
        curArrivalTime = ci.second;
        fleet++;
      }
    }
    return fleet;
  }
};*/