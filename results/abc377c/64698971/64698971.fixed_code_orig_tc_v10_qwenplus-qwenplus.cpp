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

// Custom hash for pair<int, int>
struct phash {
    inline size_t operator()(const pair<int,int> & p) const {
        const auto h1 = hash<ll>()(p.first);
        const auto h2 = hash<ll>()(p.second);
        return h1 ^ (h2 << 1);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    ll N;
    int M;
    cin >> N >> M;

    // Using an unordered_set with custom hash to store attacked positions
    unordered_set<pair<int, int>, phash> attacked;

    // The 8 possible L-shaped moves
    vector<pair<int, int>> moves = {
        {2, 1}, {1, 2}, {-1, 2}, {-2, 1},
        {-2, -1}, {-1, -2}, {1, -2}, {2, -1}
    };

    rep(i, M) {
        int a, b;
        cin >> a >> b;
        // Convert to 0-based index
        a--; b--;

        // Add current piece position to the set (to exclude from result)
        attacked.insert({a, b});

        // Check all 8 potential attack positions
        for (auto [dx, dy] : moves) {
            int x = a + dx;
            int y = b + dy;
            // Only add if within bounds
            if (x >= 0 && x < N && y >= 0 && y < N) {
                attacked.insert({x, y});
            }
        }
    }

    // Total cells = N*N
    // Subtract number of attacked cells and occupied cells (which are included in attacked)
    cout << (N * N) - (ll)attacked.size() << "\n";

    return 0;
}