#include <iostream>
#include <vector>
using namespace std;

int n, x[200050], p[200050], a[200050];
int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> x[i];
    a[1] = x[1]; // Initialize the first prefix sum
    for (int i = 2; i <= n; i++) {
        a[i] = a[i-1] + p[i-1];
    }
    int q;
    cin >> q;
    while (q--) {
        int l, r;
        cin >> l >> r;
        int low = 1, high = n, bestL = 1, bestR = 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (x[mid] >= l && x[mid] <= r) {
                high = mid - 1;
                bestL = mid;
                bestR = mid;
            } else if (x[mid] < l) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        cout << a[bestR] - a[bestL - 1] << endl;
    }
    return 0;
}