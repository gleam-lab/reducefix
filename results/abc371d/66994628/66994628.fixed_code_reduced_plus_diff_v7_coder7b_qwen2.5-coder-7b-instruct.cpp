#include<bits/stdc++.h>
using namespace std;

const int MAXN = 200005;
int n, q, x[MAXN], p[MAXN];
long long sum[MAXN];

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> x[i];
    }
    for (int i = 1; i <= n; ++i) {
        cin >> p[i];
        sum[i] = sum[i - 1] + p[i];
    }
    
    cin >> q;
    while (q--) {
        int l, r;
        cin >> l >> r;
        // Adjusting indices for zero-based indexing
        --l, --r;
        
        // Using prefix sums to calculate the range sum efficiently
        long long result = sum[r] - sum[l];
        cout << result << endl;
    }

    return 0;
}