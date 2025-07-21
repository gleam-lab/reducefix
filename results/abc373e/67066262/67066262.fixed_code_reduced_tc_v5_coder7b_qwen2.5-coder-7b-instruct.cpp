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
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
        k -= a[i];
    }

    // Sort indices based on the number of votes in ascending order
    vector<int> idx(n);
    iota(idx.begin(), idx.end(), 0);
    sort(idx.begin(), idx.end(), [&](int i, int j) { return a[i] < a[j]; });

    // Calculate prefix sums of votes
    vector<ll> pref(n + 1);
    for(int i = 0; i < n; ++i) {
        pref[i + 1] = pref[i] + a[idx[i]];
    }

    vector<ll> ans(n, -1);

    for(int i = 0; i < n; ++i) {
        ll x = 0;
        int left = 0, right = n - 1;
        
        // Binary search to find the minimum number of additional votes needed
        while(left <= right) {
            int mid = left + (right - left) / 2;
            
            // Calculate the number of candidates who can overtake candidate i
            ll overtake = 0;
            if(mid > i) {
                overtake = (pref[mid] - pref[i]) / (a[idx[mid]] + 1);
            }
            
            // Check if the current number of additional votes guarantees victory
            if(overtake < m) {
                x = mid - i;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        ans[idx[i]] = x;
    }

    // Adjust answers for candidates who already have enough votes
    for(int i = 0; i < n; ++i) {
        if(ans[i] == 0) {
            ans[i] = -1;
        }
    }

    // Output the results
    for(int i = 0; i < n; ++i) {
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}