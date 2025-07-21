#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long min_votes_needed(long long votes, long long remaining_votes, long long k, int m) {
    long long high = votes + remaining_votes;
    long long low = votes + remaining_votes - k + 1;
    long long required = -1;
    while (low <= high) {
        long long mid = low + (high - low) / 2;
        long long temp_votes = votes + mid;
        long long more_votes = 0;

        // Count how many candidates will have more votes than the current candidate
        for (int i = 0; i < m; ++i) {
            if (temp_votes + i <= k) {
                more_votes += i;
            } else {
                more_votes += k - temp_votes + 1;
                break;
            }
        }
        if (more_votes * (temp_votes + more_votes) > k) {
            high = mid - 1;
        } else {
            required = mid;
            high = mid - 1;
        }
    }
    return required;
}

int main() {
    int n, m;
    long long k;
    cin >> n >> m >> k;
    vector<long long> votes(n);
    for (int i = 0; i < n; ++i) {
        cin >> votes[i];
    }

    sort(votes.rbegin(), votes.rend());

    vector<long long> results(n);
    for (int i = 0; i < n; ++i) {
        results[i] = min_votes_needed(votes[i], k - votes[i], k, m);
    }

    for (auto &result : results) {
        if (result == -1) {
            cout << 0 << " ";
        } else {
            cout << result << " ";
        }
    }
    cout << endl;

    return 0;
}