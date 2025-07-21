#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

int main() {
    int n, m;
    long long k;
    cin >> n >> m >> k;
    vector<long long> votes(n);
    long long total_votes = 0;
    for (int i = 0; i < n; ++i) {
        cin >> votes[i];
        total_votes += votes[i];
    }

    // Calculate the votes needed to guarantee election
    vector<long long> needed_votes(n, -1);
    for (int i = 0; i < n; ++i) {
        if (votes[i] + (n - m - 1) >= votes[n - 1]) {
            // If the candidate has already the maximum possible votes needed
            needed_votes[i] = 0;
        } else {
            long long votes_needed = n - m - 1 - votes[i];
            if (votes_needed + total_votes <= k) {
                needed_votes[i] = votes_needed;
            }
        }
    }

    // Output the results
    for (int i = 0; i < n; ++i) {
        cout << needed_votes[i] << ' ';
    }
    cout << endl;

    return 0;
}