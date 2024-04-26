package main

func main() {
	nums := []int{ 2, 7, 11, 15 }
	solution(nums, 22)
}

func solution(nums []int, target int) []int {
	result := make([]int, 0)

	type NumInfo struct {
			index int
			val  int
	}

	sumMap := make(map[int]NumInfo)
	sumMap[target - nums[0]] = NumInfo{ index: 0, val: nums[0] }
	hasFounded := false
	for i := 1; i < len(nums); i += 1 {
			if matchedNumInfo, exist := sumMap[nums[i]]; exist && !hasFounded {
					result = append(result, matchedNumInfo.index, i)
					hasFounded = true;
			} else {
					sumMap[target - nums[i]] = NumInfo{ index: i, val: nums[i] }
			}
	}
	return result
}