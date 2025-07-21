#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdlib> // for abs()

using namespace std;

const int MAX_N = 100000;
const long long MAX_VAL = 1e18;

vector<long long> points;

long long findKthDistance(int k, int point) {
    long long left = 0, right = MAX_VAL;
    while (left < right) {
        long long mid = left + (right - left + 1) / 2;
        long long countCloser = 0;
        for (long long p : points) {
            if (abs(p - point) <= mid) {
                countCloser++;
            }
        }
        if (countCloser >= k) {
            right = mid - 1;
        } else {
            left = mid;
        }
    }
    return left;
}

int main() {
    int n, q;
    cin >> n >> q;
    points.resize(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> points[i];
    }
    for (int i = 0; i < q; ++i) {
        int b, k;
        cin >> b >> k;
        cout << findKthDistance(k, b) << endl;
    }
    return 0;
}