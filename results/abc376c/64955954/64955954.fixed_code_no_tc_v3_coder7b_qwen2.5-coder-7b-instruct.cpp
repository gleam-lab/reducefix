#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for(int i = 0; i < n; ++i)
        cin >> a[i];
    for(int i = 0; i < n - 1; ++i)
        cin >> b[i];

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    int x = 0;
    for(int i = 0; i < n - 1; ++i) {
        if(b[i] >= a[i + 1]) {
            x = max(x, a[i]);
        } else {
            cout << -1 << '\n';
            return 0;
        }
    }

    x = max(x, a[n - 1]);

    cout << x + 1 << '\n';

    return 0;
}