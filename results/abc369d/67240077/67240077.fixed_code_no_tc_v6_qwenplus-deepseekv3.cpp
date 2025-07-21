#include<bits/stdc++.h>
#define INF 0x3f3f3f3f3f3f3f3f
using namespace std;
typedef long long ll;
const int MAXN=2e5+10;
ll a[MAXN], f[MAXN][2];  // f[i][0] = not take i, f[i][1] = take i

int main() {
    ll n;
    scanf("%lld", &n);
    for(ll i = 1; i <= n; i++) {
        scanf("%lld", &a[i]);
    }
    
    f[0][0] = 0;         // Base case: not taking 0th element
    f[0][1] = -INF;      // Base case: cannot take 0th element (doesn't exist)
    
    for(ll i = 1; i <= n; i++) {
        // Option 1: don't take current element
        f[i][0] = max(f[i-1][0], f[i-1][1]);
        
        // Option 2: take current element
        // If previous was not taken, take current as normal
        // If previous was taken, double current
        f[i][1] = max(f[i-1][0] + a[i], f[i-1][1] + 2*a[i]);
    }
    
    printf("%lld", max(f[n][0], f[n][1]));
    return 0;
}