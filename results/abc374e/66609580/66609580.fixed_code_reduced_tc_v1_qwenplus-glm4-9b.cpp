#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int gcd(long long a, long long b) {
    return b == 0 ? a : gcd(b, a % b);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n;
    long long x;
    cin >> n >> x;
    vector<pair<long long, long long>> a, b;
    a.reserve(n);
    b.reserve(n);

    for (int i = 0; i < n; ++i) {
        long long ai, bi, pi, qi;
        cin >> ai >> pi >> bi >> qi;
        a.emplace_back(ai, pi);
        b.emplace_back(bi, qi);
    }

    sort(a.begin(), a.end(), [&](const pair<long long, long long>& x, const pair<long long, long long>& y) {
        return (x.first / gcd(x.first, x.second)) * x.second > (y.first / gcd(y.first, y.second)) * y.second;
    });

    long long sum = 0;
    long long prev = 0;
    long long area = 0;
    for (int i = 0; i < n; ++i) {
        long long cur = a[i].first / gcd(a[i].first, a[i].second) * a[i].second;
        if (cur >= x) {
            sum += prev + (cur - 1) * a[i].second;
            if (sum > x) break;
            area += cur;
        }
        prev = cur;
    }

    cout << area;
    return 0;
}