#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m, k;
    cin >> n >> m >> k;

    vector<int> A(n);
    long long votes = 0;
    for (int & candidacy : A) {
        cin >> candidacy;
        votes += candidacy;
    }

    k -= votes;  // Remaining votes to be counted

    // Sort candidates by number of votes received
    sort(all(A));

    // Calculate prefix sum for the sorted list of votes
    vector<long long> prefix(sz(A) + 1);
    prefix[0] = 0;
    for (int i = 0; i < sz(A); ++i) {
        prefix[i + 1] = prefix[i] + A[i];
    }

    vector<int> result(n, -1);  // Initialize result vector with -1

    // Iterate through candidates in reverse order
    for (int i = sz(A) - 1; i >= 0; --i) {
        if (i >= n - m) {
            result[i] = 0;  // If this candidate is among the top M, no additional votes needed
            continue;
        }

        long long votes_needed = 0;
        // Binary search to find the minimum votes needed to win
        int low = 0, high = m - 1;
        while (low < high) {
            int mid = low + (high - low + 1) / 2;
            long long sum = prefix[i + 1 + mid] - prefix[i + 1];
            if (sum + A[i] >= prefix[n - m] - prefix[n - m - mid]) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        int additional_votes = low;
        long long sum_of_top = prefix[i + 1 + additional_votes] - prefix[i + 1];
        long long sum_of_other = prefix[n - m] - prefix[n - m - additional_votes];

        if (sum_of_top + A[i] >= sum_of_other) {
            result[i] = additional_votes;
        } else {
            result[i] = (int)(k - sum_of_top + A[i] - sum_of_other);
            k -= result[i];  // Update remaining votes
        }
    }

    for (int & res : result) {
        cout << res << " ";
    }

    return 0;
}