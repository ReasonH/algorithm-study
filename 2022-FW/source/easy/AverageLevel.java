package easy;

import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;

class AverageLevel {
    private Queue<TreeNode> queue = new LinkedList<>();
    private List<Double> answer = new ArrayList<>();

    public List<Double> averageOfLevels(TreeNode root) {
        queue.add(root);

        while(!queue.isEmpty()) {
            answer.add(levelAverage(queue));
        }

        return answer;
    }

    public double levelAverage(Queue<TreeNode> subQueue) {
        double levelSum = 0;
        int division = 0;
        queue = new LinkedList<TreeNode>();
        while(!subQueue.isEmpty()) {
            TreeNode node = subQueue.poll();
            levelSum += node.val;
            if (node.left != null) queue.add(node.left);
            if (node.right != null) queue.add(node.right);
            division++;
        }

        return levelSum / division;
    }
}