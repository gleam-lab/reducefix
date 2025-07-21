#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, M, K;
    vector<long long> A(N);
    
    // è¾
    cin >> N >> M >> K;
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    
    // æåº
    sort(A.begin(), A.end(), greater<long long>());
    
    // åMååéäººçåæ
    long long Mth = A[M-1];
    long long m_votes_needed = (N - M) * Mth + M - 1 - (N - M);
    
    // ç»ææ°ç»åå§å
    vector<long long> results(N);
    
    // åææ¯ä¸ªåéäºº
    for (int i = 0; i < N; ++i) {
        if (A[i] >= m_votes_needed) {
            results[i] = 0;
        } else {
            results[i] = m_votes_needed - A[i];
        }
    }
    
    // è¾åºç»æ
    for (int i = 0; i < N; ++i) {
        cout << results[i] << " ";
    }
    cout << endl;
    
    return 0;
}