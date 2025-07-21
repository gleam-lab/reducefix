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

    vector<int> unmatched;
    int i = 0, j = 0;
    while (i < n && j < n - 1) {
        if (a[i] <= b[j]) {
            i++;
            j++;
        } else {
            j++;
        }
    }
    if (i < n) {
        if (n - i > 1) {
            cout << -1 << endl;
        } else {
            cout << a.back() << endl;
        }
    } else {
        cout << -1 << endl;
    }
    return 0;
}