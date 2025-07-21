#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX_N = 2e5 + 5;
const long long INF = 1e18;
const long long MOD = 1e18 + 7;

vector<long long> a;

int main() {
    int n, q;
    cin >> n >> q;
    a.resize(MAX_N);
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        a[x] = 1;
    }

    // Accumulate the ones to get the counts
    for (int i = 1; i < MAX_N; ++i) {
        a[i] += a[i - 1];
    }

    // Process each query
    while (q--) {
        int b, k;
        cin >> b >> k;
        long long low = -INF, high = INF;

        // Binary search for the k-th closest distance
        while (high - low > 1) {
            long long mid = (low + high) / 2;
            long long count = a[mid] - a[b];
            if (count >= k) {
                high = mid;
            } else {
                low = mid;
            }
        }

        // The k-th closest distance is now within the range [low, high]
        cout << max(0LL, high - b) << endl;
    }

    return 0;
}