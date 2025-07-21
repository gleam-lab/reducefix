#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int INF = 1e18;
const int MAXN = 2e5 + 10;
vector<int> vec[MAXN];
int step[MAXN] = {INF};

void BFS(int start) {
    queue<int> q;
    q.push(start);
    step[start] = 0;

    while (!q.empty()) {
        int current = q.front();
        q.pop();

        for (int neighbor : vec[current]) {
            if (step[neighbor] == INF) { // Unvisited node
                step[neighbor] = step[current] + 1;
                q.push(neighbor);
            }
        }
    }
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        vec[u].push_back(v);
    }

    BFS(1);

    for (int i = 1; i <= n; i++) {
        if (step[i] == INF) {
            cout << "-1";
        } else {
            cout << step[i];
        }
    }

    return 0;
}