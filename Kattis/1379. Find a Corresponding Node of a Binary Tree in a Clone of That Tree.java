import java.util.LinkedList;
import java.util.List;

class TreeNode {
    int val; 
    TreeNode left; 
    TreeNode right; 
    TreeNode(int x) { val = x; }
}

class Solution {
    public static final TreeNode getTargetCopy(final TreeNode original, final TreeNode cloned, final TreeNode target) {
        List<TreeNode> frontier = new LinkedList<TreeNode>();
        frontier.add(cloned);
        TreeNode goal = null;
        if (cloned.val == target.val) {
            goal = cloned;
            return goal;
        }
        while (frontier.size() > 0) {
            TreeNode[] neighbours = {frontier.get(0).left, frontier.get(0).right};
            for (int j = 0; j < 2; j += 1) {
                if (neighbours[j] != null) {
                    System.out.println(neighbours[j].val);
                    if (neighbours[j].val == target.val) {
                        goal = neighbours[j];
                        return goal;
                    }
                    frontier.add(neighbours[j]);
                }
            }
            frontier.remove(0);
        }
        return goal;
    }

    public static void main(String[] args) {
        TreeNode original = new TreeNode(8);
        original.right = new TreeNode(6);
        original.right.right = new TreeNode(5);
        original.right.right.right = new TreeNode(4);
        original.right.right.right.right = new TreeNode(3);
        original.right.right.right.right.right = new TreeNode(2);
        original.right.right.right.right.right.right = new TreeNode(1);

        TreeNode cloned = original;
        TreeNode target = new TreeNode(4);
        getTargetCopy(original, cloned, target);
    }
}