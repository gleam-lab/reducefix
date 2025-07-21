#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<long long> votes(n);
    for (int i = 0; i < n; ++i) {
        cin >> votes[i];
    }

    sort(votes.begin(), votes.end());

    vector<long long> additional_votes(n, 0);

    // Calculate the minimum additional votes needed for each candidate
    for (int i = 0; i < n; ++i) {
        long long required_votes = votes[i] + 1;
        long long current_votes = votes[i] - votes[n - m] + 1;

        if (required_votes <= k - (k - votes[i])) {
            // Calculate the additional votes needed to reach the required votes
            additional_votes[i] = required_votes - current_votes;
        } else {
            // It's impossible to guarantee victory
            additional_votes[i] = -1;
        }
    }

    for (const long long &vote : additional_votes) {
        cout << vote << " ";
    }
    cout << endl;

    return 0;
}