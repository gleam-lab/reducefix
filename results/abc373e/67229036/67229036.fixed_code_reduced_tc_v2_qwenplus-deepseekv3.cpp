#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5 + 5;
int n, m, k, a[N], sorted_a[N], prefix[N];

bool is_possible(int candidate, int x) {
    int total_votes = a[candidate] + x;
    int pos = upper_bound(sorted_a + 1, sorted_a + n + 1, total_votes) - sorted_a - 1;
    int count = n - pos;
    if (count < m) {
        return true;
    }
    return false;
}

int find_min_votes(int candidate) {
    int low = 0, high = k;
    int result = -1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (is_possible(candidate, mid)) {
            result = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return result;
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        sorted_a[i] = a[i];
    }
    sort(sorted_a + 1, sorted_a + n + 1);
    for (int i = 1; i <= n; i++) {
        prefix[i] = prefix[i - 1] + sorted_a[i];
    }
    int remaining_votes = k;
    for (int i = 1; i <= n; i++) {
        remaining_votes -= a[i];
    }
    for (int i = 1; i <= n; i++) {
        int min_votes = find_min_votes(i);
        if (min_votes != -1 && min_votes <= remaining_votes) {
            cout << min_votes << " ";
        } else {
            cout << "-1 ";
        }
    }
    cout << endl;
    return 0;
}