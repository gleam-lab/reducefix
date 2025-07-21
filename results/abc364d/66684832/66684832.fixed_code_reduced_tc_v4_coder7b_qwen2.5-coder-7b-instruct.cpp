#include <iostream>
#include<algorithm>
#include<queue>
#include<map>
#include<vector>
#include<cstring>
using namespace std;

#define int long long
#define endl '\n'

const int MAXN = 1e5 + 9, INF = 0x3f3f3f3f3f3f3f3f;

int n, q;
int a[MAXN];

// Function to find the k-th smallest distance
int findKthSmallestDistance(int target, int k) {
    // Using two pointers to count how many points are within the range [target-d, target+d]
    int left = 0, right = n - 1, count = 0;
    while (left <= right) {
        if (a[right] - a[left] > target * 2) {
            ++left;
        } else {
            ++count;
            --right;
        }
    }
    return count >= k ? target : -1;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> q;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    sort(a + 1, a + n + 1);

    while (q--) {
        int x, k;
        cin >> x >> k;
        int low = 0, high = 2e8;
        while (low < high) {
            int mid = (low + high) / 2;
            if (findKthSmallestDistance(mid, k) == -1) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }
        cout << low << endl;
    }

    return 0;
}