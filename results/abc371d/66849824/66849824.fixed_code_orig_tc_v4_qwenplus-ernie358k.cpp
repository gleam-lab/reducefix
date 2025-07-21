#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

int main() {
    int N;
    cin >> N;
    vector<ll> P(N + 1), X(N);
    P[0] = 0;
    
    for (int i = 0; i < N; ++i) {
        cin >> X[i];
    }
    
    for (int i = 0; i < N; ++i) {
        int p;
        cin >> p;
        P[i + 1] = P[i] + p;
    }
    
    // Sort X array and store the original indices
    vector<pair<int, int>> sortedX;
    for (int i = 0; i < N; ++i) {
        sortedX.emplace_back(X[i], i);
    }
    sort(sortedX.begin(), sortedX.end());
    
    int Q;
    cin >> Q;
    while (Q--) {
        int L, R;
        cin >> L >> R;
        
        // Binary search to find the leftmost and rightmost indices in sortedX within range [L, R]
        auto leftIt = lower_bound(sortedX.begin(), sortedX.end(), make_pair(L, -1));
        auto rightIt = upper_bound(sortedX.begin(), sortedX.end(), make_pair(R, N));
        
        int leftIdx = (leftIt != sortedX.end()) ? leftIt->second : N;
        int rightIdx = (rightIt != sortedX.begin()) ? (rightIt - 1)->second : -1;
        
        // Handle edge case where no valid index is found on the right
        if (rightIdx == -1) rightIdx = N - 1;
        
        // Calculate the sum of prefix distances within the range [leftIdx, rightIdx]
        ll ans = P[rightIdx + 1] - P[leftIdx];
        cout << ans << endl;
    }
    
    return 0;
}