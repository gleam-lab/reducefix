#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAXN = 100000;
int a[MAXN + 5];

int main() {
    int n, q;
    cin >> n >> q;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a, a + n); // Sort the points A_i
    for (int i = 0; i < q; ++i) {
        int b, k;
        cin >> b >> k;
        // Calculate the index for the k-th closest point to B_j
        int index = lower_bound(a, a + n, b) - a;
        // Handle the case where there are not enough points
        if (index == 0 && k == 1) {
            cout << 0 << endl;
        } else if (index == 0) {
            cout << (a[index + k - 1] - b) << endl;
        } else if (index + k - 1 >= n) {
            cout << (b - a[index - k + 1]) << endl;
        } else {
            cout << min(a[index + k - 1] - b, b - a[index - k + 1]) << endl;
        }
    }
    return 0;
}