#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

using namespace std;

long long binary_search(long long low, long long high, const vector<long long>& votes, int M, int target) {
    while (low <= high) {
        long long mid = low + (high - low) / 2;
        vector<long long> new_votes = votes;
        new_votes[target] += mid;
        
        sort(new_votes.begin(), new_votes.end(), greater<long long>());
        
        int cnt = 0;
        for (int i = 0; i < new_votes.size(); ++i) {
            if (new_votes[i] > new_votes[target]) {
                cnt++;
                if (cnt >= M) break;
            }
        }
        
        if (cnt < M) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return low;
}

int main() {
    long long N, M, K;
    cin >> N >> M >> K;
    
    vector<long long> votes(N);
    long long total_votes = 0;
    for (int i = 0; i < N; ++i) {
        cin >> votes[i];
        total_votes += votes[i];
    }
    
    vector<long long> results(N, -1);
    
    for (int i = 0; i < N; ++i) {
        if (votes[i] >= K) continue;
        
        long long remaining_votes = K - total_votes;
        if (remaining_votes < 0) continue;
        
        long long additional_votes = binary_search(0, remaining_votes, votes, M, i);
        if (additional_votes <= remaining_votes) {
            results[i] = additional_votes;
        }
    }
    
    for (int i = 0; i < N; ++i) {
        cout << results[i] << " ";
    }
    cout << endl;
    
    return 0;
}