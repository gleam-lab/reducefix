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

const int dx[] = {-2, -2, -1, -1, 1, 1, 2, 2};
const int dy[] = {-1, 1, -2, 2, -2, 2, -1, 1};

int N, M;
unordered_set<ll> st;

bool isValid(int x, int y) {
    return 0 <= x && x < N && 0 <= y && y < N;
}

void addMoves(int a, int b) {
    rep(i, 8) {
        int nx = a + dx[i];
        int ny = b + dy[i];
        if (isValid(nx, ny)) {
            st.insert((ll)nx * N + ny);
        }
    }
}

int main() {
    cin >> N >> M;

    rep(i, M) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        addMoves(a, b);
    }

    ll totalSquares = (ll)N * N;
    ll validSquares = totalSquares - st.size();

    cout << validSquares << endl;

    return 0;
}