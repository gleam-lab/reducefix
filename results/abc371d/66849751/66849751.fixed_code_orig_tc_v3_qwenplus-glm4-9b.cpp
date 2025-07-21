#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;

#define rep(i, n) for (int i = 0; i < (n); ++i)
#define all(x) (x).begin(), (x).end()
#define pb(a) push_back(a)
#define Yes(b) cout << ((b) ? "Yes\n" : "No\n")
#define YES(b) cout << ((b) ? "YES\n" : "NO\n")

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {
    int N;
    cin >> N;
    vector<int> X(N);
    rep(i, N) cin >> X[i];
    vector<ll> P(N + 1, 0);
    rep(i, N) cin >> P[i + 1];
    for (int i = 0; i <= N; ++i) P[i] += P[i - 1];  // Compute prefix sums

    map<int, vector<int>> x_to_ptr;
    for (int i = 0; i < N; ++i) {
        x_to_ptr[X[i]].push_back(i);
    }

    int Q;
    cin >> Q;
    rep(q, Q) {
        int L, R;
        cin >> L >> R;
        vector<int> l, r;
        for (auto& p : x_to_ptr) {
            if (p.first >= L && p.first <= R) {
                l.insert(l.end(), p.second.begin(), p.second.end());
                r.insert(r.end(), p.second.begin(), p.second.end());
            }
        }
        if (l.empty()) {
            l.push_back(N);
        } else {
            l.push_back(l.back() + 1);
        }
        if (r.empty()) {
            r.push_back(N + 1);
        } else {
            r.push_back(r.back() + 1);
        }
        cout << P[r[0]] - P[l[0]] << endl;
    }
}