#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;

#define rep(i, a, b) for (ll i = (a); i < (b); ++i)
#define per(i, a, b) for (ll i = (b)-1; i >= (a); --i)

void solve() {
    ll N, K;
    cin >> N >> K;

    vector<pll> A(N);
    rep(i, 0, N) cin >> A[i].first;
    rep(i, 0, N) cin >> A[i].second;

    sort(A.begin(), A.end());

    multiset<ll, greater<ll>> topK;
    ll sumB = 0;
    rep(i, 0, K) {
        topK.insert(A[i].second);
        sumB += A[i].second;
    }

    ll res = sumB * A[K - 1].first;

    rep(i, K, N) {
        topK.insert(A[i].second);
        sumB += A[i].second;

        if (topK.size() > K) {
            ll last = *topK.rbegin();
            sumB -= last;
            topK.erase(topK.find(last));
        }

        res = min(res, sumB * A[i].first);
    }

    cout << res << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll T;
    cin >> T;

    while (T--) {
        solve();
    }

    return 0;
}