#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

long long gcd(long long a, long long b) {
    while (b != 0) {
        long long t = b;
        b = a % b;
        a = t;
    }
    return a;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    long long n, x;
    cin >> n >> x;
    vector<pair<vector<long long>, vector<long long>>> a(n);
    for (int i = 0; i < n; ++i) {
        a[i].first.resize(2);
        a[i].second.resize(2);
        cin >> a[i].first[0] >> a[i].first[1] >> a[i].second[0] >> a[i].second[1];
    }

    auto lcm = [](long long a, long long b) {
        return a / gcd(a, b) * b;
    };

    long long low = 0, high = 1;
    for (const auto& p : a) {
        high = high * lcm(p.first[0], p.second[0]) * lcm(p.first[1], p.second[1]) / gcd(lcm(p.first[0], p.second[1]), lcm(p.first[1], p.second[0]));
    }

    while (low < high) {
        long long mid = (low + high + 1) >> 1;
        long long cnt = 0;
        for (const auto& p : a) {
            long long gcd1 = gcd(p.first[0], p.second[0]);
            long long gcd2 = gcd(p.first[1], p.second[1]);
            long long lcm1 = lcm(p.first[0], p.second[0]);
            long long lcm2 = lcm(p.first[1], p.second[1]);
            long long z = mid / lcm1 / lcm2;
            if (z > 0) {
                long long res = max(0LL, (z - 1) * (p.first[0] * (lcm1 / p.first[0]) + p.second[0] * (lcm2 / p.second[0])));
                cnt += res;
            }
        }
        if (cnt > x) {
            low = mid;
        } else {
            high = mid - 1;
        }
    }

    cout << low << '\n';
    return 0;
}