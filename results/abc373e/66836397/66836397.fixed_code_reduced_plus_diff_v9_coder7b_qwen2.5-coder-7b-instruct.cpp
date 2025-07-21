#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <functional>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n, m, k;
    cin >> n >> m >> k;

    vector<long long> a(n);
    for (long long i = 0; i < n; ++i) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    vector<long long> ac(n + 1, 0);
    for (long long i = 0; i < n; ++i) {
        ac[i + 1] = ac[i] + a[i];
    }

    auto f = [&](long long i, long long x) {
        long long na = a[i] + x;
        long long r = lower_bound(a.begin(), a.end(), na) - a.begin();
        long long uppercnt = n - r;
        long long rem = k - x;
        long long M = m - uppercnt;
        if (M <= 0) return false;
        long long l = r - M;
        long long len = r - l;
        bool flag = a[l] <= a[i];
        if (flag) --l;
        long long cnt = (na + 1) * len - (ac[r] - ac[l] - (flag ? a[i] : 0));
        return rem >= cnt;
    };

    vector<long long> result(n);
    for (long long i = 0; i < n; ++i) {
        long long ok = k, ng = -1;
        while (abs(ok - ng) > 1) {
            long long mid = (ok + ng) / 2;
            if (f(i, mid)) ok = mid;
            else ng = mid;
        }
        if (!f(i, ok)) result[i] = -1;
        else result[i] = ok;
    }

    for (long long i = 0; i < n; ++i) {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}