#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_cast<false>(cin.tie(NULL));

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

    sort(candidates.rbegin(), candidates.rend());

    vector<ll> pref(n + 1);
    for (int i = 0; i < n; ++i) {
        pref[i + 1] = pref[i] + candidates[i].first;
    }

    vector<ll> res(n, -1);

    for (int i = 0; i < n; ++i) {
        ll x = 0;
        int left = i + 1, right = n - i - 1;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            
            ll sum = pref[mid + 1] - pref[i + 1];
            if (sum + candidates[i].first * (m - i - 1) > k) {
                x = max(x, sum + candidates[i].first * (m - i - 1) - k);
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        if (x >= candidates[i].first) {
            res[candidates[i].second] = x - candidates[i].first;
        }
    }

    for (ll c : res) {
        cout << c << " ";
    }

    return 0;
}