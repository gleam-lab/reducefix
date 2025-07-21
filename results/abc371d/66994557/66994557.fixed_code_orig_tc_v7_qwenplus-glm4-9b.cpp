#include<bits/stdc++.h>
using namespace std;

int n, q;
int x[200005], p[200005], sum[2000005];

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> x[i];
    }
    
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
        sum[i] = sum[i - 1] + p[i];
    }
    
    cin >> q;
    while (q--) {
        int L, R;
        cin >> L >> R;
        
        // Handle cases where L or R are outside the range of x
        int l = lower_bound(x + 1, x + n + 1, L) - (x + 1);
        if (l == 0 || x[l] > L) l = 1;
        
        int r = upper_bound(x + 1, x + n + 1, R) - (x + 1);
        if (r == 0 || x[r - 1] < R) r = n;
        
        cout << sum[r] - sum[l - 1] << endl;
    }
    
    return 0;
}