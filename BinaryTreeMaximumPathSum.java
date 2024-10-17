/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    private int maxSum;

    public int maxPathSum(TreeNode root) {
        maxSum = Integer.MIN_VALUE;
        findMaxPath(root);
        return maxSum;
    }

    private int findMaxPath(TreeNode curNode){
        if (curNode == null) return 0;

        int leftSum = Math.max(0, findMaxPath(curNode.left));
        int rightSum = Math.max(0, findMaxPath(curNode.right));
        // max with 0 in case path is negative and doesn't contribute

        int curPathSum = curNode.val + leftSum + rightSum;
        // this considers the case when curPath is the "root"

        maxSum = Math.max(maxSum, curPathSum);

        return curNode.val + Math.max(leftSum, rightSum);
        // can only pick one side for the path
    }

    // we always want to add positive nodes as they increase the max sum
    // if we hit a negative node, it only makes sense to add it if the max sum of the nodes after is greater than the negative so the overall is still greater
    // if it doesnt make sense to add the negative node, the path of its left and right children are also a consideration for the max path sum
}