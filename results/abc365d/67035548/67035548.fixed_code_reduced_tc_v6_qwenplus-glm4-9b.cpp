#include <iostream>
#include <string>

using namespace std;

int main() {
    int n;
    string s;
    cin >> n >> s;
    
    // Initialize counters for subarrays
    int left = 0, right = 0;
    // Initialize pointers for left and right subarray
    int i = 0, j = 0;
    
    // This array will store the start of the subarrays
    int leftSubStart[n], rightSubStart[n];
    
    // Process the string from left to right
    while (i < n) {
        left = 0;
        leftSubStart[i] = i;
        while (i < n && s[i] == 'P') {
            left++;
            i++;
        }
        j = i;
        while (j < n && s[j] == 'P' || s[j] == 'X') {
            j++;
        }
        // Right subarray
        right = j - i;
        rightSubStart[j] = j;
        
        // Ensure the left subarray is not longer than the right
        if (left > right) {
            swap(left, right);
            swap(leftSubStart[i], rightSubStart[j]);
        }
        
        // Move to the next segment after the right subarray
        i = j;
    }
    
    // Maximize the combined length of the left and right subarrays
    int maxCombinedLength = 0;
    for (int k = 0; k < n; ++k) {
        if (k == 0 || rightSubStart[k - 1] > leftSubStart[k]) {
            maxCombinedLength = max(maxCombinedLength, left + right);
        }
    }
    
    cout << maxCombinedLength << endl;
    return 0;
}