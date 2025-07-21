#include<bits/stdc++.h>
using namespace std;
int n, q, x[200005], p[200005];
map<int, int> sum;

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> x[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
        sum[x[i]] = sum[x[i - 1]] + p[i - 1]; // Adjust the index here to match the prefix sums
    }
    cin >> q;
    while (q--) {
        int L, R;
        cin >> L >> R;
        int c = lower_bound(x + 1, x + n + 1, L) - x;
        int d = upper_bound(x + 1, x + n + 1, R) - x;
        // Adjust the range calculation to be inclusive of the lower bound
        c = (c == 1) ? 1 : c;
        cout << sum[x[d]] - sum[x[c - 1]] << endl; // Use the correct indices to compute the sum
    }
}