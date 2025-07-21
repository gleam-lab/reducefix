#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

inline int gcd(int a, int b) {
    while (b != 0) {
        int t = b;
        b = a % b;
        a = t;
    }
    return a;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n, x;
    cin >> n >> x;
    vector<pair<int, int>> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i].first >> arr[i].second >> arr[i].second + 1 >> arr[i].second + 2;
    }
    sort(arr.begin(), arr.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
        return a.first < b.first;
    });

    long long l = 0, r = 1e18;
    while (l + 1 < r) {
        long long mid = (l + r) / 2;
        long long cnt = 0;
        for (const auto& p : arr) {
            long long a = p.first, b = p.second, c = p.second + 1, d = p.second + 2;
            long long lcm = (a / gcd(a, b)) * b;
            long long v = mid / lcm;
            long long vm = max(0LL, (v - 1) * (c * (lcm / a) + d * (lcm / b)));
            cnt += vm;
            if (cnt > x) break;
        }
        if (cnt > x) r = mid;
        else l = mid;
    }
    cout << l;
}