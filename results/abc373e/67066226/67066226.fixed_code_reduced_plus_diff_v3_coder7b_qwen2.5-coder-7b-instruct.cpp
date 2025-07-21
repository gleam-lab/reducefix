#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    ll k;
    cin >> n >> m >> k;

    vector<ll> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        k -= a[i];
    }

    vector<pair<ll, int>> candidates(n);
    for (int i = 0; i < n; ++i) {
        candidates[i].first = a[i];
        candidates[i].second = i;
    }

    sort(candidates.begin(), candidates.end());

    vector<ll> ans(n, -1);
    for (int i = 0; i < n; ++i) {
        ll target = candidates[i].first + 1;
        int idx = i;
        while (idx < n && candidates[idx].first == target) {
            ++idx;
        }
        if (idx < n) {
            ll need = target - candidates[i].first;
            if (need <= k) {
                ans[candidates[i].second] = need;
                k -= need;
            } else {
                break;
            }
        } else {
            ans[candidates[i].second] = 0;
        }
    }

    for (auto x : ans) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}