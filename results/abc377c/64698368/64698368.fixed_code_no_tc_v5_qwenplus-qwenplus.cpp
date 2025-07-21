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
    inline size_t operator()(const pair<int,int> &p) const {
        return hash<long long>()((static_cast<ll>(p.first) << 32) | p.second);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll N;
    int M;
    cin >> N >> M;

    unordered_set<pair<ll, ll>, phash> attacked;
    
    // The 9 positions include the piece itself and the 8 attack positions
    vector<pair<ll, ll>> offsets = {
        {0, 0},
        {2, 1}, {1, 2}, {-1, 2}, {-2, 1},
        {-2, -1}, {-1, -2}, {1, -2}, {2, -1}
    };

    for (int i = 0; i < M; ++i) {
        ll a, b;
        cin >> a >> b;
        // Convert to 0-based index
        a--; b--;
        for (auto [dx, dy] : offsets) {
            ll x = a + dx;
            ll y = b + dy;
            if (x >= 0 && x < N && y >= 0 && y < N) {
                attacked.insert({x, y});
            }
        }
    }

    // Total number of squares: N*N
    // Subtract the number of attacked squares
    cout << N * N - (ll)attacked.size() << endl;

    return 0;
}