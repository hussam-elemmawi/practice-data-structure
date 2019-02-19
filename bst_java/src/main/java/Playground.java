import java.util.*;

public class Playground {

    public static void main(String[] args) {
        BST bst = new BST();

        Node root = buildBST(new int[]{1, 2, 3, 4, 5, 6, 7  });

        inorder(root);
        System.out.println();

        List<LinkedList<Node>> result = listOfDepths(root);

        for (LinkedList<Node> l: result) {
            for (Node n: l) {
                System.out.print(n.value + " ");
            }
            System.out.println();
        }
    }

    public static Node heapifyBinaryTree(Node root) {
        int size = traverse(root, 0, null);
        Node[] nodeArray = new Node[size];
        traverse(root, 0, nodeArray);

        Arrays.sort(nodeArray, new Comparator<Node>() {
            @Override
            public int compare(Node n1, Node n2) {
                int val1 = n1.value;
                int val2 = n2.value;

                return val1 < val2 ? -1 : (val1 == val2 ? 0 : 1);
            }
        });

        for (int i = 0; i < size; ++i) {
            int left = 2 * i + 1;
            int right = 2 * i + 2;

            nodeArray[i].left = left > size ? null : nodeArray[left];
            nodeArray[i].right = right > size ? null : nodeArray[right];
        }
        return nodeArray[0]; // root node
    }

    private static int traverse(Node root, int count, Node[] array) {
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

    public static Node buildBST(int[] arr) {
        return buildBST(arr, 0, arr.length - 1);
    }

    private static Node buildBST(int[] arr, int left, int right) {
        if (left <= right) {
            int middle = left + (right - left) / 2;
            Node node = new Node(arr[middle]);

            node.left = buildBST(arr, left, middle - 1);
            node.right = buildBST(arr, middle + 1, right);

            return node;
        }
        return null;
    }

    public static void inorder(Node node) {
        if (node == null) return;
        inorder(node.left);
        System.out.print(node.value + " ");
        inorder(node.right);
    }

    public static List<LinkedList<Node>> listOfDepths(Node root) {
        if (root == null) return Collections.emptyList();

        List<LinkedList<Node>> listOfLists = new ArrayList<>();
        int level = 0;
        listOfDepthsHelper(root, listOfLists, level);
        return listOfLists;
    }

    private static void listOfDepthsHelper(Node root, List<LinkedList<Node>> listOfLists, int level) {
        if (root == null) return;
        LinkedList<Node> levelList;
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
}
