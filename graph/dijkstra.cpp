// 蟻本P.98

#include <queue>
using namespace std;
typedef pair<int, int> P;

struct Edge { int from, to, cost;};

const int MAX_N = 5000;
int N, dist[MAX_N];
vector<Edge> G[MAX_N];
priority_queue<P, vector<P>, greater<P> > que;

void dijkstra(int s) {
  fill(dist, dist + N, INT_MAX);
  dist[s] = 0;
  que.push(P(0, s));

  while (que.size()) {
    P p = que.top();
    que.pop();
    int V = p.second;
    if (dist[V] < p.first) continue;
    for (int i=0; i<G[V].size(); i++) {
      Edge e = G[V][i];
      int d = dist[e.from] + e.cost;
      if (d < dist[e.to]) {
        dist[e.to] = d;
        que.push(P(dist[e.to], e.to));
      }
    }
  }
}