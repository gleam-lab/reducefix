#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>

using namespace std;

typedef pair<int, int> pii;

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        
        vector<pii> A(n), B(n);
        for (int i = 0; i < n; ++i) {
            cin >> A[i].first;
            A[i].second = i;
        }
        for (int i = 0; i < n; ++i) {
            cin >> B[i].first;
            B[i].second = i;
        }

        // Sort by A_i in descending order and by B_i in ascending order
        sort(A.begin(), A.end(), greater<pii>());
        sort(B.begin(), B.end());

        // Multiset to keep track of B values in the current window
        multiset<int> bs;
        long long sum = 0, result = LLONG_MAX;

        // Initialize the first window
        for (int i = 0; i < k; ++i) {
            bs.insert(B[A[i].second].first);
            sum += B[A[i].second].first;
        }

        // Calculate the initial result
        result = A[k-1].first * sum;

        // Slide the window across the array
        for (int i = k; i < n; ++i) {
            int old_index = A[i-k].second;
            int new_index = A[i].second;

            // Remove the old element from the set
            auto it = bs.find(B[old_index].first);
            bs.erase(it);
            sum -= B[old_index].first;

            // Add the new element to the set
            bs.insert(B[new_index].first);
            sum += B[new_index].first;

            // Update the result
            result = min(result, A[i].first * sum);
        }

        cout << result << '\n';
    }

    return 0;
}