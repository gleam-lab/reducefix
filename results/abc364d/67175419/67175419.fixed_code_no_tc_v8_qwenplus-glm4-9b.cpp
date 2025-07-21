#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n, q;
int a[N], b[N], k[N];

bool check(int mid, int x, int y) {
    // Calculate the number of points within the range [x-mid, x+mid]
    int left = upper_bound(a + 1, a + n + 1, x - mid) - a - 1;
    int right = lower_bound(a + 1, a + n + 1, x + mid) - a;
    // Check if there are at least k points in the range
    return right - left >= k[mid];
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> q;
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < q; ++i) cin >> b[i] >> k[i];
    sort(a + 1, a + n + 1); // Sort the points on the number line

    // Binary search for each point B_j
    for (int j = 0; j < q; ++j) {
        int left = -1, right = n;
        while (right - left > 1) {
            int mid = left + (right - left) / 2; // Mid point in terms of the number of points
            if (check(mid, b[j], k[j])) {
                left = mid;
            } else {
                right = mid;
            }
        }
        // The distance is the k-th closest point to B_j
        cout << a[left + k[left]] - b[j] << '\n';
    }

    return 0;
}