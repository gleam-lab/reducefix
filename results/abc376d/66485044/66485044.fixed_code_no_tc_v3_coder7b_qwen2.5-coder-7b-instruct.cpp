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
    for(int i = 0; i < m; i++) {
        scanf("%d %d", &u, &v);
        vec[u].push_back(v);
    }

    // Initialize all steps to -1 indicating unvisited nodes
    memset(step, -1, sizeof(step));
    q.push(1);
    step[1] = 0;

    while (!q.empty()) {
        int top = q.front();
        q.pop();

        for (int i = 0; i < vec[top].size(); i++) {
            int to = vec[top][i];
            if (step[to] != -1) {  // If we've visited this node before
                int cycleLength = step[top] - step[to] + 1;
                printf("%d\n", cycleLength);
                return 0;
            } else if (!vis[to]) {
                step[to] = step[top] + 1;
                q.push(to);
                vis[to] = true;
            }
        }
    }

    printf("-1\n");
    return 0;
}