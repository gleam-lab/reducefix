#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

int main() {
    int T;
    cin >> T;
    
    while (T--) {
        int N, K;
        cin >> N >> K;
        
        vector<pair<ll, ll>> arr(N);
        
        for (int i = 0; i < N; ++i) {
            cin >> arr[i].first;
            arr[i].second = i;
        }
        
        for (int i = 0; i < N; ++i) {
            cin >> arr[i].second;
        }
        
        sort(arr.rbegin(), arr.rend()); // Sort by A in descending order
        
        ll min_result = LLONG_MAX;
        
        // Process each possible choice of maximum element in the subset
        for (int i = 0; i < min(K, N); ++i) {
            ll sum_B = 0;
            // Sum the first i+1 smallest B values
            for (int j = 0; j <= i; ++j) {
                sum_B += arr[j].second;
            }
            // Calculate the result for this subset
            min_result = min(min_result, arr[i].first * sum_B);
        }
        
        cout << min_result << endl;
    }
    
    return 0;
}