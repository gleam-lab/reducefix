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

    int N, M;
    cin >> N >> M;

    set<pair<ll, ll>> st;
    vector<pair<ll, ll>> moves = {{2, 1}, {1, 2}, {-1, 2}, {-2, 1}, {-2, -1}, {-1, -2}, {1, -2}, {2, -1}};

    rep(i, M) {
        ll a, b;
        cin >> a >> b;
        a--, b--;

        rep(j, 8) {
            ll na = a + moves[j].first;
            ll nb = b + moves[j].second;
            if (na >= 0 && na < N && nb >= 0 && nb < N) {
                st.insert({na, nb});
            }
        }
    }

    ll total_squares = N * N;
    ll empty_squares = total_squares - st.size();

    cout << empty_squares << endl;

    return 0;
}