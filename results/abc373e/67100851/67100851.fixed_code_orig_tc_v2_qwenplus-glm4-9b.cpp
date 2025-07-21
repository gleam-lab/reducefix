#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef pair<int, ll> pii;

int N, M, K;
ll A[200001];

ll get_min_votes(int i, ll remaining_votes) {
    // Your logic to calculate the minimum votes needed for candidate i
    // given the remaining_votes
    // For demonstration, just return a placeholder
    return 0;
}

int main() {
    // Input
    cin >> N >> M >> K;
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    // Calculate minimum votes needed for each candidate
    for (int i = 0; i < N; ++i) {
        ll votes_needed = get_min_votes(i, K - accumulate(A, A + N, 0));
        if (votes_needed < 0) {
            cout << "-1 ";
        } else {
            cout << votes_needed << " ";
        }
    }
    cout << endl;

    return 0;
}