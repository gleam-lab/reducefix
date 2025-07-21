#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

const int MAX_COORDINATE = 2e8 + 1;
int n, q;
vector<int> a(MAX_COORDINATE);

int main() {
    cin >> n >> q;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        a[x]++;
    }

    for (int i = 1; i < MAX_COORDINATE; ++i) {
        a[i] += a[i - 1];
    }

    for (int i = 0; i < q; ++i) {
        int b, k;
        cin >> b >> k;
        int l = 0, r = n - 1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (a[mid] >= k) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }

        // Find the k-th closest point to b
        int ans = 0;
        for (int j = min(l, n - 1); j >= 0; --j) {
            if (a[j] >= k) {
                ans = j;
                k -= a[j];
            }
        }
        cout << abs(ans - b) << endl;
    }

    return 0;
}