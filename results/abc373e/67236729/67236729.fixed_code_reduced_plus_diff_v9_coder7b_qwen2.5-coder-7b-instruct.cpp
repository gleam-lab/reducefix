#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200010;
int n, m, k;
long long a[MAXN];

bool check(long long d, int id) {
    long long total_votes = 0;
    int count_greater = 0;
    
    for (int i = 1; i <= n; ++i) {
        if (i == id) continue;
        if (a[id] + d > a[i]) {
            ++count_greater;
            total_votes += a[id] + d - a[i];
        } else {
            total_votes += a[i];
        }
    }

    return count_greater < m && total_votes >= k;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m >> k;
    for (int i = 1; i <= n; ++i) cin >> a[i];

    vector<int> results(n, -1);
    for (int i = 1; i <= n; ++i) {
        long long left = 0, right = k - a[i];
        while (left < right) {
            long long mid = (left + right) / 2;
            if (check(mid, i)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        if (check(left, i)) {
            results[i - 1] = left;
        }
    }

    for (int i = 0; i < n; ++i) cout << results[i] << " ";
    cout << endl;

    return 0;
}