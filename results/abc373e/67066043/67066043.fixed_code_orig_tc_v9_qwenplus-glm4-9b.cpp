#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define ll long long

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<ll> A(n);
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    // Pairing votes with indices and sorting by votes descending
    vector<pair<ll, int>> votes(A.begin(), A.end());
    sort(votes.rbegin(), votes.rend());

    vector<ll> prefix(n + 1, 0);
    for (int i = 0; i < n; i++) {
        prefix[i + 1] = prefix[i] + votes[i].first;
    }

    vector<ll> required_votes(n, LLONG_MAX);
    // For each candidate, calculate minimum votes needed to guarantee victory
    for (int i = 0; i < n; i++) {
        if (i >= m) break; // Only need to consider top M candidates

        int remaining_votes = k - prefix[n - m + 1];
        required_votes[i] = votes[i].first + remaining_votes - prefix[i + 1] - prefix[n - m + 1];

        // Binary search to find the minimum possible votes
        int l = 0, r = required_votes[i];
        while (l < r) {
            int mid = (l + r + 1) / 2;
            int count = 0;
            for (int j = 0; j < m && j <= i; j++) {
                int pos = lower_bound(votes.begin() + j + 1, votes.begin() + j + 1 + mid, votes[j].first + mid + 1) - votes.begin();
                count += max(0LL, min(mid, (long long)(n - m - (j >= n - m ? 1 : 0))));
            }
            if (count > remaining_votes) {
                r = mid - 1;
            } else {
                l = mid;
            }
        }
        required_votes[i] = l;
    }

    // Output the results
    for (int i = 0; i < n; i++) {
        if (required_votes[i] == LLONG_MAX) {
            cout << -1 << ' ';
        } else {
            cout << required_votes[i] << ' ';
        }
    }
    cout << endl;

    return 0;
}