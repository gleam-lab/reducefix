#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<long long, int> pii;

bool can_win(vector<pii>& candidates, int i, long long additional_votes, int M) {
    int higher_ranked_count = 0;
    for (int j = 0; j < candidates.size(); ++j) {
        if (candidates[j].second == i) continue;
        if (candidates[j].first + additional_votes > candidates[i].first) {
            ++higher_ranked_count;
        }
    }
    return higher_ranked_count < M;
}

int main() {
    int N, M;
    long long K;
    cin >> N >> M >> K;

    vector<pii> candidates(N);
    for (int i = 0; i < N; ++i) {
        cin >> candidates[i].first;
        candidates[i].second = i;
    }

    sort(candidates.begin(), candidates.end());

    vector<long long> results(N, 0);
    for (int i = 0; i < N; ++i) {
        if (can_win(candidates, i, 0, M)) {
            results[i] = 0;
            continue;
        }

        long long left = 0, right = K;
        while (left <= right) {
            long long mid = left + (right - left) / 2;
            if (can_win(candidates, i, mid, M)) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        if (left > K) {
            results[i] = -1;
        } else {
            results[i] = left;
        }
    }

    for (int i = 0; i < N; ++i) {
        cout << results[i] << " ";
    }
    cout << endl;

    return 0;
}