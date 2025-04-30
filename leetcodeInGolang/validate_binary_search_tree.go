package main

import (
	"math"
)

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func IsValidBST(root *TreeNode) bool {
	minVal := math.MinInt64
	isValid := true

	var visit func(node *TreeNode)
	visit = func(node *TreeNode) {
		if node == nil {
			return
		}
		visit(node.Left)
		if node.Val <= minVal {
			isValid = false
		}
		minVal = node.Val
		visit(node.Right)
	}
	visit(root)
	return isValid
}
