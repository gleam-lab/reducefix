#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int main() {
    int n, q;
    cin >> n;
    
    vector<int> x(n + 1), p(n + 1); // Using vector for better memory management and to avoid off-by-one errors
    map<int, int> prefixSum;
    
    for (int i = 1; i <= n; ++i) {
        cin >> x[i];
    }
    
    for (int i = 1; i <= n; ++i) {
        cin >> p[i];
        prefixSum[x[i]] += p[i]; // Using x[i] as the key in the map for direct prefix sum calculation
    }
    
    cin >> q;
    while (q--) {
        int L, R;
        cin >> L >> R;
        
        // Find the total sum of p[i] for all x[i] in range [L, R]
        // Since prefixSum is a map, it automatically handles missing keys by returning 0
        int sumL = 0, sumR = 0;
        auto itL = prefixSum.lower_bound(L);
        if (itL != prefixSum.end()) {
            sumL = itL->second;
            if (itL != prefixSum.begin()) {
                --itL;
                sumL -= itL->second;
                ++itL; // Move back to the correct position for the next possible increment
            }
            // Increment sumL by summing all values from [L, current key - 1] if any
            while (itL != prefixSum.end() && itL->first < R + 1) {
                sumL += itL->second;
                ++itL;
            }
        }
        
        auto itR = prefixSum.upper_bound(R);
        if (itR != prefixSum.begin()) {
            --itR;
            sumR = itR->second;
            if (itR->first < L) {
                // Move to the first key >= L and sum up to that point (already handled by lower_bound logic)
                auto tempIt = prefixSum.lower_bound(L);
                if (tempIt != prefixSum.end()) {
                    sumR -= tempIt->second;
                    if (tempIt != prefixSum.begin()) {
                        --tempIt;
                        while (tempIt != prefixSum.begin() && tempIt->first >= L) {
                            sumR += tempIt->second;
                            --tempIt;
                        }
                        // If we overshot, add back the value at tempIt (if it exists and is < L)
                        if (tempIt->first < L) {
                            sumR += tempIt->second;
                        }
                    }
                }
            }
        }
        
        // The correct sum is sumR (which includes all up to R) minus sumL (which excludes all < L)
        cout << sumR - sumL << endl;
    }
    
    return 0;
}