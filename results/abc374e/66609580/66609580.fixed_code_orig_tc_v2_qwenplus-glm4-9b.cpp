#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <climits>
using namespace std;

int n;
long long a[110], b[110], p[110], q[110], x;
vector<pair<long long, long long>> tasks;

inline long long gcd(long long a, long long b) {
    while (b != 0) {
        long long t = b;
        b = a % b;
        a = t;
    }
    return a;
}

bool check(long long v) {
    long long cnt = 0;
    for (const auto& task : tasks) {
        long long lcm = task.first;
        long long vm = max(0LL, (v / lcm - 1) * min(p[task.second] * (lcm / a[task.second]), q[task.second] * (lcm / b[task.second])));
        cnt += vm;
        if (cnt > x) return 0;
    }
    return 1;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n >> x;
    tasks.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i] >> p[i] >> b[i] >> q[i];
        tasks[i] = {gcd(a[i], b[i]) * a[i] * b[i], i};
    }
    sort(tasks.begin(), tasks.end());
    long long l = 0, r = 2 * LLONG_MAX;
    while (l + 1 < r) {
        long long mid = (l + r + 1) / 2;
        if (check(mid)) l = mid;
        else r = mid;
    }
    cout << l;
}