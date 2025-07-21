#include<bits/stdc++.h>
using namespace std;

int n, q, x[200005], p[200005];
long long sum[200005]; // Changed to long long to prevent overflow

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> x[i];
    }
    for(int i = 1; i <= n; i++) {
        cin >> p[i];
        sum[i] = sum[i-1] + p[i]; // Accumulate as long long
    }
    
    cin >> q;
    while(q--) {
        int l, r;
        cin >> l >> r;
        int left_pos = lower_bound(x+1, x+n+1, l) - x;
        int right_pos = upper_bound(x+1, x+n+1, r) - x;
        cout << (sum[right_pos-1] - sum[left_pos-1]) << '\n';
    }
    
    return 0;
}