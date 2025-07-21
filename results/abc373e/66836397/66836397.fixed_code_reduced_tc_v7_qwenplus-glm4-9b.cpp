#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

int main() {
    long long n, m, k;
    cin >> n >> m >> k;

    vector<long long> a(n);
    long long total_votes = 0;
    for (long long i = 0; i < n; ++i) {
        cin >> a[i];
        total_votes += a[i];
    }

    // Sort candidates by votes received
    sort(a.begin(), a.end());

    // Calculate the votes needed to guarantee victory for the candidates
    vector<long long> votes_needed(n, -1);
    long long remaining_votes = k - total_votes;

    for (int i = 0; i < n; ++i) {
        // The number of candidates who would have more votes than ours is n - (i + 1)
        // To guarantee victory, we need to have more votes than the (m-1)th highest candidate
        if (n - (i + 1) <= m) {
            // We need to have one more vote than the (m-1)th candidate (0-based index)
            long long votes_to_secure = a[m - 2] + 1;

            // Calculate additional votes needed by the current candidate
            long long additional_votes_needed = votes_to_secure - a[i];

            if (additional_votes_needed <= remaining_votes) {
                votes_needed[i] = additional_votes_needed;
            }
        }
    }

    // Output the result
    for (long long needed : votes_needed) {
        if (needed == -1) {
            cout << "-1 ";
        } else {
            cout << needed << " ";
        }
    }
    cout << endl;

    return 0;
}