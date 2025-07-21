#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

//å©ç»æä½ï¼ç¨äºä¿å­åéäººçä¿¡æ¯åä½ç½®
struct Candidate {
    ll votes;
    int index;
    bool operator<(const Candidate& other) const {
        return votes < other.votes;
    }
};

// ä¸»å½æ°
int main() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<ll> votes(n);
    for (int i = 0; i < n; ++i) {
        cin >> votes[i];
    }

    // å°åéäººç¥¨æ°æåº
    vector<Candidate> candidates(n);
    for (int i = 0; i < n; ++i) {
        candidates[i] = {votes[i], i};
    }
    sort(candidates.begin(), candidates.end());

    vector<ll> remaining_votes(n);
    for (int i = 0; i < n; ++i) {
        remaining_votes[i] = k - votes[candidates[i].index];
    }

    // è®¡ç®åm-1ä¸ªç¥¨æ°æå¤çåéäººæéçæå°ç¥¨æ°
    vector<ll> required_votes(candidates.size(), 0);
    for (int i = 0; i < m - 1; ++i) {
        ll max_votes = candidates[i].votes;
        for (int j = i + 1; j < m; ++j) {
            max_votes = max(max_votes, candidates[j].votes);
        }
        required_votes[i] = max_votes - candidates[i].votes;
    }

    // ä½¿ç¨äºåæ¥æ¾ç¡®å®æ¯ä¸ªåéäººè³å°éè¦å¤å°ç¥¨æè½ä¿è¯èå©
    for (int i = 0; i < m; ++i) {
        ll left = 0, right = remaining_votes[i];
        while (left < right) {
            ll mid = (left + right + 1) / 2;
            ll num_winners = 0;
            for (int j = i; j < candidates.size() && candidates[j].votes + mid < max_votes; ++j) {
                ++num_winners;
            }
            if (num_winners < m) {
                left = mid;
            } else {
                right = mid - 1;
            }
        }
        required_votes[i] = left + candidates[i].votes;
    }

    // è¾åºç»æ
    for (ll vote : required_votes) {
        cout << vote << " ";
    }
    cout << endl;

    return 0;
}