#include "bst.h"

int main() {
    TBinarySearchTree<int, int> bst;
    bst.Insert(10, 10);
    bst.Insert(12, 12);
    bst.Insert(9,9);
    bst.Insert(99, 99);
    bst.Insert(59, 59);
    bst.Insert(61, 61);
    bst.Insert(69, 69);
    bst.Insert(45, 45);
    std::cout << bst << std::endl;
    bst.Remove(59);
    bst.Remove(10);
    std::cout << bst << std::endl;
    std::cout << bst.Find(69) << std::endl;
    std::cout << bst.Find(99) << std::endl;
    return 0;
}
