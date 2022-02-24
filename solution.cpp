#include "solution.h"
#include "util.h"
#include <queue>
#include <map>
#include <algorithm>
#include <string>
#include <queue>
#include <sstream>
#include <functional>

using namespace sol361;
using namespace std;

/*takeaways
  - try every empty spot and calculate the kill counts
    from that location
  - return the max among them
*/

int Solution::maxCount(vector<vector<char>> &grid)
{
  const auto m = (int)grid.size();
  const auto n = (int)grid[0].size();

  int maxCount = 0;

  auto killCount = [&](pair<int, int> loc)
  {
    auto count = 0;
    for (auto dir : dirs)
    {
      auto x = loc.first + dir.first;
      auto y = loc.second + dir.second;
      /* not hitting the wall and within the bound */
      while (
          x >= 0 && x < m &&
          y >= 0 && y < n &&
          grid[x][y] != 'W')
      {
        if (grid[x][y] == 'E')
          count++;
        /* keep moving along in the same direction */
        x = x + dir.first;
        y = y + dir.second;
      }
    }
    return count;
  };

  /* check every empty spot */
  for (auto i = 0; i < m; i++)
    for (auto j = 0; j < n; j++)
      if (grid[i][j] == '0')
        maxCount = std::max(maxCount, killCount({i, j}));

  return maxCount;
}