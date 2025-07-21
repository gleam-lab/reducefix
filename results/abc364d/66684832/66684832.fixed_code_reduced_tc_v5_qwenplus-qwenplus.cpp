#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define int long long
#define endl '\n'

const int N = 2e5 + 9;

int n, q;
int a[N];

// Binary search to find the k-th smallest distance
int find_kth_distance(int b, int k) {
    // Binary search bounds based on coordinate range
    int left = 0, right = 2e8 + 10;
    while (left < right) {
        int mid = (left + right) / 2;
        
        // Find number of elements in a[] whose distance to b is <= mid
        int l = lower_bound(a + 1, a + n + 1, b - mid) - a;
        int r = upper_bound(a + 1, a + n + 1, b + mid) - a;
        int count = r - l;

        if (count >= k)
            right = mid;
        else
            left = mid + 1;
    }
    return left;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> q;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    
    sort(a + 1, a + n + 1);  // Sort A points

    while (q--) {
        int b, k;
        cin >> b >> k;
        cout << find_kth_distance(b, k) << endl;
    }

    return 0;
}