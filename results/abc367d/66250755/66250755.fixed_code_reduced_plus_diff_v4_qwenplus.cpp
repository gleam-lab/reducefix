#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, m;
ll a[400005], w[400005];
map<ll, ll> cnt;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i] %= m;
        a[i + n] = a[i];
    }
    
    ll an = 0;
    cnt[0] = 1;
    
    for (int i = 1; i <= 2 * n; i++) {
        w[i] = (w[i-1] + a[i]) % m;
        
        if (i >= n) {
            an += cnt[w[i]];
        }
        
        if (i >= n) {
            cnt[w[i - n]]--;
            if (cnt[w[i - n]] == 0) {
                cnt.erase(w[i - n]);
            }
        }
        
        cnt[w[i]]++;
    }
    
    cout << an;
    return 0;
}