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

    int ans = -1;
    for (int i = 0; i < n - 1; ++i) {
        if (a[i + 1] <= b[i]) {
            ans = max(ans, a[i]);
        } else {
            break;
        }
    }

    if (ans == -1 && a[n - 1] <= b[n - 2]) {
        ans = a[n - 1];
    }

    cout << ans << endl;
    return 0;
}