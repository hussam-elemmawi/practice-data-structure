import java.util.Stack;

public class BST {
    private TreeNode root;

    public BST() {
    }

    public BST(int value) {
        root = new TreeNode(value);
    }

    public void insert(int value) {
        root = insert(root, value);
    }

    protected TreeNode insert(TreeNode root, int value) {
        if (root == null) {
            root = new TreeNode(value);
            return root;
        }
        if (value < root.value) {
            root.left = insert(root.left, value);
        } else if (value > root.value) {
            root.right = insert(root.right, value);
        }
        return root;
    }

    public int height() {
        return height(this.root);
    }

    protected int height(TreeNode root) {
        if (root != null) {
            return 1 + Math.max(height(root.left), height(root.right));
        }
        return 0;
    }

    public void inorderIterative() {
        Stack<TreeNode> stack = new Stack<>();
        TreeNode current = root;

        while (!stack.isEmpty() || current != null) {
            if (current != null) {
                stack.push(current);
                current = current.left;
            } else {
                current = stack.pop();
                System.out.print(current.value + " ");
                current = current.right;
            }
        }
        System.out.println();
    }

    public void postorderIterative() {
        Stack<TreeNode> stack = new Stack<>();
        stack.push(root);
        Stack<Integer> output = new Stack<>();

        while (!stack.empty()) {
            TreeNode current = stack.pop();
            output.push(current.value);

            if (current.left != null)
                stack.push(current.left);
            if (current.right != null)
                stack.push(current.right);
        }

        while (!output.empty()) {
            System.out.print(output.pop() + " ");
        }
        System.out.println();
    }

    public void preorderIterative() {
        TreeNode parent = root;
        Stack<TreeNode> stack = new Stack<>();
        stack.push(root);

        while (!stack.isEmpty()) {
            TreeNode current = stack.pop();
            System.out.print(current.value + " ");

            if (current.right != null) {
                stack.push(current.right);
            }
            if (current.left != null) {
                stack.push(current.left);
            }
        }
        System.out.println();
    }

    public void preOrder() {
        preOrder(root);
        System.out.println();
    }

    public void inOrder() {
        inOrder(root);
        System.out.println();
    }

    public void postOrder() {
        postOrder(root);
        System.out.println();
    }

    protected void preOrder(TreeNode root) {
        if (root != null) {
            visit(root);
            preOrder(root.left);
            preOrder(root.right);
        }
    }

    protected void inOrder(TreeNode root) {
        if (root != null) {
            inOrder(root.left);
            visit(root);
            inOrder(root.right);
        }
    }

    protected void postOrder(TreeNode root) {
        if (root != null) {
            postOrder(root.left);
            postOrder(root.right);
            visit(root);
        }
    }

    protected void visit(TreeNode treeNode) {
        System.out.print(treeNode.value + " ");
    }

    public int size() {
        return size(root);
    }

    protected int size(TreeNode root) {
        if (root != null) {
            return 1 + size(root.left) + size(root.right);
        }
        return 0;
    }

    public void deleteTree() {
        root = null;
        // Garbage collector will do the rest
    }

    public boolean search(int val) {
        return search(root, val);
    }

    protected boolean search(TreeNode root, int val) {
        if (root != null) {
            if (root.value == val) return true;
            return search(root.left, val) || search(root.right, val);
        }
        return false;
    }

    public int minValue() {
        TreeNode minTreeNode = minValue(root);
        if (minTreeNode == null) return Integer.MAX_VALUE;
        return minTreeNode.value;
    }

    protected TreeNode minValue(TreeNode root) {
        if (root != null) {
            if (root.left == null) return root;
            else return minValue(root.left);
        }
        return null;
    }

    public int maxValue() {
        TreeNode maxTreeNode = maxValue(root);
        if (maxTreeNode == null) return Integer.MIN_VALUE;
        return maxTreeNode.value;
    }

    protected TreeNode maxValue(TreeNode root) {
        if (root != null) {
            if (root.right == null) return root;
            else return maxValue(root.right);
        }
        return null;
    }

    public boolean isBST() {
        if (root != null) {
            return isBST(root.left, Integer.MIN_VALUE, root.value) && isBST(root.right, root.value, Integer.MAX_VALUE);
        }
        return true;
    }

    protected boolean isBST(TreeNode root, int lowerBound, int upperBound) {
        if (root != null) {
            return root.value >= lowerBound && root.value <= upperBound
                    && isBST(root.left, lowerBound, root.value)
                    && isBST(root.right, root.value, upperBound);
        }
        return true;
    }

    public void delete(int val) {
        root = delete(root, val);
    }

    protected TreeNode delete(TreeNode root, int val) {
        if (root != null) {
            if (val < root.value) {
                root.left = delete(root.left, val);
            } else if (val > root.value) {
                root.right = delete(root.right, val);
            } else {
                // found the node
                if (root.left == null && root.right == null) {
                    root = null;
                } else if (root.left == null) {
                    return root.right;
                } else if (root.right == null) {
                    return root.left;
                } else {
                    root.value = minValue(root.right).value;
                    root.right = delete(root.right, root.value);
                }
            }
        }

        return root;
    }

    public int getSuccessor(int val) {
        TreeNode succ = getSuccessor(root, val);
        if (succ != null) return succ.value;
        return Integer.MIN_VALUE;
    }

    protected TreeNode getSuccessor(TreeNode root, int val) {
        if (root == null) return root;

        if (root.right != null) {
            return minValue(root.right);
        }

        TreeNode successor = null;

        while (root != null) {
            if (val < root.value) {
                successor = root;
                root = root.left;
            } else if (val > root.value) {
                root = root.right;
            } else {
                // reached the node
                break;
            }
        }
        return successor;
    }

    public TreeNode lowestCommonAncestor(int val1, int val2) {
        if (search(val1) && search(val2)) {
            return lowestCommonAncestor(root, val1, val2);
        }
        return new TreeNode(-1);
    }

    private TreeNode lowestCommonAncestor(TreeNode root, int val1, int val2) {
        if (val1 >= root.value) {
            return val2 <= root.value ? root : lowestCommonAncestor(root.right, val1, val2);
        } else {
            return val2 >= root.value ? root : lowestCommonAncestor(root.left, val1, val2);
        }
    }

    public TreeNode lowestCommonAncestorIterative(int val1, int val2) {
        if (search(val1) && search(val2)) {
            TreeNode runner = root;

            while (runner != null) {
                if (val1 >= runner.value) {
                    if (val2 <= runner.value) return runner;
                    runner = runner.right;
                } else {
                    if (val2 >= runner.value) return runner;
                    runner = runner.left;
                }
            }
        }
        return new TreeNode(-1);
    }
}
