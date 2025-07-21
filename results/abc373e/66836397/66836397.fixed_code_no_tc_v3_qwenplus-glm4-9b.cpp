#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

using ll = long long;

ll calculateMinimumVotes(const vector<ll>& votes, ll candidateIndex, ll m) {
    ll n = votes.size();
    sort(votes.begin(), votes.end(), greater<ll>());
    
    ll currentVotes = votes[candidateIndex];
    ll rank = 0;
    for (ll i = 0; i < n; ++i) {
        if (votes[i] == currentVotes) {
            rank++;
        } else {
            break;
        }
    }
    
    ll moreThanRank = n - rank;
    ll requiredRank = m - 1;
    if (requiredRank >= moreThanRank) {
        return -1; // Cannot secure the victory under any circumstances
    }
    
    ll additionalVotes = currentVotes + (requiredRank - moreThanRank) + 1;
   
    return min(additionalVotes, votes[0] - 1); // votes[0] is the max votes received by any candidate
}

int main() {
    ll n, m, K;
    cin >> n >> m >> K;
    
    vector<ll> votes(n);
    ll remainingVotes = K;
    for (ll& vote : votes) {
        cin >> vote;
        remainingVotes -= vote;
    }
    
    vector<ll> minVotes(n, -1);
    for (ll i = 0; i < n; ++i) {
        minVotes[i] = calculateMinimumVotes(votes, i, m);
    }
    
    for (ll vote : minVotes) {
        cout << vote << " ";
    }
    cout << endl;
    
    return 0;
}