#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    
    vector<long long> A(N);
    vector<long long> B(N - 1);
    
    for (int i = 0; i < N; ++i) cin >> A[i];
    for (int i = 0; i < N - 1; ++i) cin >> B[i];
    
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    
    // We will use binary search to find minimal x
    long long left = 1, right = 1e18, answer = -1;

    while (left <= right) {
        long long mid = (left + right) / 2;
        
        // Create a list of available boxes including the new one with size 'mid'
        vector<long long> tempBoxes = B;
        tempBoxes.push_back(mid);
        sort(tempBoxes.begin(), tempBoxes.end());

        bool ok = true;
        for (int i = 0; i < N; ++i) {
            if (A[i] > tempBoxes[i]) {
                ok = false;
                break;
            }
        }

        if (ok) {
            answer = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    cout << answer << endl;
}