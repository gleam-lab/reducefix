#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<long long> A(n);

    for (int i = 0; i < n; ++i) {
        cin >> A[i];
    }

    // Sort candidates by votes
    sort(A.begin(), A.end(), greater<long long>());

    vector<long long> required_votes(n, 0);
    long long cumulative_votes = 0;
    for (int i = 0; i < n; ++i) {
        if (i >= m) {
            cumulative_votes -= A[i - m];
        }
        cumulative_votes += A[i];
        required_votes[i] = cumulative_votes - (k - cumulative_votes);
    }

    // Adjust required votes for each candidate
    for (int i = 0; i < n; ++i) {
        if (A[i] >= required_votes[i]) {
            required_votes[i] = 0;
        } else if (k - cumulative_votes < required_votes[i] - A[i]) {
            required_votes[i] = -1;
        } else {
            required_votes[i] -= A[i];
        }
    }

    for (int i = 0; i < n; ++i) {
        cout << required_votes[i] << ' ';
    }
    cout << endl;

    return 0;
}