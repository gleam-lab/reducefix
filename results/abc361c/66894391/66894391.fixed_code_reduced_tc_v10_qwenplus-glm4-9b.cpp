#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> A(n);
    
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }
    
    int minVal = INT_MAX, maxVal = INT_MIN;
    int count = 0;
    vector<int> window;

    for (int i = 0; i < n; i++) {
        // Add current element to window
        window.push_back(A[i]);
        count++;

        // Remove elements from the left until window size is exactly K
        while (count > k) {
            minVal = min(minVal, window.front());
            maxVal = max(maxVal, window.front());
            window.erase(window.begin());
            count--;
        }

        // If window is exactly K, calculate the difference
        if (count == k) {
            minVal = min(minVal, *min_element(window.begin(), window.end()));
            maxVal = max(maxVal, *max_element(window.begin(), window.end()));
        }
    }

    cout << maxVal - minVal << endl;

    return 0;
}