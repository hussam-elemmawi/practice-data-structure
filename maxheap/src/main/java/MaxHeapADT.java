public interface MaxHeapADT {
    void insert(int item);
    int getMax();
    int getsize();
    boolean isEmpty();
    int extractMax();
    void remove(int index);
    int[] heapSort(int[] items);
}
