#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

const int MAX_N = 200010; // Using 200010 to handle -10^8 coordinate values
int a[MAX_N];

void solve() {
    int N, Q;
    cin >> N >> Q;

    // Reading the coordinates of points A
    for (int i = 1; i <= N; ++i) {
        int x;
        cin >> x;
        a[x + 100000000]++; // Offset by 100000000 to handle negative values
    }

    // Prefix sum to calculate the number of points up to each position
    for (int i = 1; i < MAX_N; ++i) {
        a[i] += a[i - 1];
    }

    // Processing each query
    for (int j = 1; j <= Q; ++j) {
        int b, k;
        cin >> b >> k;
        
        // Binary search to find the k-th closest point to b
        int l = 0, r = 2e8;
        while (r - l > 1) {
            int mid = (l + r) / 2;
            if (a[mid + 100000000] - a[max(0, b + mid - 100000000) - 1] >= k) {
                r = mid;
            } else {
                l = mid;
            }
        }

        // Output the k-th closest distance
        cout << r << endl;
    }
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}