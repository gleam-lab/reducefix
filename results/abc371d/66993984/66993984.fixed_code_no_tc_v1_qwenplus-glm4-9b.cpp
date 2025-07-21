#include<bits/stdc++.h>
using namespace std;
int n, q;
int x[200005], p[200005];
map<int, int> sum;

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> x[i];
    }
    
    // Initialize the prefix sum map
    sum[x[1]] = p[1];
    
    // Fill the prefix sum map
    for (int i = 2; i <= n; i++) {
        sum[x[i]] = sum[x[i - 1]] + p[i];
    }
    
    cin >> q;
    while (q--) {
        int L, R;
        cin >> L >> R;
        
        // Adjust L and R to be zero-indexed
        int c = lower_bound(x + 1, x + n + 1, L) - x;
        int d = upper_bound(x + 1, x + n + 1, R) - x;
        
        // Use the prefix sum map to calculate the sum of p[i] from L to R
        cout << sum[x[d]] - sum[x[c]] << endl;
    }
    
    return 0;
}