package main

import (
	"fmt"
)

func main() {
	nums := []int{2, 0, 1, 4, 3}
	res := solution(nums, 6)
	fmt.Printf("res: %+v \n", res)
}

func solution(nums []int, target int) []int {
	type Result []int
	// { [target - cur]: index, ... }
	// each time read with cur, if exist means match
	result := Result{}
	tempMap := make(map[int]int)

	for i := 0; i < len(nums); i += 1 {
		curNum := nums[i]
		matchIndex, exists := tempMap[curNum]
		if exists {
			result = append(result, i, matchIndex)
			break
		}
		gap := target - curNum
		tempMap[gap] = i
	}

	return result
}
