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
        k -= a[i];
    }

    // Sort the votes in descending order
    sort(a.begin(), a.end(), greater<long long>());

    // Calculate the cumulative sum of votes
    vector<long long> cum_sum(n + 1);
    for (int i = 0; i < n; ++i) {
        cum_sum[i + 1] = cum_sum[i] + a[i];
    }

    // Initialize the result vector
    vector<long long> res(n, 0);

    // Iterate over each candidate to find the minimum additional votes needed
    for (int i = 0; i < n; ++i) {
        long long additional_votes_needed = 0;

        // Find the position where the current candidate's votes would fit
        int pos = lower_bound(cum_sum.begin(), cum_sum.end(), a[i] + k) - cum_sum.begin();

        // Calculate the number of candidates with more votes than the current candidate
        int num_candidates_more_votes = n - pos;

        // If the number of candidates with more votes is less than M, the candidate is already elected
        if (num_candidates_more_votes < m) {
            continue;
        }

        // Calculate the minimum additional votes needed
        additional_votes_needed = (num_candidates_more_votes - m + 1) * (pos + 1) - cum_sum[pos];

        // Ensure the additional votes needed are within bounds
        if (additional_votes_needed > k) {
            additional_votes_needed = -1;
        }

        res[i] = additional_votes_needed;
    }

    // Output the results
    for (int i = 0; i < n; ++i) {
        cout << res[i] << " ";
    }
    cout << endl;

    return 0;
}