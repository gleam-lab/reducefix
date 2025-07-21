#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int N = 2e5 + 10;

int n, q;
int a[N], b[N];

int getKth(int x, int k) {
    int left = 0, right = n;
    while (left < right) {
        int mid = (left + right) / 2;
        if (b[mid] < x) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    return left - k;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> q;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < q; ++i) {
        cin >> b[i] >> b[i + 1];
        b[i] = lower_bound(a, a + n, b[i]) - a;
        b[i + 1] = b[i] + b[i + 1] - 1;
    }
    int now = 0;
    for (int i = 0; i < q; ++i) {
        cout << abs(a[getKth(now, b[i])] - b[i + 1]) << endl;
        now = max(now, getKth(now, b[i]));
    }
    return 0;
}