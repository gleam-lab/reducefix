#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<ll>

vector<ll> a;

void preprocess() {
    sort(a.begin(), a.end());
}

ll query(ll k) {
    auto it = upper_bound(a.begin(), a.end(), k);
    return it - a.begin();
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    ll n, q; cin >> n >> q;
    a.resize(n);
    for(ll& ai : a) cin >> ai;

    preprocess();

    for(ll j = 0; j < q; ++j) {
        ll bj, kj; cin >> bj >> kj;
        --kj; // Convert to 0-based index
        ll dist = abs(bj - a[kj]);
        cout << dist * (kj + 1) << '\n';
    }

    return 0;
}