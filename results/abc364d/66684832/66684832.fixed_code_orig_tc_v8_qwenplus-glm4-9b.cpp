#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int N = 2e5 + 9;
int n, q;
int a[N], b[N], k[N];

bool check_distance(int dist) {
    int count = 0;
    for (int i = 1; i <= n; i++) {
        if (abs(a[i] - b) <= dist) count++;
    }
    return count >= k[j];
}

int find_distance(int l, int r, int target) {
    while (l < r) {
        int mid = (l + r + 1) / 2;
        if (check_distance(mid)) {
            r = mid - 1;
        } else {
            l = mid;
        }
    }
    return l;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> q;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= q; i++) cin >> b[i] >> k[i];

    for (int j = 1; j <= q; j++) {
        int answer = find_distance(0, 1e9, k[j]);
        cout << answer << "\n";
    }

    return 0;
}