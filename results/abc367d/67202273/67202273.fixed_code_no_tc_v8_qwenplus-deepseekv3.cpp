#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN=4e5+10;
ll a[MAXN], sum[MAXN];
map<ll, ll> cnt;

int main(){
    ll n, m, ans=0;
    scanf("%lld %lld", &n, &m);
    for(ll i=1; i<=n; i++){
        scanf("%lld", &a[i]);
        a[i+n] = a[i];
    }
    
    sum[0] = 0;
    for(ll i=1; i<=2*n; i++){
        sum[i] = (sum[i-1] + a[i]) % m;
        if(i <= n){
            cnt[sum[i]]++;
        }
    }
    
    // Initialize with the counts from first n elements
    ans += cnt[sum[n]];  // This counts the full array sum
    
    for(ll i=n+1; i<=2*n; i++){
        // Remove the contribution of the element that's sliding out
        ll prev_sum = sum[i-n];
        cnt[prev_sum]--;
        
        // Add the counts of current sum in the window
        ans += cnt[sum[i]];
        
        // Add the current sum to the counts for next iterations
        cnt[sum[i]]++;
    }
    
    printf("%lld", ans);
    return 0;
}