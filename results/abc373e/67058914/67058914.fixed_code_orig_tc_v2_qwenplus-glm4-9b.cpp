#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Candidate {
    ll votes;
    ll index;
};

bool compare(Candidate a, Candidate b) {
    return a.votes > b.votes;
}

int main() {
    int N, M, K;
    cin >> N >> M >> K;
    vector<Candidate> candidates(N);
    for (int i = 0; i < N; ++i) {
        cin >> candidates[i].votes;
        candidates[i].index = i;
    }

    sort(candidates.begin(), candidates.end(), compare);

    // Calculate the remaining votes
    ll remaining_votes = K - accumulate(candidates.begin(), candidates.end(), 0LL);

    vector<ll> additional_votes_needed(N, -1);

    // Assign the minimum additional votes needed for leaders
    if (M == 1) {
        for (int i = 0; i < N; ++i) {
            if (remaining_votes >= 0) {
                additional_votes_needed[candidates[i].index] = 0;
            } else {
                additional_votes_needed[candidates[i].index] = -1;
            }
        }
    } else {
        for (int i = 0; i < N; ++i) {
            if (i < M - 1) {
                additional_votes_needed[candidates[i].index] = 0;
            } else {
                // Binary search to find the minimum additional votes needed
                int left = 0, right = candidates[i].votes + remaining_votes - candidates[M - 2].votes - 1;
                while (left < right) {
                    int mid = (left + right + 1) / 2;
                    ll needed = mid - candidates[i].votes;
                    if (needed <= remaining_votes) {
                        if (accumulate(candidates.begin(), candidates.begin() + M - 1, 0LL) + needed == accumulate(candidates.begin() + i, candidates.end(), 0LL) + needed) {
                            additional_votes_needed[candidates[i].index] = needed;
                            right = mid;
                        } else {
                            left = mid;
                        }
                    } else {
                        left = mid + 1;
                    }
                }
                if (additional_votes_needed[candidates[i].index] == -1) {
                    additional_votes_needed[candidates[i].index] = right + candidates[i].votes;
                }
            }
        }
    }

    for (ll i = 0; i < N; ++i) {
        cout << additional_votes_needed[i] << ' ';
    }
    cout << endl;

    return 0;
}