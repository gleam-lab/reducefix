#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    long long k;
    cin >> n >> m >> k;

    vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<pair<long long, int>> candidates(n);
    for (int i = 0; i < n; ++i) {
        candidates[i].first = a[i];
        candidates[i].second = i;
    }

    sort(candidates.begin(), candidates.end());

    vector<long long> prefix(n);
    prefix[0] = candidates[0].first;
    for (int i = 1; i < n; ++i) {
        prefix[i] = prefix[i - 1] + candidates[i].first;
    }

    long long remainingVotes = k - prefix[n - 1];

    vector<long long> required_votes(n);
    for (int i = 0; i < n; ++i) {
        int rank = n - i;
        if (rank > m) {
            required_votes[i] = -1;
        } else {
            int j = upper_bound(candidates.begin(), candidates.begin() + n, make_pair(candidates[n - m].first, 0)) - candidates.begin() - 1;
            long long votes_needed = prefix[n - 1] - prefix[j] + candidates[n - 1].first - candidates[j].first;
            if (remainingVotes < votes_needed) {
                required_votes[i] = -1;
            } else {
                required_votes[i] = candidates[n - 1].first - candidates[j].first + candidates[i].first;
            }
        }
    }

    for (long long vote : required_votes) {
        cout << (vote == -1 ? -1 : vote - k + prefix[n - 1]) << ' ';
    }
    cout << '\n';

    return 0;
}