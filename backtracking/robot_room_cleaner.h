/*

The idea is that
1. you shouldn't move to the same place twice - so you need to keep records
   about what have visited. Although you don't know the full map, you can just
   use relative coordinates

2. One tricky thing is that robot has to turn to the direction then move. So how
   you book keeping the coordinates with robot move is important! What you are
   facing currently + what you have turned will affect how you update the
   coordinate!

   This is where backtracking comes in. You should recover the orientation
   after the recursion - so at the end you know you are back to the same state.

            (0, 1) d = 0
              ^
    (-1, 0) <   > (1, 0) d = 1
      d = 3   v
            (0, -1) d = 2

    Also, to simplify, try to always do turnRight for changing the direction.
    And make the direction array the same as what turn right would have
    reflected to the coordinates.

    Say you are facing right, the first time you turnRight, the coordinates diff
    should actually be (0, -1) (going down).

    That's why below we are doing int nextFacing = (curFacing + d) % 4;
    we pass in the curFacing, which gives up the information of the delta
    of coordinates we need to do whenever turnRight is called.

    At the end, we turn 180 degree, move, then turn 180 degree again to recover
    the state.
 */

class Solution {
 public:
  std::unordered_set<std::string> visited;
  static constexpr std::array<int, 5> dir = {0, 1, 0, -1, 0};
  void turnBack(Robot& robot) {
    robot.turnRight();
    robot.turnRight();
  }
  // row <= 100 and col <= 200, extreme case, original point at top right
  // so relative coordinate would only go to -100, -200 etc
  char toChar(int val) { return val < 0 ? char(val + 255) : char(val); }
  void cleanRoom(Robot& robot, int row = 0, int col = 0, int curFacing = 0) {
    const auto idx = std::to_string(toChar(row)) + '_' + toChar(col);
    if (visited.count(idx)) return;
    robot.clean();
    visited.emplace(std::move(idx));
    for (int d = 0; d < 4; ++d) {
      if (robot.move()) {
        int nextFacing = (curFacing + d) % 4;
        cleanRoom(robot,
                  row + dir[nextFacing],
                  col + dir[nextFacing + 1],
                  nextFacing);
        turnBack(robot);  // heading back to where it comes
        robot.move();
        turnBack(robot);  // recovered the original orientation
      }
      robot.turnRight();  // try all 4 dirs and eventually recover
    }
  }
};