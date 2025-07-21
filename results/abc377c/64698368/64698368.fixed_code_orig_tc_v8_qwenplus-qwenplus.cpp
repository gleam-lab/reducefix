#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long

const int dx[] = {2, 1, -1, -2, -2, -1, 1, 2};
const int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};

int main() {
    ll N;
    int M;
    cin >> N >> M;

    set<pair<ll, ll>> threatened;
    set<pair<ll, ll>> occupied;

    vector<pair<ll, ll>> moves = {
        {2,1}, {1,2}, {-1,2}, {-2,1},
        {-2,-1}, {-1,-2}, {1,-2}, {2,-1}
    };

    rep(i, M) {
        ll a, b;
        cin >> a >> b;
        // Convert to 0-based indexing
        a--; b--;
        occupied.insert({a, b});
        for (auto [da, db] : moves) {
            ll na = a + da;
            ll nb = b + db;
            if (0 <= na && na < N && 0 <= nb && nb < N) {
                threatened.insert({na, nb});
            }
        }
    }

    ll total = N * N;
    ll blocked = occupied.size() + threatened.size();

    cout << total - blocked << endl;

    return 0;
}