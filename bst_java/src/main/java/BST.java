import java.util.HashSet;
import java.util.Stack;

public class BST {
    private Node root;

    public BST() {
    }

    public BST(int value) {
        root = new Node(value);
    }

    public void insert(int value) {
        root = insert(root, value);
    }

    protected Node insert(Node root, int value) {
        if (root == null) {
            root = new Node(value);
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

    protected int height(Node root) {
        if (root != null) {
            return 1 + Math.max(height(root.left), height(root.right));
        }
        return 0;
    }

    public void inorderIterative() {
        Stack<Node> stack = new Stack<>();
        Node current = root;

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
        Stack<Node> stack = new Stack<>();
        stack.push(root);
        Stack<Integer> output = new Stack<>();

        while (!stack.empty()) {
            Node current = stack.pop();
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
        Node parent = root;
        Stack<Node> stack = new Stack<>();
        stack.push(root);

        while (!stack.isEmpty()) {
            Node current = stack.pop();
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

    protected void preOrder(Node root) {
        if (root != null) {
            visit(root);
            preOrder(root.left);
            preOrder(root.right);
        }
    }

    protected void inOrder(Node root) {
        if (root != null) {
            inOrder(root.left);
            visit(root);
            inOrder(root.right);
        }
    }

    protected void postOrder(Node root) {
        if (root != null) {
            postOrder(root.left);
            postOrder(root.right);
            visit(root);
        }
    }

    protected void visit(Node node) {
        System.out.print(node.value + " ");
    }

    public int size() {
        return size(root);
    }

    protected int size(Node root) {
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

    protected boolean search(Node root, int val) {
        if (root != null) {
            if (root.value == val) return true;
            return search(root.left, val) || search(root.right, val);
        }
        return false;
    }

    public int minValue() {
        Node minNode = minValue(root);
        if (minNode == null) return Integer.MAX_VALUE;
        return minNode.value;
    }

    protected Node minValue(Node root) {
        if (root != null) {
            if (root.left == null) return root;
            else return minValue(root.left);
        }
        return null;
    }

    public int maxValue() {
        Node maxNode = maxValue(root);
        if (maxNode == null) return Integer.MIN_VALUE;
        return maxNode.value;
    }

    protected Node maxValue(Node root) {
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

    protected boolean isBST(Node root, int lowerBound, int upperBound) {
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

    protected Node delete(Node root, int val) {
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
        Node succ = getSuccessor(root, val);
        if (succ != null) return succ.value;
        return Integer.MIN_VALUE;
    }

    protected Node getSuccessor(Node root, int val) {
        if (root == null) return root;

        if (root.right != null) {
            return minValue(root.right);
        }

        Node successor = null;

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

    public Node lowestCommonAncestor(int val1, int val2) {
        if (search(val1) && search(val2)) {
            return lowestCommonAncestor(root, val1, val2);
        }
        return new Node(-1);
    }

    private Node lowestCommonAncestor(Node root, int val1, int val2) {
        if (val1 >= root.value) {
            return val2 <= root.value ? root : lowestCommonAncestor(root.right, val1, val2);
        } else {
            return val2 >= root.value ? root : lowestCommonAncestor(root.left, val1, val2);
        }
    }

    public Node lowestCommonAncestorIterative(int val1, int val2) {
        if (search(val1) && search(val2)) {
            Node runner = root;

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
        return new Node(-1);
    }
}
