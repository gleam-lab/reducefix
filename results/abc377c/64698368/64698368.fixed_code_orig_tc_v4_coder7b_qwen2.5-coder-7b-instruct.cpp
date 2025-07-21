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

vector<pair<int, int>> directions = {{2, 1}, {1, 2}, {-1, 2}, {-2, 1}, {-2, -1}, {-1, -2}, {1, -2}, {2, -1}};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll N, M;
    cin >> N >> M;

    // Set to keep track of occupied squares
    unordered_set<ll> occupied_squares;
    
    rep(i, M) {
        ll a, b;
        cin >> a >> b;
        --a, --b; // Convert to zero-based index
        occupied_squares.insert(a * N + b);
    }

    // Set to keep track of unsafe squares
    unordered_set<ll> unsafe_squares;
    
    repi(y, 0, N) {
        repi(x, 0, N) {
            if (occupied_squares.count(y * N + x)) continue;
            for (auto [dy, dx] : directions) {
                ll ny = y + dy, nx = x + dx;
                if (ny >= 0 && ny < N && nx >= 0 && nx < N) {
                    unsafe_squares.insert(ny * N + nx);
                }
            }
        }
    }

    // Count the number of safe squares
    ll safe_squares = N * N - unsafe_squares.size();
    cout << safe_squares << endl;

    return 0;
}