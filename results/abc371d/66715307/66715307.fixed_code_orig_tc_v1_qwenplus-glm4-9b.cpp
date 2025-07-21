#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, q;
    cin >> n;
    vector<int> x(n + 1), p(n + 1), a(n + 1);

    // Read values of x
    for (int i = 1; i <= n; i++) cin >> x[i];

    // Compute prefix sums of p to get a
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
        a[i] = a[i - 1] + p[i];
    }

    cin >> q;

    while (q--) {
        int l, r;
        cin >> l >> r;

        // Binary search to find the left boundary (l1)
        int l1 = 1, r1 = n;
        while (l1 < r1) {
            int mid = l1 + (r1 - l1 + 1) / 2;
            if (x[mid] >= l) r1 = mid;
            else l1 = mid;
        }

        // Binary search to find the right boundary (l2)
        int l2 = 1, r2 = n;
        while (l2 < r2) {
            int mid = l2 + (r2 - l2 + 1) / 2;
            if (x[mid] <= r) l2 = mid + 1;
            else r2 = mid;
        }

        // Calculate and print the result
        cout << a[l2 - 1] - a[l1 - 1] << endl;
    }

    return 0;
}