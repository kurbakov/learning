#include <iostream>
#include "vector"

// Graph as a vector of vectors
class Graph{
private:
    std::vector<std::vector<int> > graph;

public:
    Graph(int);

    void add_edge(int, int, int);
    void delete_edge(int, int);

    void print();
};

Graph::Graph(int x) {

    std::vector<int> temp(x,0);
    for(int i=0;i<x;i++)
        graph.push_back(temp);
}

void Graph::add_edge(int from, int to, int weight) {
    if(from < graph.size() && to < graph.size()){
        graph[from][to] = weight;
    }
}

void Graph::delete_edge(int from, int to) {
    if(from < graph.size() && to < graph.size()){
        graph[from][to] = 0;
    }
}

void Graph::print() {
    for(unsigned int i=0; i<graph.size(); i++){
        std::cout << "Edge: " << i << ":   ";
        for(unsigned int j=0; j<graph[i].size(); j++)
            std::cout << graph[i][j] << " ";
        std::cout << std::endl;
    }
}

int main(){
    Graph g(5);

    g.add_edge(0,1,10);
    g.add_edge(1,2,10);
    g.add_edge(2,3,10);
    g.add_edge(3,4,10);

    g.print();
}
