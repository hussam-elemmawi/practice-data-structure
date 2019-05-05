public class AVLTree extends BST {

    @Override
    protected int height(TreeNode root) {
        if (root == null) return 0;
        return root.height;
    }

    @Override
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

        if (root == null) return root;

        root.height = 1 + Math.max(height(root.left), height(root.right));

        int balanceFactor = getBalanceFactor(root);

        // left left case
        if (balanceFactor > 1 && getBalanceFactor(root.left) >= 0) {
            return rightRotateNode(root);
        }

        // left right case (zig-zag case)
        if (balanceFactor > 1 && getBalanceFactor(root.left) < 0) {
            root.left = leftRotateNode(root.left);
            return rightRotateNode(root);
        }

        // righ right case
        if (balanceFactor < -1 && getBalanceFactor(root.right) <= 0) {
            return leftRotateNode(root);
        }

        // right left case (zag-zig case)
        if (balanceFactor < - 1 && getBalanceFactor(root.right) > 0) {
            root.right = rightRotateNode(root.right);
            return leftRotateNode(root);
        }

        return root;
    }

    @Override
    protected TreeNode insert(TreeNode root, int value) {
        if (root == null) {
            root = new TreeNode(value);
            return root;
        }
        if (value < root.value) {
            root.left = insert(root.left, value);
        } else if (value > root.value) {
            root.right = insert(root.right, value);
        } else return root;

        root.height = 1 + Math.max(height(root.left), height(root.right));

        int balanceFactor = getBalanceFactor(root);

        if (balanceFactor > 1 && value < root.left.value) {
            return rightRotateNode(root);
        }

        if (balanceFactor > 1 && value > root.left.value) {
            root.left = leftRotateNode(root.left);
            return rightRotateNode(root);
        }

        if (balanceFactor < -1 && value > root.right.value) {
            return leftRotateNode(root);
        }

        if (balanceFactor < -1 && value < root.right.value) {
            root.right = rightRotateNode(root.right);
            return leftRotateNode(root);
        }

        return root;
    }

    private int getBalanceFactor(TreeNode treeNode) {
        if (treeNode == null) return 0;
        return height(treeNode.left) - height(treeNode.right);
    }

    private TreeNode rightRotateNode(TreeNode y) {
        TreeNode x = y.left;
        TreeNode B = x.right;

        x.right = y;
        y.left = B;

        y.height = 1 + Math.max(height(y.left), height(y.right));
        x.height = 1 + Math.max(height(x.left), height(x.right));

        return x;
    }

    private TreeNode leftRotateNode(TreeNode y) {
        TreeNode x = y.right;
        TreeNode B = x.left;

        x.left = y;
        y.right = B;

        y.height = 1 + Math.max(height(y.left), height(y.right));
        x.height = 1 + Math.max(height(x.left), height(x.right));

        return x;
    }
}
