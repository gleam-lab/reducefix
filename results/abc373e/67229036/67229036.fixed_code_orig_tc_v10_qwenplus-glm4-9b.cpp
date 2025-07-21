#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define int long long
const int N = 2e5 + 5;

int n, m, k;
vector<int> a;

int check(int x, int y) {
    int votes_needed = lower_bound(a.begin(), a.begin() + x, y + 1) - a.begin();
    if (votes_needed < m)
        return 0;
    int votes_left = k - (c[ votes_needed - 1 ] - (x > 0 ? c[0] : 0));
    return (x + y + 1) * (votes_needed - m) - votes_left;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> m >> k;
    a.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a.rbegin(), a.rend()); // Reverse sort for descending order
    vector<int> c(n + 1, 0);
    for (int i = 0, s = 0; i < n; ++i) {
        s += a[i];
        c[i + 1] = s;
    }
    cout << (check(0, 0) >= 0 ? 0 : -1) << " ";
    for (int i = 1; i < n; ++i) {
        int l = a[i] + 1, r = k + 1;
        while (l < r) {
            int mid = l + (r - l + 1) / 2;
            if (check(a[i], mid) >= a[i])
                r = mid;
            else
                l = mid;
        }
        cout << (a[i] + l >= a[0] ? l : -1) << " ";
    }
    return 0;
}