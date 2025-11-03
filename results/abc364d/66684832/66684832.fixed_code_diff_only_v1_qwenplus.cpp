#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define int long long
const int N = 2e5 + 9;

int n, q;
int a[N];

// Check if there are at least k points within distance 'dist' from position 'pos'
bool check(int pos, int dist, int k) {
    // Find the leftmost index >= (pos - dist)
    int left_idx = lower_bound(a + 1, a + n + 1, pos - dist) - a;
    // Find the rightmost index <= (pos + dist), upper_bound gives first > so subtract 1
    int right_idx = upper_bound(a + 1, a + n + 1, pos + dist) - a - 1;
    
    int count = right_idx - left_idx + 1;
    return count >= k;
}

int findans(int pos, int k) {
    int l = 0, r = 2e8;  // Max possible distance is 2*10^8
    int ans = r;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (check(pos, mid, k)) {
            ans = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    return ans;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);

    while (q--) {
        int x, k;
        cin >> x >> k;
        cout << findans(x, k) << '\n';
    }

    return 0;
}