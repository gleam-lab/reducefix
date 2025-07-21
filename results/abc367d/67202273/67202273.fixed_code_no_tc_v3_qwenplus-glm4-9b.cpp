#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN=4e5+10;
ll a[MAXN], sum[MAXN], cnt[MAXN];
int main(){
    ll n, m;
    scanf("%lld %lld", &n, &m);
    for(ll i = 1; i <= n; i++){
        scanf("%lld", &a[i]);
    }
    
    // Calculate prefix sums and count occurrences of each sum up to n
    for(ll i = 1; i <= n; i++){
        sum[i] = (a[i] + (i > 1 ? sum[i-1] : 0)) % m;
        cnt[sum[i]]++;
    }
    
    ll ans = 0;
    // Calculate the number of valid pairs from the second half of the array
    for(ll i = n + 1; i <= 2 * n; i++){
        ll current_sum = (a[i] + (i > 1 ? sum[i-1] : 0)) % m;
        ans += cnt[(current_sum + m - 1) % m]; // Add the count of the complement sum
        cnt[current_sum]++;
    }
    
    printf("%lld\n", ans);
    return 0;
}