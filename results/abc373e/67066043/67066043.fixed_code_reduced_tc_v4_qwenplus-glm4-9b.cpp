#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

struct Candidate {
    int id;
    long long votes;
};

bool compare(const Candidate& a, const Candidate& b) {
    return a.votes > b.votes;
}

int main() {
    int n, m, k;
    vector<long long> votes;
    cin >> n >> m >> k;
    Candidate candidates[n];

    for (int i = 0; i < n; ++i) {
        cin >> candidates[i].votes;
        votes.push_back(candidates[i].votes);
        candidates[i].id = i;
    }

    sort(candidates, candidates + n, compare);
    sort(votes.begin(), votes.end(), greater<long long>());

    vector<long long> remaining_votes = votes;
    for (int i = 0; i < n; ++i) {
        if (i + 1 < m) {
            remaining_votes[i] -= votes[i + m - 1] - votes[i];
        } else {
            remaining_votes[i] -= votes[i];
        }
    }

    vector<long long> additional_votes_needed(n);
    long long sum_remaining_votes = 0;
    for (int i = 0; i < n; ++i) {
        sum_remaining_votes += remaining_votes[i];
        if (candidates[i].votes + sum_remaining_votes >= votes[n - m]) {
            additional_votes_needed[candidates[i].id] = votes[n - m] - candidates[i].votes;
            break;
        } else {
            if (i == n - 1) {
                additional_votes_needed[candidates[i].id] = -1;
            } else {
                additional_votes_needed[candidates[i].id] = votes[n - m] - candidates[i].votes;
            }
        }
    }

    for (long long i : additional_votes_needed) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}