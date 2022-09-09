#include <iostream>
#include <vector>


// https://leetcode.com/problems/maximal-square/

class Solution {
  private:
    int convertToOneOrZeroInt(char& inputChar) {
      char one = (char)49;
      return inputChar == one ? 1 : 0;;
    }

  public:
    int maximalSquare(std::vector<std::vector<char>>& matrix) {
      int rowLength = matrix.size();
      int columnLength = matrix[0].size();
      char one = (char)49;

      // represent the sideLength of a current square
      std::vector<std::vector<int>> dp;

      for (int i = 0; i < rowLength; i += 1)
      {
        std::vector<int> empty(columnLength);
        dp.push_back(empty);
      }

      dp[0][0] = this->convertToOneOrZeroInt(matrix[0][0]);
      int result = this->convertToOneOrZeroInt(matrix[0][0]);

      // handle first row
      for (int i = 1; i < columnLength; i += 1) {
        if (matrix[0][i] == one) {
          result = 1;
        }
        dp[0][i] = this->convertToOneOrZeroInt(matrix[0][i]);
      }

      // handle first column
      for (int i = 1; i < rowLength; i += 1) {
        if (matrix[i][0] == one) {
          result = 1;
        }
        dp[i][0] = this->convertToOneOrZeroInt(matrix[i][0]);
      }

      if (rowLength == 1 || columnLength == 1) return result;

      for (int i = 1; i < rowLength; i += 1) {
        for (int j = 1; j < columnLength; j += 1) {
          char cur = matrix[i][j];
          int top = dp[i - 1][j];
          int left = dp[i][j - 1];
          int topLeft = dp[i - 1][j - 1];
          bool isSquare = (cur == one && top && left && topLeft);
          if (isSquare) {
            int newSideLength = std::min((std::min(top, left)), topLeft) + 1;
            int tempResult = newSideLength * newSideLength;
            result = tempResult > result ? tempResult : result;
            dp[i][j] = newSideLength;
          } else {
            if (cur == one && result == 0) {
              result = 1;
            }
            dp[i][j] = this->convertToOneOrZeroInt(matrix[i][j]);
          }
        }
      }

      return result;
    }
};

int main()
{
  Solution SolutionInstance;

  /**
    {"1","0","1","0","0"},
    {"1","0","1","1","1"},
    {"1","1","1","1","1"},
    {"1","0","0","1","0"}
  */
  char one = (char)49;
  char zero = (char)48;
  std::vector<std::vector<char>> matrix = {
    { one, zero, one, zero, zero },
    { one, zero, one, one, one },
    { one, one, one, one, one },
    { one, zero, zero, one, zero },
  };

  int result = SolutionInstance.maximalSquare(matrix);

  std::cout << "result is: " << result << std::endl;

  return 0;
}
