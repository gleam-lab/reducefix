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
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        k -= a[i];
    }
    
    vector<pair<ll, int>> candidates(n);
    for (int i = 0; i < n; i++) {
        candidates[i] = {a[i], i};
    }

    sort(all(candidates), [&](const pair<ll, int>& p1, const pair<ll, int>& p2) {
        return p1.first < p2.first;
    });

    vector<ll> pref(n + 1);
    for (int i = 0; i < n; i++) {
        pref[i + 1] = pref[i] + candidates[i].first;
    }

    vector<ll> ans(n, -1);

    for (int i = 0; i < n; i++) {
        ll needed = 0;
        int count = 0;
        for (int j = 0; j < n; j++) {
            if (j != i && candidates[j].first > candidates[i].first) {
                count++;
                if (count >= m) break;
            }
        }
        
        if (count < m) {
            needed = (m - count) * (candidates[i].first + 1) - pref[n] + pref[i + 1];
            if (needed > k) {
                ans[candidates[i].second] = -1;
            } else {
                ans[candidates[i].second] = needed;
            }
        } else {
            ans[candidates[i].second] = 0;
        }
    }

    for (auto i : ans) {
        cout << i << ' ';
    }

    return 0;
}