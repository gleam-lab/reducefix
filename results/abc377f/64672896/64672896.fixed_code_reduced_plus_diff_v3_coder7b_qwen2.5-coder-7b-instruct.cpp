#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll N, M;
    cin >> N >> M;

    vector<pair<ll, ll>> pos(M);
    set<pair<ll, ll>> occupied;
    for(ll i=0; i<M; i++) {
        ll a, b;
        cin >> a >> b;
        pos[i] = {a, b};
        occupied.insert({a, b});
        occupied.insert({a, b+1});
        occupied.insert({a-1, b});
        occupied.insert({a+1, b});
        occupied.insert({a-1, b+1});
        occupied.insert({a+1, b-1});
        occupied.insert({a, b-1});
        occupied.insert({a+1, b+1});
        occupied.insert({a-1, b-1});
    }

    ll ans = N*N - occupied.size();
    cout << ans << '\n';
    return 0;
}