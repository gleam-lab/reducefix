#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n), b(n - 1);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n - 1; ++i) {
        cin >> b[i];
    }
    
    sort(a.begin(), a.end(), greater<int>());
    sort(b.begin(), b.end(), greater<int>());
    
    int k = 0;
    bool possible = true;
    for (int i = 0; i < n - 1; ++i) {
        if (a[i] > b[i]) {
            possible = false;
            break;
        }
    }
    
    if (!possible) {
        cout << -1 << endl;
        return 0;
    }
    
    // The remaining toy is a[n-1], which needs to fit into the new box of size x >= a[n-1]
    cout << a[n - 1] << endl;
    return 0;
}