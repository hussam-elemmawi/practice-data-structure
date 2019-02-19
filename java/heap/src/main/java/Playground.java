public class Playground {

    public static void main(String[] args) {
        Heap heap = new Heap(10);
        heap.insert(4);
        heap.insert(1);
        heap.insert(6);
        heap.insert(3);
        heap.insert(59);
        heap.insert(11);
        heap.insert(12);
        heap.insert(14);
        heap.insert(41);
        heap.insert(0);

        heap.printBuffer();
        System.out.println();
        heap.printHeap();
    }
}
