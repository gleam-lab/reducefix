#include<bits/stdc++.h>
using namespace std;
int n, q, x[200005];
long long p_prefix[200005];  // Use long long to avoid integer overflow

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> x[i];
    }
    
    p_prefix[0] = 0;
    for (int i = 1; i <= n; ++i) {
        int p;
        cin >> p;
        p_prefix[i] = p_prefix[i - 1] + p;
    }
    
    cin >> q;
    while (q--) {
        int L, R;
        cin >> L >> R;
        
        // Find first index where x[i] >= L
        int left = lower_bound(x + 1, x + n + 1, L) - x;
        // Find first index where x[i] > R
        int right = upper_bound(x + 1, x + n + 1, R) - x;
        
        cout << p_prefix[right - 1] - p_prefix[left - 1] << "\n";
    }
    
    return 0;
}