#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

const int N = 1e5 + 5;
const int INF = 1e9 + 7;

int a[N];

int main() {
    int n, q;
    cin >> n >> q;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < q; i++) {
        int b, k;
        cin >> b >> k;
        int l = 0, r = n - 1;
        while (l < r) {
            int mid = (l + r) / 2;
            if (a[mid] - b <= k) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        if (a[l] - b <= k) {
            cout << (a[l] - b) * (a[l] - b) << endl;
        } else {
            cout << (b - a[l - 1]) * (b - a[l - 1]) << endl;
        }
    }
    return 0;
}