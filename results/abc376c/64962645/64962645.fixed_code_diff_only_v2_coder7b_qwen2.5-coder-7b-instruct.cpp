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

    // Find the smallest box size that can accommodate all toys
    int x = -1;
    for (int i = 0; i < n - 1; ++i) {
        if (a[i] <= b[i]) {
            x = b[i];
            break;
        }
    }

    // If no such box is found, check if the largest toy can fit in any box
    if (x == -1 && a.back() <= b.back()) {
        x = a.back();
    }

    cout << x << endl;
    return 0;
}