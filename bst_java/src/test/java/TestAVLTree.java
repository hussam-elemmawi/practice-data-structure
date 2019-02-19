import org.junit.Test;

public class TestAVLTree {

    @Test
    public void insert_sortedIncreasingInput() {
        AVLTree avlTree = new AVLTree();

        avlTree.insert(1);
        avlTree.insert(2);
        avlTree.insert(3);
        avlTree.insert(4);
        avlTree.insert(5);
        avlTree.insert(6);

        assert avlTree.height() <= 3;
    }

    @Test
    public void insert_sortedDecreasingInput() {
        AVLTree avlTree = new AVLTree();

        avlTree.insert(6);
        avlTree.insert(5);
        avlTree.insert(4);
        avlTree.insert(3);
        avlTree.insert(2);
        avlTree.insert(1);

        assert avlTree.height() <= 3;
    }

    @Test
    public void delete_confirmHeightFixed() {
        AVLTree avlTree = new AVLTree();

        avlTree.insert(1);
        avlTree.insert(2);
        avlTree.insert(3);
        avlTree.insert(4);
        avlTree.insert(5);
        avlTree.insert(6);
        avlTree.insert(7);
        avlTree.insert(8);

        // #nodes = 8
        // so I need h = log2(n) + 1
        assert avlTree.height() == 4;

        // I'm deleting the root
        avlTree.delete(4);

        assert avlTree.height() <= 3;
    }
}
