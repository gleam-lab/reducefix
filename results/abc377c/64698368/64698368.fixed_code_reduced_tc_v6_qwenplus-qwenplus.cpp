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

// Custom hash for pair<int,int>
struct phash {
    inline size_t operator()(const pair<int,int> &p) const {
        const auto h1 = hash<int>()(p.first);
        const auto h2 = hash<int>()(p.second);
        return h1 ^ (h2 << 16);
    }
};

int N, M;
unordered_set<pair<int,int>, phash> attacked_cells;

void try_insert(int a, int b) {
    if (1 <= a && a <= N && 1 <= b && b <= N) {
        attacked_cells.insert({a, b});
    }
}

int main() {
    cin >> N >> M;

    vector<pair<int, int>> attack_offsets = {
        {2, 1}, {1, 2}, {-1, 2}, {-2, 1},
        {-2, -1}, {-1, -2}, {1, -2}, {2, -1}
    };

    // We store only the occupied cells to exclude them from the result
    unordered_set<pair<int,int>, phash> occupied_cells;

    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        occupied_cells.insert({a, b});
        
        // Mark all cells that this piece can attack
        for (auto [dx, dy] : attack_offsets) {
            try_insert(a + dx, b + dy);
        }
    }

    // Total number of cells minus attacked or occupied cells
    ll total_cells = (ll)N * (ll)N;
    ll unavailable_cells = attacked_cells.size() + occupied_cells.size();
    
    cout << total_cells - unavailable_cells << endl;
}