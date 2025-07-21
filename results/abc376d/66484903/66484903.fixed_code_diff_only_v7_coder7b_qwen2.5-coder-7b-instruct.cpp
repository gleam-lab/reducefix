#include<bits/stdc++.h>
#define INF 0x3f3f3f3f3f3f3f3f
using namespace std;
typedef long long ll;
const int MAXN = 2e5 + 10;
vector<int> vec[MAXN]; // Changed vector type from ll to int as node indices are integers
queue<int> q; // Changed queue type from ll to int
int step[MAXN];
bool vis[MAXN];

int main() {
    int n, m, u, v;
    scanf("%d %d", &n, &m); // Changed ll to int for input types
    for (int i = 1; i <= m; i++) {
        scanf("%d %d", &u, &v); // Changed ll to int for input types
        vec[u].push_back(v);
    }
    q.push(1);
    step[1] = 0; // Initialize start node distance to 0
    while (!q.empty()) {
        int top = q.front();
        vis[top] = true;
        q.pop();
        for (int i = 0; i < vec[top].size(); i++) {
            int to = vec[top][i];
            if (to == 1) {
                printf("%d\n", step[top] + 1); // Print result and add newline
                return 0;
            }
            if (!vis[to]) {
                step[to] = step[top] + 1;
                q.push(to);
            }
        }
    }
    printf("-1\n"); // Print -1 and add newline if no path found
    return 0;
}