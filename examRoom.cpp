#include <iostream>
#include <vector>

// https://leetcode.com/problems/exam-room/

class ExamRoom {
  public:
    int total;
    std::vector<int> students;

    ExamRoom(int n) {
      total = n;
    }
    
    int seat() {
      int length = students.size();
      if (length == 0) {
        students.push_back(0);
        return 0;
      }

      int prePos = -1, maxDist = students[0], seat = 0;
      for (int i = 0; i < length; i += 1) {
        int curPos = students[i];

        if (prePos > -1) {
          int tempDist = (curPos - prePos) / 2;

          if (tempDist > maxDist) {
            maxDist = tempDist;
            seat = prePos + tempDist;
          }
        }
        
        prePos = curPos;
      }

      int lastPos = students[length - 1];      
      if (total - 1 - lastPos > maxDist) {
        seat = total - 1;
      }

      int insertIndex = 0;
      while (
        insertIndex < length && students[insertIndex] < seat
      ) {
        insertIndex += 1;
      }

      students.insert(students.begin() + insertIndex, seat);

      return seat;
    }
    
    void leave(int p) {
      int length = students.size();
      int leaveIndex = 0;
      while (
        leaveIndex < length && students[leaveIndex] != p
      ) {
        leaveIndex += 1; 
      }

      students.erase(students.begin() + leaveIndex); 
    }
};
