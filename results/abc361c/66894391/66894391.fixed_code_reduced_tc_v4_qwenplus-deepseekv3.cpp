#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K;
    cin >> N >> K;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    multiset<int> window;
    int window_size = N - K;
    int min_diff = INT_MAX;

    // We need to find a window of size (N - K) where max - min is minimized
    // To do this, we can slide a window of size (N - K) across the array and track the min max - min
    // Using a multiset to maintain the window's elements allows us to access max and min in O(log N) time
    for (int i = 0; i < N; ++i) {
        window.insert(A[i]);
        if (window.size() > window_size) {
            window.erase(window.find(A[i - window_size]));
        }
        if (window.size() == window_size) {
            int current_diff = *window.rbegin() - *window.begin();
            if (current_diff < min_diff) {
                min_diff = current_diff;
            }
        }
    }

    cout << min_diff << '\n';

    return 0;
}