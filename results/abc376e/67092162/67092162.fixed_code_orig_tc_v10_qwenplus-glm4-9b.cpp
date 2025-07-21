#include <bits/stdc++.h>
using namespace std;
const int maxN = 2e5 + 5;
int n, k;
int a[maxN], b[maxN];
int bit[maxN + 1]; // Binary Indexed Tree for prefix sums

// Function to add a value to BIT
void add(int idx, int val) {
    while (idx <= maxN) {
        bit[idx] += val;
        idx += idx & -idx;
    }
}

// Function to compute prefix sum up to idx in BIT
int getSum(int idx) {
    int sum = 0;
    while (idx > 0) {
        sum += bit[idx];
        idx -= idx & -idx;
    }
    return sum;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int t;
    cin >> t;
    while (t--) {
        cin >> n >> k;
        for (int i = 1; i <= n; i++) cin >> a[i];
        for (int i = 1; i <= n; i++) cin >> b[i];

        // Pairing and sorting
        pair<int, int> p[n + 1];
        for (int i = 1; i <= n; i++) {
            p[i] = {a[i], b[i]};
        }
        sort(p + 1, p + 1 + n);

        long long ans = LLONG_MAX;
        for (int i = 1; i <= n; i++) {
            // Calculate the sum of B[i] for the current maximum A[i]
            long long sumB = getSum(i) - (i > k ? getSum(i - k) : 0);

            // Calculate the potential answer
            long long currentAnswer = (long long)p[i].first * sumB;
            ans = min(ans, currentAnswer);

            // Update BIT for the next iteration
            add(i, p[i].second);
        }
        cout << ans << "\n";
    }
    return 0;
}