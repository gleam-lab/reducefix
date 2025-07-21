#include<bits/stdc++.h>
#define INF 0x3f3f3f3f3f3f3f3f
using namespace std;
typedef long long ll;
const int MAXN=2e5+10;
ll a[MAXN], f[MAXN], cnt[MAXN];
int main(){
    ll n;
    cin >> n;
    for(ll i = 1; i <= n; i++) {
        cin >> a[i];
    }
    f[0] = f[1] = INF;
    cnt[0] = cnt[1] = 0;
    for(ll i = 2; i <= n; i++) {
        f[i] = min(f[i - 1], min(f[i - 2] + a[i], f[i - 2] + a[i] + a[i]));
        if (f[i - 1] < f[i - 2] + a[i]) {
            cnt[i] = cnt[i - 1];
        } else if (f[i - 1] > f[i - 2] + a[i]) {
            cnt[i] = cnt[i - 2];
        } else { // f[i - 1] == f[i - 2] + a[i]
            cnt[i] = cnt[i - 2] + 1;
        }
    }
    cout << min(f[n], f[n - 1]);
    return 0;
}