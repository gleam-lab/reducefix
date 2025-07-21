#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
#define int long long

const int N = 1e5 + 5;
int a[N];

int find_kth_closest(int n, int x, int k) {
    vector<int> distances(n);
    for (int i = 0; i < n; ++i) {
        distances[i] = abs(a[i] - x);
    }
    nth_element(distances.begin(), distances.begin() + k - 1, distances.end());
    return distances[k - 1];
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q;
    cin >> N >> Q;
    for (int i = 0; i < N; ++i) {
        cin >> a[i];
    }
    sort(a, a + N);

    while (Q--) {
        int b, k;
        cin >> b >> k;
        int low = 0;
        int high = 2e8;
        int answer = 0;

        while (low <= high) {
            int mid = (low + high) / 2;
            int left = lower_bound(a, a + N, b - mid) - a;
            int right = upper_bound(a, a + N, b + mid) - a;
            int count = right - left;

            if (count >= k) {
                answer = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        cout << answer << '\n';
    }

    return 0;
}