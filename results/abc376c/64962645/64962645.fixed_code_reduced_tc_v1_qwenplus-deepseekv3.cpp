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
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    
    int needed_x = -1;
    int i = 0, j = 0;
    while (i < n && j < n - 1) {
        if (a[i] <= b[j]) {
            i++;
            j++;
        } else {
            if (needed_x == -1) {
                needed_x = a[i];
                i++;
            } else {
                cout << -1 << endl;
                return 0;
            }
        }
    }
    if (i < n) {
        if (needed_x == -1) {
            needed_x = a.back();
        } else {
            cout << -1 << endl;
            return 0;
        }
    }
    cout << needed_x << endl;
    return 0;
}