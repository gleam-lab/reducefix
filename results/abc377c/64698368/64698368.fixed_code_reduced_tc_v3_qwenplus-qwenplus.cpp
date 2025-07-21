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

struct phash{
    inline size_t operator()(const pair<ll,ll> & p) const{
        const auto h1 = hash<ll>()(p.first);
        const auto h2 = hash<ll>()(p.second);
        return h1 ^ (h2 << 1);
    }
};

int main() {
    ll N;
    int M;
    cin >> N >> M;

    unordered_set<pair<ll,ll>, phash> attacked;
    set<pair<ll,ll>> occupied;

    vector<pair<ll,ll>> dir = {
        {2,1}, {1,2}, {-1,2}, {-2,1},
        {-2,-1}, {-1,-2}, {1,-2}, {2,-1}
    };

    for(int i = 0; i < M; ++i) {
        ll a, b;
        cin >> a >> b;
        // Convert to 0-based index
        a--; b--;
        
        // Mark the cell itself as occupied
        occupied.emplace(a, b);

        // Mark all cells that can be attacked by this piece
        for(auto [dx, dy] : dir) {
            ll na = a + dx;
            ll nb = b + dy;
            if(na >= 0 && na < N && nb >= 0 && nb < N) {
                attacked.emplace(na, nb);
            }
        }
    }

    // Remove occupied cells from attacked cells
    for(auto& p : occupied) {
        attacked.erase(p);
    }

    // Total valid cells = N*N - (occupied cells + attacked cells)
    ll total_cells = N * N;
    ll result = total_cells - (occupied.size() + attacked.size());

    cout << result << endl;
}