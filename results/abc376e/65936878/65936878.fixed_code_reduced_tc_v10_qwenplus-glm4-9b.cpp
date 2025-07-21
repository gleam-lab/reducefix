#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n), b(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i] >> b[i];
        }

        // Pair each A[i] with B[i] and sort by A[i] descending and then by B[i] descending
        vector<pair<int, int>> ab(n);
        for (int i = 0; i < n; ++i) {
            ab[i] = {a[i], b[i]};
        }
        sort(ab.begin(), ab.end(), [](const pair<int, int>& p1, const pair<int, int>& p2) {
            if (p1.first != p2.first) return p1.first > p2.first;
            return p1.second > p2.second;
        });

        long long sum = 0;
        // Calculate the sum of B[i] for the top k elements of A[i]
        for (int i = 0; i < k; ++i) {
            sum += ab[i].second;
        }

        // The minimum value of the expression is the maximum A[i] from the top k elements
        // multiplied by the sum of their respective B[i]
        long long result = ab[0].first * sum;
        cout << result << '\n';
    }
    return 0;
}