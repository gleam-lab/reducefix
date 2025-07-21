#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> b(n - 1);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n - 1; i++) {
        cin >> b[i];
    }
    
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    
    int x = -1;
    bool possible = false;
    
    for (int k = 0; k < n; k++) {
        vector<int> new_b = b;
        if (k == 0) {
            new_b.insert(new_b.begin(), a[n - 1]);
        } else if (k == n) {
            new_b.push_back(a[n - 1]);
        } else {
            new_b.insert(new_b.begin() + k, a[n - 1]);
        }
        sort(new_b.begin(), new_b.end());
        
        bool valid = true;
        for (int i = 0; i < n; i++) {
            if (a[i] > new_b[i]) {
                valid = false;
                break;
            }
        }
        if (valid) {
            if (x == -1 || a[n - 1] < x) {
                x = a[n - 1];
            }
            possible = true;
        }
    }
    
    if (possible) {
        cout << x << endl;
    } else {
        cout << -1 << endl;
    }
    
    return 0;
}