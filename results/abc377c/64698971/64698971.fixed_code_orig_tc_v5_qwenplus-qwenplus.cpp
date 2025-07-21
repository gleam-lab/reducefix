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

// Hash function for pair to be used in unordered_set
struct phash {
    size_t operator()(const pair<int, int>& p) const {
        return hash<long long>()((ll)p.first * (ll)1e18 + p.second);
    }
};

int N, M;
unordered_set<pair<int, int>, phash> blocked;

void try_insert(int x, int y) {
    if (x >= 1 && x <= N && y >= 1 && y <= N) {
        blocked.insert({x, y});
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> N >> M;

    // These are the relative positions a knight can attack from in horse move fashion
    vector<pair<int, int>> moves = {
        {2, 1}, {1, 2}, {-1, 2}, {-2, 1},
        {-2, -1}, {-1, -2}, {1, -2}, {2, -1}
    };

    for (int i = 0; i < M; ++i) {
        int x, y;
        cin >> x >> y;
        blocked.insert({x, y});

        for (auto [dx, dy] : moves) {
            try_insert(x + dx, y + dy);
        }
    }

    cout << (N * 1LL * N) - (ll)blocked.size() << endl;
}