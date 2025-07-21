#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repi(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
#define rrep(i, n) for (int i = n-1; i >= (int)(0); i--)
#define rrepi(i, a, b) for (int i = (int)(a); i > (int)(b); i--)
#define ALL(a) (a).begin(),(a).end()
#define IF_T if(false)

using namespace std;

using ll = long long;
using PII = pair<int, int>;

// Custom hash for unordered_set of pairs
struct pair_hash {
    template<class T1, class T2>
    size_t operator()(const pair<T1, T2>& p) const {
        return hash<T1>{}(p.first) ^ (hash<T2>{}(p.second) << 1);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll N;
    int M;
    cin >> N >> M;

    // Store all occupied or threatened positions in an unordered_set
    unordered_set<PII, pair_hash> blocked;

    // The 8 possible attack moves + (0,0) to mark original piece position
    vector<PII> moves = {
        {0, 0},
        {2, 1}, {1, 2}, {-1, 2}, {-2, 1},
        {-2, -1}, {-1, -2}, {1, -2}, {2, -1}
    };

    rep(i, M) {
        int a, b;
        cin >> a >> b;
        // Convert to 0-based index
        a--; b--;

        for (auto [dx, dy] : moves) {
            int na = a + dx;
            int nb = b + dy;
            if (na >= 0 && na < N && nb >= 0 && nb < N) {
                blocked.insert({na, nb});
            }
        }
    }

    // Total number of cells is N * N
    // Subtract the number of blocked cells
    cout << N * N - (ll)blocked.size() << "\n";

    return 0;
}