public interface HeapADT {

    void insert(int val);
    void delete(int val);
    void deleteMax();
    int getMax();
    int extractMax();
    void heapify(int[] numbers, int lastIndex);
    void heapSort(int[] numbers);
    void printBuffer();
    void printHeap();
}
