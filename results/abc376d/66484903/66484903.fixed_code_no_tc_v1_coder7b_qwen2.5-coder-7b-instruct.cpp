#include <bits/stdc++.h>
#define INF 0x3f3f3f3f3f3f3f3f
using namespace std;

typedef long long ll;
const int MAXN = 2e5 + 10;

vector<int> vec[MAXN];
queue<int> q;
int step[MAXN];
bool vis[MAXN];

int main() {
    int n, m, u, v;
    scanf("%d %d", &n, &m);
    
    for (int i = 1; i <= m; i++) {
        scanf("%d %d", &u, &v);
        vec[u].push_back(v);
    }

    // Initialize queue with all nodes connected directly to node 1
    for (int i = 1; i <= n; i++) {
        if (find(vec[i].begin(), vec[i].end(), 1) != vec[i].end()) {
            q.push(i);
            vis[i] = true;
            step[i] = 1;
        }
    }

    while (!q.empty()) {
        int top = q.front();
        q.pop();

        for (int to : vec[top]) {
            if (!vis[to]) {
                vis[to] = true;
                step[to] = step[top] + 1;
                q.push(to);
            } else if (to == 1 && step[to] > step[top]) {
                printf("%d\n", step[top] + step[to]);
                return 0;
            }
        }
    }

    printf("-1\n");
    return 0;
}