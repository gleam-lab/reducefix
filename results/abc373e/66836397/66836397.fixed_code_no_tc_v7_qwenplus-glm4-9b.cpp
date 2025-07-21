#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

int main() {
    long long n, m, K;
    cin >> n >> m >> K;
    
    vector<long long> A(n), remaining_votes = A;
    long long sum_votes = 0;
    for (long long &vote : A) {
        cin >> vote;
        sum_votes += vote;
    }
    
    sort(remaining_votes.begin(), remaining_votes.end(), greater<long long>());

    vector<long long> guaranteed_votes(n);
    long long remaining_to Allocate = K - sum_votes;
    
    for (int i = 0; i < n; i++) {
        if (i >= m) {
            long long votes_needed = n - i - m + 1;
            guaranteed_votes[i] = votes_needed;
            remaining_to Allocate -= votes_needed;
        } else {
            long long votes_needed = m - i - 1;
            guaranteed_votes[i] = votes_needed;
            remaining_to Allocate -= votes_needed;
        }
        if (remaining_to Allocate < 0) {
            guaranteed_votes[i] = -1;
            remaining_to Allocate = -1;
            break;
        }
    }
    
    for (int i = 0; i < n; i++) {
        long long votes_needed = m - i - 1;
        if (votes_needed > remaining_votes.front()) {
            votes_needed = remaining_votes.front();
        }
        guaranteed_votes[i] += votes_needed;
    }
    
    for (long long vote : guaranteed_votes) {
        cout << vote << " ";
    }
    cout << endl;
    
    return 0;
}