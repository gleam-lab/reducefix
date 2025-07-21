#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX_VAL = 2e8 + 5;

int n, q;
vector<int> a(MAX_VAL + 1, 0);

bool check(int mid, int k) {
    int count = 0;
    for (int i = -mid; i <= mid; ++i) {
        int left = max(0, i - (1e8 + mid));
        int right = min(MAX_VAL, i + (1e8 + mid));
        count += a[right] - a[left];
    }
    return count >= k;
}

int main() {
    cin >> n >> q;
    for (int i = 0; i < n; ++i) {
        int pos;
        cin >> pos;
        a[pos]++;
    }

    for (int i = 0; i < q; ++i) {
        int b, k;
        cin >> b >> k;
        int l = -1e8 - 1, r = 1e8 + 1;
        while (l + 1 < r) {
            int mid = (l + r) / 2;
            if (check(mid, k)) {
                l = mid;
            } else {
                r = mid;
            }
        }
        cout << l + 1 << '\n';
    }

    return 0;
}