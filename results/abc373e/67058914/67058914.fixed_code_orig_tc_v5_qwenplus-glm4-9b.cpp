#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M, K;
long long votes_needed[200001];

int main() {
    cin >> N >> M >> K;
    vector<pair<long long, int>> candidates(N + 1);
    
    // Read votes and candidate indices
    for (int i = 1; i <= N; ++i) {
        cin >> candidates[i].first;
        candidates[i].second = i;
    }

    // Sort by votes
    sort(candidates.begin() + 1, candidates.begin() + N + 1);

    // Calculate votes needed to beat each candidate
    for (int i = 1; i <= N; ++i) {
        votes_needed[i] = K - candidates[i].first;
    }

    // Apply binary search for each candidate to find minimum votes needed
    for (int i = 1; i <= N; ++i) {
        long long l = 0, r = votes_needed[i];
        while (l < r) {
            long long mid = (l + r + 1) / 2;
            int count = 1;  // Start by counting the current candidate
            for (int j = i - 1; j > 0 && candidates[j].first + mid > candidates[j - 1].first; --j) {
                ++count;
                if (count >= M) {
                    l = mid;
                    break;
                }
            }
            if (count >= M) {
                r = mid - 1;
            } else {
                l = mid;
            }
        }
        if (count < M) {
            cout << -1 << " ";
        } else {
            cout << l << " ";
        }
    }

    return 0;
}