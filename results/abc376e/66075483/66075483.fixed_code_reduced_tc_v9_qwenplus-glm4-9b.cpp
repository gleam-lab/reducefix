#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <set>
using namespace std;
#define int long long

int32_t main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> A(n), B(n);
        for (int i = 0; i < n; i++) {
            cin >> A[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> B[i];
        }

        // Sort indices based on A values for easy access to top K A values
        vector<pair<int, int>> indices(n);
        for (int i = 0; i < n; i++) {
            indices[i] = {A[i], i};
        }
        sort(indices.begin(), indices.end());

        // Calculate the sum of B values for the top K A values
        multiset<int> topBValues;
        long long sumTopB = 0;
        for (int i = 0; i < n; i++) {
            if (i < k) {
                topBValues.insert(B[indices[i].second]);
            }
            if (i >= k) {
                sumTopB += B[indices[i].second];
                topBValues.erase(topBValues.find(B[indices[i - k].second]));
            }
        }
        sumTopB += *topBValues.begin();  // Add the smallest B value from the top K

        // The answer is the maximum A value times the sum of B values for the top K A values
        long long answer = *max_element(A.begin(), A.end()) * sumTopB;
        cout << answer << endl;
    }
    return 0;
}