#include<bits/stdc++.h>
using namespace std;
int n, q, x[200005], p[200005];

int main() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> x[i];
    }
    q = n; // Assuming q is the number of queries
    while(q--) {
        int L, R;
        cin >> L >> R;
        int l = lower_bound(x, x + n, L) - x;
        int r = upper_bound(x, x + n, R) - x;
        cout << x[r - 1] - (l > 0 ? x[l - 1] : 0) << endl; // Subtract the previous element if l > 0
    }
    return 0;
}