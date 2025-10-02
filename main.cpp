#include <iostream>
#include "linkedlist.h"

int main() {
    linkedlist<int> list;

    // Add elements
    list.push_back(5);
    list.push_back(3);
    list.push_back(8);
    list.push_front(1);
    list.push_back(3); // duplicate value
    list.push_back(7);

    std::cout << "Original list: ";   //Original list: 1 5 3 8 3 7 
    for(auto& val : list) std::cout << val << " ";
    std::cout<<"\n";

    // Find element
    auto it = list.find(3);
    if(it != list.end()) {
        std::cout << "Found: " << *it << "\n";  //Found: 3
    } else {
        std::cout << "3 not found\n";
    }

    // Erase all occurrences of 3
    list.erase(3);
    std::cout << "After erasing 3: ";
    for(auto& val : list) std::cout << val << " "; //After erasing 3: 1 5 8 7 
    std::cout << "\n";

    // Reverse the list
    list.reverse();
    std::cout << "After reversing: ";
    for(auto& val : list) std::cout << val << " "; //After reversing: 7 8 5 1 
    std::cout << "\n";

    // Sort the list
    list.sort();
    std::cout << "After sorting: ";
    for(auto& val : list) std::cout << val << " "; //After sorting: 1 5 7 8
    std::cout << "\n";

    // Clear the list
    list.clear();
    std::cout << "After clearing, list empty? " << (list.empty() ? "Yes" : "No") << "\n"; //After clearing, list empty? Yes

    return 0;
}
