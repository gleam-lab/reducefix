#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define int long long

const int N = 1e5 + 10;
int a[N];

int count_within_distance(int n, int b, int d) {
    int left = lower_bound(a, a + n, b - d) - a;
    int right = upper_bound(a, a + n, b + d) - a;
    return right - left;
}

int find_kth_distance(int n, int b, int k) {
    int low = 0;
    int high = 2e8;  // Maximum possible distance based on constraints
    int answer = high;
    while (low <= high) {
        int mid = (low + high) / 2;
        int count = count_within_distance(n, b, mid);
        if (count >= k) {
            answer = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return answer;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a, a + n);

    while (q--) {
        int b, k;
        cin >> b >> k;
        cout << find_kth_distance(n, b, k) << '\n';
    }

    return 0;
}