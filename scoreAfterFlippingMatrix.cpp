#include <vector>
#include <unordered_map>
#include <math.h>

// https://leetcode.com/problems/score-after-flipping-matrix/

class Solution
{
public:
  int calRowTotal(std::vector<int> &row)
  {
    int rowLength = row.size();

    int result = 0;

    for (int i = 0; i < rowLength; i += 1)
    {
      if (row[i] > 0)
      {
        result += (int)(pow(2, rowLength - i - 1) + 0.5);
      }
    }

    return result;
  }
  void convertRowWithOneComplement(std::vector<int> &row)
  {
    int rowLength = row.size();
    for (int i = 0; i < rowLength; i += 1)
    {
      if (row[i] == 0)
      {
        row[i] = 1;
      }
      else
      {
        row[i] = 0;
      }
    }
  }

  int matrixScore(std::vector<std::vector<int>> &grid)
  {
    int gridLength = grid.size();   // 有幾列
    int rowLength = grid[0].size(); // 有幾行
    for (int i = 0; i < gridLength; i += 1)
    { // 檢查第一個，是 0 的話反轉
      int firstOfRow = grid[i][0];
      if (firstOfRow == 0)
      {
        convertRowWithOneComplement(grid[i]);
      }
    }
    std::unordered_map<int, int> FFMap = {
        {0, 0},
        {1, 0}};

    for (int j = 1; j < rowLength; j += 1)
    {
      // 對每一行進行檢查，當 0 比較多，整行反轉
      for (int k = 0; k < gridLength; k += 1)
      {
        if (grid[k][j] == 0)
        {
          FFMap[0] += 1;
        }
        else
        {
          FFMap[1] += 1;
        }
      }
      if (FFMap[0] > FFMap[1])
      {
        for (int k = 0; k < gridLength; k += 1)
        {
          if (grid[k][j] == 0)
          {
            grid[k][j] = 1;
          }
          else
          {
            grid[k][j] = 0;
          }
        }
      }
      FFMap[0] = 0;
      FFMap[1] = 0;
    }
    // 加總每列的值
    int result = 0;
    for (int i = 0; i < gridLength; i += 1)
    {
      result += calRowTotal(grid[i]);
    }
    return result;
  }
};
