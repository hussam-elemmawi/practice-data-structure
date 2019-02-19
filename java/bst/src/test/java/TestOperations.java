import org.junit.Test;

public class TestOperations {

    @Test
    public void insertNode_emptyBST() {
        BST bst = new BST();

        bst.insert(5);

        assert bst.height() == 1;
    }

    @Test
    public void insertNode_sameValue_onlyOneNode() {
        BST bst = new BST();

        bst.insert(5);

        bst.insert(5);

        assert bst.height() == 1;
    }

    @Test
    public void insertNode_smallerValue_onlyOneNode() {
        BST bst = new BST();

        bst.insert(5);

        bst.insert(3);

        assert bst.height() == 2;
    }

    @Test
    public void insertNode_largerValue_onlyOneNode() {
        BST bst = new BST();

        bst.insert(5);

        bst.insert(7);

        assert bst.height() == 2;
    }

    @Test
    public void height_emptyBST() {
        BST bst = new BST();

        assert bst.height() == 0;
    }

    @Test
    public void height_onlyOneElementBST() {
        BST bst = new BST();

        bst.insert(5);

        assert bst.height() == 1;
    }

    @Test
    public void height_rootAndLeftChildBST() {
        BST bst = new BST();

        bst.insert(5);

        bst.insert(3);

        assert bst.height() == 2;
    }

    @Test
    public void height_rootAndRightChildBST() {
        BST bst = new BST();

        bst.insert(5);

        bst.insert(7);

        assert bst.height() == 2;
    }

    @Test
    public void height_rootAndTwoChildrenBST() {
        BST bst = new BST();

        bst.insert(5);

        bst.insert(3);

        bst.insert(7);

        assert bst.height() == 2;
    }

    @Test
    public void height_rootAndTwoLeftDescendantsBST() {
        BST bst = new BST();

        bst.insert(5);

        bst.insert(3);

        bst.insert(1);

        assert bst.height() == 3;
    }

    @Test
    public void height_rootAndTwoRightDescendantsBST() {
        BST bst = new BST();

        bst.insert(5);

        bst.insert(7);

        bst.insert(9);

        assert bst.height() == 3;
    }

    @Test
    public void size_emptyBST() {
        BST bst = new BST();

        assert bst.size() == 0;
    }

    @Test
    public void size_onlyOneElementBST() {
        BST bst = new BST();

        bst.insert(5);

        assert bst.size() == 1;
    }

    @Test
    public void size_rootAndLeftChildBST() {
        BST bst = new BST();

        bst.insert(5);

        bst.insert(3);

        assert bst.size() == 2;
    }

    @Test
    public void size_rootAndRightChildBST() {
        BST bst = new BST();

        bst.insert(5);

        bst.insert(7);

        assert bst.size() == 2;
    }

    @Test
    public void size_rootAndTwoChildrenBST() {
        BST bst = new BST();

        bst.insert(5);

        bst.insert(3);
        bst.insert(7);

        assert bst.size() == 3;
    }

    @Test
    public void search_emptyBST() {
        BST bst = new BST();

        assert !bst.search(4);
    }

    @Test
    public void search_notExists_onlyRootElementBST() {
        BST bst = new BST();

        bst.insert(3);

        assert !bst.search(4);
    }

    @Test
    public void search_exists_onlyRootElementBST() {
        BST bst = new BST();

        bst.insert(3);

        assert bst.search(3);
    }

    @Test
    public void search_exists_onLeftChildBST() {
        BST bst = new BST();

        bst.insert(5);
        bst.insert(3);

        assert bst.search(3);
    }

    @Test
    public void search_exists_onRightChildBST() {
        BST bst = new BST();

        bst.insert(5);
        bst.insert(7);

        assert bst.search(7);
    }

    @Test
    public void search_exists_onLeftDescentantBST() {
        BST bst = new BST();

        bst.insert(5);

        bst.insert(3);
        bst.insert(1);

        assert bst.search(1);
    }

    @Test
    public void search_exists_onRightDescentantBST() {
        BST bst = new BST();

        bst.insert(5);

        bst.insert(7);
        bst.insert(9);

        assert bst.search(9);
    }

    @Test
    public void minValue_emptyBST() {
        BST bst = new BST();

        assert bst.minValue() == Integer.MAX_VALUE;
    }

    @Test
    public void minValue_onlyRootElementBST() {
        BST bst = new BST();

        bst.insert(5);

        assert bst.minValue() == 5;
    }

    @Test
    public void minValue_twoChildrenBST() {
        BST bst = new BST();

        bst.insert(5);
        bst.insert(3);
        bst.insert(7);

        assert bst.minValue() == 3;
    }

    @Test
    public void minValue_moreThanTwoChildrenBST() {
        BST bst = new BST();

        bst.insert(5);
        bst.insert(3);
        bst.insert(1);
        bst.insert(9);
        bst.insert(7);

        assert bst.minValue() == 1;
    }

    @Test
    public void maxValue_emptyBST() {
        BST bst = new BST();

        assert bst.maxValue() == Integer.MIN_VALUE;
    }

    @Test
    public void maxValue_onlyRootElementBST() {
        BST bst = new BST();

        bst.insert(5);

        assert bst.maxValue() == 5;
    }

    @Test
    public void maxValue_twoChildrenBST() {
        BST bst = new BST();

        bst.insert(5);
        bst.insert(3);
        bst.insert(7);

        assert bst.maxValue() == 7;
    }

    @Test
    public void maxValue_moreThanTwoChildrenBST() {
        BST bst = new BST();

        bst.insert(5);
        bst.insert(3);
        bst.insert(1);
        bst.insert(9);
        bst.insert(7);

        assert bst.maxValue() == 9;
    }

    @Test
    public void isBST_emptyBST() {
        BST bst = new BST();

        assert bst.isBST();
    }

    @Test
    public void isBST_onlyRootElementBST() {
        BST bst = new BST();

        bst.insert(5);

        assert bst.isBST();
    }

    @Test
    public void isBST_twoChildrenBST() {
        BST bst = new BST();

        bst.insert(5);
        bst.insert(3);
        bst.insert(2);
        bst.insert(10);
        bst.insert(10000);
        bst.insert(99);
        bst.insert(0);

        bst.preOrder(); // watch the tree printed!

        assert bst.isBST();
    }

    @Test
    public void delete_emptyBST() {
        BST bst = new BST();

        assert bst.height() == 0;

        bst.delete(19);

        assert bst.height() == 0;
    }

    @Test
    public void delete_onlyRootElementBST() {
        BST bst = new BST();

        bst.insert(5);

        assert bst.height() == 1;

        bst.delete(5);

        assert bst.height() == 0;
    }

    @Test
    public void delete_deleteLeaf_leftChildBST() {
        BST bst = new BST();

        bst.insert(5);
        bst.insert(3);

        assert bst.height() == 2;

        bst.delete(3);

        assert bst.height() == 1;
    }

    @Test
    public void delete_deleteLeaf_rightChildBST() {
        BST bst = new BST();

        bst.insert(5);
        bst.insert(7);

        assert bst.height() == 2;

        bst.delete(7);

        assert bst.height() == 1;
    }

    @Test
    public void delete_deleteRoot_twoChildrenBST() {
        BST bst = new BST();

        bst.insert(5);
        bst.insert(3);
        bst.insert(7);

        assert bst.height() == 2;

        bst.delete(5);

        assert bst.height() == 2;
    }

    @Test
    public void delete_deleteInnerNode() {
        BST bst = new BST();

        bst.insert(5);
        bst.insert(3);
        bst.insert(7);
        bst.insert(9);
        bst.insert(6);

        assert bst.height() == 3;

        bst.delete(7);

        bst.preOrder();

        assert bst.height() == 3;
    }

    @Test
    public void delete_deleteRoot_height_3_rightSubtree() {
        BST bst = new BST();

        bst.insert(5);
        bst.insert(3);
        bst.insert(7);
        bst.insert(9);
        bst.insert(6);

        assert bst.height() == 3;

        bst.delete(5);

        // assert root.value == 6
        bst.preOrder();

        assert bst.height() == 3;
    }


    @Test
    public void getSuccessor_emptyBST() {
        BST bst = new BST();

        assert bst.getSuccessor(4) == Integer.MIN_VALUE;
    }

    @Test
    public void getSuccessor_onlyRootElementBST() {
        BST bst = new BST();

        bst.insert(5);

        assert bst.getSuccessor(5) == Integer.MIN_VALUE;
    }

    @Test
    public void getSuccessor_onlyRootElementBST_valueNotExists() {
        BST bst = new BST();

        bst.insert(3);

        assert bst.getSuccessor(5) == Integer.MIN_VALUE;
    }

    @Test
    public void getSuccessor_valueIsLeftChild() {
        BST bst = new BST();

        bst.insert(5);
        bst.insert(3);

        assert bst.getSuccessor(3) == 5;
    }

    @Test
    public void getSuccessor_valueIsRightChild() {
        BST bst = new BST();

        bst.insert(5);
        bst.insert(7);

        // no successor for 7 (the most right child)
        assert bst.getSuccessor(7) == 7;
    }

    @Test
    public void getSuccessor_oneRightDescendant_valueIsRoot() {
        BST bst = new BST();

        bst.insert(5);
        bst.insert(7);

        assert bst.getSuccessor(5) == 7;
    }

    @Test
    public void getSuccessor_twoRightDescendant_valueIsRoot() {
        BST bst = new BST();

        bst.insert(5);
        bst.insert(7);
        bst.insert(6);

        assert bst.getSuccessor(5) == 6;
    }

    @Test
    public void getSuccessor_noRightDescendant_oneLeftChild_valueIsLeftChild() {
        BST bst = new BST();

        bst.insert(5);
        bst.insert(3);

        assert bst.getSuccessor(3) == 5;
    }

    @Test
    public void getSuccessor_noRightDescendant_valueIsRightChildOfLeftChild() {
        BST bst = new BST();

        bst.insert(5);
        bst.insert(3);
        bst.insert(4);
        bst.insert(1);

        assert bst.getSuccessor(4) == 5;
    }

    @Test
    public void getSuccessor_twoRightDescendant_valueIsLeftChildOfRightChild() {
        BST bst = new BST();

        bst.insert(5);
        bst.insert(7);
        bst.insert(6);

        assert bst.getSuccessor(6) == 6;
    }
}
