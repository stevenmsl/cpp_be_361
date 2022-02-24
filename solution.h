#ifndef SOLUTION_H
#define SOLUTION_H

#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <string>

using namespace std;
namespace sol361
{

  class Solution
  {
  private:
    /* left, right, up, and down */
    vector<pair<int, int>> dirs = {{0, -1}, {0, 1}, {1, 0}, {-1, 0}};

  public:
    int maxCount(vector<vector<char>> &grid);
  };
}
#endif