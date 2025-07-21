#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
int n, q;
int a[N];

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> q;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    sort(a, a + n);

    while (q--) {
        int b, k;
        cin >> b >> k;

        // Binary search for the k-th closest point to b
        int l = 0, r = n - 1;
        while (r - l > 1) {
            int m = (l + r) / 2;
            if (a[m] >= b) {
                r = m;
            } else {
                l = m;
            }
        }

        // Calculate the distances from b to the closest points and find the k-th closest
        int dist1 = abs(a[l] - b);
        int dist2 = (r < n) ? abs(a[r] - b) : __INT_MAX__;
        int closest = (dist1 < dist2) ? dist1 : dist2;
        cout << closest << '\n';
    }

    return 0;
}