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
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
        k -= a[i];
    }

    // Sort the array and get the prefix sum array
    vector<ll> sorted_a = a;
    sort(sorted_a.begin(), sorted_a.end());
    vector<ll> pref(n + 1);
    for(int i = 0; i < n; ++i)
        pref[i + 1] = sorted_a[i] + pref[i];

    // Initialize the answer array with -1
    vector<ll> ans(n, -1);

    // Iterate over each candidate
    for(int i = 0; i < n; ++i) {
        ll need = -1;
        // Calculate the minimum additional votes needed
        for(ll x = 0; x <= k; ++x) {
            int count = 0;
            int idx = upper_bound(sorted_a.begin(), sorted_a.end(), sorted_a[i] + x) - sorted_a.begin();
            if(idx > n - m - 1)
                count += (idx - (n - m - 1)) * (sorted_a[i] + x) - (pref[idx] - pref[n - m - 1]);
            if(idx <= i && i < idx)
                --count;
            else
                count += x;
            if(count <= k) {
                need = x;
                break;
            }
        }
        ans[i] = need;
    }

    // Output the result
    for(auto i : ans) cout << i << ' ';
    return 0;
}