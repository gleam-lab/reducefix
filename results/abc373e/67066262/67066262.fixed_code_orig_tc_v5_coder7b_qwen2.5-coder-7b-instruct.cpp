#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_castio(false);
    cin.tie(nullptr);

    int n, m;
    ll k;
    cin >> n >> m >> k;

    vector<ll> a(n);
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
        k -= a[i];
    }

    // Sort the votes in descending order
    sort(a.rbegin(), a.rend());

    // Initialize the prefix sum array
    vector<ll> pref(n + 1);
    for(int i = 0; i < n; ++i) {
        pref[i + 1] = pref[i] + a[i];
    }

    // Initialize the result array
    vector<ll> res(n, -1);

    // Iterate through each candidate
    for(int i = 0; i < n; ++i) {
        ll need = 0;
        for(int j = i + 1; j < n; ++j) {
            need += max(0LL, a[j] + need - pref[j] + a[i]);
        }
        
        // Check if the candidate can win with the calculated need
        if(k >= need) {
            res[i] = need;
        } else {
            res[i] = 0;
        }
    }

    // Print the results
    for(int i = 0; i < n; ++i) {
        cout << res[i] << " ";
    }
    cout << endl;

    return 0;
}