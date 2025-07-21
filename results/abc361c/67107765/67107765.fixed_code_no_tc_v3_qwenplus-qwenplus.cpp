#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, K;
    cin >> N >> K;

    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    // We will use a sliding window of size (N - K)
    int window_size = N - K;
    multiset<int> window;

    // Initialize the first window
    for (int i = 0; i < window_size; ++i) {
        window.insert(A[i]);
    }

    int min_diff = *window.rbegin() - *window.begin();

    // Slide the window across the array
    for (int i = window_size; i < N; ++i) {
        window.erase(window.find(A[i - window_size]));  // Remove the element going out
        window.insert(A[i]);                            // Add the new element

        int current_diff = *window.rbegin() - *window.begin();
        min_diff = min(min_diff, current_diff);
    }

    cout << min_diff << endl;
}