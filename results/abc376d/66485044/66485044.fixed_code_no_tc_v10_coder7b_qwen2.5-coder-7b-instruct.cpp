#include<bits/stdc++.h>
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
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &u, &v);
        vec[u].push_back(v);
        vec[v].push_back(u); // Assuming undirected graph
    }
    q.push(1);
    step[1] = 0;
    vis[1] = true;
    while (!q.empty()) {
        int top = q.front();
        q.pop();
        for (int i = 0; i < vec[top].size(); i++) {
            int to = vec[top][i];
            if (to == 1 && top != 1) {
                printf("%d\n", step[top]);
                return 0;
            } else if (to == 1) {
                printf("0\n");
                return 0;
            }
            if (!vis[to]) {
                step[to] = step[top] + 1;
                vis[to] = true;
                q.push(to);
            }
        }
    }
    printf("-1\n");
    return 0;
}