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
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        k -= a[i];
    }
    vector<int> ord(n);
    iota(all(ord), 0);
    sort(all(ord), [&](int i, int j) {
        return a[i] < a[j];
    });
    vector<ll> sorted_a(a.begin(), a.end());
    sort(all(sorted_a));
    vector<ll> pref(n + 1);
    for(int i = 0; i < n; i++) {
        pref[i + 1] = sorted_a[i] + pref[i];
    }
    vector<ll> ans(n, -1);
    for(int i = 0; i < n; i++) {
        ll l = 0, r = k + 1;
        while(l < r) {
            ll mid = (l + r + 1) / 2;
            ll max_votes = (mid == k + 1 ? 0 : sorted_a[mid - 1] + mid);
            ll votes_needed = max_votes - a[i];
            ll min_votes = sorted_a[mid] + mid;
            ll votes_available = 0;

            int count = upper_bound(all(a), votes_needed) - a.begin();
            if(i >= count) count--;

            votes_available += count * votes_needed;
            votes_available += (n - count - 1) * min_votes;

            if(votes_available > k) {
                r = mid - 1;
            } else {
                l = mid;
            }
        }
        if(l == k + 1) ans[ord[i]] = -1;
        else ans[ord[i]] = l;
    }
    for(int i = 0; i < n; i++) {
        cout << ans[i] << " ";
    }
    cout << '\n';
    return 0;
}