#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN=4e5+10;
ll a[MAXN],sum[MAXN],cnt[MAXN];
int main(){
    ll n,m,ans=0;
    scanf("%lld %lld",&n,&m);
    for(ll i=0;i<n;i++){
        scanf("%lld",&a[i]);
        a[i+n] = a[i];  // Corrected the starting index to 0 for duplication
    }
    for(ll i=0;i<=2*n;i++){
        sum[i+1] = (sum[i] + a[i]) % m;  // Initialize sum array with cumulative sums
        cnt[sum[i]]++;  // Increment count of occurrences of this sum modulo m
    }
    for(ll i=n+1;i<=2*n;i++){
        cnt[sum[i-n]]--;  // Decrement count of occurrences of old sum
        ans += cnt[sum[i]];  // Add the count of current sum to the answer
        cnt[sum[i]]++;  // Increment count of occurrences of current sum
    }
    printf("%lld\n",ans);
    return 0;
}