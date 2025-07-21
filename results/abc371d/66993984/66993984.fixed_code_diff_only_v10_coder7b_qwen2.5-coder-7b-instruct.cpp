#include<bits/stdc++.h>
using namespace std;

const int MAXN = 200005;

int n, q, x[MAXN], p[MAXN];
map<int, int> prefixSum;

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> x[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
        prefixSum[i] = prefixSum[i - 1] + p[i];
    }

    cin >> q;
    while (q--) {
        int L, R;
        cin >> L >> R;
        
        // Adjusting indices to be zero-based as lower_bound and upper_bound use zero-based indexing
        int c = lower_bound(x + 1, x + n + 1, L) - x - 1;
        int d = upper_bound(x + 1, x + n + 1, R) - x;
        
        // Handling edge case where R is not found in x array
        if (d == 0 || x[d] != R) {
            d--;
        }
        
        cout << prefixSum[d] - prefixSum[c] << endl;
    }

    return 0;
}