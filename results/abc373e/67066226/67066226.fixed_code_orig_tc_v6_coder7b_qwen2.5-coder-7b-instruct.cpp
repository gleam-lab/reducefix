#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define all(x) (x).begin(), (x).end()

vector<ll> minVotesNeeded(vector<ll>& votes, int N, int M, ll K) {
    vector<ll> res(N, -1);

    // Sort the votes array in descending order
    sort(votes.rbegin(), votes.rend());

    // Calculate the prefix sum array
    vector<ll> prefixSum(N + 1);
    for(int i = 0; i < N; ++i) {
        prefixSum[i + 1] = prefixSum[i] + votes[i];
    }

    // Iterate over each candidate
    for(int i = 0; i < N; ++i) {
        // Calculate the minimum number of additional votes needed for candidate i to win
        ll needed = 0;
        for(int j = i + 1; j < N; ++j) {
            if(j - i <= M) {
                needed = max(needed, votes[i] - votes[j] + 1);
            } else {
                break;
            }
        }
        // Add one more vote to ensure the candidate wins even if others tie
        needed++;
        
        // Check if we have enough remaining votes to meet the needed amount
        if(K - prefixSum[i + 1] >= needed) {
            res[i] = needed;
        }
    }

    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    ll K;
    cin >> N >> M >> K;

    vector<ll> votes(N);
    for(int i = 0; i < N; ++i) {
        cin >> votes[i];
    }

    vector<ll> result = minVotesNeeded(votes, N, M, K);

    for(int i = 0; i < N; ++i) {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}