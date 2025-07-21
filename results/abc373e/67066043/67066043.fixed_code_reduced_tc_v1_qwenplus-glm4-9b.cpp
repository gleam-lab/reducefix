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
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
        k -= a[i];
    }
    vector<pair<ll, int>> candidates(n);
    for(int i = 0; i < n; ++i) {
        candidates[i] = {a[i], i};
    }
    sort(candidates.begin(), candidates.end());
    reverse(candidates.begin(), candidates.end());
    vector<ll> cnt(n);
    for(int i = 0; i < m; ++i) {
        cnt[candidates[i].second] += 1;
    }
    vector<ll> ans(n, -1);
    for(int i = 0; i < n; ++i) {
        ll votes_needed = 0;
        int rank = i + 1;
        for(int j = 0; j < n && rank > 0; ++j) {
            if(cnt[j] == 0 && candidates[j].first == a[i]) {
                votes_needed = max(votes_needed, rank - 1);
                rank--;
            }
        }
        if(votes_needed == 0) {
            ans[candidates[i].second] = 0;
            continue;
        }
        votes_needed += k / (n - votes_needed);
        if(votes_needed <= k - a[i]) {
            ans[candidates[i].second] = votes_needed - (k - a[i]);
        } else {
            ans[candidates[i].second] = -1;
        }
    }
    for(int i = 0; i < n; ++i) {
        cout << ans[i] << (i < n - 1 ? ' ' : '\n');
    }
}