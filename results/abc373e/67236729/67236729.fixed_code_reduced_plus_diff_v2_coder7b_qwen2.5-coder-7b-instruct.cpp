#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using ull = unsigned long long;
using ii = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vi>;
using vvii = vector<vii>;
using vb = vector<bool>;
using vvb = vector<vb>;
using vld = vector<ld>;
using vs = vector<string>;
using vc = vector<char>;

const int INF = 0x3f3f3f3f;
const ll INFL = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;

namespace IO {
    template<class T>
    inline void read(T &x) {
        char c = getchar();
        x = 0, c = c == '-' ? '-' : c;
        while (c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
        if (c == '-') x = -x;
    }

    template<class T>
    inline void write(T x) {
        if (x < 0) putchar('-'), x = -x;
        if (x >= 10) write(x / 10);
        putchar(x % 10 + '0');
    }

    template<class T>
    inline void writeln(T x) {
        write(x);
        putchar('\n');
    }
}

using namespace IO;

int n, m, k;
vi a;

inline bool check(int x) {
    vi suff(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        suff[i] = suff[i - 1] + a[i - 1];
    }
    for (int i = 1; i <= n; ++i) {
        int l = 0, r = n;
        while (l < r) {
            int mid = (l + r) >> 1;
            if (suff[n] - suff[mid] + x >= (n - mid) * a[i - 1] + k) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        if (l >= n - m + 1) return true;
    }
    return false;
}

int main() {
    read(n), read(m), read(k);
    a.resize(n);
    for (int i = 0; i < n; ++i) {
        read(a[i]);
    }
    vi ans(n);
    for (int i = 0; i < n; ++i) {
        if (a[i] * (n - m) + k <= a[i] * (n - 1)) {
            ans[i] = 0;
        } else {
            int l = 0, r = 1e12;
            while (l < r) {
                int mid = (l + r) >> 1;
                if (check(mid)) {
                    r = mid;
                } else {
                    l = mid + 1;
                }
            }
            ans[i] = l;
        }
    }
    for (int i = 0; i < n; ++i) {
        writeln(ans[i]);
    }
    return 0;
}