#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> A(n);
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    // Remove k elements from both ends
    vector<int> A_left(A.begin(), A.begin() + k);
    vector<int> A_right(A.end() - k, A.end());
    vector<int> A_middle(A_left.end(), A_right.begin());
    
    sort(A_middle.begin(), A_middle.end());
    long long sum = 0;
    for (int i = 0; i < A_middle.size(); i++) {
        sum += A_middle[i];
    }
    
    // Minimize max diff by reducing sum from both ends
    int left = 0, right = A_middle.size() - 1;
    int min_diff = LLONG_MAX;
    while (left <= right) {
        int diff = right - left;
        int current_sum = sum - A_middle[left] * diff - A_middle[right] * diff;
        min_diff = min(min_diff, current_sum / diff);
        left++;
        right--;
    }
    
    cout << min_diff << endl;
    return 0;
}