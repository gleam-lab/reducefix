#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    ll N, M; cin >> N >> M;
    vector<pair<ll, ll>> pieces(M);
    set<pair<ll, ll>> occupied;

    for(int i = 0; i < M; ++i) {
        cin >> pieces[i].first >> pieces[i].second;
        occupied.insert(pieces[i]);
    }

    auto isValid = [&](ll x, ll y) {
        if(x > N || x <= 0 || y > N || y <= 0) return false;
        if(occupied.count({x, y})) return false;

        for(auto [ax, ay]: pieces) {
            if(ax == x || ay == y || ax + ay == x + y || ax - ay == x - y) return false;
        }
        return true;
    };

    ll count = 0;
    for(ll i = 1; i <= N; ++i) {
        for(ll j = 1; j <= N; ++j) {
            if(isValid(i, j)) ++count;
        }
    }

    cout << count << '\n';

    return 0;
}