#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> as; // as[i] will store the top 10 largest vertices in the component of i
vector<int> fa;

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

    for (int i = 1; i <= n; i++) {
        fa[i] = i;
        as[i].push_back(i); // Initially, each vertex is its own component with itself as the top element
    }

    while (q--) {
        int op, ix, iy;
        cin >> op >> ix >> iy;

        if (op == 1) {
            int u = gtf(ix);
            int v = gtf(iy);
            if (u != v) {
                vector<int> merged;
                int i = 0, j = 0;
                // Merge the two sorted lists in descending order
                while ((i < as[u].size() || j < as[v].size()) && merged.size() < 10) {
                    int a = (i < as[u].size()) ? as[u][i] : -1;
                    int b = (j < as[v].size()) ? as[v][j] : -1;
                    if (a > b) {
                        merged.push_back(a);
                        i++;
                    } else if (b != -1) {
                        merged.push_back(b);
                        j++;
                    } else {
                        break;
                    }
                }
                fa[v] = u;
                as[u] = merged;
            }
        } else {
            int v = gtf(ix);
            if (iy <= as[v].size()) {
                cout << as[v][iy - 1] << '\n';
            } else {
                cout << -1 << '\n';
            }
        }
    }

    return 0;
}