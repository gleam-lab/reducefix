#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    
    // Read the elements of the array
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    
    // Sort the array to facilitate the removal of the largest elements
    sort(a.begin(), a.end());
    
    // We need to find the minimum possible value of the maximum minus the minimum in the remaining array
    // This is achieved by removing the K largest elements from the sorted array
    // The result is the difference between the K-th largest and the (K+1)-th smallest element in the original array
    
    // The K-th largest element in the sorted array is at index n-k-1
    // The (K+1)-th smallest element in the sorted array is at index k
    int max_val_after_removal = a[n-k-1];
    int min_val_after_removal = a[k];
    
    // The answer is the difference between the K-th largest and the (K+1)-th smallest element
    cout << max_val_after_removal - min_val_after_removal << endl;
    
    return 0;
}