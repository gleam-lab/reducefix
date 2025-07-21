#include<bits/stdc++.h>
#define INF 0x3f3f3f3f3f3f3f3f
using namespace std;
typedef long long ll;
const int MAXN=2e5+10;
ll a[MAXN], f[MAXN][2];

int main() {
    ll n;
    scanf("%lld", &n);
    for(ll i=1; i<=n; i++) {
        scanf("%lld", &a[i]);
    }
    
    f[0][0] = 0; // Not taking the previous element
    f[0][1] = -INF; // Cannot take if no previous element
    
    for(ll i=1; i<=n; i++) {
        // Case 1: Don't take current element
        f[i][0] = max(f[i-1][0], f[i-1][1]);
        
        // Case 2: Take current element with possible multiplication
        // Previous was not taken, so current is first in sequence (count=1)
        ll take1 = f[i-1][0] + a[i];
        // Previous was taken, so current is second in sequence (count=2)
        ll take2 = f[i-1][1] + 2*a[i];
        
        f[i][1] = max(take1, take2);
    }
    
    printf("%lld", max(f[n][0], f[n][1]));
    return 0;
}