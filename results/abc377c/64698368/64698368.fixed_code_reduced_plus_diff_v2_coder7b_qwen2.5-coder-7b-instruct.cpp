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

    unordered_set<ll> st;
    rep(i, M) {
        ll a, b;
        cin >> a >> b;
        --a, --b;
        vector<pair<ll, ll>> moves = {{2, 1}, {1, 2}, {-1, 2}, {-2, 1}, {-2, -1}, {-1, -2}, {1, -2}, {2, -1}};
        for (auto& move : moves) {
            ll x = a + move.first, y = b + move.second;
            if (x >= 0 && x < N && y >= 0 && y < N) {
                st.insert(x * N + y);
            }
        }
    }

    cout << N * N - st.size();
}