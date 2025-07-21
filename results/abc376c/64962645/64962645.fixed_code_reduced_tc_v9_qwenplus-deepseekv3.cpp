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
    
    int k = -1;
    for (int i = 0; i < n; ++i) {
        if (i < n - 1 && a[i] > b[i]) {
            k = i;
            break;
        }
        if (i == n - 1) {
            k = n - 1;
            break;
        }
    }
    
    if (k == -1) {
        cout << a.back() << endl;
        return 0;
    }
    
    int x = a[k];
    vector<int> new_b = b;
    new_b.push_back(x);
    sort(new_b.begin(), new_b.end(), greater<int>());
    
    bool possible = true;
    for (int i = 0; i < n; ++i) {
        if (a[i] > new_b[i]) {
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