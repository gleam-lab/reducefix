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

vector<vector<bool>> can_place;

bool valid(int i, int j) {
    return i >= 0 && i < can_place.size() && j >= 0 && j < can_place[0].size();
}

int dx[] = {2, 1, -1, -2, -2, -1, 1, 2};
int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};

void bfs(vector<pair<int, int>>& pieces) {
    queue<pair<int, int>> q;
    for (auto& [i, j] : pieces) {
        q.push({i, j});
        can_place[i][j] = false;
    }
    
    while (!q.empty()) {
        auto [i, j] = q.front(); q.pop();
        
        for (int d = 0; d < 8; ++d) {
            int ni = i + dx[d], nj = j + dy[d];
            
            if (valid(ni, nj)) {
                if (can_place[ni][nj]) {
                    can_place[ni][nj] = false;
                    q.push({ni, nj});
                }
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int N, M; cin >> N >> M;
    can_place.resize(N, vector<bool>(N, true));

    vector<pair<int, int>> pieces(M);
    rep(i, M) {
        int a, b; cin >> a >> b; --a, --b;
        pieces[i] = {a, b};
    }

    bfs(pieces);

    ll result = 0;
    rep(i, N) rep(j, N) if (can_place[i][j]) ++result;

    cout << result << endl;
}