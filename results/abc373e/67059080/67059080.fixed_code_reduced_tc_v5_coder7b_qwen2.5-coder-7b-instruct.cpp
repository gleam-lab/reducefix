#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

int N, M;
ll K;

// Function to check if a candidate can win with x additional votes
bool canWin(vector<ll>& votes, int i, ll x, ll remainingVotes) {
    ll curVotes = votes[i] + x;
    ll neededVotes = curVotes + 1;
    
    int count = 0;
    for (int j = 0; j < N; ++j) {
        if (j != i && votes[j] >= neededVotes) {
            ++count;
        }
    }
    
    return count < M;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> N >> M >> K;
    
    vector<ll> votes(N);
    for (int i = 0; i < N; ++i) {
        cin >> votes[i];
    }
    
    vector<int> result(N);
    
    for (int i = 0; i < N; ++i) {
        if (votes[i] + K < M) {
            result[i] = -1;
        } else {
            ll remainingVotes = K;
            for (int j = 0; j < N; ++j) {
                if (j != i) {
                    remainingVotes -= votes[j];
                }
            }
            
            ll left = 0, right = remainingVotes;
            while (left < right) {
                ll mid = (left + right) / 2;
                if (canWin(votes, i, mid, remainingVotes)) {
                    right = mid;
                } else {
                    left = mid + 1;
                }
            }
            
            result[i] = left;
        }
    }
    
    for (int i = 0; i < N; ++i) {
        cout << result[i] << " ";
    }
    cout << endl;
    
    return 0;
}