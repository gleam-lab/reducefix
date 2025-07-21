#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

long long binarySearch(long long left, long long right, long long target, long long sum, long long k, int m) {
    while (left < right) {
        long long mid = left + (right - left) / 2;
        long long totalVotes = sum + mid * (m - 1);
        if (totalVotes >= k) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    return left;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    long long k;
    cin >> n >> m >> k;

    vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        k -= a[i];
    }

    sort(a.rbegin(), a.rend());

    vector<long long> prefixSum(n + 1);
    for (int i = 1; i <= n; ++i) {
        prefixSum[i] = prefixSum[i - 1] + a[i - 1];
    }

    vector<long long> results(n);
    for (int i = 0; i < n; ++i) {
        long long needed = binarySearch(0, k, a[i], prefixSum[n] - prefixSum[i], k, m);
        results[i] = needed - a[i];
        if (results[i] < 0) {
            results[i] = 0;
        }
    }

    for (int i = 0; i < n; ++i) {
        cout << results[i] << " ";
    }
    cout << endl;

    return 0;
}