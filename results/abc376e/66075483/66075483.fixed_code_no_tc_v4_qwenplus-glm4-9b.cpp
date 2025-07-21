#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
#define int long long

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, K;
        cin >> N >> K;
        vector<int> A(N), B(N);
        for (int i = 0; i < N; ++i) {
            cin >> A[i];
        }
        for (int i = 0; i < N; ++i) {
            cin >> B[i];
        }

        // Pairing elements from A and B
        vector<pair<int, int>> AB(N);
        for (int i = 0; i < N; ++i) {
            AB[i] = make_pair(A[i], B[i]);
        }

        // Sort by the first element of the pair (A[i])
        sort(AB.begin(), AB.end());

        // Use a multiset to keep the sum of B[i]s in the window of size K
        multiset<int> B_sum;
        int current_sum = 0;
        int min_value = INT_MAX;

        // Iterate through the sorted pairs
        for (int i = 0; i < N; ++i) {
            current_sum += AB[i].second;

            // Maintain the size of the multiset to be K
            if (B_sum.size() == K) {
                current_sum -= B_sum.begin(); // Remove the smallest element from the sum
                B_sum.erase(B_sum.begin());   // Remove the smallest element from the set
            }

            B_sum.insert(AB[i].second); // Insert the current element into the set

            // If we have a valid window of size K, calculate the product
            if (B_sum.size() == K) {
                min_value = min(min_value, AB[i].first * current_sum);
            }
        }

        // Output the minimum product found
        cout << min_value << endl;
    }
    return 0;
}