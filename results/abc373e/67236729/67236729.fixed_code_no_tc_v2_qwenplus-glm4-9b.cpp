#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, M, K;
    cin >> N >> M >> K;
    vector<int> A(N);
    for (int &a : A) cin >> a;

    sort(A.begin(), A.end());

    // è®¡ç®å©ä½ç¥¨æ°
    long long remaining_votes = K - accumulate(A.begin(), A.end(), 0LL);

    // è®¡ç®æ¯ä¸ªåéäººéè¦çç¥¨æ°
    vector<long long> result(N);
    for (int i = 0; i < N; ++i) {
        // å½ååéäººæå
        int rank = 0;
        for (int j = N - 1; j >= 0; --j) {
            if (A[j] <= A[i]) {
                rank++;
            } else {
                break;
            }
        }

        // è®¡ç®èå©æéçç¥¨æ°
        if (rank >= M) {
            // å¦æå½åæåMæ´é«ï¼åé¢å¤ç¥¨æ°åºè¯¥ä¸º0
            result[i] = 0;
        } else {
            // è®¡ç®éè¦çé¢å¤ç¥¨æ°
            long long votes_needed = A[i] + remaining_votes - M + rank;
            if (votes_needed <= 0) {
                result[i] = -1; // ä¸å¯è½èå©
            } else {
                result[i] = votes_needed;
            }
        }
    }

    // è¾åºç»æ
    for (int res : result) {
        cout << res << ' ';
    }
    cout << endl;

    return 0;
}