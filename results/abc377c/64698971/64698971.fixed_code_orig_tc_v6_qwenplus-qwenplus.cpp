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
    inline size_t operator()(const pair<int,int> &p) const {
        const auto h1 = hash<int>()(p.first);
        const auto h2 = hash<int>()(p.second);
        return h1 ^ (h2 << 1);
    }
};

int N,M;
unordered_set<pair<int,int>, phash> st;

void set_insert(int a, int b, int N) {
    if (0 <= a && a < N && 0 <= b && b < N) {
        st.insert({a, b});
    }
}

int main() {
    cin >> N >> M;

    // The 8 positions this piece can attack from
    vector<pair<int, int>> attack_offsets = {
        {2,1}, {1,2}, {-1,2}, {-2,1},
        {-2,-1}, {-1,-2}, {1,-2}, {2,-1}
    };

    st.reserve(9 * M); // Each piece can mark up to 9 squares

    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        
        // Add its own position (it's already occupied and cannot be used)
        st.insert({a, b});

        // Add all potentially attacked positions
        for (auto [dx, dy] : attack_offsets) {
            set_insert(a + dx, b + dy, N);
        }
    }

    // Total number of valid empty cells not under attack
    ll total_cells = (ll)N * (ll)N;
    cout << total_cells - (ll)st.size();

    return 0;
}