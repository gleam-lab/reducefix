#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int INF = 1e9 + 7;

int main() {
    int n, q;
    cin >> n >> q;
    vector<int> a;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        a.push_back(x);
    }

    while (q--) {
        int b, k;
        cin >> b >> k;
        // Binary search to find the k-th closest point
        int low = 0, high = n - 1;
        while (low < high) {
            int mid = (low + high + 1) >> 1;
            if ((a[mid] - b) * k > (a[mid - 1] - b) * k) {
                low = mid;
            } else {
                high = mid - 1;
            }
        }
        // Output the k-th closest distance
        cout << (a[low] - b) * k << '\n';
    }

    return 0;
}