#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN=4e5+10;
ll a[MAXN], sum[MAXN], cnt[MAXN];
int main(){
    ll n, m, ans=0;
    scanf("%lld %lld", &n, &m);
    for(ll i = 1; i <= n; i++) {
        scanf("%lld", &a[i]);
        a[i+n] = a[i];  // Extend the array
    }
    for(ll i = 1; i <= 2*n; i++) {
        sum[i+1] = (sum[i] + a[i]) % m;  // Calculate the modular sum
        if(i <= n) {
            cnt[sum[i]]++;  // Increment the count for the first half
        }
    }
    for(ll i = n+1; i <= 2*n; i++) {
        cnt[sum[i-n]]--;  // Decrement the count for the sum at i-n
        ans += cnt[sum[i]];  // Add the count to the answer
        cnt[sum[i]]++;  // Increment the count for the sum at i
    }
    printf("%lld\n", ans);
    return 0;
}