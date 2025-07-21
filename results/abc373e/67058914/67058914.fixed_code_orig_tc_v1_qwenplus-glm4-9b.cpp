#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

struct Node {
    long long val;
    int idx;
};

int main() {
    int N, M, K;
    cin >> N >> M >> K;
    vector<long long> A(N);
    for (int &a : A) cin >> a;

    vector<Node> nodes(N);
    for (int i = 0; i < N; ++i) nodes[i] = {A[i], i};

    // Sort candidates based on the number of votes they have received initially
    sort(nodes.begin(), nodes.end(), [](const Node &a, const Node &b) {
        return a.val > b.val;
    });

    // Calculate the number of votes needed for each candidate to ensure victory
    vector<long long> votes_needed(N);
    for (int i = 0; i < N; ++i) {
        long long remaining_votes = K - nodes[i].val;
        int competitors = upper_bound(nodes.begin(), nodes.begin() + i + 1, nodes[i], [](const Node &a, const Node &b) {
            return a.val > b.val;
        }) - nodes.begin();
        if (competitors < M) {
            votes_needed[i] = 0;
        } else {
            votes_needed[i] = LLONG_MAX;
            for (int j = 0; j < N; ++j) {
                if (nodes[j].val > nodes[i].val) {
                    long long votes_to_candidate_j = nodes[j].val - nodes[i].val + M - 1;
                    if (votes_to_candidate_j <= remaining_votes) {
                        votes_needed[i] = min(votes_needed[i], votes_to_candidate_j);
                    }
                }
            }
        }
        if (votes_needed[i] == LLONG_MAX) {
            votes_needed[i] = -1;
        }
    }

    // Output the votes needed for each candidate
    for (long long votes : votes_needed) {
        cout << votes << " ";
    }
    cout << endl;

    return 0;
}