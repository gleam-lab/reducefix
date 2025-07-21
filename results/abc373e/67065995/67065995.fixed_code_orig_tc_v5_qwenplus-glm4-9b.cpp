#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<long long> votes(n);
    long long total_votes = 0;
    for (int i = 0; i < n; ++i) {
        cin >> votes[i];
        total_votes += votes[i];
    }

    // Sort the votes and reverse to get descending order
    sort(votes.begin(), votes.end(), greater<long long>());

    // Calculate the votes each candidate needs to guarantee victory
    vector<long long> needed_votes(n, -1);
    for (int i = 0; i < n; ++i) {
        if (i >= m) {
            // This candidate is not in the top M
            needed_votes[i] = votes[m - 1] - votes[i];
        } else {
            // This candidate is in the top M, no need for additional votes
            needed_votes[i] = 0;
        }
    }

    // Print the result
    for (auto &vote : needed_votes) {
        cout << vote << " ";
    }
    cout << endl;

    return 0;
}