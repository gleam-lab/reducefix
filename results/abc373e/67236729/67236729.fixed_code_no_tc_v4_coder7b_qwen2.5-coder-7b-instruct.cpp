#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN = 200010;

long long a[MAXN];
long long b[MAXN];
long long sm[MAXN];

bool check(long long x, long long y, long long m, long long n, long long k) {
    int pos = upper_bound(b + 1, b + n + 1, x + y) - b;
    int up = n - pos + 1;
    if (up >= m) return false;
    long long S = sm[pos - (m - up)] - sm[pos];
    if (b[pos - (m - up)] <= x && x <= b[pos - 1]) {
        S -= x;
        S += b[pos - (m - up) - 1];
    }
    return (x + y + 1) * (m - up) - S > k - y;
}

int main() {
    long long n, m, k;
    cin >> n >> m >> k;

    for (long long i = 1; i <= n; ++i) {
        cin >> a[i];
        b[i] = a[i];
        k -= a[i];
    }

    sort(b + 1, b + n + 1);

    for (long long i = 1; i <= n; ++i) {
        long long left = 0, right = k, answer = -1;
        while (left <= right) {
            long long mid = left + (right - left) / 2;
            if (check(a[i], mid, m, n, k)) {
                answer = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        cout << answer << " ";
    }
    cout << endl;

    return 0;
}