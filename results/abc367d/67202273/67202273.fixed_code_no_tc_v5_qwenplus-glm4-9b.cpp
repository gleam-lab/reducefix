#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN=4e5+10;
ll a[MAXN],sum[MAXN],cnt[MAXN];

int main(){
    ll n,m;
    scanf("%lld %lld",&n,&m);
    for(ll i=1;i<=n;i++){
        scanf("%lld",&a[i]);
        a[i+n]=a[i]; // Copy array elements to create the "tiled" effect
    }
    for(ll i=1;i<=2*n;i++){
        sum[i]=sum[i-1]+a[i]; // Calculate prefix sums
        sum[i] %= m;
    }
    for(ll i=1;i<=2*n;i++){
        cnt[sum[i]]++; // Increment count of current sum
        if(i > n){ // Only consider the first n elements for the answer
            ans += cnt[sum[i-n]]; // Add counts of sums that were seen before
        }
    }
    printf("%lld",ans); // Output the result
    return 0;
}