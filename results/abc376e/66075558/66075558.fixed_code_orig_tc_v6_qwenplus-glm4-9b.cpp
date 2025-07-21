#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, K;
vector<pair<int, int>> B_sorted; // Pair of (value from A, corresponding value from B)

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> N >> K;
        vector<int> A(N), B(N);
        
        for (int i = 0; i < N; i++) {
            cin >> A[i];
        }
        
        for (int i = 0; i < N; i++) {
            cin >> B[i];
            B_sorted.push_back({A[i], B[i]});
        }
        
        // Sort B_sorted by the first element of pair (A[i])
        sort(B_sorted.begin(), B_sorted.end());
        
        // Calculate prefix sums and keep track of the min product
        long long prefix_sum = 0;
        int min_product = LLONG_MAX;
        
        for (int i = 0; i < N; i++) {
            int current_A = B_sorted[i].first;
            int current_B = B_sorted[i].second;
            
            if ((i + 1) >= K) {
                // Calculate the sum of the first K elements in B_sorted
                long long sum_B = 0;
                for (int j = i - K + 1; j <= i; j++) {
                    sum_B += B_sorted[j].second;
                }
                
                // Calculate the product and update min_product
                min_product = min(min_product, current_A * sum_B);
            }
        }
        
        cout << min_product << endl;
    }
    
    return 0;
}