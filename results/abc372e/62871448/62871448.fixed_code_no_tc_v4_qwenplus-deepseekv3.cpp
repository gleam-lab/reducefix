#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> as; // as[i] will store the top 10 largest vertices in the set of i, sorted in descending order
vector<int> fa; // parent array for union-find

int gtf(int x) {
    if (x == fa[x]) return x;
    return fa[x] = gtf(fa[x]);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;
    
    fa.resize(n + 1);
    as.resize(n + 1);

    for (int i = 1; i <= n; ++i) {
        fa[i] = i;
        as[i].push_back(i); // Initially, each vertex is its own set with itself as the only element
    }

    while (q--) {
        int op, u, v, k;
        cin >> op;
        if (op == 1) {
            cin >> u >> v;
            int fu = gtf(u);
            int fv = gtf(v);
            if (fu != fv) {
                // Merge the two sets, keeping the top 10 largest elements
                vector<int> merged;
                int i = 0, j = 0;
                while ((i < as[fu].size() || j < as[fv].size()) && merged.size() < 10) {
                    if (i < as[fu].size() && (j >= as[fv].size() || as[fu][i] >= as[fv][j])) {
                        merged.push_back(as[fu][i]);
                        ++i;
                    } else {
                        merged.push_back(as[fv][j]);
                        ++j;
                    }
                }
                as[fu] = merged;
                fa[fv] = fu;
            }
        } else {
            cin >> v >> k;
            int fv = gtf(v);
            if (k > as[fv].size()) {
                cout << "-1\n";
            } else {
                cout << as[fv][k - 1] << "\n";
            }
        }
    }

    return 0;
}