#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

const int MAXN = 2e5 + 5;
vector<int> adj[MAXN];
bool visited[MAXN], recStack[MAXN];

// Function to detect cycle using DFS
bool detectCycleUtil(int u, int parent) {
    visited[u] = true;
    recStack[u] = true;

    for (auto v : adj[u]) {
        if (!visited[v]) {
            if (detectCycleUtil(v, u))
                return true;
        } else if (v != parent && recStack[v])
            return true;
    }

    recStack[u] = false;
    return false;
}

// Function to find the minimum cycle length containing node 1
int findMinCycle() {
    memset(visited, false, sizeof(visited));
    memset(recStack, false, sizeof(recStack));

    for (int i = 1; i <= 2 * MAXN; ++i) {
        if (!visited[i] && detectCycleUtil(i, -1))
            return i;
    }

    return -1;
}

int main() {
    int N, M;
    cin >> N >> M;

    for (int i = 0; i < M; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    int result = findMinCycle();

    if (result != -1) {
        cout << result << endl;
    } else {
        cout << "-1" << endl;
    }

    return 0;
}