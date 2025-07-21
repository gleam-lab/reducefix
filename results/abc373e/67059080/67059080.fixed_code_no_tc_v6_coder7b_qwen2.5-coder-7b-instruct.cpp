#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int N, M;
ll K;

// Function to determine the minimum additional votes needed for candidate i to win
ll minVotesNeeded(vector<ll>& votes, int i, int M, ll K) {
    // Sort the votes to easily find the threshold for winning
    sort(votes.begin(), votes.end());
    
    // Calculate the total votes received by candidates ranked higher than i
    ll sumHigher = accumulate(votes.begin(), votes.begin() + i, 0LL);
    
    // Calculate the minimum votes needed for candidate i to win
    ll target = sumHigher + 1;
    
    // Binary search to find the exact number of votes needed
    ll left = 0, right = K;
    while (left < right) {
        ll mid = (left + right) / 2;
        if (target * mid - sumHigher <= K - mid) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    
    // Ensure candidate i can still win after receiving 'left' votes
    if (target * left - sumHigher > K - left) {
        return -1;
    }
    
    return left;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M >> K;
    vector<ll> votes(N);
    
    // Read the votes for each candidate
    for (int i = 0; i < N; ++i) {
        cin >> votes[i];
    }
    
    vector<ll> results(N);
    
    // Calculate the minimum additional votes needed for each candidate
    for (int i = 0; i < N; ++i) {
        results[i] = minVotesNeeded(votes, i, M, K);
    }
    
    // Output the results
    for (int i = 0; i < N; ++i) {
        cout << results[i] << " ";
    }
    cout << endl;
    
    return 0;
}