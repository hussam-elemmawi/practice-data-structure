import org.junit.Test;

public class TestLinkedList {


    @Test
    public void test_size_emptyLinkedList() {
        LinkedList<Object> linkedList = new LinkedList<>();

        assert linkedList.size() == 0;
    }

    @Test
    public void test_empty_emptyLinkedList() {
        LinkedList<Object> linkedList = new LinkedList<>();

        assert linkedList.empty();
    }

    @Test(expected = IndexOutOfBoundsException.class)
    public void test_valueAt_emptyLinkedList() {
        LinkedList<Object> linkedList = new LinkedList<>();

        linkedList.valueAt(0);
    }

    @Test(expected = IndexOutOfBoundsException.class)
    public void test_valueAt_emptyLinkedList_indexBeyondListSize() {
        LinkedList<Object> linkedList = new LinkedList<>();

        assert linkedList.valueAt(1) == null;
    }

    @Test(expected = IndexOutOfBoundsException.class)
    public void test_valueAt_emptyLinkedList_indexBelowZero() {
        LinkedList<Object> linkedList = new LinkedList<>();

        assert linkedList.valueAt(-1) == null;
    }

    @Test
    public void test_valueAt() {
        LinkedList<Integer> linkedList = new LinkedList<>();

        linkedList.pushFront(1);

        assert linkedList.valueAt(0).equals(1);
    }

    @Test(expected = IndexOutOfBoundsException.class)
    public void test_valueAt_indexBeyondListSize() {
        LinkedList<Integer> linkedList = new LinkedList<>();

        linkedList.pushFront(1);

        assert linkedList.valueAt(2) == null;
    }

    @Test(expected = IndexOutOfBoundsException.class)
    public void test_valueAt_indexEqualsListSize() {
        LinkedList<Integer> linkedList = new LinkedList<>();

        linkedList.pushFront(1);

        linkedList.valueAt(1);
    }

    @Test(expected = IndexOutOfBoundsException.class)
    public void test_valueAt_indexBelowListSize() {
        LinkedList<Integer> linkedList = new LinkedList<>();

        linkedList.pushFront(1);

        assert linkedList.valueAt(-1) == null;
    }

    @Test
    public void test_pushFront_emptyList() {
        LinkedList<Integer> linkedList = new LinkedList<>();

        linkedList.pushFront(1);

        assert linkedList.valueAt(0) == 1;
        assert linkedList.size() == 1;
    }

    @Test
    public void test_pushFront_notEmptyList() {
        LinkedList<Integer> linkedList = new LinkedList<>();

        linkedList.pushFront(1);
        linkedList.pushFront(2);

        assert linkedList.valueAt(1) == 1;
        assert linkedList.size() == 2;
    }

    @Test(expected = IndexOutOfBoundsException.class)
    public void test_popFront_emptyList() {
        LinkedList<Integer> linkedList = new LinkedList<>();

        linkedList.pushFront(0);

        Integer item = linkedList.popFront();

        assert item == 0;
        assert linkedList.size() == 0;
        linkedList.valueAt(0);
    }

    @Test
    public void test_popFront_notEmptyList() {
        LinkedList<Integer> linkedList = new LinkedList<>();

        linkedList.pushFront(0);
        linkedList.pushFront(1);

        Integer item = linkedList.popFront();

        assert item == 1;
        assert linkedList.size() == 1;
        assert linkedList.valueAt(0) == 0;
    }

    @Test
    public void test_pushBack_emptyList() {
        LinkedList<Integer> linkedList = new LinkedList<>();

        linkedList.pushBack(0);

        assert linkedList.valueAt(0) == 0;
        assert linkedList.size() == 1;
    }

    @Test
    public void test_pushBack_notEmptyList() {
        LinkedList<Integer> linkedList = new LinkedList<>();

        linkedList.pushBack(0);

        assert linkedList.valueAt(0) == 0;
        assert linkedList.size() == 1;

        linkedList.pushBack(1);

        assert linkedList.valueAt(0) == 0;
        assert linkedList.valueAt(1) == 1;
        assert linkedList.size() == 2;
    }

    @Test
    public void test_popBack_emptyList() {
        LinkedList<Integer> linkedList = new LinkedList<>();

        Integer item = linkedList.popBack();

        assert item == null;
        assert linkedList.size() == 0;
    }

    @Test
    public void test_popBack_notEmptyList() {
        LinkedList<Integer> linkedList = new LinkedList<>();

        linkedList.pushBack(0);
        linkedList.pushBack(1);

        assert linkedList.size() == 2;

        Integer item = linkedList.popBack();

        assert item == 1;
        assert linkedList.size() == 1;
    }

    @Test
    public void test_front_emptyList() {
        LinkedList<Integer> linkedList = new LinkedList<>();

        assert linkedList.front() == null;
        assert linkedList.size() == 0;
    }

    @Test
    public void test_front_notEmptyList() {
        LinkedList<Integer> linkedList = new LinkedList<>();

        linkedList.pushBack(0);
        linkedList.pushBack(1);

        assert linkedList.size() == 2;

        assert linkedList.front() == 0;
        assert linkedList.size() == 2;
    }

    @Test
    public void test_back_emptyList() {
        LinkedList<Integer> linkedList = new LinkedList<>();

        assert linkedList.back() == null;
        assert linkedList.size() == 0;
    }

    @Test
    public void test_back_notEmptyList() {
        LinkedList<Integer> linkedList = new LinkedList<>();

        linkedList.pushBack(0);
        linkedList.pushBack(1);

        assert linkedList.size() == 2;

        assert linkedList.back() == 1;
        assert linkedList.size() == 2;
    }

    @Test(expected = IndexOutOfBoundsException.class)
    public void test_insert_emptyList_indexBelowZero() {
        LinkedList<Integer> linkedList = new LinkedList<>();

        linkedList.insert(-1, 0);
    }

    @Test(expected = IndexOutOfBoundsException.class)
    public void test_insert_emptyList_indexBeyondSize() {
        LinkedList<Integer> linkedList = new LinkedList<>();

        linkedList.insert(1, 0);
    }

    @Test
    public void test_insert_emptyList() {
        LinkedList<Integer> linkedList = new LinkedList<>();

        linkedList.insert(0, 0);

        assert linkedList.valueAt(0) == 0;
        assert linkedList.size() == 1;
    }

    @Test
    public void test_insert_emptyList_insertInRightFollowingIndexes() {
        LinkedList<Integer> linkedList = new LinkedList<>();

        linkedList.insert(0, 0);
        linkedList.insert(1, 1);

        assert linkedList.valueAt(0) == 0;
        assert linkedList.valueAt(1) == 1;
        assert linkedList.size() == 2;
    }

    @Test
    public void test_insert_emptyList_insertInBetweenIndexes() {
        LinkedList<Integer> linkedList = new LinkedList<>();

        linkedList.insert(0, 0);
        linkedList.insert(1, 1);
        linkedList.insert(1, 99);

        assert linkedList.valueAt(0) == 0;
        assert linkedList.valueAt(1) == 99;
        assert linkedList.valueAt(2) == 1;
        assert linkedList.size() == 3;
    }

    @Test
    public void test_insert_emptyList_insertAsPushFront() {
        LinkedList<Integer> linkedList = new LinkedList<>();

        linkedList.insert(0, 0);
        linkedList.insert(0, 99);

        assert linkedList.valueAt(0) == 99;
        assert linkedList.valueAt(1) == 0;
        assert linkedList.size() == 2;
    }

    @Test
    public void test_insert_emptyList_insertAsPushBack() {
        LinkedList<Integer> linkedList = new LinkedList<>();

        linkedList.insert(0, 0);
        linkedList.insert(1, 99);

        assert linkedList.valueAt(0) == 0;
        assert linkedList.valueAt(1) == 99;
        assert linkedList.size() == 2;
    }

    @Test(expected = IndexOutOfBoundsException.class)
    public void test_erase_emptyList() {
        LinkedList<Integer> linkedList = new LinkedList<>();

        linkedList.erase(0);
    }

    @Test(expected = IndexOutOfBoundsException.class)
    public void test_erase_emptyList_indexBelowZero() {
        LinkedList<Integer> linkedList = new LinkedList<>();

        linkedList.erase(-1);
    }

    @Test(expected = IndexOutOfBoundsException.class)
    public void test_erase_emptyList_indexBeyondSize() {
        LinkedList<Integer> linkedList = new LinkedList<>();

        linkedList.erase(1);
    }

    @Test(expected = IndexOutOfBoundsException.class)
    public void test_erase_notEmptyList_indexBeyondSize() {
        LinkedList<Integer> linkedList = new LinkedList<>();

        linkedList.pushFront(0);
        linkedList.pushFront(1);

        linkedList.erase(100);
    }

    @Test(expected = IndexOutOfBoundsException.class)
    public void test_erase_notEmptyList_indexBelowZero() {
        LinkedList<Integer> linkedList = new LinkedList<>();

        linkedList.pushFront(0);
        linkedList.pushFront(1);

        linkedList.erase(-1);
    }

    @Test(expected = IndexOutOfBoundsException.class)
    public void test_erase_notEmptyList_oneItem() {
        LinkedList<Integer> linkedList = new LinkedList<>();

        linkedList.pushFront(0);

        linkedList.erase(0);

        assert linkedList.size() == 0;
    }

    @Test(expected = IndexOutOfBoundsException.class)
    public void test_erase_notEmptyList_manyItems_eraseFront() {
        LinkedList<Integer> linkedList = new LinkedList<>();

        linkedList.pushFront(0);
        linkedList.pushFront(1);
        linkedList.pushFront(2);

        linkedList.erase(0);

        assert linkedList.valueAt(0) == 1;
        assert linkedList.valueAt(1) == 2;
        assert linkedList.size() == 2;
    }

    @Test
    public void test_erase_notEmptyList_manyItems_eraseBack() {
        LinkedList<Integer> linkedList = new LinkedList<>();

        linkedList.pushFront(2);
        linkedList.pushFront(1);
        linkedList.pushFront(0);

        linkedList.erase(2);

        assert linkedList.valueAt(0) == 0;
        assert linkedList.valueAt(1) == 1;
        assert linkedList.size() == 2;
    }

    @Test
    public void test_erase_notEmptyList_manyItems_eraseAtMiddle() {
        LinkedList<Integer> linkedList = new LinkedList<>();

        linkedList.pushFront(2);
        linkedList.pushFront(1);
        linkedList.pushFront(0);

        linkedList.erase(1);

        assert linkedList.valueAt(0) == 0;
        assert linkedList.valueAt(1) == 2;
        assert linkedList.size() == 2;
    }

    @Test(expected = IndexOutOfBoundsException.class)
    public void test_valueNthFromEnd_emptyList() {
        LinkedList<Integer> linkedList = new LinkedList<>();

        linkedList.valueNthFromTheEnd(0);
    }

    @Test(expected = IndexOutOfBoundsException.class)
    public void test_valueNthFromEnd_emptyList_indexBeyondSize() {
        LinkedList<Integer> linkedList = new LinkedList<>();

        linkedList.valueNthFromTheEnd(1);
    }

    @Test(expected = IndexOutOfBoundsException.class)
    public void test_valueNthFromEnd_emptyList_indexBelowZero() {
        LinkedList<Integer> linkedList = new LinkedList<>();

        linkedList.valueNthFromTheEnd(-1);
    }

    @Test(expected = IndexOutOfBoundsException.class)
    public void test_valueNthFromEnd_notEmptyList_indexBeyondSize() {
        LinkedList<Integer> linkedList = new LinkedList<>();

        linkedList.pushFront(0);

        linkedList.valueNthFromTheEnd(1);
    }

    @Test(expected = IndexOutOfBoundsException.class)
    public void test_valueNthFromEnd_notEmptyList_indexBelowZero() {
        LinkedList<Integer> linkedList = new LinkedList<>();

        linkedList.pushFront(0);

        linkedList.valueNthFromTheEnd(-1);
    }

    @Test
    public void test_valueNthFromEnd_notEmptyList() {
        LinkedList<Integer> linkedList = new LinkedList<>();

        linkedList.pushFront(2);
        linkedList.pushFront(1);
        linkedList.pushFront(0);

        Integer item = linkedList.valueNthFromTheEnd(0);
        assert item == 2;

        item = linkedList.valueNthFromTheEnd(1);
        assert item == 1;

        item = linkedList.valueNthFromTheEnd(2);
        assert item == 0;
    }

    @Test
    public void test_reverse_emptyList() {
        LinkedList<Integer> linkedList = new LinkedList<>();

        linkedList.reverse();
        // nothing happened
    }

    @Test
    public void test_reverse_notEmptyList_oneItem() {
        LinkedList<Integer> linkedList = new LinkedList<>();

        linkedList.pushFront(0);

        // list now should be {0}

        linkedList.reverse();

        // list now should be {0}

        assert linkedList.valueAt(0) == 0;
        assert linkedList.size() == 1;
    }

    @Test
    public void test_reverse_notEmptyList_manyItems() {
        LinkedList<Integer> linkedList = new LinkedList<>();

        linkedList.pushFront(2);
        linkedList.pushFront(1);
        linkedList.pushFront(0);

        // list now should be {0 -> 1 -> 2}

        linkedList.reverse();

        // list now should be {2 -> 1 -> 0}

        assert linkedList.valueAt(0) == 2;
        assert linkedList.valueAt(1) == 1;
        assert linkedList.valueAt(2) == 0;
    }

    @Test
    public void test_removeItem_emptyList() {
        LinkedList<Integer> linkedList = new LinkedList<>();

        linkedList.removeItem(1);

        // nothing happened
    }

    @Test
    public void test_removeItem_notEmptyList_foundItem_onceAtFront() {
        LinkedList<Integer> linkedList = new LinkedList<>();

        linkedList.pushFront(2);
        linkedList.pushFront(1);
        linkedList.pushFront(0);

        assert linkedList.size() == 3;

        // list now should be {0 -> 1 -> 2}

        linkedList.removeItem(0);

        // list now should be {1 -> 2}

        assert linkedList.size() == 2;

        assert linkedList.valueAt(0) == 1;
        assert linkedList.valueAt(1) == 2;
    }

    @Test
    public void test_removeItem_notEmptyList_foundItem_onceAtMiddle() {
        LinkedList<Integer> linkedList = new LinkedList<>();

        linkedList.pushFront(2);
        linkedList.pushFront(1);
        linkedList.pushFront(0);

        assert linkedList.size() == 3;

        // list now should be {0 -> 1 -> 2}

        linkedList.removeItem(1);

        // list now should be {0 -> 2}

        assert linkedList.size() == 2;

        assert linkedList.valueAt(0) == 0;
        assert linkedList.valueAt(1) == 2;
    }

    @Test
    public void test_removeItem_notEmptyList_foundItem_onceAtEnd() {
        LinkedList<Integer> linkedList = new LinkedList<>();

        linkedList.pushFront(2);
        linkedList.pushFront(1);
        linkedList.pushFront(0);

        assert linkedList.size() == 3;

        // list now should be {0 -> 1 -> 2}

        linkedList.removeItem(2);

        // list now should be {0 -> 1}

        assert linkedList.size() == 2;

        assert linkedList.valueAt(0) == 0;
        assert linkedList.valueAt(1) == 1;
    }

    @Test
    public void test_removeItem_notEmptyList_foundItem_many() {
        LinkedList<Integer> linkedList = new LinkedList<>();

        linkedList.pushFront(2);
        linkedList.pushFront(1);
        linkedList.pushFront(1);
        linkedList.pushFront(0);

        assert linkedList.size() == 4;

        // list now should be {0 -> 1 -> 1 -> 2}

        linkedList.removeItem(1);

        // list now should be {0 -> 1 -> 2}

        assert linkedList.size() == 3;

        assert linkedList.valueAt(0) == 0;
        assert linkedList.valueAt(1) == 1;
        assert linkedList.valueAt(2) == 2;
    }
}
