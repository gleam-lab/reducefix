#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX_N = 200005;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, K;
        cin >> N >> K;
        vector<pair<int, int>> A(N), B(N);
        
        for (int i = 0; i < N; i++) {
            cin >> A[i].first;
            A[i].second = i;
        }
        for (int i = 0; i < N; i++) {
            cin >> B[i].first;
            B[i].second = i;
        }

        // Sort A by value in descending order and by index in ascending order for stable sorting
        sort(A.begin(), A.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
            if (a.first == b.first) return a.second < b.second;
            return a.first < b.first;
        });

        // Create a sorted version of B based on the sorted indices from A if they are less than K
        vector<pair<int, int>> B_sorted;
        for (int i = 0; i < N; i++) {
            if (i < K) {
                B_sorted.push_back(B[A[i].second]);
            }
        }

        // Calculate the minimum possible value of the expression
        int ans = INT_MAX;
        int current_sum = 0;
        for (int i = 0; i < B_sorted.size(); i++) {
            current_sum += B_sorted[i].first;
            // Since A is sorted in descending order, the max element for the subset of size K or less is A[i].first
            ans = min(ans, A[i].first * current_sum);
        }

        cout << ans << endl;
    }
    return 0;
}