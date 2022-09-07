package easy;

import java.util.LinkedList;
import java.util.Queue;

class SameTree {
    private Queue<TreeNode> pQueue = new LinkedList<>();
    private Queue<TreeNode> qQueue = new LinkedList<>();

    public boolean isSameTree(TreeNode p, TreeNode q) {
        if (p != null) pQueue.add(p);
        if (q != null) qQueue.add(q);

        while(!pQueue.isEmpty() && !qQueue.isEmpty()) {

            TreeNode pNode = pQueue.poll();
            TreeNode qNode = qQueue.poll();
            if (pNode.val != qNode.val) {
                return false;
            }

            if (!isSameStruct(pNode.left, qNode.left)) {
                return false;
            }

            if (!isSameStruct(pNode.right, qNode.right)) {
                return false;
            }
        }

        return pQueue.size() == qQueue.size();
    }

    public boolean isSameStruct(TreeNode p, TreeNode q) {
        if (p != null && q != null) {
            pQueue.add(p);
            qQueue.add(q);
            return true;
        } else if (p == null && q == null) {
            return true;
        } else {
            return false;
        }
    }
}