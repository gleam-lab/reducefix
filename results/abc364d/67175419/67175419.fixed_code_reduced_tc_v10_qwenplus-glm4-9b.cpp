#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;

int main() {
    int n, q;
    cin >> n >> q;
    vector<int> a(N);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());

    for (int j = 0; j < q; j++) {
        int b, k;
        cin >> b >> k;
        int kth_closest = a[k - 1];
        cout << abs(kth_closest - b) << '\n';
    }

    return 0;
}