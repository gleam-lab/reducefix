#include<bits/stdc++.h>
#define endl "\n"
using namespace std;

const int N = 100005; // Adjusted size based on the problem constraints
int a[N];

bool check(int mid, int x, int y) {
    // Calculate the distance and check if it's within the k-th closest range
    int dis = abs(a[mid] - x) + y; // We use a[mid] directly here for optimization
    return dis >= y;
}

void solve(void) {
    int n, q; cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        int x; cin >> x;
        // Store distances from the origin for each point
        a[i] = abs(x);
    }
    // Sort to find the k-th closest point
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= q; i++) {
        int b, k; cin >> b >> k;
        // Binary search for the k-th closest point
        int l = 0, r = n;
        while (r > l) {
            int mid = l + (r - l + 1) / 2;
            if (check(mid, b, k)) r = mid;
            else l = mid;
        }
        // Output the result
        cout << a[l] << endl;
    }
}

int main() {
    solve();
    return 0;
}