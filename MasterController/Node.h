#ifndef NODE_H
#define NODE_H

template <class U>
class Node {
    Node();
    Node(const Node& orig);
    virtual ~Node();
    // alphabetically sorted neighbor nodes
    Node* operator[](uint8_t ind);
    Node** GetNeighborNodes();
    U GetOverallVal();
    // neighbor node selector via criteria
    uint8_t operator()();
    // depth-first search
    // step back search(temp node generation)
    uint8_t GenerateNextNode();
private:
    // aggregated overall value
    U overall_val_;

    // alphabetically sorted neighbor nodes
    Node** neighbor_nodes_;

    uint16_t genenerated_node_stack_;
    Node** generated_node_stack_;
};

#endif /* NODE_H */

