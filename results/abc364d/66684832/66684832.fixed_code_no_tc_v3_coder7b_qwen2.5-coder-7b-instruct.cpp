#include <iostream>
#include<algorithm>
#include<queue>
#include<map>
#include<vector>
#include<cstring>
using namespace std;

const int MAXN = 1e5 + 7;
long long a[MAXN];

// Function to binary search for the k-th smallest distance
long long binarySearch(long long target, int k) {
    long long left = 0, right = 1e8, mid;
    while (left < right) {
        mid = (left + right) / 2;
        int count = 0;
        for (int i = 0; i < target; ++i) {
            if (abs(a[i] - target) <= mid) {
                count++;
            }
        }
        if (count >= k) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    return left;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    // Sort the array of points A
    sort(a, a + n);

    while (q--) {
        int x, k;
        cin >> x >> k;
        // Adjust k because array indices start at 0
        --k;
        // Perform binary search to find the k-th smallest distance
        long long result = binarySearch(n, k + 1);
        // Calculate the actual distance from x to the found point
        cout << abs(x - a[result]) << endl;
    }

    return 0;
}