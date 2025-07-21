#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
#include <climits>

using namespace std;

const int MAXN = 110;

long long a[MAXN], b[MAXN], p[MAXN], q[MAXN];
int n;
long long x;

bool check(long long v) {
    long long cnt = 0;
    for (int i = 1; i <= n; ++i) {
        long long lcm_ab = a[i] / gcd(a[i], b[i]) * b[i];
        long long vm = max(0LL, (v / lcm_ab - 1) * min(p[i] * (lcm_ab / a[i]), q[i] * (lcm_ab / b[i])));
        cout << vm;
        cnt += vm;
        
        long long val = max(0LL, v / lcm_ab - 1) * lcm_ab;
        long long ms = LLONG_MAX >> 1;
        for (long long j = 0; (j - 1) * a[i] <= v - val; ++j) {
            ms = min(ms, j * p[i] + max(0LL, ((v - val - j * a[i]) / b[i] + !!((v - val - j * a[i]) % b[i])) * q[i]));
        }
        cout << '\n' << v << ',' << i << ':' << vm << ' ' << ms << ' ' << vm + ms << '\n';
        cnt += ms;
        if (cnt > x) return false;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    
    cin >> n >> x;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i] >> p[i] >> b[i] >> q[i];
    }
    
    long long l = 0, r = INT_MAX;
    while (l + 1 < r) {
        long long mid = (l + r) >> 1;
        if (check(mid)) l = mid;
        else r = mid;
    }
    
    cout << l << '\n';
    return 0;
}