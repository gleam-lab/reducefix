#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int n, q;
int a[N], b[Q], k[Q];

int check(int mid) {
    int count = 0;
    for (int i = 1; i <= n; i++) {
        if (abs(a[i] - b[mid]) <= abs(a[i] - k[mid])) count++;
    }
    return count >= k[mid];
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> q;
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + n + 1);
    for (int i = 0; i < q; i++) {
        cin >> b[i] >> k[i];
        // Binary search for the k-th closest point
        int l = 1, r = n;
        while (l < r) {
            int mid = (l + r) / 2;
            if (check(mid)) l = mid + 1;
            else r = mid;
        }
        // Output the distance between the k-th closest point and B[i]
        cout << abs(a[l] - b[i]) << "\n";
    }
    return 0;
}