#include<bits/stdc++.h>
using namespace std;
using LL = __int128;
typedef long long ll;

const int N = 1e6 + 7;
int main() {
    int n, m;
    cin >> n;
    vector<int> a(n + 1), b(n + 1), c(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    c[1] = b[1] = a[1]; // Initialize to the first element of a
    for (int i = 2; i <= n; ++i) {
        b[i] = a[i];
        c[i] = c[i - 1] + b[i];
    }
    
    cin >> m;
    while (m--) {
        int l, r;
        cin >> l >> r;
        if (l == 1) {
            cout << c[r] << endl;
        } else if (r == n) {
            cout << c[n] - c[l - 1] << endl;
        } else {
            cout << c[r] - c[l - 1] << endl;
        }
    }
    return 0;
}