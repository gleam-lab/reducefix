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

int N, M;
set<pair<int, int>> st;

vector<vector<bool>> is_blocked;

bool is_valid(int i, int j) {
    return 0 <= i && i < N && 0 <= j && j < N;
}

void mark_blockers(int i, int j) {
    vector<pair<int, int>> directions = {{2, 1}, {1, 2}, {-1, 2}, {-2, 1}, {-2, -1}, {-1, -2}, {1, -2}, {2, -1}};
    for (auto& dir : directions) {
        int ni = i + dir.first;
        int nj = j + dir.second;
        if (is_valid(ni, nj)) {
            is_blocked[ni][nj] = true;
        }
    }
}

int main() {
    cin >> N >> M;

    is_blocked.resize(N, vector<bool>(N, false));

    vector<pair<int, int>> vc = {{0, 0}, {2, 1}, {1, 2}, {-1, 2}, {-2, 1}, {-2, -1}, {-1, -2}, {1, -2}, {2, -1}};
    rep(i, M) {
        int a, b; cin >> a >> b;
        a--, b--;
        for (auto& x : vc) {
            int na = a + x.first;
            int nb = b + x.second;
            if (is_valid(na, nb)) {
                is_blocked[na][nb] = true;
            }
        }
    }

    ll result = 0;
    rep(i, N) {
        rep(j, N) {
            if (!is_blocked[i][j]) {
                result++;
            }
        }
    }

    cout << result << endl;
}