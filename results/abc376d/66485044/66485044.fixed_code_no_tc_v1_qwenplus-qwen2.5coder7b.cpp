#include<bits/stdc++.h>
#define INF 0x3f3f3f3f3f3f3f3f
using namespace std;
typedef long long ll;
const int MAXN = 2e5 + 10;
vector<int> vec[MAXN]; // Changed from ll to int as we don't need large numbers here
queue<int> q; // Changed from ll to int for consistency with vector indices
int step[MAXN];
bool vis[MAXN];

int main() {
    int n, m, u, v;
    scanf("%d %d", &n, &m); // Changed from ll to int for better readability and performance
    for (int i = 0; i < m; i++) { // Changed loop index type from ll to int
        scanf("%d %d", &u, &v); // Changed from ll to int
        vec[u].push_back(v);
    }
    q.push(1);
    step[1] = 0; // Initialize starting node's step to 0
    vis[1] = true; // Mark starting node as visited
    while (!q.empty()) {
        int top = q.front();
        q.pop();
        for (int i = 0; i < vec[top].size(); i++) {
            int to = vec[top][i];
            if (to == 1) {
                printf("%d\n", step[top] + 1); // Correctly print the result
                return 0;
            }
            if (!vis[to]) {
                step[to] = step[top] + 1;
                vis[to] = true; // Mark the next node as visited
                q.push(to);
            }
        }
    }
    printf("-1\n"); // Correctly print -1 if no path found
    return 0;
}