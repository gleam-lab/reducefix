#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define int long long
#define endl '\n'

const int N = 1e5 + 9;
int a[N];

int count_points(int n, int b, int dx) {
    int left = lower_bound(a + 1, a + n + 1, b - dx) - a;
    int right = upper_bound(a + 1, a + n + 1, b + dx) - a;
    return right - left;
}

int find_kth_distance(int n, int b, int k) {
    int low = 0;
    int high = 2e18; // Sufficiently large to cover all possible distances
    
    while (low < high) {
        int mid = low + (high - low) / 2;
        if (count_points(n, b, mid) >= k) {
            high = mid;
        } else {
            low = mid + 1;
        }
    }
    return low;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);

    while (q--) {
        int b, k;
        cin >> b >> k;
        cout << find_kth_distance(n, b, k) << endl;
    }

    return 0;
}