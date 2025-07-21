#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    long long k;
    cin >> n >> m >> k;

    vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    // Sort the vote counts in descending order
    sort(a.begin(), a.end(), greater<long long>());

    // Calculate the cumulative sum of votes
    vector<long long> cum_sum(n + 1);
    for (int i = 0; i < n; ++i) {
        cum_sum[i + 1] = cum_sum[i] + a[i];
    }

    // Determine the minimum additional votes needed for each candidate
    vector<long long> results(n);
    for (int i = 0; i < n; ++i) {
        // If the candidate already has enough votes, no additional votes are needed
        if (a[i] > cum_sum[i + 1] - a[i] - k) {
            results[i] = 0;
        } else {
            // Calculate the required additional votes
            results[i] = max(0LL, cum_sum[m - 1] - cum_sum[i] - a[i] + 1);
        }
    }

    // Output the results
    for (int i = 0; i < n; ++i) {
        cout << results[i] << " ";
    }
    cout << endl;

    return 0;
}