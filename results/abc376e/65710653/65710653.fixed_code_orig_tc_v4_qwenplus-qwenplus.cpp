#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<long long, long long>;

#define rep(i, a, b) for(long long i = (a); i < (b); i++)
#define per(i, a, b) for(long long i = (b)-1; i >= (a); i--)
#define all(a) (a).begin(), (a).end()
#define sz(x) ((ll)(x).size())

struct cmp {
    bool operator()(const pll& a, const pll& b) const {
        if (a.first != b.first)
            return a.first > b.first;
        return a.second > b.second;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll T;
    cin >> T;

    while (T--) {
        ll N, K;
        cin >> N >> K;

        vector<pll> A(N);
        rep(i, N) cin >> A[i].first;
        rep(i, N) cin >> A[i].second;

        sort(all(A), cmp());

        multiset<ll> active;
        ll sum = 0;
        for (ll i = 0; i < K; ++i) {
            active.insert(A[i].second);
            sum += A[i].second;
        }

        ll ans = sum * A[K-1].first;

        for (ll i = K; i < N; ++i) {
            active.insert(A[i].second);
            sum += A[i].second;

            if (sz(active) > K) {
                sum -= *prev(active.end());
                active.erase(prev(active.end()));
            }

            ans = min(ans, sum * A[i].first);
        }

        cout << ans << endl;
    }

    return 0;
}