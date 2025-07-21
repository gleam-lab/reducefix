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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll N, M;
    cin >> N >> M;

    set<pair<ll, ll>> st;

    vector<pair<ll, ll>> vc = {{0, 0}, {2, 1}, {1, 2}, {-1, 2}, {-2, 1}, {-2, -1}, {-1, -2}, {1, -2}, {2, -1}};
    rep(i, M) {
        ll a, b; cin >> a >> b;
        --a, --b;
        for (auto x : vc) {
            ll nx = a + x.first, ny = b + x.second;
            if (0 <= nx && nx < N && 0 <= ny && ny < N) {
                st.insert({nx, ny});
            }
        }
    }

    ll total_squares = N * N;
    ll valid_empty_squares = total_squares - st.size();

    cout << valid_empty_squares << '\n';
}