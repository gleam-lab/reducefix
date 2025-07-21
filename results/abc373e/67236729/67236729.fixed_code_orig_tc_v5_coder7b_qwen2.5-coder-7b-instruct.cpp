#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200010;

int n, m, k;
long long a[MAXN];

bool can_win(long long x) {
    long long needed[MAXM + 1] = {0};
    for (int i = 1; i <= n; ++i) {
        needed[a[i]] += x;
    }
    
    vector<long long> prefix_sum(MAXM + 1, 0);
    for (int i = 1; i <= MAXM; ++i) {
        prefix_sum[i] = prefix_sum[i - 1] + needed[i];
    }
    
    for (int i = 1; i <= n; ++i) {
        long long sum = prefix_sum[MAXM] - prefix_sum[a[i]];
        if (sum + needed[a[i]] <= k) {
            return true;
        }
    }
    
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m >> k;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    long long left = 0, right = k - accumulate(a + 1, a + n + 1, 0LL);
    vector<long long> res(n);
    
    while (left <= right) {
        long long mid = (left + right) / 2;
        if (can_win(mid)) {
            res[i] = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    for (int i = 0; i < n; ++i) {
        cout << res[i] << " ";
    }
    cout << endl;

    return 0;
}