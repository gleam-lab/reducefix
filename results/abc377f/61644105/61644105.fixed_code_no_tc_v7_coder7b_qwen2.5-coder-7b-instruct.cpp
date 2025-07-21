#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll n, m;
vector<pair<ll, ll>> pieces;

bool isValid(ll x, ll y) {
    for(auto& [px, py] : pieces) {
        if(px == x || py == y || px + py == x + y || px - py == x - y) return false;
    }
    return true;
}

int main() {
    cin >> n >> m;
    pieces.resize(m);
    for(int i = 0; i < m; ++i) cin >> pieces[i].first >> pieces[i].second;

    ll count = 0;
    for(ll i = 1; i <= n; ++i) {
        for(ll j = 1; j <= n; ++j) {
            if(isValid(i, j)) ++count;
        }
    }

    cout << count << endl;
    return 0;
}