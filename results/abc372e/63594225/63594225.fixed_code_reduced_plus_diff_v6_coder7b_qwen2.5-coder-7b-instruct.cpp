#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int MAXN = 2 * 100000 + 5;

vector<int> adj[MAXN];
priority_queue<int, vector<int>, greater<int>> pq[MAXN];

void addEdge(int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
    pq[u].push(v);
    pq[v].push(u);
}

void updatePQ(int node, int removedNode) {
    pq[node].pop();
    pq[node].push(removedNode);
}

int findKthLargest(int node, int k) {
    if (pq[node].size() < k) {
        return -1;
    } else {
        priority_queue<int, vector<int>, greater<int>> tempPQ = pq[node];
        for (int i = 1; i < k; ++i) {
            tempPQ.pop();
        }
        return tempPQ.top();
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    cin >> n >> q;

    for (int i = 1; i <= n; ++i) {
        addEdge(i, i); // Self-loop to handle single element case
    }

    while (q--) {
        int type, u, v;
        cin >> type >> u >> v;

        if (type == 1) {
            addEdge(u, v);
        } else {
            cout << findKthLargest(u, v) << endl;
        }
    }

    return 0;
}