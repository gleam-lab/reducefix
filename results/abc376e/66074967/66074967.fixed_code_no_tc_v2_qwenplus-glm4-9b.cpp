#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX_N = 2e5 + 9;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
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
        
        // Pair A and B values and sort by A descending
        vector<pair<int, int>> AB(N);
        for (int i = 0; i < N; ++i) {
            AB[i] = {A[i], B[i]};
        }
        sort(AB.begin(), AB.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
            return a.first > b.first;
        });
        
        long long sum = 0, maxB = 0, result = LLONG_MAX;
        
        // Iterate over sorted A to find the minimum result
        for (int i = 0; i < N; ++i) {
            if (i >= K - 1) { // Ensure we only consider K elements
                sum += AB[i].second;
                maxB = max(maxB, AB[i].second);
            }
            
            if (i >= K - 1) { // Once we have considered K elements, start calculating results
                result = min(result, maxB * sum);
            }
        }
        
        cout << result << '\n';
    }
    
    return 0;
}