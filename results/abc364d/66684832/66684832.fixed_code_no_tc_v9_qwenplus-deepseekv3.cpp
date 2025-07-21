#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define int long long

const int N = 1e5 + 5;
int a[N];

int find_kth_distance(int n, int b, int k) {
    int left = 0, right = 2e14; // Sufficiently large to cover all possible distances
    int answer = 0;
    while (left <= right) {
        int mid = (left + right) / 2;
        // Count the number of elements <= b + mid and >= b - mid
        auto lower = lower_bound(a, a + n, b - mid);
        auto upper = upper_bound(a, a + n, b + mid);
        int count = upper - lower;
        if (count >= k) {
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

    int N, Q;
    cin >> N >> Q;
    for (int i = 0; i < N; ++i) {
        cin >> a[i];
    }
    sort(a, a + N);

    while (Q--) {
        int b, k;
        cin >> b >> k;
        cout << find_kth_distance(N, b, k) << '\n';
    }

    return 0;
}