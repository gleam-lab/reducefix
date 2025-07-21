#include<bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 5;
long long x[MAXN], p[MAXN];
long long sum[MAXN];

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    
    int n, q;
    cin >> n;
    for(int i = 1; i <= n; ++i) cin >> x[i];
    for(int i = 1; i <= n; ++i) cin >> p[i];
    
    sum[0] = 0;
    for(int i = 1; i <= n; ++i) sum[i] = sum[i-1] + p[i];
    
    cin >> q;
    while(q--) {
        int L, R;
        cin >> L >> R;
        
        int left = lower_bound(x + 1, x + n + 1, L) - x;
        int right = upper_bound(x + 1, x + n + 1, R) - x;
        
        if(left == right) continue; // No valid range found
        
        cout << sum[right-1] - sum[left-1] << '\n';
    }
    
    return 0;
}