#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n), b(n - 1);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n - 1; i++) cin >> b[i];
    
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    
    int x = -1;
    int i = 0, j = 0;
    while (i < n && j < n - 1) {
        if (a[i] <= b[j]) {
            i++;
            j++;
        } else {
            if (x == -1) {
                x = a[i];
                i++;
            } else {
                // More than one toy cannot be placed in existing boxes
                cout << -1 << endl;
                return 0;
            }
        }
    }
    
    if (i < n) {
        if (x == -1) {
            x = a[i];
        } else {
            // More than one toy cannot be placed in existing boxes
            cout << -1 << endl;
            return 0;
        }
    }
    
    // Now check if the remaining boxes can accommodate all toys except the one that needs x
    // We need to ensure that all toys <= x can be placed in the boxes
    // But since x is the minimal size that wasn't placed, the previous ones are already placed
    // So the answer is x
    cout << x << endl;
    
    return 0;
}