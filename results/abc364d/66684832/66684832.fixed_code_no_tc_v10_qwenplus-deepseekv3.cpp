#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define int long long
#define endl '\n'

const int N = 1e5 + 5;
int a[N];

int count_points(int n, int x, int d) {
    int left = x - d;
    int right = x + d;
    int l = lower_bound(a, a + n, left) - a;
    int r = upper_bound(a, a + n, right) - a;
    return r - l;
}

int find_kth_distance(int n, int x, int k) {
    int low = 0, high = 2e8;
    int ans = 0;
    while (low <= high) {
        int mid = (low + high) / 2;
        int cnt = count_points(n, x, mid);
        if (cnt >= k) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return ans;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, q;
    cin >> n >> q;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a, a + n);

    while (q--) {
        int x, k;
        cin >> x >> k;
        vector<int> distances(n);
        for (int i = 0; i < n; ++i) {
            distances[i] = abs(a[i] - x);
        }
        nth_element(distances.begin(), distances.begin() + k - 1, distances.end());
        cout << distances[k - 1] << endl;
    }

    return 0;
}