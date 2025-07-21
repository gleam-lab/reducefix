#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> b(n - 1);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n - 1; ++i) {
        cin >> b[i];
    }
    
    sort(a.begin(), a.end(), greater<int>());
    sort(b.begin(), b.end(), greater<int>());
    
    int x = -1;
    int j = 0;
    for (int i = 0; i < n; ++i) {
        if (j < n - 1 && a[i] <= b[j]) {
            ++j;
        } else {
            x = a[i];
            break;
        }
    }
    
    if (x == -1) {
        cout << 1 << endl;
        return 0;
    }
    
    vector<int> new_b;
    for (int i = 0; i < n - 1; ++i) {
        if (i != j - 1) {
            new_b.push_back(b[i]);
        }
    }
    new_b.push_back(x);
    sort(new_b.begin(), new_b.end(), greater<int>());
    
    bool possible = true;
    int k = 0;
    for (int i = 0; i < n; ++i) {
        if (k < n && a[i] <= new_b[k]) {
            ++k;
        } else {
            possible = false;
            break;
        }
    }
    
    if (possible) {
        cout << x << endl;
    } else {
        cout << -1 << endl;
    }
    
    return 0;
}