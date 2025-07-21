#include<bits/stdc++.h>
#define endl "\n"
using namespace std;

const int INF = 1e9 + 7;
const int N = 200000;

int a[N];

int main() {
    int n, q;
    cin >> n >> q;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    for (int i = 1; i < n; ++i) {
        a[i] += a[i - 1];
    }

    for (int j = 0; j < q; ++j) {
        int b, k;
        cin >> b >> k;
        // Linear search to find the k-th closest point to b
        int l = 0, r = n - 1, ans = -1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (a[mid] >= k) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        // Calculate the distance to the found point
        if (ans == -1) {
            cout << "INF" << endl;
        } else {
            cout << abs(a[ans] - b) << endl;
        }
    }

    return 0;
}