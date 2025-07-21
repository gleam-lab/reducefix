#include<bits/stdc++.h>
using namespace std;
int n, q, x[200005], p[200005];
int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }
    cin >> q;
    while (q--) {
        int l, r;
        cin >> l >> r;
        long long sum = 0;
        for (int i = l - 1; i < r; i++) {
            sum += x[i];
        }
        cout << sum << endl;
    }
    return 0;
}