#include "iostream"
#include "map"

// directed weighted graph (simplest form)
class Graph{
private:
    std::map<char, std::map<char, int> > graph;

public:
    Graph();
    ~Graph();

    void add_vertex(char);
    void add_edge(char, char, int);
    void delete_vertex(char);
    void delete_edge(char, char);

    bool exists_vertex(char);
    bool exists_edge(char, char);

    void destroy_graph();
};

Graph::Graph() {}
Graph::~Graph() {destroy_graph();}

void Graph::add_vertex(char vertex) {
    std::map<char, std::map<char, int> >::iterator it = graph.find(vertex);

    if(it != graph.end())
        return;

    std::map<char, int> v;
    graph[vertex] = v;
}

void Graph::add_edge(char from, char to, int weight) {
    std::map<char, std::map<char, int> >::iterator it_1 = graph.find(from);
    std::map<char, std::map<char, int> >::iterator it_2 = graph.find(to);

    if(it_1 != it_2 && it_1 != graph.end() && it_2 != graph.end()){
        it_1->second[to] = weight;
    }
}

void Graph::delete_vertex(char vertice) {
    std::map<char, std::map<char, int> >::iterator it = graph.find(vertice);

    if(it == graph.end())
        return;

    graph.erase(it);
}

void Graph::delete_edge(char v_1, char v_2) {

    if(!exists_edge(v_1, v_2))
        return;

    std::map<char, std::map<char, int> >::iterator it_map;
    std::map<char, int>::iterator it_map2;

    // delete v_2 from v_1
    it_map = graph.find(v_1);
    it_map2 = it_map->second.find(v_2);

    it_map->second.erase(it_map2);
}

bool Graph::exists_vertex(char vertice) {
    std::map<char, std::map<char, int> >::iterator it;

    it = graph.find(vertice);
    if(it == graph.end())
        return false;

    return true;
}

bool Graph::exists_edge(char v_1, char v_2) {
    if(graph[v_1].find(v_2) != graph[v_1].end())
        return true;

    return false;
}

void Graph::destroy_graph() {
    std::map<char, std::map<char, int> >::iterator it;
    for(it=graph.begin(); it != graph.end(); it++){
        it->second.clear();
    }

    graph.clear();
}


int main(){

    Graph g;

    g.add_vertex('a');
    std::cout << g.exists_vertex('a') << std::endl;

    g.delete_vertex('a');
    std::cout << g.exists_vertex('a') << std::endl;

    g.add_vertex('a');
    g.add_vertex('b');
    g.add_edge('a', 'b', 1);
    std::cout << g.exists_edge('a', 'b') << std::endl;
    std::cout << g.exists_edge('b', 'a') << std::endl;

    g.delete_edge('a', 'b');
    std::cout << g.exists_edge('a', 'b') << std::endl;


    return 0;
}

