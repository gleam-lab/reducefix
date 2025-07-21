#include <iostream>
#include <vector>
using namespace std;

int n, q;
vector<int> x, p, a;

int main() {
    cin >> n;
    x.assign(n + 1, 0); // Initialize the vector of size n+1

    for (int i = 1; i <= n; ++i) {
        cin >> x[i];
    }

    for (int i = 1; i <= n; ++i) {
        cin >> p[i];
        if (i == 1) {
            a[i] = p[i];
        } else {
            a[i] = a[i - 1] + p[i];
        }
    }

    cin >> q;
    while (q--) {
        int l, r;
        cin >> l >> r;
        // Binary search to find the smallest index with value >= l
        int l1 = 1, r1 = n;
        while (l1 < r1) {
            int mid = l1 + (r1 - l1 + 1) / 2;
            if (x[mid] < l) {
                r1 = mid - 1;
            } else {
                l1 = mid;
            }
        }

        // Binary search to find the largest index with value <= r
        int l2 = 1, r2 = n;
        while (l2 < r2) {
            int mid = l2 + (r2 - l2 + 1) / 2;
            if (x[mid] > r) {
                r2 = mid - 1;
            } else {
                l2 = mid;
            }
        }

        // Output the sum for the range
        cout << a[l2] << " - " << (l1 > 0 ? a[l1 - 1] : 0) << endl;
    }
    return 0;
}