#include "Node.h"

template <class U>
Node<U>::Node() {

}

template <class U>
Node<U>::Node(const Node& orig) {

}

template <class U>
Node<U>::~Node() {

}

template <class U>
// alphabetically sorted neighbor nodes
Node* Node<U>::operator[](uint8_t ind) {
    return neighbor_nodes_[ind];
}

template <class U>
Node** Node<U>::GetNeighborNodes() {
    return neighbor_nodes_;
}

template <class U>
U Node<U>::GetOverallVal() {
    return overall_val_;
}

// neighbor node selector via criteria

template <class U>
uint8_t Node<U>::operator()() {
    return 0;
}

// depth-first search
// step back search(temp node generation)

template <class U>
uint8_t Node<U>::GenerateNextNode() {
    return 0;
}