#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

int main() {
    int n, q;
    cin >> n >> q;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    while (q--) {
        int b, k;
        cin >> b >> k;
        k--; // Convert to 0-based index

        // Binary search for the k-th closest point
        int low = 0, high = n - 1;
        while (low <= high) {
            int mid = (low + high) / 2;
            ll distance = abs((ll)a[mid] - b);
            if (mid == 0 || abs(a[mid - 1] - b) <= distance) {
                // We found the k-th closest point or we're at the first element
                high = mid - 1;
            } else {
                // We need to go to the right part of the array
                low = mid + 1;
            }
        }

        // Now we have the index of the k-th closest point
        cout << abs((ll)a[low] - b) << endl;
    }

    return 0;
}