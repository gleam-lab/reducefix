#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

const int N = 200000;

vector<int> graph[N];

int findKthLargest(int node, int k) {
    // Convert graph of node to a sorted set to find k-th largest
    set<int> adjNodes(graph[node].begin(), graph[node].end());
    if (k > adjNodes.size()) return -1; // Not enough nodes
    // Retrieve the k-th largest element
    return *(prev(adjNodes.end(), k - 1)); // prev gives us the iterator to k-th largest
}

int main() {
    int n, q;
    cin >> n >> q;

    while (q--) {
        int type;
        cin >> type;

        if (type == 1) {
            int u, v;
            cin >> u >> v;
            // Since the graph is undirected, add both u->v and v->u
            graph[u].push_back(v);
            graph[v].push_back(u);
        } else {
            int v, k;
            cin >> v >> k;
            // Output the k-th largest vertex connected to vertex v
            cout << findKthLargest(v, k) << endl;
        }
    }

    return 0;
}