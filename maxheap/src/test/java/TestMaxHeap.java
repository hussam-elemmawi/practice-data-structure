import org.junit.Test;

public class TestMaxHeap {

    @Test
    public void test_insert_noItem() {
        MaxHeap maxHeap = new MaxHeap(0);

        assert maxHeap.getsize() == 0;
        assert maxHeap.getMax() == -1;
    }

    @Test
    public void test_insert_singleItem() {
        MaxHeap maxHeap = new MaxHeap(1);

        maxHeap.insert(5);

        assert maxHeap.getsize() == 1;
        assert maxHeap.getMax() == 5;
    }

    @Test
    public void test_insert_multipleItems() {
        MaxHeap maxHeap = new MaxHeap(3);

        maxHeap.insert(5);
        maxHeap.insert(3);
        maxHeap.insert(6);

        assert maxHeap.getsize() == 3;
        assert maxHeap.getMax() == 6;
    }

    @Test
    public void test_extractMax_noItem() {
        MaxHeap maxHeap = new MaxHeap(0);

        assert maxHeap.extractMax() == -1;
    }

    @Test
    public void test_extractMax_singleItem() {
        MaxHeap maxHeap = new MaxHeap(1);

        maxHeap.insert(5);

        assert maxHeap.extractMax() == 5;
        assert maxHeap.extractMax() == -1;
    }

    @Test
    public void test_extractMax_multipleItems() {
        MaxHeap maxHeap = new MaxHeap(3);

        maxHeap.insert(5);
        maxHeap.insert(3);
        maxHeap.insert(6);

        assert maxHeap.extractMax() == 6;
        assert maxHeap.extractMax() == 5;
    }


    @Test
    public void test_remove_noItem() {
        MaxHeap maxHeap = new MaxHeap(0);

        assert maxHeap.getsize() == 0;
        maxHeap.remove(0);
    }

    @Test
    public void test_remove_singleItem() {
        MaxHeap maxHeap = new MaxHeap(1);

        maxHeap.insert(5);

        assert maxHeap.getsize() == 1;
        maxHeap.remove(0);
        assert maxHeap.getsize() == 0;
    }

    @Test
    public void test_remove_multipleItems_maxItem() {
        MaxHeap maxHeap = new MaxHeap(3);

        maxHeap.insert(5);
        maxHeap.insert(3);
        maxHeap.insert(6);

        assert maxHeap.getsize() == 3;
        maxHeap.remove(0);
        assert maxHeap.getsize() == 2;
        assert maxHeap.getMax() == 5;
    }

    @Test
    public void test_remove_multipleItems_middleNodeItem() {
        MaxHeap maxHeap = new MaxHeap(3);

        maxHeap.insert(5);
        maxHeap.insert(3);
        maxHeap.insert(6);

        assert maxHeap.getsize() == 3;
        maxHeap.remove(1);
        assert maxHeap.getsize() == 2;
        assert maxHeap.extractMax() == 6;
        assert maxHeap.extractMax() == 3;
    }

    @Test
    public void test_remove_multipleItems_leafItem() {
        MaxHeap maxHeap = new MaxHeap(3);

        maxHeap.insert(5);
        maxHeap.insert(3);
        maxHeap.insert(6);

        assert maxHeap.getsize() == 3;
        maxHeap.remove(2);
        assert maxHeap.getsize() == 2;
        assert maxHeap.extractMax() == 6;
        assert maxHeap.extractMax() == 5;
    }

    @Test
    public void test_insert_remove_extractMax_workingProperly() {
        MaxHeap maxHeap = new MaxHeap(10);

        maxHeap.insert(5);
        maxHeap.insert(7);
        maxHeap.insert(3);
        maxHeap.insert(9);
        maxHeap.insert(2);
        maxHeap.insert(10);

        assert maxHeap.getsize() == 6;

        maxHeap.remove(0);
        assert maxHeap.getsize() == 5;

        assert maxHeap.extractMax() == 9;
        assert maxHeap.getsize() == 4;


        maxHeap.insert(10);
        assert maxHeap.getMax() == 10;
        assert maxHeap.getsize() == 5;
    }

    @Test
    public void test_sort_noItems() {
        MaxHeap maxHeap = new MaxHeap(0);

        int[] items = maxHeap.heapSort(new int[]{});

        assert items.length == 0;
    }


    @Test
    public void test_sort_oneItems() {
        MaxHeap maxHeap = new MaxHeap(1);

        int[] items = maxHeap.heapSort(new int[]{4});

        assert items.length == 1;
        assert items[0] == 4;
    }

    @Test
    public void test_sort_multipleItems() {
        MaxHeap maxHeap = new MaxHeap(1);

        int[] items = maxHeap.heapSort(new int[]{4, 1, 4, 7});

        assert items.length == 4;
        assert items[0] == 1;
        assert items[1] == 4;
        assert items[2] == 4;
        assert items[3] == 7;
    }
}
