# SinglyLinkedList-STL-Style

A **custom, STL-style singly linked list** implemented in C++.  
Supports iterators, `push_front`, `push_back`, `erase`, `reverse`, `sort`, and range-based for loops.

---

## Features

- Singly linked list with `head` and `tail` pointers
- STL-style **iterator** for forward traversal
- `push_front` and `push_back`
- `erase` by value (removes all occurrences)
- `reverse` and `sort` functions
- `find` function returning iterator
- Range-based for loop compatible
- `size()` and `empty()` methods

---

## Header Usage

Include the header in your C++ project:

```cpp
#include "linkedlist.h"


| Method                       | Description                           |
| ---------------------------- | ------------------------------------- |
| `push_front(const T& value)` | Insert element at the beginning       |
| `push_back(const T& value)`  | Insert element at the end             |
| `erase(const T& value)`      | Remove all occurrences of a value     |
| `reverse()`                  | Reverse the list                      |
| `sort()`                     | Sort the list in ascending order      |
| `find(const T& value)`       | Find element, returns pointer to node |
| `size()`                     | Return number of elements             |
| `empty()`                    | Check if list is empty                |
| `clear()`                    | Delete all nodes                      |


Notes
This implementation is singly linked, unlike std::list (doubly linked).
Supports forward iterators only.
Designed for educational purposes to understand linked lists and iterators.


License
MIT License – free to use, modify, and distribute.



Absolutely! Here's a **ready-to-paste `README.md`** for your GitHub project:

````markdown
# SinglyLinkedList-STL-Style

A **custom, STL-style singly linked list** implemented in C++.  
Supports iterators, `push_front`, `push_back`, `erase`, `reverse`, `sort`, and range-based for loops.

---

## Features

- Singly linked list with `head` and `tail` pointers
- STL-style **iterator** for forward traversal
- `push_front` and `push_back`
- `erase` by value (removes all occurrences)
- `reverse` and `sort` functions
- `find` function returning iterator
- Range-based for loop compatible
- `size()` and `empty()` methods

---

## Header Usage

Include the header in your C++ project:

```cpp
#include "linkedlist.h"
````

---

## Example Usage

```cpp
#include <iostream>
#include "linkedlist.h"

int main() {
    linkedlist<int> list;

    // Add elements
    list.push_back(10);
    list.push_back(30);
    list.push_back(20);
    list.push_front(5);

    std::cout << "List elements: ";
    for(auto& x : list) {
        std::cout << x << " ";
    }
    std::cout << "\n";

    // Find element
    auto it = list.find(20);
    if(it != nullptr) std::cout << "Found: " << it->value << "\n";

    // Erase element
    list.erase(30);
    std::cout << "After erase 30: ";
    for(auto& x : list) std::cout << x << " ";
    std::cout << "\n";

    // Reverse list
    list.reverse();
    std::cout << "Reversed list: ";
    for(auto& x : list) std::cout << x << " ";
    std::cout << "\n";

    // Sort list
    list.sort();
    std::cout << "Sorted list: ";
    for(auto& x : list) std::cout << x << " ";
    std::cout << "\n";

    return 0;
}
```

**Output:**

```
List elements: 5 10 30 20
Found: 20
After erase 30: 5 10 20
Reversed list: 20 10 5
Sorted list: 5 10 20
```

---

## Methods

| Method                       | Description                           |
| ---------------------------- | ------------------------------------- |
| `push_front(const T& value)` | Insert element at the beginning       |
| `push_back(const T& value)`  | Insert element at the end             |
| `erase(const T& value)`      | Remove all occurrences of a value     |
| `reverse()`                  | Reverse the list                      |
| `sort()`                     | Sort the list in ascending order      |
| `find(const T& value)`       | Find element, returns pointer to node |
| `size()`                     | Return number of elements             |
| `empty()`                    | Check if list is empty                |
| `clear()`                    | Delete all nodes                      |

---

## Notes

* This implementation is **singly linked**, unlike `std::list` (doubly linked).
* Supports **forward iterators only**.
* Designed for **educational purposes** to understand linked lists and iterators.

---

## License

MIT License – free to use, modify, and distribute.

```

---

If you want, I can also **make a version for doubly linked list** with iterators and reverse traversal, ready for GitHub too.  

Do you want me to do that?
```
