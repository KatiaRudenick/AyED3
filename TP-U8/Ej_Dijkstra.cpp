#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <climits>

using namespace std;

//representa una arista en el grafo
struct Edge {
    int to;
    int weight;
};

// Implementacion del algoritmo de Dijkstra
vector<int> dijkstra(int start, const unordered_map<int, vector<Edge>>& graph, int n) {
    vector<int> distances(n, INT_MAX);  // Distancias iniciales
    distances[start] = 0;
    
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, start});  // {distancia, nodo}

    while (!pq.empty()) {
        int dist = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (dist > distances[u]) continue;

        for (const Edge& edge : graph.at(u)) {
            int v = edge.to;
            int weight = edge.weight;

            if (distances[u] + weight < distances[v]) {
                distances[v] = distances[u] + weight;
                pq.push({distances[v], v});
            }
        }
    }

    return distances;
}

int main() {
    // Representa grafo como lista de adyacencia
    unordered_map<int, vector<Edge>> graph;
    
    // Mapeo de nodos
    unordered_map<char, int> node_map = {{'A', 0}, {'B', 1}, {'C', 2}, {'D', 3},
                                         {'E', 4}, {'F', 5}, {'G', 6}, {'H', 7}};
    
    // Agrega aristas al grafo
    graph[node_map['A']].push_back({node_map['B'], 3});
    graph[node_map['A']].push_back({node_map['C'], 5});
    graph[node_map['A']].push_back({node_map['H'], 10});
    graph[node_map['B']].push_back({node_map['A'], 3});
    graph[node_map['B']].push_back({node_map['C'], 5});
    graph[node_map['B']].push_back({node_map['D'], 8});
    graph[node_map['B']].push_back({node_map['E'], 6});
    graph[node_map['B']].push_back({node_map['G'], 12});
    graph[node_map['C']].push_back({node_map['A'], 5});
    graph[node_map['C']].push_back({node_map['B'], 5});
    graph[node_map['C']].push_back({node_map['F'], 7});
    graph[node_map['C']].push_back({node_map['E'], 4});
    graph[node_map['D']].push_back({node_map['B'], 8});
    graph[node_map['D']].push_back({node_map['G'], 3});
    graph[node_map['D']].push_back({node_map['H'], 14});
    graph[node_map['E']].push_back({node_map['B'], 6});
    graph[node_map['E']].push_back({node_map['C'], 4});
    graph[node_map['E']].push_back({node_map['F'], 1});
    graph[node_map['E']].push_back({node_map['G'], 9});
    graph[node_map['F']].push_back({node_map['C'], 7});
    graph[node_map['F']].push_back({node_map['E'], 1});
    graph[node_map['G']].push_back({node_map['B'], 12});
    graph[node_map['G']].push_back({node_map['D'], 3});
    graph[node_map['G']].push_back({node_map['E'], 9});
    graph[node_map['G']].push_back({node_map['H'], 9});
    graph[node_map['H']].push_back({node_map['A'], 10});
    graph[node_map['H']].push_back({node_map['D'], 14});
    graph[node_map['H']].push_back({node_map['G'], 9});
    
    int start = node_map['A'];  // Nodo inicial
    int n = 8;  // Nro total de nodos

    // Algoritmo Dijkstra desde el nodo inicial
    vector<int> distances = dijkstra(start, graph, n);

    //distancias desde el nodo inicial
    for (const auto& pair : node_map) {
        cout << "Distancia desde A hasta " << pair.first << ": " << distances[pair.second] << endl;
    }

    return 0;
}
