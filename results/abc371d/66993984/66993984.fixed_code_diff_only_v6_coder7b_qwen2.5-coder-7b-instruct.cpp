#include<bits/stdc++.h>
using namespace std;

int n, q, x[200005], p[200005];
map<int, int> prefix_sum;

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> x[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
        prefix_sum[x[i]] += p[i]; // Accumulate prefix sums based on x values
    }

    cin >> q;
    while (q--) {
        int L, R;
        cin >> L >> R;
        int result = 0;
        if (prefix_sum.find(R) != prefix_sum.end()) result += prefix_sum[R];
        if (prefix_sum.find(L - 1) != prefix_sum.end()) result -= prefix_sum[L - 1];
        cout << result << endl;
    }
    return 0;
}