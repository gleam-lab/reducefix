#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
using namespace std;

const int MAX_N = 200000; // Maximum number of points A plus offset for binary search

int main() {
    int N, Q;
    cin >> N >> Q;
    vector<int> A(N + 1);
    
    // Reading the coordinates of points A
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    
    // Sorting points A to use binary search later
    sort(A.begin(), A.end());
    
    // For each query, find the k-th closest point to B_k
    for (int j = 0; j < Q; ++j) {
        int B, k;
        cin >> B >> k;
        
        // Binary search to find the k-th closest point
        int left = 0, right = N - 1, bestIndex = 0;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            // Calculate the distance to the closest point on the left side
            int distLeft = (A[mid] < B) ? B - A[mid] : A[mid] - B;
            // Calculate the distance to the closest point on the right side
            int distRight = (mid < N - 1) ? A[mid + 1] - B : numeric_limits<int>::max();
            
            // Check if the current mid is a better candidate
            if (k > distLeft && k <= distRight) {
                bestIndex = mid;
                break;
            } else if (k <= distLeft) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        
        // Calculate and print the distance to the k-th closest point
        int closestX = A[bestIndex];
        cout << abs(B - closestX) << endl;
    }
    
    return 0;
}