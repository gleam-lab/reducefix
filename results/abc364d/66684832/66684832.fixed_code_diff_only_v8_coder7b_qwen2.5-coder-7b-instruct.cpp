#include <iostream>
#include<algorithm>
#include<queue>
#include<map>
#include<vector>
#include<cstring>
using namespace std;

#define int long long
#define endl '\n'

const int N = 2e5 + 9, inf = 0x3f3f3f3f3f3f3f3f;

int n, m, cnt, ans, q;
int a[N], b[N], k[N];

// Function to find the k-th smallest element using binary search
int findKthSmallest(int target, int k) {
    int left = 0, right = 1e8;
    while (left < right) {
        int mid = (left + right) / 2;
        int count = 0;
        
        // Count how many elements are less than or equal to mid
        for (int i = 1; i <= n; ++i) {
            if (abs(a[i] - target) <= mid) {
                count++;
            }
        }
        
        if (count < k) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    return left;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> q;
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + n + 1);

    for (int i = 1; i <= q; i++) {
        cin >> b[i] >> k[i];
        cout << findKthSmallest(b[i], k[i]) << endl;
    }

    return 0;
}