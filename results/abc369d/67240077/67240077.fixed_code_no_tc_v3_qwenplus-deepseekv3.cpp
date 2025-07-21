#include<bits/stdc++.h>
#define INF 0x3f3f3f3f3f3f3f3f
using namespace std;
typedef long long ll;
const int MAXN=2e5+10;
ll a[MAXN], f[MAXN][2];

int main() {
    ll n;
    scanf("%lld", &n);
    for(ll i = 1; i <= n; i++) {
        scanf("%lld", &a[i]);
    }
    
    f[0][0] = 0;       // Previous element was not selected
    f[0][1] = -INF;     // Initial state: no previous element selected
    
    for(ll i = 1; i <= n; i++) {
        // Current not selected: take max of previous selected or not
        f[i][0] = max(f[i-1][0], f[i-1][1]);
        // Current selected:
        // If previous not selected, multiply by 1 (first selection)
        // If previous selected, multiply by 2 (alternating)
        f[i][1] = max(f[i-1][0] + a[i], f[i-1][1] + 2 * a[i]);
    }
    
    printf("%lld", max(f[n][0], f[n][1]));
    return 0;
}