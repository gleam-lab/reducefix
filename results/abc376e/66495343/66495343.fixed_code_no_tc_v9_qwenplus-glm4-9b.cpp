#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;

int a[N], b[N];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    int T;
    cin >> T;

    while (T--) {
        int n, k;
        cin >> n >> k;

        for (int i = 0; i < n; i++) {
            cin >> a[i] >> b[i];
        }

        // Pairing the values of b with their corresponding a
        vector<pair<int, int>> p(n);
        for (int i = 0; i < n; i++) {
            p[i] = {b[i], a[i]};
        }

        // Sort by b, and then by a if b values are the same
        sort(p.begin(), p.end());

        long long res = LLONG_MAX;
        long long sum = 0;
        long long b_sum = 0;
        for (int i = 0; i < n; i++) {
            if (i < k - 1) {
                sum += p[i].first;
                b_sum += p[i].second;
            } else {
                // Update the result for the current min possible value of max(a[i])
                res = min(res, sum * p[i].second);
                // Remove the smallest element of b from sum
                sum -= p[i - k + 1].first;
                // Add the new element of b
                sum += p[i].first;
                // Update b_sum to reflect the actual sum of a's we are using in the product
                b_sum = p[i - k + 1].second;
            }
        }

        cout << res << endl;
    }

    return 0;
}