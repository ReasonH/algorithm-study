package easy;

import java.util.HashSet;
import java.util.Set;

public class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;
    TreeNode() {}
    TreeNode(int val) { this.val = val; }
    TreeNode(int val, TreeNode left, TreeNode right) {
        Set<Character> set = new HashSet<>();
        this.val = val;
        this.left = left;
        this.right = right;
    }
}