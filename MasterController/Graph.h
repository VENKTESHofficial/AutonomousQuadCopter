#ifndef GRAPH_H
#define GRAPH_H

template <class T>
class Graph {
public:
    Graph();
    Graph(const Graph& orig);
    virtual ~Graph();
    
    Node* GetInitNode();
    Node** GetNodeContainer();
    uint8_t SPFS();
    uint8_t BFS();
    uint8_t DFS();
    uint8_t GenerateTree();
private:
    Node* init_node_;
    Node** node_container_;
};

#endif /* GRAPH_H */

