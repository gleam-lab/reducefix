#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define int long long
#define endl '\n'

const int N = 1e5 + 9;

int n, q;
int a[N];

signed main() {
    ios::sync_with_stdio(false);
    cin >> n >> q;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a, a + n);

    for (int _ = 0; _ < q; ++_) {
        int b, k;
        cin >> b >> k;
        vector<int> distances;
        // Use binary search to find the closest elements efficiently
        int* pos = lower_bound(a, a + n, b);
        int left = pos - a - 1;
        int right = pos - a;
        int count = 0;
        while (count < k && (left >= 0 || right < n)) {
            if (left < 0) {
                right++;
            } else if (right >= n) {
                left--;
            } else if (abs(a[left] - b) <= abs(a[right] - b)) {
                left--;
            } else {
                right++;
            }
            count++;
        }
        cout << abs((left >= 0 ? a[left] : a[right]) - b) << endl;
    }

    return 0;
}