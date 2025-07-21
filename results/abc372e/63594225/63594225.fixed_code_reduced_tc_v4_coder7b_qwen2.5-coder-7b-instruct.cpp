#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

const int MAX_N = 2 * 100005;

vector<set<int>> adjList(MAX_N);
vector<set<int>> sortedAdjList(MAX_N);

void addEdge(int u, int v) {
    adjList[u].insert(v);
    adjList[v].insert(u);
    
    // Update sorted adjacency lists
    sortedAdjList[u].insert(v);
    sortedAdjList[v].insert(u);
    
    // Remove excess elements to keep at most 10 elements
    if (sortedAdjList[u].size() > 10) {
        sortedAdjList[u].erase(prev(sortedAdjList[u].end()));
    }
    if (sortedAdjList[v].size() > 10) {
        sortedAdjList[v].erase(prev(sortedAdjList[v].end()));
    }
}

int getKthLargest(int v, int k) {
    if (k > sortedAdjList[v].size()) {
        return -1;
    }
    return *next(sortedAdjList[v].begin(), k - 1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    while (q--) {
        int t, u, v;
        cin >> t >> u >> v;

        if (t == 1) {
            addEdge(u, v);
        } else {
            cout << getKthLargest(u, v) << '\n';
        }
    }

    return 0;
}