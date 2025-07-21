#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long solve(long long n, long long k, vector<long long>& a) {
    sort(a.begin(), a.end());
    long long ans = LONG_MAX;
    for (long long i = 0; i <= k; ++i) {
        long long sum = 0;
        for (long long j = 0; j < n - k; ++j) {
            sum += a[i + j];
        }
        ans = min(ans, sum);
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long n, k;
    cin >> n >> k;
    vector<long long> a(n);
    for (long long i = 0; i < n; ++i) {
        cin >> a[i];
    }

    cout << solve(n, k, a) << '\n';

    return 0;
}