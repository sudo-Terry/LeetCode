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
    public List<List<Integer>> levelOrder(TreeNode root) {
        // root 부터 bfs
        // level 단위로 탐색하면서 ans list에 add하자
        List<List<Integer>> ans = new LinkedList<List<Integer>>();

        if(root == null) return ans;
        Queue<TreeNode> q = new LinkedList<TreeNode>();
        q.add(root);
        while(!q.isEmpty()){
            List<Integer> l = new ArrayList<Integer>();
            int q_size = q.size();
            for(int i = 0; i < q_size; i++){
                TreeNode n = q.poll();
                l.add(n.val);
                if(n.left != null) q.add(n.left);
                if(n.right != null) q.add(n.right);
            }
            ans.add(l);
        }

        return ans;
    }
}