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
    
    // We need to choose a window of size (N - K) in the original array
    // where max - min is minimized.
    // Since the order must be preserved, we can't sort.
    // So, we need to find such a window in the original array.
    // However, for large N, we need an efficient way to find this.
    
    // One approach is to use a sliding window with multiset to track min and max.
    // But this would be O(N log N) which is acceptable for N up to 2e5.
    
    multiset<int> window;
    int min_diff = INT_MAX;
    int window_size = N - K;
    
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
    
    cout << min_diff << endl;
    
    return 0;
}