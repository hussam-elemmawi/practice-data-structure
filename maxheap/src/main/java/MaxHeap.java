import com.sun.xml.internal.ws.api.message.ExceptionHasMessage;

public class MaxHeap implements MaxHeapADT {

    private int buffer[];
    private int capacity;
    private int size = 0;

    public MaxHeap(int cap) {
        if (cap < 1) return;
        init(cap);
    }

    private void init(int cap) {
        buffer = new int[cap];
        capacity = cap;
        size = 0;
    }

    @Override
    public void insert(int item) {
        if (size == capacity) return;
        int index = size++;
        buffer[index] = item;

        siftUp(index);
    }

    private void siftUp(int index) {
        if (index < 0 || index >= size) return;

        int parentIndex = index / 2;
        if(buffer[parentIndex] < buffer[index]) {
            swap(parentIndex, index);
            siftUp(parentIndex);
        }
    }

    private void swap(int a, int b) {
        int temp = buffer[a];
        buffer[a] = buffer[b];
        buffer[b] = temp;
    }

    @Override
    public int getMax() {
        if (size < 1) return -1;
        return buffer[0];
    }

    @Override
    public int getsize() {
        return size;
    }

    @Override
    public boolean isEmpty() {
        return size == 0;
    }

    @Override
    public int extractMax() {
        if (isEmpty()) return -1;
        int max = getMax();
        remove(0);
        return max;
    }

    @Override
    public void remove(int index) {
        if (isEmpty() || index < 0 || index >= size)
            return;
        swap(index, size - 1);
        --size;
        siftDown(index);
    }

    private void siftDown(int index) {
        if (index < 0 || index >= size) return;

        int leftChildIdx = index * 2;
        int rightChildIdx = index * 2 + 1;

        if (leftChildIdx >= size && rightChildIdx >= size) return;

        int largestChildIdx;

        if (leftChildIdx >= size) {
            largestChildIdx = rightChildIdx;
        } else if (rightChildIdx >= size) {
            largestChildIdx = leftChildIdx;
        } else {
            largestChildIdx = buffer[leftChildIdx] > buffer[rightChildIdx] ? leftChildIdx : rightChildIdx;
        }

        if (largestChildIdx < size && buffer[largestChildIdx] > buffer[index]) {
            swap(largestChildIdx, index);
            siftDown(largestChildIdx);
        }
    }

    @Override
    public int[] heapSort(int[] items) {
        if (items.length < 2) return items;

        buffer = items;
        capacity = items.length;
        size = items.length;

        heapfiy();

        for (int i = 0; i < capacity; ++i) {
            remove(0);
        }

        return items;
    }

    private void heapfiy() {
        for (int i = (buffer.length - 1) / 2; i >= 0; --i) {
            siftDown(i);
        }
    }

    public void printBuffer() {
        int i = 0;
        for (; i < buffer.length - 1; ++i) {
            System.out.print(buffer[i] + " ");
        }
        System.out.print(buffer[i]);
    }

    public void printHeap() {
        int parent = 0;

        while (parent < size / 2) {
            int leftChild = parent * 2 + 1;
            int rightChild = parent * 2 + 2;

            System.out.print(buffer[parent] + " ");

            if (leftChild < size)
                System.out.print(buffer[leftChild] + " ");
            if (rightChild < size)
                System.out.print(buffer[rightChild] + " ");

            System.out.println();
            ++parent;
        }
    }
}
