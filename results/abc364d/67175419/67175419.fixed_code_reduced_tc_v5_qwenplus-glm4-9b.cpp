#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;

int n, q;
int a[N];
int b[N], k[N];

int check(int x, int y, int z) {
    int left = lower_bound(a + 1, a + n + 1, y - x) - a;
    int right = upper_bound(a + 1, a + n + 1, y + x) - a;
    return right - left >= z;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    for (int i = 0; i < q; i++) {
        cin >> b[i] >> k[i];
    }
    
    for (int i = 0; i < q; i++) {
        int l = 0, r = 1e8;
        while (l < r) {
            int mid = (l + r + 1) / 2; // Use l + r + 1 to ensure the left side is included in the search
            if (check(mid, b[i], k[i])) {
                r = mid - 1;
            } else {
                l = mid;
            }
        }
        cout << l << "\n";
    }
    return 0;
}