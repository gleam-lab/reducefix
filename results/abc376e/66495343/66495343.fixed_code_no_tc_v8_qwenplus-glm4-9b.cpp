#include<bits/stdc++.h>
using namespace std;
#define int long long
#define PII pair<int, int>

const int N = 2e5 + 10;

int a[N], b[N];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;

        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }

        for (int i = 1; i <= n; i++) {
            cin >> b[i];
        }

        // Pair each A[i] with B[i] and sort by A[i]
        vector<PII> pairs;
        for (int i = 1; i <= n; i++) {
            pairs.emplace_back(a[i], b[i]);
        }
        sort(pairs.begin(), pairs.end());

        int res = LLONG_MAX;
        long long sum = 0;

        // Iterate from the end to maintain the largest K elements in sum
        for (int i = n; i >= 1 && k > 0; i--) {
            sum += pairs[i].second;
            if (k > 1) {
                res = min(res, pairs[i].first * sum);
                k--;
            } else {
                // If only one element is left in the sum, multiply it with the max element
                res = min(res, pairs[i].first * sum);
                break;
            }
        }

        cout << res << "\n";
    }

    return 0;
}