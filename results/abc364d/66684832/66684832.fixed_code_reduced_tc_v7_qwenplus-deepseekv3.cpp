#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define int long long

const int N = 1e5 + 5;

int n, q;
int a[N];

bool check(int pos, int mid, int k) {
    int left = lower_bound(a + 1, a + n + 1, pos - mid) - a;
    int right = upper_bound(a + 1, a + n + 1, pos + mid) - a;
    return (right - left) >= k;
}

int findans(int pos, int k) {
    int left = 0;
    int right = 2e18; // Sufficiently large to cover all possible distances
    int answer = 2e18;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (check(pos, mid, k)) {
            answer = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return answer;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> q;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);

    while (q--) {
        int pos, k;
        cin >> pos >> k;
        cout << findans(pos, k) << '\n';
    }

    return 0;
}