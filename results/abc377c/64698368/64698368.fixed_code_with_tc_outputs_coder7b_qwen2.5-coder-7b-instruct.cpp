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

struct phash {
    inline size_t operator()(const pair<ll, ll>& p) const {
        const auto h1 = hash<ll>()(p.first);
        const auto h2 = hash<ll>()(p.second);
        return h1 ^ (h2 << 1);
    }
};

int N, M;
unordered_set<pair<ll, ll>, phash> st;

void set_insert(ll a, ll b) {
    if (a >= 0 && a < N && b >= 0 && b < N) st.emplace(a, b);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;

    vector<pair<ll, ll>> vc = {{0, 0}, {2, 1}, {1, 2}, {-1, 2}, {-2, 1}, {-2, -1}, {-1, -2}, {1, -2}, {2, -1}};
    rep(i, M) {
        ll a, b;
        cin >> a >> b;
        a--; b--;
        for (auto& x : vc) {
            set_insert(a + x.first, b + x.second);
        }
    }

    ll total = (ll)N * N;
    cout << total - (ll)st.size();
}