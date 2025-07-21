#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, q;
    cin >> n >> q;

    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    for (int i = 0; i < q; ++i) {
        int b, k;
        cin >> b >> k;

        // Find the k-th closest point
        int l = 1, r = n;
        while (l < r) {
            int mid = (l + r) / 2;
            int count = 0;
            for (int j = 1; j <= n; ++j) {
                if (abs(a[j] - b) <= mid) {
                    count++;
                }
            }
            if (count >= k) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }

        // Output the distance between the k-th closest point and b
        cout << abs(a[l] - b) << endl;
    }

    return 0;
}