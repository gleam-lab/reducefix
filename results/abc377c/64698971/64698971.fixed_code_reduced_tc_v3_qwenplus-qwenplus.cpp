#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repi(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
#define rrep(i, n) for (int i = n-1; i >= (int)(0); i--)
#define rrepi(i, a, b) for (int i = (int)(a); i > (int)(b); i--)
#define ALL(a) (a).begin(),(a).end()
#define ALL_(a) (a),(a)+size(a)
#define IF_T if(Is_test)

#define ll long long
using namespace std;

struct phash {
    inline size_t operator()(const pair<ll,ll> & p) const {
        const auto h1 = hash<ll>()(p.first);
        const auto h2 = hash<ll>()(p.second);
        return h1 ^ (h2 << 1);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    ll N;
    int M;
    cin >> N >> M;

    unordered_set<pair<ll, ll>, phash> attacked;
    set<pair<ll, ll>> occupied;

    vector<pair<ll, ll>> dir = {
        {2, 1}, {1, 2}, {-1, 2}, {-2, 1},
        {-2, -1}, {-1, -2}, {1, -2}, {2, -1}
    };

    while (M--) {
        ll a, b;
        cin >> a >> b;
        // Store original coordinates as occupied
        occupied.insert({a, b});
        
        // Mark all attackable positions from this piece
        for (auto [dx, dy] : dir) {
            ll x = a + dx;
            ll y = b + dy;
            if (x >= 1 && x <= N && y >= 1 && y <= N) {
                attacked.insert({x, y});
            }
        }
    }

    // Remove positions that are already occupied by pieces
    for (auto [x, y] : occupied) {
        if (attacked.count({x, y})) {
            attacked.erase({x, y});
        }
    }

    // Total squares - (occupied + attacked positions)
    cout << (N * N - (ll)occupied.size() - (ll)attacked.size());

    return 0;
}