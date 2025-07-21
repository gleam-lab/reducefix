#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 200005;

ll a[N], b[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    
    for (int i = 1; i < n; ++i) {
        cin >> b[i];
    }
    
    // Sort toys and boxes in ascending order
    sort(a + 1, a + n + 1);
    sort(b + 1, b + n);
    
    ll need = -1;
    int j = 1;
    
    // Try to assign toys to boxes greedily
    for (int i = 1; i < n; ++i) {
        if (j <= n && b[i] >= a[j]) {
            j++;
        } else {
            // Need an extra box for the largest remaining toy
            if (need != -1) {
                cout << -1 << endl;
                return 0;
            }
            need = a[n];
            n--;  // Remove that toy from consideration
            i--;  // Don't consume a box this iteration
        }
    }
    
    // If we still have one toy left, we need a box for it
    if (j <= n) {
        if (need != -1) {
            cout << -1 << endl;
        } else {
            cout << a[n] << endl;
        }
    } else {
        if (need == -1) cout << 0 << endl;
        else cout << need << endl;
    }
    
    return 0;
}