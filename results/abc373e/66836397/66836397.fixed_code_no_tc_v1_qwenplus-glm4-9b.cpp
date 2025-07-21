#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 200000;

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<long long> a(n);
    long long sum_votes = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        sum_votes += a[i];
    }

    vector<pair<long long, int>> candidates;
    for (int i = 0; i < n; ++i) {
        candidates.emplace_back(a[i], i);
    }

    sort(candidates.begin(), candidates.end());

    vector<long long> remaining_votes(k - sum_votes);
    long long votes_needed = 0;
    for (int i = 0; i < m - 1; ++i) {
        votes_needed += candidates[n - i - 1].first;
    }

    vector<long long> result(n, 0);
    for (int i = 0; i < n; ++i) {
        long long current_votes = candidates[i].first;
        long long remaining_candidates = n - i - 1;
        long long max_votes_needed = votes_needed + remaining_candidates * (remaining_votes.size() - remaining_candidates);
        if (current_votes + remaining_votes.size() >= max_votes_needed) {
            result[candidates[i].second] = 0;
        } else {
            result[candidates[i].second] = max_votes_needed - current_votes;
        }
    }

    for (int i = 0; i < n; ++i) {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}