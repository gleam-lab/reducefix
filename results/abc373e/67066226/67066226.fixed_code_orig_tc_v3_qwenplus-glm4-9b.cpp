#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N, M;
    long long K;
    vector<long long> A;

    cin >> N >> M >> K;
    A.reserve(N);
    long long votes_sum = 0;
    for (int i = 0; i < N; ++i) {
        long long votes;
        cin >> votes;
        votes_sum += votes;
        A.push_back(votes);
    }
    
    sort(A.begin(), A.end());
    
    vector<long long> additional_votes(N, -1);
    for (int i = 0; i < N; ++i) {
        long long max_votes_needed = A[i] + (long long)(N - M);
        if (A[i] + votes_sum - max_votes_needed < M) {
            additional_votes[i] = max_votes_needed - A[i];
        }
    }
    
    for (long long additional_vote : additional_votes) {
        cout << (additional_vote == -1 ? -1 : (long long)additional_vote) << ' ';
    }
    cout << endl;
    
    return 0;
}