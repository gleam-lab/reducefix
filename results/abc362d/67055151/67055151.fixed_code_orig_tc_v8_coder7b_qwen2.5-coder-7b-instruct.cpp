#include <bits/stdc++.h>
using namespace std;

#define forn(i, n) for(int i = 0; i < n; ++i)
#define fora(i, a, n) for(int i = a; i < n; ++i)
#define ford(i, n) for(int i = n - 1; i >= 0; --i)
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define sz(a) ((int)a.size())

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vpi;

const int INF = 1e9;

struct Edge {
    int to, weight;
    Edge(int _to, int _weight) : to(_to), weight(_weight) {}
};

struct Node {
    int id, dist;
    Node(int _id, int _dist) : id(_id), dist(_dist) {}
    bool operator<(const Node& other) const {
        return dist > other.dist;
    }
};

vector<vector<Edge>> adjList;
vector<int> distTo;

void dijkstra(int start) {
    distTo.resize(adjList.size(), INF);
    distTo[start] = 0;
    priority_queue<Node> pq;
    pq.push(Node(start, 0));

    while(!pq.empty()) {
        Node u = pq.top(); pq.pop();
        if(u.dist != distTo[u.id]) continue;
        for(auto& edge : adjList[u.id]) {
            int v = edge.to, weight = edge.weight;
            if(distTo[v] > distTo[u.id] + weight) {
                distTo[v] = distTo[u.id] + weight;
                pq.push(Node(v, distTo[v]));
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    adjList.resize(n);
    forn(i, m) {
        int u, v, w;
        cin >> u >> v >> w;
        --u; --v;
        adjList[u].pb(Edge(v, w));
        adjList[v].pb(Edge(u, w));
    }

    vector<int> result;
    dijkstra(0);
    forn(i, n - 1) {
        result.pb(distTo[i + 1]);
    }

    for(auto &x : result) cout << x << " ";

    return 0;
}