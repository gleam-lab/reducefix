#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

typedef struct {
    long long votes;
    long long total_votes;
    int idx;
} Node;

bool canWin(Node a, Node b, int remaining_votes, int m) {
    if (a.votes >= b.votes) return false;
    long long required = b.votes - a.votes;
    if (b.votes - m < a.votes) {
        required += (b.votes - m) - a.votes;
    }
    return remaining_votes >= required;
}

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<Node> nodes(n);
    long long sum = 0;
    for (int i = 0; i < n; ++i) {
        cin >> nodes[i].votes;
        sum += nodes[i].votes;
        nodes[i].total_votes = sum;
        nodes[i].idx = i;
    }

    // Sort nodes by votes received
    sort(nodes.begin(), nodes.end(), [](const Node& a, const Node& b) {
        return a.votes < b.votes;
    });

    // Calculate minimum votes needed to guarantee victory
    vector<long long> votes_needed(n, -1);
    long long remaining_votes = k - sum;
    for (int i = 0; i < n; ++i) {
        if (i < m || nodes[i].votes + remaining_votes >= nodes[n - m].votes) {
            votes_needed[i] = 0;
        } else {
            long long required = nodes[n - m].votes - nodes[i].votes;
            if (nodes[n - m].votes - m < nodes[i].votes) {
                required += (nodes[n - m].votes - m) - nodes[i].votes;
            }
            if (remaining_votes < required) {
                votes_needed[i] = -1;
            } else {
                votes_needed[i] = required - remaining_votes;
            }
        }
    }

    // Output the result
    for (long long needed : votes_needed) {
        cout << needed << " ";
    }
    cout << endl;

    return 0;
}