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
set<pair<int, int>> threatened;
set<pair<int, int>> pieces;

void add_threatened(int a, int b) {
    int dx[] = {2, 1, -1, -2, -2, -1, 1, 2};
    int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
    rep(i, 8) {
        int nx = a + dx[i];
        int ny = b + dy[i];
        if (1 <= nx && nx <= N && 1 <= ny && ny <= N) {
            threatened.insert({nx, ny});
        }
    }
}

int main() {
    cin >> N >> M;

    rep(i, M) {
        int a, b;
        cin >> a >> b;
        pieces.insert({a, b});
        add_threatened(a, b);
    }

    ll total_squares = (ll)N * N;
    ll safe_squares = total_squares - threatened.size() - pieces.size();
    for (auto p : pieces) {
        if (threatened.count(p)) {
            safe_squares++;
        }
    }

    cout << safe_squares << endl;
}