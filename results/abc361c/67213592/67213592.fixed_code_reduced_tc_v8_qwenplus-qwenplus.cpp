#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;
    vector<int> A(n);
    for (int i = 0; i < n; ++i) {
        cin >> A[i];
    }

    // Pair up values with indices
    vector<pair<int, int>> valIndex(n);
    for (int i = 0; i < n; ++i) {
        valIndex[i] = {A[i], i};
    }
    sort(valIndex.begin(), valIndex.end());

    // Result variable
    long long result = 1e18;

    // To maintain the window of indices and track min/max
    multiset<int> windowIndices;

    for (int i = 0; i < n; ++i) {
        windowIndices.insert(valIndex[i].second);

        if (i >= n - k - 1) {
            // Window size reached N-K
            int minIndex = *windowIndices.begin();
            int maxIndex = *windowIndices.rbegin();

            if (maxIndex - minIndex >= n - k - 1) {
                // These indices can be kept in order
                int minValue = valIndex[i - (n - k - 1)].first;
                int maxValue = valIndex[i].first;
                result = min(result, (long long)(maxValue - minValue));
            }

            // Slide window
            windowIndices.erase(windowIndices.find(valIndex[i - (n - k - 1)].second));
        }
    }

    cout << result << endl;
}