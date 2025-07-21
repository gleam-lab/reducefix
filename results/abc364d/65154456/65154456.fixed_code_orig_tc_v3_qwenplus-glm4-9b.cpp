#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N, Q;
    cin >> N >> Q;
    vector<pair<int, int>> A(N); // å­å¨æ¯ä¸ªA_içç´¢å¼ååæ 

    for (int i = 0; i < N; ++i) {
        cin >> A[i].second;
        A[i].first = i + 1; // å­å¨ç´¢å¼
    }

    // å°B_jæåæ æåº
    vector<pair<int, int>> B(Q);
    for (int i = 0; i < Q; ++i) {
        cin >> B[i].second >> B[i].first;
    }
    sort(B.begin(), B.end());

    // ç¨äºå­å¨ææA_içç©ºé
    vector<vector<int>> A_index(200001);

    // å°A_iæåæ åç»
    for (auto &a : A) {
        A_index[a.second].push_back(a.first);
    }

    // å¯¹äºæ¯ä¸ªB_jï¼ä½¿ç¨äºåæ¥æ¾æ¾å°ç¬¬k_j-æè¿çA_i
    for (auto &b : B) {
        // äºåæ¥æ¾åºé´çå·¦å³è¾¹ç
        int l = 0, r = 200001;
        // ç¼å­ç¬¬k_j-æè¿çA_içè·ç¦»
        double kth_min_distance = 1e18;
        int k = b.first - 1; // å°k_jè½¬æ¢ä¸º0-basedç´¢å¼

        while (l < r) {
            int mid = (l + r) / 2;
            // å¨A_index[mid]ä¸­æ¾å°ç¬¬k-thæå°çA_i
            if (A_index[mid].size() <= k) {
                r = mid;
            } else {
                int target_index = A_index[mid][k];
                // æ´æ°ç¬¬k-thæå°çA_içè·ç¦»
                kth_min_distance = min(kth_min_distance, abs(A[target_index].second - b.second));
                r = mid;
            }
        }

        // è¾åºç»æ
        cout << kth_min_distance << endl;
    }

    return 0;
}