#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int N = 200000 + 5;

int n, m, k;
vector<long long> a(N);
vector<long long> b(N);

int check(int x, int y) {
    long long sum = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i] + x < a[n - 1] - m + 1) {
            sum += a[n - 1] - m + 1 - a[i] - x;
        } else {
            sum += a[i] + x - a[n - m - 1];
        }
    }
    return sum >= y;
}

int main() {
    cin >> n >> m >> k;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    sort(a.rbegin(), a.rend());
    b[0] = a[0];
    for (int i = 1; i < n; ++i) {
        b[i] = b[i - 1] + a[i];
    }

    for (int i = 0; i < n; ++i) {
        int l = 0, r = k + 1;
        while (l + 1 < r) {
            int mid = l + (r - l) / 2;
            if (check(a[i], mid)) {
                r = mid;
            } else {
                l = mid;
            }
        }
        if (r <= k) {
            cout << r - b[i] << " ";
        } else {
            cout << "-1 ";
        }
    }
    return 0;
}