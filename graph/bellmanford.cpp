#include <algorithm>
#include <iostream>

struct Edge {int from, to, cost; };
const int MAX_V = 100, MAX_E = 1000;
Edge edge[MAX_E];
int V, E, dist[MAX_V];
bool update = true;

// 蟻本 P.95
void bellmanford(int s) {
  for(int k=0; k<V; k++) {
    update = false;
    for (int i=0; i<E; i++) {
      Edge e = edge[i];
      if (dist[e.from] != INT_MAX && dist[e.from] + e.cost < dist[e.to]) {
        dist[e.to] = dist[e.from] + e.cost;
        update = true;
      }
    }
  }
}

int shortestPath(int s) {
  std::fill(dist, dist+V, INT_MAX);
  dist[s] = 0;
  bellmanford(s);
  return dist[V-1];
}

bool find_negative_loop(int s) {
  std::fill(dist, dist+V, 0);
  bellmanford(s);
  return update;
}