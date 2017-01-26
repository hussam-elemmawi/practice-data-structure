#Linked Lists
Implementation for a LinkedList in C using three manners:

1. Using a `int size` variable to store the size. (I saw nobody implementing a linked list with storing the size, but why the hack not!)
2. Using a pointer to the head node only.
3. Using two pointers, head and tail. 

The following table shows the time taken for each operation per each implementatin

| Operation| With size| Head only| Head & tail |
| -------------|------------|-------|------|
| `size()`|O(1)|O(n)| O(n)|
| `is_empty()`|O(1)| O(1)| O(1)|
| `value_at()`|O(n)| O(n)| O(n)|
| `front();`|O(1)| O(1)| O(1)|
| `back();`|O(n)| O(n)| O(1)|
| `push_front()`|O(1) | O(1)| O(1)|
| `push_back()`|O(n)| O(n)| O(1)|
| `pop_front();`|O(1)| O(1)| O(1)|
| `pop_back();`|O(n)| O(n)| O(1)|
| `insert();`|O(n)| O(n)| O(n)|
| `value_n_from_back();`| O(n)| O(n)| O(n)|
| `insert();`|O(n)| O(n)| O(n)|
| `remove();`|O(n)| O(n)| O(n)|
| `reverse();`|O(n)| O(n)| O(n)|