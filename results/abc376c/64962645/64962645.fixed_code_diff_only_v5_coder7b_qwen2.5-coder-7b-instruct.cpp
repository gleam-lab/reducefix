#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n), b(n - 1);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    for (int i = 0; i < n - 1; ++i)
        cin >> b[i];

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    int mx_b = *max_element(b.begin(), b.end());
    if (a.back() <= mx_b) {
        cout << -1 << endl;
        return 0;
    }

    for (int i = 0; i < n - 1; ++i) {
        if (a[i] > b[i]) {
            cout << a[i] << endl;
            return 0;
        }
    }

    cout << a[n - 1] << endl;
    return 0;
}