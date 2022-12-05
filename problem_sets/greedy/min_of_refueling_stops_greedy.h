class Solution {
    /*
    idea from
    https://leetcode.com/problems/minimum-number-of-refueling-stops/discuss/294025/Java-Simple-Code-Greedy

    - observation:

    Start at 0, with start fuel = 35
    Stations = [(10, 25), (20, 12), (30,21), (40, 5), (50,3)]

    with 0 step, you can reach 35, which makes you have the ability
    to go through station @[10, 20, 30]

    so what's the max distance with 1 step?
    you build from 0 step, for the station 0 step can cover, the distance that
    you can further reach only related to the fuel in the station

    why? say you stay at station 20, you use 35 - 20 = 15 to reach 20, so at 20
    you will have fuel 15 + 12 = 27 fuel to go further, so maximally you can
    reach 20 + 27 = 47.
      0                 (init pos)
      + 35              (init fuel)
      - (20 - 0)        (fuel from 0 to 20)
      + (20 - 0)        (move from pos 0 to 20)
      +  12             (fuel@20)
    = 47


    Or put it another way, you know you can reach 35 already, and you stay
    extra@20 then the result of max dis you can reach will simply be 35 + 12,
    because the amount of fuel use is the same as the distance you will be
    traveling.

    with this in mind, we can basically find the solution greedily, with finding
    the maximum distance we can go with more and more step.

    Say we know with stay k times, while that the k-th stay is at station i,
    and we can maximally reach x

    then with k + 1 stay, we can find a non-visited station with pos <= x, where
    it has the largest fuel to add. This will make sure we find the maximum
    place we can reach while using k + 1 stay!

    Note that such station is not necessarily after station i. Consider the case

    startFuel = 299, target = 1000
    i:   0       1         2        3        4         5
      [[13,21],[26,115],[100,47],[225,99],[299,141],[444,198]]

    you will find that with 1 step, maxReach = 141 + 299 with stay at station 4.
    But then you can't even move to station 5, as it's at 444 > 400. Rather, the
    second step will be i = 1, e.g. the largest that you haven't took before pos
    400.

    So you can basically maintain a max queue to store all the station you can
    reach and in each iteration, you just pop out the one with max gas, and push
    new station that you can reach into the queue for next iteration
    */
  public:
    int minRefuelStops(int target, int startFuel,
                       vector<vector<int>>& stations) {
        int stayUsedSoFar = 0;
        int maxReach = startFuel;
        int nextIdx = 0;
        std::priority_queue<int> candidates;
        while (maxReach < target) {
            // adding the newly visitable station
            while (nextIdx < stations.size() &&
                   stations[nextIdx][0] <= maxReach) {
                candidates.emplace(stations[nextIdx][1]);
                ++nextIdx;
            }
            if (candidates.empty())
                return -1;
            maxReach += candidates.top();
            candidates.pop();
            stayUsedSoFar++;
        }
        return stayUsedSoFar;
    }
};