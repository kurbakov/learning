#include "iostream"
#include "map"
#include "set"

// bi-directed unweighted graph (simplest form)
class Graph{
private:
    std::map<char, std::set<char> > graph;

public:
    Graph();
    ~Graph();

    void add_vertice(char);
    void add_edge(char, char);
    void delete_vertice(char);
    void delete_edge(char, char);

    bool exists_vertice(char);
    bool exists_edge(char, char);

    void destroy_graph();
};

Graph::Graph() {}
Graph::~Graph() {destroy_graph();}

void Graph::add_vertice(char vertice) {
    std::map<char, std::set<char> >::iterator it = graph.find(vertice);

    if(it != graph.end())
        return;

    std::set<char> v;
    graph[vertice] = v;
}

void Graph::add_edge(char v_1, char v_2) {
    std::map<char, std::set<char> >::iterator it_1 = graph.find(v_1);
    std::map<char, std::set<char> >::iterator it_2 = graph.find(v_2);

    if(it_1 != it_2 && it_1 != graph.end() && it_2 != graph.end()){
        it_1->second.insert(v_2);
        it_2->second.insert(v_1);
    }
}

void Graph::delete_vertice(char vertice) {
    std::map<char, std::set<char> >::iterator it = graph.find(vertice);

    if(it == graph.end())
        return;

    graph.erase(it);
}

void Graph::delete_edge(char v_1, char v_2) {

    if(!exists_edge(v_1, v_2))
        return;

    std::map<char, std::set<char> >::iterator it_map;
    std::set<char>::iterator it_set;

    // delete v_2 from v_1
    it_map = graph.find(v_1);
    it_set = it_map->second.find(v_2);

    it_map->second.erase(it_set);

    // delete v_1 from v_2
    it_map = graph.find(v_2);
    it_set = it_map->second.find(v_1);

    it_map->second.erase(it_set);
}

bool Graph::exists_vertice(char vertice) {
    std::map<char, std::set<char> >::iterator it;

    it = graph.find(vertice);
    if(it == graph.end())
        return false;

    return true;
}

bool Graph::exists_edge(char v_1, char v_2) {
    bool cond1 = false, cond2 = false;

    if(graph[v_1].find(v_2) != graph[v_1].end())
        cond1 = true;

    if(graph[v_2].find(v_1) != graph[v_2].end())
        cond2 = true;

    if(cond1 == true && cond2 == true)
        return true;

    return false;
}

void Graph::destroy_graph() {
    std::map<char, std::set<char> >::iterator it;
    for(it=graph.begin(); it != graph.end(); it++){
        it->second.clear();
    }

    graph.clear();
}


int main(){

    Graph g;

    g.add_vertice('a');
    std::cout << g.exists_vertice('a') << std::endl;

    g.delete_vertice('a');
    std::cout << g.exists_vertice('a') << std::endl;

    g.add_vertice('a');
    g.add_vertice('b');
    g.add_edge('a', 'b');
    std::cout << g.exists_edge('a', 'b') << std::endl;

    g.delete_edge('a', 'b');
    std::cout << g.exists_edge('a', 'b') << std::endl;


    return 0;
}

