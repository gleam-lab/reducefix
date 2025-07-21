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

vector<vector<int>> directions = {{0, 0}, {2, 1}, {1, 2}, {-1, 2}, {-2, 1}, {-2, -1}, {-1, -2}, {1, -2}, {2, -1}};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll N, M;
    cin >> N >> M;

    unordered_set<ll> captured;

    rep(i, M) {
        int a, b;
        cin >> a >> b;
        --a, --b; // Convert to zero-based index

        for (auto& dir : directions) {
            int na = a + dir[0], nb = b + dir[1];
            if (na >= 0 && na < N && nb >= 0 && nb < N) {
                captured.insert((ll)na * N + nb);
            }
        }
    }

    ll total_squares = N * N;
    ll available_squares = total_squares - captured.size();

    cout << available_squares << endl;

    return 0;
}