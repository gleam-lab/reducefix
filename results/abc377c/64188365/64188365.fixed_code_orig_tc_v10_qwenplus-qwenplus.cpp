#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); ++i)
using ll = long long;

// Directions representing positions where a piece can attack
const int dx[8] = {2,1,-1,-2,-2,-1,1,2};
const int dy[8] = {1,2,2,1,-1,-2,-2,-1};

int main() {
    ll N;
    int M;
    cin >> N >> M;

    set<pair<ll, ll>> occupied;
    set<pair<ll, ll>> attacked;

    for (int i = 0; i < M; ++i) {
        ll x, y;
        cin >> x >> y;
        occupied.emplace(x, y);
    }

    // For each piece, mark the squares it can attack
    for (auto& p : occupied) {
        ll x = p.first;
        ll y = p.second;

        for (int d = 0; d < 8; ++d) {
            ll nx = x + dx[d];
            ll ny = y + dy[d];

            if (nx >= 1 && nx <= N && ny >= 1 && ny <= N) {
                attacked.emplace(nx, ny);
            }
        }
    }

    // The result is total squares - occupied - attacked
    ll total = N * N;
    ll blocked = occupied.size() + attacked.size();

    cout << total - blocked << endl;

    return 0;
}