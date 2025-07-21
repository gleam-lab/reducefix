#include <bits/stdc++.h>

using namespace std;

struct Candidate {
    long long votes;
    int index;
};

bool compare(Candidate a, Candidate b) {
    return a.votes > b.votes;
}

int main() {
    long long n, m, k;
    cin >> n >> m >> k;
    
    vector<Candidate> candidates(n);
    for (int i = 0; i < n; ++i) {
        cin >> candidates[i].votes;
        candidates[i].index = i;
    }
    
    // Sort candidates by votes in descending order
    sort(candidates.begin(), candidates.end(), compare);

    vector<long long> prefix_sum(n + 1, 0);
    for (int i = 0; i < n; ++i) {
        prefix_sum[i + 1] = prefix_sum[i] + candidates[i].votes;
    }

    vector<int> results(n, 0);

    for (int i = 0; i < n; ++i) {
        long long required_votes = 0;
        for (int j = i; j < n; ++j) {
            required_votes += candidates[j].votes + 1;
        }

        if (required_votes <= k) {
            results[candidates[i].index] = 0;
        } else {
            int remaining_candidates = n - i;
            long long total_required = prefix_sum[n] - prefix_sum[i] + remaining_candidates;
            if (total_required <= k) {
                results[candidates[i].index] = 0;
            } else {
                results[candidates[i].index] = k - (prefix_sum[n] - prefix_sum[i]) + 1;
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        cout << results[i] << " ";
    }
    cout << endl;

    return 0;
}