/*
atan2(y, x) returns the principal value of the arc tangent of y/x, expressed in
radians, in the interval [-pi,+pi] radians.

Meaning, the return value * 180 / PI == degree to positive x axis

So the idea here is simple, you move your position to the original, or offset
each point with your location. Then the atan2 of points will be the principal
to the location. Then you can basically sort the principals (or convert to
degree) for each points accordingly.

Then the final part is basically maintaining a 2 pointers to see how many points
are inside the input visibleAngle.
*/
class Solution {
 public:
  int visiblePoints(vector<vector<int>>& points, int visionAngle,
                    vector<int>& location) {
    std::vector<double> angles;
    int overlapped = 0;
    auto angle = [](double principal) {
      static constexpr auto radius = 180.0 / M_PI;
      return principal * radius;
    };

    for (const auto& pt : points) {
      if (pt[0] != location[0] || pt[1] != location[1]) {
        angles.push_back(
            angle(atan2(pt[1] - location[1], pt[0] - location[0])));
      } else {
        overlapped++;
      }
    }
    int maxPts = 0;
    std::sort(angles.begin(), angles.end());
    int oriAngleCnt = angles.size();
    for (int i = 0; i < oriAngleCnt; ++i) {
      // wrap around to handle the case that maybe starting
      // point is at phase IV while max angle goes to phase I
      angles.push_back(angles[i] + 360);
    }
    for (int maxIdx = 0, minIdx = 0; maxIdx < angles.size(); maxIdx++) {
      while (angles[maxIdx] - angles[minIdx] > visionAngle) {
        minIdx++;
      }
      maxPts = std::max(maxPts, maxIdx - minIdx + 1);
    }
    return maxPts + overlapped;
  }
};