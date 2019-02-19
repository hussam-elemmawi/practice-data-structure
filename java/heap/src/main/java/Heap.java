import java.util.ArrayList;

public class Heap implements HeapADT {

    private int[] buffer;
    private int heapSize = 0;
    private int CAPACITY;

    public Heap(int capacity) {
        CAPACITY = capacity;
        buffer = new int[capacity];
    }

    @Override
    public void insert(int val) {
        if (heapSize == CAPACITY) return;
        int index = heapSize;
        buffer[index] = val;
        ++heapSize;

        siftUp(index);
    }

    private void siftUp(int index) {
        int parent = index / 2;

        if (parent >= 0 && buffer[parent] < buffer[index]) {
            swap(parent, index);
            siftUp(parent);
        }
    }

    @Override
    public void delete(int val) {
        if (heapSize == 0) return;
        int index = -1;
        for (int i = 0; i < heapSize; ++i) {
            if (buffer[i] == val) {
                index = i;
                break;
            }
        }

        if (index != -1) {
            buffer[index] = buffer[heapSize - 1];
            heapSize--;

            siftDown(index);
        }
    }

    private void siftDown(int index) {
        if (index < 0 || index > heapSize) return;

        int leftChild = index * 2;
        int rightChild = index * 2 + 1;

        if (leftChild >= heapSize && rightChild >= heapSize) {
            return;
        }

        int largestChild;
        if (leftChild >= heapSize) {
            largestChild = rightChild;
        } else if (rightChild >= heapSize) {
            largestChild = leftChild;
        } else {
            largestChild = buffer[leftChild] > buffer[rightChild] ? leftChild : rightChild;
        }

        if (largestChild > 0 && largestChild < heapSize) {
            // index is the parent
            swap(index, largestChild);
            siftDown(largestChild);
        }
    }

    @Override
    public void deleteMax() {
        delete(buffer[0]);
    }

    @Override
    public int getMax() {
        return buffer[0];
    }

    @Override
    public int extractMax() {
        int max = getMax();
        deleteMax();
        return max;
    }

    private void initializeHeap(int[] numbers) {
        buffer = numbers;
        CAPACITY = numbers.length;
        heapSize = numbers.length - 1;
    }

    @Override
    public void heapify(int[] numbers, int lastIndex) {
        initializeHeap(numbers);

        if (numbers.length > 1) {
            for (int i = (numbers.length - 1) / 2; i >= 0; --i) {
                siftDown(i);
            }
        }
    }

    private void swap(int a, int b) {
        int temp = buffer[a];
        buffer[a] = buffer[b];
        buffer[b] = temp;
    }

    @Override
    public void heapSort(int[] numbers) {
        initializeHeap(numbers);

        for (int i = heapSize - 1; i >= 0; --i) {
            swap(0, --heapSize);
            siftDown(heapSize - 1);
        }
    }

    @Override
    public void printBuffer() {
        int i = 0;
        for (; i < buffer.length - 1; ++i) {
            System.out.print(buffer[i] + " ");
        }
        System.out.print(buffer[i]);
    }

    @Override
    public void printHeap() {
        int parent = 0;

        while (parent < heapSize / 2) {
            int leftChild = parent * 2 + 1;
            int rightChild = parent * 2 + 2;

            System.out.print(buffer[parent] + " ");

            if (leftChild < heapSize)
                System.out.print(buffer[leftChild] + " ");
            if (rightChild < heapSize)
                System.out.print(buffer[rightChild] + " ");

            System.out.println();
            ++parent;
        }
    }
}
