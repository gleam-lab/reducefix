#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> b(n - 1);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n - 1; i++) cin >> b[i];
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    int ans;
    bool ok = true;

    for (int i = 0; i < n - 1; i++) {
        if (a[i] > b[i]) {
            cout << "-1" << endl;
            return 0;
        }
    }
    for (int i = n - 2; i >= 0; i--) {
        if (a[i + 1] > b[i]) {
            cout << a[i + 1] << endl;
            return 0;
        }
    }
    cout << a[0] << endl;
}