/*

Best one in discussion:
https://leetcode.com/problems/generate-random-point-in-a-circle/solutions/1113623/js-python-java-c-polar-notation-solution-w-explanation/?orderBy=most_votes


The thought is using Polar notation with [r * cosθ, r * sinθ]

The caveat is that you can't generate r simply through uniform distribution?

Why? Consider a circle with radius 1, in the center of circle, the area of the
inner circle with radius 0.5 is (0.5)^2*PI, and the full circle has area PI

So the outer ring has size PI - 0.25PI = 0.75PI

So the intuition is that, although the outer ring is also with length 0.5, the
area is much bigger. So if you generate length with uniform distribution (plus
angle with uniform distribution, which is fine.), it will have smaller chance to
become a point at the outside ring than inside circle. And what's the circle
area relationship with radius? it's proportional to radius^2. So the solution
is that we could take square root of out uniformly generated length, then the
distribution should be correct.

*/

class Solution {
 private:
  double r_ = 0.0;
  double x_ = 0.0;
  double y_ = 0.0;

 public:
  Solution(double radius, double x_center, double y_center)
      : r_{radius}, x_{x_center}, y_{y_center} {}

  double randFraction() const {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    static std::uniform_real_distribution<> dis(0.0, 1.0);
    return dis(gen);
  }

  vector<double> randPoint() {
    auto randAngle = randFraction() * (2 * M_PI);
    auto randLen = r_ * std::sqrt(randFraction());
    return {x_ + randLen * std::cos(randAngle),
            y_ + randLen * std::sin(randAngle)};
  }
};
