#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define vi vector<int>
#define vl vector<ll>

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q; cin >> n >> q;
    vl a(n), b(q), k(q);

    rep(i, n) cin >> a[i];
    rep(j, q) cin >> b[j] >> k[j];

    sort(a.begin(), a.end());

    rep(j, q) {
        auto it = lower_bound(a.begin(), a.end(), b[j]);
        int dist = abs(*it - b[j]);

        if(it != a.begin()) {
            int prevDist = abs(*(it - 1) - b[j]);
            if(prevDist <= dist) {
                dist = prevDist;
                --it;
            }
        }

        rep(l, k[j] - 1) {
            if(it == a.begin()) break;
            --it;
            dist = min(dist, abs(*it - b[j]));
        }

        rep(r, k[j] - 1) {
            ++it;
            if(it == a.end()) break;
            dist = min(dist, abs(*it - b[j]));
        }

        cout << dist << '\n';
    }

    return 0;
}