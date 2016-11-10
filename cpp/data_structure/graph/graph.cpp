#include "iostream"
#include "map"
#include "set"
#include "stack"
#include "queue"

// bi-directed unweighted graph (simplest form)
class Graph{
private:
    std::map<char, std::set<char> > graph;

public:
    Graph();
    ~Graph();

    void add_vertex(char);
    void add_edge(char, char);
    void delete_vertex(char);
    void delete_edge(char, char);

    bool exists_vertex(char);
    bool exists_edge(char, char);

    void destroy_graph();

    void dfs(char);
    void bfs(char);
};

Graph::Graph() {}
Graph::~Graph() {destroy_graph();}

void Graph::add_vertex(char vertex) {
    std::map<char, std::set<char> >::iterator it = graph.find(vertex);

    if(it != graph.end())
        return;

    std::set<char> v;
    graph[vertex] = v;
}

void Graph::add_edge(char v_1, char v_2) {
    std::map<char, std::set<char> >::iterator it_1 = graph.find(v_1);
    std::map<char, std::set<char> >::iterator it_2 = graph.find(v_2);

    if(it_1 != it_2 && it_1 != graph.end() && it_2 != graph.end()){
        it_1->second.insert(v_2);
        it_2->second.insert(v_1);
    }
}

void Graph::delete_vertex(char vertice) {
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

bool Graph::exists_vertex(char vertice) {
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

// https://www.youtube.com/watch?v=iaBEKo5sM7w
void Graph::dfs(char v) {
    std::stack<char> stack;
    std::map<char, bool> visited_nodes;

    std::map<char, std::set<char> >::iterator it_map;
    std::set<char>::iterator it_set;

    for(it_map=graph.begin(); it_map!=graph.end(); it_map++)
        visited_nodes[it_map->first] = false;

    stack.push(v);
    visited_nodes[v] = true;

    while (!stack.empty()){
        v = stack.top();
        std::cout << v << " ";
        stack.pop();

        for(it_set = graph[v].begin(); it_set!= graph[v].end(); it_set++){
            if(visited_nodes[*it_set] == false){
                visited_nodes[*it_set] = true;
                stack.push(*it_set);
            }
        }
    }
    std::cout << std::endl;
}

// http://www.geeksforgeeks.org/breadth-first-traversal-for-a-graph/
void Graph::bfs(char v) {
    std::queue<char> queue;
    std::map<char, bool> visited_nodes;

    std::map<char, std::set<char> >::iterator it_map;
    std::set<char>::iterator it_set;

    for(it_map=graph.begin(); it_map!=graph.end(); it_map++)
        visited_nodes[it_map->first] = false;

    queue.push(v);
    visited_nodes[v] = true;

    while(!queue.empty()){
        v = queue.front();
        std::cout << v << " ";
        queue.pop();

        for(it_set = graph[v].begin(); it_set != graph[v].end(); it_set++){
            if(visited_nodes[*it_set] == false){
                visited_nodes[*it_set] = true;
                queue.push(*it_set);
            }
        }
    }
    std::cout << std::endl;
}

int main(){

    Graph g;

    g.add_vertex('a');
    std::cout << g.exists_vertex('a') << std::endl;

    g.delete_vertex('a');
    std::cout << g.exists_vertex('a') << std::endl;

    g.add_vertex('a');
    g.add_vertex('b');
    g.add_edge('a', 'b');
    std::cout << g.exists_edge('a', 'b') << std::endl;

    g.dfs('a');
    g.bfs('a');

    g.delete_edge('a', 'b');
    std::cout << g.exists_edge('a', 'b') << std::endl;


    return 0;
}

