#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

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

    // Calculate prefix sums for sorted votes
    vector<ll> sorted_a = a;
    sort(sorted_a.begin(), sorted_a.end());
    vector<ll> pref(n + 1);
    for(int i = 0; i < n; i++)
        pref[i + 1] = sorted_a[i] + pref[i];

    // Initialize answer array with -1
    vector<ll> ans(n, -1);

    // Iterate over each candidate
    for(int i = 0; i < n; i++) {
        ll x = 0;
        // Check if candidate can win with x additional votes
        while(true) {
            ll rid = upper_bound(sorted_a.begin(), sorted_a.end(), a[i] + x) - sorted_a.begin();
            ll lid = n - m - (i >= n - m ? 1 : 0);
            ll cnt = 0;
            if(rid > lid)
                cnt += (rid - lid) * (a[i] + x) - (pref[rid] - pref[lid]);
            if(lid <= i && i < rid)
                cnt--;
            else
                cnt += x;

            if(cnt <= k) {
                ans[i] = x;
                break;
            }
            x++;
        }
    }

    // Output results
    for(auto i : ans)
        cout << i << ' ';
    return 0;
}