#include<bits/stdc++.h>
using namespace std;

const int N = 100005; // Maximum N + Q
int a[N], cnt[N];

bool check(int mid, int x, int y) {
    // Calculate the number of A's within distance 'mid' from B
    int left = max(0, x - mid);
    int right = min(N - 1, x + mid);
    if (left > right) {
        return true; // If no A's are within the range, then the condition is satisfied
    }
    int count = cnt[right];
    if (left > 0) count -= cnt[left - 1];
    return count >= y;
}

void solve() {
    int n, q;
    cin >> n >> q;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    // Precompute the count of A's up to each point
    for (int i = 0; i < n; ++i) {
        cnt[a[i]]++;
    }
    for (int i = 1; i < n; ++i) {
        cnt[a[i]] += cnt[a[i - 1]];
    }
    for (int i = 0; i < q; ++i) {
        int x, k;
        cin >> x >> k;
        int l = 0, r = 1e10;
        while (r - l > 1) {
            int mid = (l + r) / 2;
            if (check(mid, x, k)) {
                r = mid;
            } else {
                l = mid;
            }
        }
        cout << r << '\n';
    }
}

int main() {
    solve();
    return 0;
}