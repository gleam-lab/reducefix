#include <iostream>
#include <vector>
#include <set>
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

    multiset<int> window;
    long long min_diff = 1e18;

    // Initialize the first window of size N-K
    for (int i = 0; i < N - K; ++i) {
        window.insert(A[i]);
    }

    min_diff = (*window.rbegin()) - (*window.begin());

    // Slide the window
    for (int i = N - K; i < N; ++i) {
        // Remove the element going out of the window
        auto it = window.find(A[i - (N - K)]);
        if (it != window.end()) {
            window.erase(it);
        }
        // Add the new element coming into the window
        window.insert(A[i]);

        // Update the minimum difference
        min_diff = min(min_diff, (long long)(*window.rbegin()) - (*window.begin()));
    }

    cout << min_diff << endl;
}