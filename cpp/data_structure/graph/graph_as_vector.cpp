#include <iostream>
#include "vector"

// Graph as a vector of vectors
class Graph{
private:
    std::vector<std::vector<int> > graph;

public:
    Graph(int);

    void add_vertices();
    void delete_vertices(int);
    void add_edge(int, int);
    void delete_edge(int, int);

    int get_size();
    void print();
};

Graph::Graph(int x) {

    std::vector<int> temp;
    for(int i=0;i<x;i++)
        graph.push_back(temp);
}

void Graph::add_vertices() {
    std::vector<int> temp;
    graph.push_back(temp);
}

void Graph::delete_vertices(int x) {
    if(graph.size()>x)
        graph.erase(graph.begin()+x);
}

void Graph::add_edge(int from, int to) {
    if(from < graph.size() && to < graph.size()){
        graph[from].push_back(to);
    }
}

void Graph::delete_edge(int from, int to) {
    if(from < graph.size() && to < graph.size()){
        int position = -1;

        for(unsigned int i=0; i<graph[from].size(); i++)
            if(graph[from][i] == to)
                position = i;

        if(position != -1)
            graph[from].erase(graph[from].begin()+position);
    }
}

int Graph::get_size() {
    return int (graph.size());
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

    g.add_edge(0,2);
    g.add_edge(0,3);

    g.add_edge(1,2);
    g.add_edge(1,4);

    g.add_edge(2,0);
    g.add_edge(2,4);

    g.add_edge(3,1);

    g.add_edge(4,0);

    g.print();
}
