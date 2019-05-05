import java.util.*;

public class Playground {

    public static void main(String[] args) {
        BST bst = new BST();

        TreeNode root = buildBST(new int[]{3,1,4,2});
    }

    public static TreeNode heapifyBinaryTree(TreeNode root) {
        int size = traverse(root, 0, null);
        TreeNode[] treeNodeArray = new TreeNode[size];
        traverse(root, 0, treeNodeArray);

        Arrays.sort(treeNodeArray, new Comparator<TreeNode>() {
            @Override
            public int compare(TreeNode n1, TreeNode n2) {
                int val1 = n1.value;
                int val2 = n2.value;

                return val1 < val2 ? -1 : (val1 == val2 ? 0 : 1);
            }
        });

        for (int i = 0; i < size; ++i) {
            int left = 2 * i + 1;
            int right = 2 * i + 2;

            treeNodeArray[i].left = left > size ? null : treeNodeArray[left];
            treeNodeArray[i].right = right > size ? null : treeNodeArray[right];
        }
        return treeNodeArray[0]; // root node
    }

    private static int traverse(TreeNode root, int count, TreeNode[] array) {
        if (root == null) {
            return count;
        }
        if (array != null) {
            array[count] = root;
        }
        ++count;
        count = traverse(root.left, count, array);
        count = traverse(root.right, count, array);
        return count;
    }

    public static TreeNode buildBST(int[] arr) {
        return buildBST(arr, 0, arr.length - 1);
    }

    private static TreeNode buildBST(int[] arr, int left, int right) {
        if (left <= right) {
            int middle = left + (right - left) / 2;
            TreeNode treeNode = new TreeNode(arr[middle]);

            treeNode.left = buildBST(arr, left, middle - 1);
            treeNode.right = buildBST(arr, middle + 1, right);

            return treeNode;
        }
        return null;
    }

    public static List<LinkedList<TreeNode>> listOfDepths(TreeNode root) {
        if (root == null) return Collections.emptyList();

        List<LinkedList<TreeNode>> listOfLists = new ArrayList<>();
        int level = 0;
        listOfDepthsHelper(root, listOfLists, level);
        return listOfLists;
    }

    private static void listOfDepthsHelper(TreeNode root, List<LinkedList<TreeNode>> listOfLists, int level) {
        if (root == null) return;
        LinkedList<TreeNode> levelList;
        try {
            levelList = listOfLists.get(level);
        } catch (IndexOutOfBoundsException e) {
            listOfLists.add(level, new LinkedList<>());
            levelList = listOfLists.get(level);
        }

        levelList.add(root);
        listOfDepthsHelper(root.left, listOfLists, level + 1);
        listOfDepthsHelper(root.right, listOfLists, level + 1);
    }

    int kSmallest = Integer.MIN_VALUE;

    public int kthSmallest(TreeNode root, int k) {
        visit_inorder(root, k);
        return kSmallest;
    }

    private void visit_inorder(TreeNode root, int k) {
        if (root != null && k > 0) {
            visit_inorder(root.left, k);
            visit(root, k - 1);
            visit_inorder(root.right, k - 1);
        }
    }

    private void visit(TreeNode root, int k) {
        if (k > 0) {
            kSmallest = root.value;
        }
    }
}
