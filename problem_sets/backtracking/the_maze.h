/*
Generally a variation of normal 2d walking

You can use the same dir array trick, just need to do a while loop.

The second trick is using some value in the maze input matrix as the visited
flag.

- The slightly tricky thing is how you generate the next point if you are
  altering maze value. As you are doing while loop to find the next point to
  move to.
- If you are making a visited point un-walkable, you will basically generate
  the wrong next walking point! So when generate nextPt, a visited point should
  still be walkable. Just when you dfs, you should return early!

- In OJ ... the common trick of using a bitset<10'000> is about the same speed
  and is about the same memory consumption ... so either way is fine
*/

class Solution {
  static constexpr int visited = -1;
  std::array<int, 5> dir = {1, 0, -1, 0, 1};

  std::vector<int> nextPt(const vector<vector<int>>& maze, vector<int> cor,
                          int d) {
    int m = maze.size();
    int n = maze.front().size();
    int& r = cor[0];
    int& c = cor[1];
    while (r + dir[d] >= 0 && r + dir[d] < m
           && c + dir[d + 1] >= 0 && c + dir[d + 1] < n
           && maze[r + dir[d]][c + dir[d + 1]] <= 0) {
      r += dir[d];
      c += dir[d + 1];
    }
    return cor;
  }

 public:
  bool hasPath(vector<vector<int>>& maze, vector<int>& start,
               vector<int>& destination) {
    if (maze[start[0]][start[1]] == visited) {
      return false;
    }
    if (start[0] == destination[0] && start[1] == destination[1]) {
      return true;
    }
    maze[start[0]][start[1]] = visited;
    for (int d = 0; d < 4; ++d) {
      auto nextCor = nextPt(maze, start, d);
      if (hasPath(maze, nextCor, destination)) {
        return true;
      }
    }
    return false;
  }
};