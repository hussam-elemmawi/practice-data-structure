public class LinkedList<T> {

    private Node<T> head;

    public LinkedList() {
        head = null;
    }

    public int size() {
        Node<T> runner = head;
        int size = 0;

        while (runner != null) {
            ++size;
            runner = runner.next;
        }

        return size;
    }

    public boolean empty() {
        return head == null;
    }

    public T valueAt(int index) {
        if (index < 0) throw new IndexOutOfBoundsException();

        Node<T> runner = head;
        int counter = 0;

        while (runner != null && counter < index) {
            runner = runner.next;
            ++counter;
        }

        if (runner == null) {
            throw new IndexOutOfBoundsException();
        } else {
            return runner.item;
        }
    }

    public void pushFront(T item) {
        Node<T> newNode = new Node<>(item);

        if (head == null) {
            head = newNode;
        } else {
            newNode.next = head;
            head = newNode;
        }
    }

    public T popFront() {
        if (head != null) {
            T item = head.item;
            head = head.next;
            return item;
        }
        return null;
    }

    public void pushBack(T item) {
        Node<T> runner = head;

        while (runner != null && runner.next != null) {
            runner = runner.next;
        }

        if (runner == null) {
            runner = new Node<>(item);
            head = runner;
        } else {
            runner.next = new Node<>(item);
        }
    }

    public T popBack() {
        if (head != null) {
            Node<T> runner = head;
            Node<T> previous = runner;

            while (runner.next != null) {
                previous = runner;
                runner = runner.next;
            }

            T item = runner.item;
            previous.next = null;
            return item;
        }
        return null;
    }

    public T front() {
        return head == null ? null : head.item;
    }

    public T back() {
        Node<T> runner = head;

        while (runner != null && runner.next != null) {
            runner = runner.next;
        }

        return runner == null ? null : runner.item;
    }

    public void insert(int index, T item) {
        if (index < 0) {
            throw new IndexOutOfBoundsException();
        } else if (index == 0) {
            pushFront(item);
        } else {
            Node<T> runner = head;

            int counter = 0;

            while (runner != null && counter < index - 1) {
                runner = runner.next;
                ++counter;
            }

            if (runner == null && counter == index -1) {
                throw new IndexOutOfBoundsException();
            }

            Node<T> newNode = new Node<>(item);

            if (runner == null) {
                head = newNode;
            } else {
                newNode.next = runner.next;
                runner.next = newNode;
            }
        }
    }

    public void erase(int index) {
        if (head == null) throw new IndexOutOfBoundsException();

        Node<T> runner = head;

        int counter = 0;

        while (runner != null && counter < index - 1) {
            runner = runner.next;
            ++counter;
        }

        if (counter + 1 != index) {
            throw new IndexOutOfBoundsException();
        }

        runner.next = runner.next.next;
    }

    public T valueNthFromTheEnd(int n) {
        if (n >= size() || n < 0) throw new IndexOutOfBoundsException();

        Node<T> slow = head;
        Node<T> fast = head;

        int counter = 0;
        while (counter < n) {
            fast = fast.next;
            ++counter;
        }

        while (fast.next != null) {
            fast = fast.next;
            slow = slow.next;
        }

        return slow.item;
    }

    public void reverse() {
        if (head == null || head.next == null) return;

        Node<T> previous = null;
        Node<T> runner = head;
        Node<T> next = head.next;

        while (runner != null) {
            runner.next = previous;
            previous = runner;
            runner = next;

            if (next != null) {
                next = next.next;
            }
        }
        head = previous;
    }

    // removes the first item in the list with this value
    public void removeItem(T item) {
        Node<T> runner = head;
        Node<T> previous = head;

        while (runner != null && !runner.item.equals(item)) {
            previous = runner;
            runner = runner.next;
        }

        if (runner != null) { // found
            if (runner == head) {
                head = head.next;
            } else {
                previous.next = runner.next;
            }
        }
    }
}
