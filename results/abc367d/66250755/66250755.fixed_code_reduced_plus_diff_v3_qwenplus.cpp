#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, m;
ll a[400005], w[400005];
map<ll, int> cnt;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i] %= m;
        a[i + n] = a[i];
    }
    
    ll sum = 0;
    ll ans = 0;
    
    // Initialize with prefix sum 0
    cnt[0] = 1;
    
    for (int i = 1; i < 2 * n; i++) {
        sum = (sum + a[i]) % m;
        
        // If we have passed the first n elements, remove the contribution 
        // of the prefix that is now out of the sliding window of length n
        if (i >= n) {
            ll prev_sum = (sum - a[i - n + 1] + m) % m;
            cnt[prev_sum]--;
        }
        
        // Add the number of previous prefixes with the same sum
        ans += cnt[sum];
        
        // Include current prefix sum
        cnt[sum]++;
    }
    
    cout << ans;
    return 0;
}