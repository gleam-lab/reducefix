#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5 + 5;
vector<int> A[MAXN], B(MAXN);

void solve() {
    int n, q; cin >> n >> q;
    for(int i = 1; i <= n; ++i) {
        int x; cin >> x;
        A[x].push_back(i);
    }
    sort(A.begin(), A.end());
    
    for(int i = 1; i <= q; ++i) {
        int x, k; cin >> x >> k;
        auto it = lower_bound(B.begin(), B.end(), x);
        int idx = it - B.begin();
        int dist = abs(x - B[idx]);
        if(idx > 0 && abs(x - B[idx - 1]) < dist) {
            dist = abs(x - B[--idx]);
        }
        if(idx < n - 1 && abs(x - B[idx + 1]) < dist) {
            dist = abs(x - B[++idx]);
        }
        if(k == 1) {
            cout << dist << '\n';
        } else {
            vector<int> sortedDist;
            for(auto &p : A[B[idx]]) {
                sortedDist.push_back(abs(p - x));
            }
            sort(sortedDist.begin(), sortedDist.end());
            cout << sortedDist[k - 1] << '\n';
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    solve();
    return 0;
}