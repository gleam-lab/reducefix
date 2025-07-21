#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int n, q, a[N];

int main() {
    cin >> n >> q;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    sort(a + 1, a + n + 1); // Sort the array a

    while (q--) {
        int b, k;
        cin >> b >> k;
        int dist = lower_bound(a + 1, a + n + 1, b) - a; // Find the closest point on a to b
        // Find the k-th closest point to b on a
        int kth_closest = a[dist + k - 1];
        // Output the distance between the k-th closest point and b
        cout << abs(b - kth_closest) << '\n';
    }
    return 0;
}