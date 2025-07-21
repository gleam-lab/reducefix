#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(), (x).end()

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    ll k;
    cin >> n >> m >> k;
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        k -= a[i];
    }
    vectoræºåpair<ll, int> votes(n);
    for (int i = 0; i < n; ++i) {
        votes[i] = {a[i], i};
    }
    sort(votes.rbegin(), votes.rend());

    vector<ll> b(n);
    for (int i = 0; i < n; ++i) {
        b[i] = votes[i].first;
    }

    vector<ll> pref(n + 1);
    pref[0] = 0;
    for (int i = 0; i < n; ++i) {
        pref[i + 1] = pref[i] + b[i];
    }

    vector<ll> ans(n);
    for (int i = 0; i < n; ++i) {
        ll targetRank = votes[i].second + m;
        if (targetRank > n) {
            ans[votes[i].second] = 0;
            continue;
        }

        ll maxVotesAtTargetRank = (targetRank < n ? pref[targetRank + 1] : k) - pref[n - m];
        if (b[i] + k - maxVotesAtTargetRank >= b[i]) {
            ans[votes[i].second] = 0;
        } else {
            ll minVotesNeeded = maxVotesAtTargetRank - b[i] + 1;
            ans[votes[i].second] = minVotesNeeded;
        }
    }

    for (ll vote : ans) cout << vote << ' ';
    cout << '\n';

    return 0;
}