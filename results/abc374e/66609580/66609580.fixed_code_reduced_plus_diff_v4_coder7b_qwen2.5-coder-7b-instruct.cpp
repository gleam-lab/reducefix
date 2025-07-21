#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

constexpr long long INF = numeric_limits<long long>::max() / 2;

bool check(const vector<vector<int>>& data, int n, long long x) {
    for (const auto& row : data) {
        int a = row[0], p = row[1], b = row[2], q = row[3];
        long long lcm = (a / gcd(a, b)) * b;
        long long vm = max(0LL, (x / lcm - 1) * min(p * (lcm / a), q * (lcm / b)));
        if (vm > x) return false;

        long long ms = INF;
        for (long long j = 0; (j - 1) * a <= x - vm; ++j) {
            ms = min(ms, j * p + max(0LL, ((x - vm - j * a) / b + !!((x - vm - j * a) % b)) * q));
        }
        if (vm + ms > x) return false;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    long long x;
    cin >> n >> x;

    vector<vector<int>> data(n);
    for (int i = 0; i < n; ++i) {
        data[i].resize(4);
        cin >> data[i][0] >> data[i][1] >> data[i][2] >> data[i][3];
    }

    long long l = 0, r = x;
    while (l + 1 < r) {
        long long mid = (l + r) >> 1;
        if (check(data, n, mid)) {
            l = mid;
        } else {
            r = mid;
        }
    }

    cout << l << '\n';
    return 0;
}