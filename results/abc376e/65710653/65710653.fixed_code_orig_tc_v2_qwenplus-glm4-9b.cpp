#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, K;
        cin >> N >> K;
        vector<pair<int, int>> A(N);
        
        for (int i = 0; i < N; ++i) {
            cin >> A[i].first >> A[i].second;
        }
        
        // Sort pairs by A first in descending order
        sort(A.begin(), A.end(), greater<pair<int, int>>());
        
        long long min_product = LLONG_MAX;
        long long current_sum = 0;
        
        // Use a sliding window to calculate the sum of B for the top K elements
        for (int i = 0; i < K; ++i) {
            current_sum += A[i].second;
        }
        
        // Calculate the initial product for the window of size K
        min_product = min(min_product, A[0].first * current_sum);
        
        // Slide the window across the rest of the elements
        for (int i = K; i < N; ++i) {
            current_sum += A[i].second - A[i-K].second;
            min_product = min(min_product, A[i].first * current_sum);
        }
        
        cout << min_product << '\n';
    }
    
    return 0;
}