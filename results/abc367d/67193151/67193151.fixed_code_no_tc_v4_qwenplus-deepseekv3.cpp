#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int n,m;
long long a[N*2], prefix[N*2], cnt[N];

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> m;
    for(int i=1; i<=n; i++) {
        cin >> a[i];
        a[i+n] = a[i]; // Make circular
    }
    
    prefix[0] = 0;
    for(int i=1; i<=2*n; i++) {
        prefix[i] = prefix[i-1] + a[i];
    }
    
    long long res = 0;
    cnt[0] = 1; // For empty prefix
    
    for(int i=1; i<=n; i++) {
        int mod = (prefix[i] % m + m) % m;
        res += cnt[mod];
        cnt[mod]++;
    }
    
    // Reset for circular counting
    memset(cnt, 0, sizeof(cnt));
    cnt[0] = 1;
    
    for(int i=1; i<=2*n; i++) {
        int mod = (prefix[i] % m + m) % m;
        if(i > n) {
            int prev_mod = (prefix[i-n] % m + m) % m;
            cnt[prev_mod]--;
        }
        res += cnt[mod];
        if(i < n) {
            cnt[mod]++;
        }
    }
    
    cout << res;
    return 0;
}