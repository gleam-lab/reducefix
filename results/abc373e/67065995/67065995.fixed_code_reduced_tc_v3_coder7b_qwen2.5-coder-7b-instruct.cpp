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
    
    // Sort indices based on the number of votes
    vector<int> idx(n);
    iota(idx.begin(), idx.end(), 0);
    sort(idx.begin(), idx.end(), [&](int i, int j) {
        return a[i] < a[j];
    });
    
    // Calculate the prefix sum array of sorted votes
    vector<ll> pref(n + 1);
    for(int i = 0; i < n; ++i) {
        pref[i + 1] = pref[i] + a[idx[i]];
    }
    
    // Determine the minimum additional votes needed for each candidate
    vector<ll> res(n, -1);
    for(int i = 0; i < n; ++i) {
        ll target = a[idx[i]] + 1;
        ll left = i, right = n - m;
        
        // Binary search to find the minimum additional votes needed
        while(left < right) {
            ll mid = (left + right) / 2;
            ll total_votes = pref[mid + 1] + (target * (n - mid - 1));
            
            if(total_votes <= k) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        
        if(pref[left + 1] + (target * (n - left - 1)) <= k) {
            res[idx[i]] = target - a[idx[i]];
        }
    }
    
    // Output the results
    for(int i = 0; i < n; ++i) {
        cout << res[i] << " ";
    }
    cout << endl;
    
    return 0;
}