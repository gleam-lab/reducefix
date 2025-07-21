#include<bits/stdc++.h>
#define INF 0x3f3f3f3f3f3f3f3f
using namespace std;
typedef long long ll;
const int MAXN=2e5+10;
ll a[MAXN],f[MAXN][2];
int main(){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }
    f[0][0] = -INF; // Initialize with negative infinity for the case when we pick the first element
    f[0][1] = 0;    // Initialize with 0 for the case when we don't pick any element
    for(int i=1;i<=n;i++){
        // Calculate the maximum value when we pick the current element
        f[i][0] = max(f[i-1][0], f[i-1][1] + a[i]);
        // Calculate the maximum value when we don't pick the current element
        f[i][1] = max(f[i-1][0], f[i-1][1]);
    }
    // The result is the maximum value between picking or not picking the last element
    printf("%lld", max(f[n][0], f[n][1]));
    return 0;
}