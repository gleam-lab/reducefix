#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN=4e5+10;
ll a[MAXN], sum[MAXN], cnt[MAXN];

int main(){
    ll n, m, ans = 0, current_sum = 0;
    scanf("%lld %lld", &n, &m);
    for(ll i = 1; i <= n; i++){
        scanf("%lld", &a[i]);
        a[i+n] = a[i];  // Extend the array circularly
    }
    
    // Initialize sum and cnt arrays
    for(int i = 1; i <= 2*n; i++){
        sum[i] = 0;
        cnt[i] = 0;
    }
    
    // Calculate prefix sums
    for(ll i = 1; i <= 2*n; i++){
        current_sum = (current_sum + a[i]) % m;
        sum[i] = current_sum;
        cnt[current_sum]++;
    }
    
    // Count the valid intervals
    for(ll i = n+1; i <= 2*n; i++){
        cnt[sum[i-n]]--;
        ans += cnt[sum[i]];
        cnt[sum[i]]++;
    }
    
    printf("%lld", ans);
    return 0;
}