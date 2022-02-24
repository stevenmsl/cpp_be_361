#include <iostream>
#include <tuple>
#include <vector>
#include <string>
#include "solution.h"
#include "util.h"

using namespace std;
using namespace sol361;

/*
Input: [["0","E","0","0"],["E","0","W","E"],["0","E","0","0"]]
Output: 3
Explanation: For the given grid,

0 E 0 0
E 0 W E
0 E 0 0

Placing a bomb at (1,1) kills 3 enemies.
*/
tuple<vector<vector<char>>, int>
testFixture1()
{
  auto grid = vector<vector<char>>{{'0', 'E', '0', '0'},
                                   {'E', '0', 'W', 'E'},
                                   {'0', 'E', '0', '0'}};
  return make_tuple(grid, 3);
}

void test1()
{
  auto f = testFixture1();
  cout << "Test 1 - exepct to see " << to_string(get<1>(f)) << endl;
  Solution sol;
  auto result = sol.maxCount(get<0>(f));
  cout << "result: " << to_string(result) << endl;
}

main()
{
  test1();
  return 0;
}