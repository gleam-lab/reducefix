#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN=8e5+10;

int main(){
    ll n, m;
    scanf("%lld %lld", &n, &m);
    vector<ll> a(2*n + 1), sum(2*n + 2);
    vector<ll> cnt(m, 0);
    
    for(ll i = 1; i <= n; i++){
        scanf("%lld", &a[i]);
        a[i + n] = a[i];
    }
    
    // Compute prefix sums modulo m
    for(ll i = 1; i <= 2*n; i++){
        sum[i] = (sum[i-1] + a[i]) % m;
    }
    
    // Initialize count with prefix sums from first segment [0, n-1]
    // Note: sum[0] = 0 should be counted
    cnt[0]++; // sum[0] = 0
    for(ll i = 1; i < n; i++){
        cnt[sum[i]]++;
    }
    
    ll ans = 0;
    // Process the second half
    for(ll i = n; i < 2*n; i++){
        // Remove the contribution of sum[i-n] 
        // because it's now outside the sliding window of length < n
        if(i - n >= 0){
            cnt[sum[i - n]]--;
        }
        
        // Count how many previous prefix sums equal current sum
        // This means the subarray between those points has sum ≡ 0 (mod m)
        ans += cnt[sum[i]];
        
        // Add current prefix sum to count if we're still within valid range
        if(i < 2*n - 1){ // We only add sums that can be used for future indices
            cnt[sum[i]]++;
        }
    }
    
    printf("%lld\n", ans);
    return 0;
}