#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 2e5 + 5;

ll a[N], b[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < n - 1; ++i) cin >> b[i];
    
    sort(a, a + n);
    sort(b, b + n - 1);
    
    // We need to assign toys to boxes:
    // - Each toy must go into a box of size >= its size
    // - Each box can take at most one toy
    
    // The problem is equivalent to matching with one extra toy (we can buy one extra box)
    
    int j = 0;
    int extra_needed = 0;
    ll x = 0;
    
    for (int i = 0; i < n; ++i) {
        if (j < n - 1 && b[j] >= a[i]) {
            j++;
        } else {
            // This toy needs the extra box
            extra_needed++;
            x = max(x, a[i]);
        }
    }
    
    if (extra_needed <= 1) {
        cout << x << endl;
    } else {
        cout << -1 << endl;
    }
    
    return 0;
}