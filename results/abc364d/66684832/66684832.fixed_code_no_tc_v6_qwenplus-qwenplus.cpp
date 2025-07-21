#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define int long long
const int INF = 1e18;

int n, q;
int a[100005];

// Binary search to find the k-th smallest distance
int query(int b, int k) {
    int left = 0;
    int right = 2e8; // Max possible distance is 2*1e8
    int answer = right;

    while (left <= right) {
        int mid = (left + right) / 2;
        // Find first position where a[i] >= b - mid
        int l = lower_bound(a, a + n, b - mid) - a;
        // Find first position where a[i] > b + mid
        int r = upper_bound(a, a + n, b + mid) - a;
        int count = r - l;

        if (count >= k) {
            answer = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    return answer;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> q;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a, a + n);

    for (int i = 0; i < q; ++i) {
        int b, k;
        cin >> b >> k;
        cout << query(b, k) << "\n";
    }

    return 0;
}