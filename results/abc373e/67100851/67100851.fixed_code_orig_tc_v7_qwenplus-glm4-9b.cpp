#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

int main() {
    int N, M, K;
    cin >> N >> M >> K;
    vector<ll> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    sort(A.begin(), A.end(), greater<ll>()); // ä»é«å°ä½æåº

    vector<ll> min_votes_needed(N, 0);
    for (int i = 0; i < N; ++i) {
        ll current_votes = A[i];
        ll remaining_votes = K - current_votes;
        ll votes_needed = M - current_votes;

        // å¦æå©ä½ç¥¨æ°ä¸è¶³ä»¥è®©åéäººå¾å°Mç¥¨ï¼åè¾åº-1
        if (votes_needed > remaining_votes) {
            min_votes_needed[i] = -1;
        } else {
            // ä½¿ç¨äºåæ¥æ¾ç¡®å®æéçæå°é¢å¤ç¥¨æ°
            ll low = 0, high = votes_needed;
            while (low < high) {
                ll mid = low + (high - low) / 2;
                ll total_votes_needed = votes_needed + mid;

                // æ£æ¥æ¯å¦æå¯è½å¨å©ä½ç¥¨æ°ä¸­èµ¢å¾æ´å¤ç¥¨
                ll votes_than_current = 0;
                for (int j = i + 1; j < N; ++j) {
                    votes_than_current += max(0LL, A[j] - current_votes - mid);
                }

                if (votes_than_current <= remaining_votes - total_votes_needed) {
                    high = mid;
                } else {
                    low = mid + 1;
                }

                // æ¾å°æå°çæ»¡è¶³æ¡ä»¶çæç¥¨æ°
                if (low == votes_needed + 1) {
                    min_votes_needed[i] = -1;
                    break;
                }
            }

            if (min_votes_needed[i] == 0) {
                min_votes_needed[i] = low;
            }
        }
    }

    for (ll vote : min_votes_needed) {
        cout << vote << " ";
    }
    cout << endl;
}