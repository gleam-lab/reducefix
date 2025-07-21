#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pint = pair<int, int>;
using pll = pair<ll, ll>;

#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rrep(i, n) for (ll i = (ll)(n)-1; i >= 0; i--)
#define fi first
#define se second
#define pb push_back
#define all(v) (v).begin(), (v).end()

template <typename T>
inline bool chmax(T &a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

template <typename T>
inline bool chmin(T &a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll T;
    cin >> T;
    while (T--) {
        ll N, K;
        cin >> N >> K;
        vector<pll> AB(N);
        rep(i, N) cin >> AB[i].fi;
        rep(i, N) cin >> AB[i].se;
        sort(all(AB));
        priority_queue<ll> pq;
        ll sum = 0;
        ll ans = numeric_limits<ll>::max();
        rep(i, N) {
            sum += AB[i].se;
            pq.push(AB[i].se);
            if (pq.size() > K) {
                sum -= pq.top();
                pq.pop();
            }
            if (pq.size() == K) {
                chmin(ans, sum * AB[i].fi);
            }
        }
        cout << ans << '\n';
    }
    return 0;
}