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

    // Calculate the prefix sum array
    vector<ll> pref(n + 1);
    for(int i = 0; i < n; ++i) {
        pref[i + 1] = pref[i] + a[i];
    }

    // Sort indices based on the number of votes
    vector<int> idx(n);
    iota(idx.begin(), idx.end(), 0);
    sort(idx.begin(), idx.end(), [&](int i, int j) {
        return a[i] < a[j];
    });

    // Initialize the answer array with -1
    vector<ll> ans(n, -1);

    // Iterate over each candidate
    for(int i = 0; i < n; ++i) {
        // Calculate the minimum number of additional votes needed
        ll x = 0;
        ll need = 0;
        for(int j = 0; j < min(m, n); ++j) {
            if(a[idx[j]] + x > a[idx[i]]) {
                need += (a[idx[j]] + x - a[idx[i]]);
            } else {
                break;
            }
        }
        if(need <= k) {
            ans[idx[i]] = x;
        }
    }

    // Output the results
    for(ll val : ans) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}