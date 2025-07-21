#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define int long long
const int N = 2e5 + 9;

int n, k, t;
int a[N], b[N];

int solve() {
    if (k == 1) {
        return a[0] * b[0];
    }

    sort(a, a + n);
    sort(b, b + n);
    
    int prefix_sum = 0;
    int max_product = 0;

    for (int i = 0; i < n; ++i) {
        prefix_sum += b[i];

        if (i >= k - 1) {
            // Calculate product with the current max and the prefix sum up to k elements
            max_product = max(max_product, a[i] * prefix_sum);
        }
    }

    return max_product;
}

int main() {
    cin >> t;
    while (t--) {
        cin >> n >> k;
        for (int i = 0; i < n; ++i) {
            cin >> a[i] >> b[i];
        }
        cout << solve() << endl;
    }
    return 0;
}