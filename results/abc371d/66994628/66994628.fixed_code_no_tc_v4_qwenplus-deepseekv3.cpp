#include<bits/stdc++.h>
using namespace std;
const int MAXN = 200005;
int n, q, x[MAXN], p[MAXN];
long long sum[MAXN]; // Using long long to prevent overflow

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> x[i];
    }
    for(int i = 1; i <= n; i++) {
        cin >> p[i];
        sum[i] = sum[i-1] + p[i];
    }
    
    cin >> q;
    while(q--) {
        int l, r;
        cin >> l >> r;
        
        // Find first x[i] >= l
        int left = lower_bound(x + 1, x + n + 1, l) - x;
        // Find first x[i] > r
        int right = upper_bound(x + 1, x + n + 1, r) - x;
        
        // The sum includes x[left] to x[right-1]
        cout << sum[right-1] - sum[left-1] << '\n';
    }
    return 0;
}