#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define vi vector<int>
#define vl vector<ll>
#define vd vector<double>
#define vb vector<bool>
#define vs vector<string>
#define vc vector<char>
#define ull unsigned long long

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, q;
    cin >> n >> q;

    vl a(n), b(q);
    vl k(q);

    rep(i, n) cin >> a[i];
    rep(j, q) {
        cin >> b[j] >> k[j];
    }

    multiset<ll> dists;
    rep(i, n) {
        dists.insert(abs(a[i]));
    }

    rep(j, q) {
        auto it = dists.begin();
        advance(it, k[j] - 1);
        cout << *it << '\n';
    }

    return 0;
}