#include <iostream>
#include <queue>
#include <stack>
#include <vector>

class CGraph {
 public:
  CGraph(int n) { _graph.reserve(n); }

  void add_edge(int a, int b) {
    if (a >= _graph.size() || b >= _graph.size())
      return;

    add_edge_if_not_exiss(a, b);
    add_edge_if_not_exiss(b, a);
  }

  void bfs(int n = 0) {
    if (n >= _graph.size())
      return;

    std::vector<bool> visited(_graph.size(), false);

    std::queue<int> q;
    q.push(n);

    while (!q.empty()) {
      int vertex = q.front();
      q.pop();

      std::cout << "Vist: " << vertex << std::endl;

      visited[vertex] = true;
      for (const auto& v : _graph[vertex])
        if (!visited[vertex])
          q.push(v);
    }
  }

  void dfs(int n = 0) {
    if (n >= _graph.size())
      return;

    std::vector<bool> visited(_graph.size(), false);

    std::stack<int> s;
    s.push(n);
    while (!s.empty()) {
      int vertex = s.top();
      s.pop();

      visited[vertex] = true;
      for (const auto& v : _graph[vertex])
        if (!visited[v])
          s.push(v);
    }
  }

  void topological_sort(int n = 0) {}

 private:
  void add_edge_if_not_exiss(int vertex1, int vertex2) {
    for (const auto& v : _graph[vertex1])
      if (v == vertex2)
        return;

    _graph[vertex1].push_back(vertex2);
  }

  std::vector<std::vector<int>> _graph;
};

int main(int argc, char* argv[]) {
  std::cout << "hello graph" << std::endl;
  return 0;
}
