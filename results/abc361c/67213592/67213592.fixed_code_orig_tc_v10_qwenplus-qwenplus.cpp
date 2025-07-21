#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K;
    cin >> N >> K;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    // Pair up values with their indices
    vector<pair<int, int>> valIndex(N);
    for (int i = 0; i < N; ++i) {
        valIndex[i] = {A[i], i};
    }

    // Sort based on values
    sort(valIndex.begin(), valIndex.end());

    int minDiff = numeric_limits<int>::max();

    // Sliding window over the sorted values
    for (int i = 0; i + (N - K - 1) < N; ++i) {
        int j = i + (N - K - 1);
        vector<int> indices;
        for (int k = i; k <= j; ++k) {
            indices.push_back(valIndex[k].second);
        }
        sort(indices.begin(), indices.end());

        // Check if indices are strictly increasing (valid subsequence)
        bool valid = true;
        for (int l = 1; l < (int)indices.size(); ++l) {
            if (indices[l] <= indices[l - 1]) {
                valid = false;
                break;
            }
        }

        if (valid) {
            minDiff = min(minDiff, valIndex[j].first - valIndex[i].first);
        }
    }

    cout << minDiff << endl;
}