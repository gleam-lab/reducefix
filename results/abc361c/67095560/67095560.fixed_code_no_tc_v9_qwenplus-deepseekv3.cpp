#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N, K;
    cin >> N >> K;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    
    int window_size = N - K;
    if (window_size == 1) {
        cout << 0 << endl;
        return 0;
    }
    
    multiset<int> window;
    for (int i = 0; i < window_size; ++i) {
        window.insert(A[i]);
    }
    
    int min_diff = *window.rbegin() - *window.begin();
    
    for (int i = window_size; i < N; ++i) {
        window.erase(window.find(A[i - window_size]));
        window.insert(A[i]);
        int current_diff = *window.rbegin() - *window.begin();
        if (current_diff < min_diff) {
            min_diff = current_diff;
        }
    }
    
    cout << min_diff << endl;
    
    return 0;
}