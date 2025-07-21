#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1005;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    int H, W, Y;
    cin >> H >> W >> Y;
    vector<vector<int>> A(H, vector<int>(W));
    for(int i = 0; i < H; ++i)
        for(int j = 0; j < W; ++j)
            cin >> A[i][j];
    
    // Union-Find structure to manage connected components
    vector<int> parent(MAXN * MAXN), rank(MAXN * MAXN, 1);
    iota(parent.begin(), parent.end(), 0);

    auto find = [&](int u) -> int {
        return parent[u] == u ? u : parent[u] = find(parent[u]);
    };

    auto unite = [&](int u, int v) -> bool {
        int pu = find(u), pv = find(v);
        if(pu == pv) return false;
        if(rank[pu] > rank[pv]) swap(pu, pv);
        parent[pu] = pv;
        rank[pv] += rank[pu];
        return true;
    };

    vector<int> areas(Y + 1, H * W);
    queue<int> q;
    vector<vector<bool>> seen(H, vector<bool>(W));

    for(int t = 1; t <= Y; ++t) {
        for(int i = 0; i < H; ++i) {
            for(int j = 0; j < W; ++j) {
                if(A[i][j] <= t && !seen[i][j]) {
                    seen[i][j] = true;
                    q.push(i * W + j);
                }
            }
        }

        while(!q.empty()) {
            int u = q.front(); q.pop();
            int i = u / W, j = u % W;
            for(auto [di, dj]: {{-1, 0}, {1, 0}, {0, -1}, {0, 1}}) {
                int ni = i + di, nj = j + dj;
                if(ni >= 0 && ni < H && nj >= 0 && nj < W && A[ni][nj] <= t && !seen[ni][nj]) {
                    seen[ni][nj] = true;
                    q.push(ni * W + nj);
                    unite(u, ni * W + nj);
                }
            }
        }

        unordered_set<int> components;
        for(int i = 0; i < H; ++i) {
            for(int j = 0; j < W; ++j) {
                if(A[i][j] <= t && !components.count(find(i * W + j))) {
                    components.insert(find(i * W + j));
                }
            }
        }

        int totalArea = 0;
        for(auto c: components) {
            totalArea += rank[c];
        }

        areas[t] = totalArea;
    }

    for(int t = 1; t <= Y; ++t)
        cout << areas[t] << '\n';

    return 0;
}