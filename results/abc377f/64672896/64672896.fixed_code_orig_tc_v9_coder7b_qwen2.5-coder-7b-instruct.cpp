#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll N, M;
    cin >> N >> M;

    vector<pair<ll, ll>> pieces(M);
    set<ll> sums, diffs;
    for (ll i = 0; i < M; i++) {
        cin >> pieces[i].first >> pieces[i].second;
        sums.insert(pieces[i].first + pieces[i].second);
        diffs.insert(pieces[i].first - pieces[i].second);
    }

    ll total_empty_squares = N * N;
    for (const auto& [x, y] : pieces) {
        total_empty_squares -= (sums.count(x + y) > 0) + (diffs.count(x - y) > 0) + (x > 0) + (y > 0) + (x < N) + (y < N);
    }
    total_empty_squares += M;

    cout << total_empty_squares << '\n';

    return 0;
}