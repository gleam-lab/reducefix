#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN=2e5+10;
ll a[MAXN], f[MAXN][2]; // f[i][0]: not take i, f[i][1]: take i

int main() {
    ll n;
    scanf("%lld", &n);
    for(ll i=1; i<=n; i++) {
        scanf("%lld", &a[i]);
    }
    
    f[1][0] = 0;        // Not taking first element
    f[1][1] = a[1];     // Taking first element
    
    for(ll i=2; i<=n; i++) {
        // Not taking current element
        f[i][0] = max(f[i-1][0], f[i-1][1]);
        
        // Taking current element
        // If previous was taken, current is multiplied by 2
        // If previous was not taken, current is taken as is
        f[i][1] = max(f[i-1][0] + a[i], f[i-1][1] + 2*a[i]);
    }
    
    printf("%lld\n", max(f[n][0], f[n][1]));
    return 0;
}