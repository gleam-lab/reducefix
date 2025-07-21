#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    
    sort(a.begin(), a.end()); // Sort the array to easily access the minimum and maximum values
    
    // To minimize the difference between the max and min of the resulting array, we should aim to
    // remove elements that are extreme values (either very small or very large).
    // We can achieve this by removing the smallest `K/2` and the largest `K/2` elements, if possible.
    // If k is odd, we can remove the smallest `K//2` elements and the largest `K//2 + 1` elements.
    
    int left = K / 2;
    int right = n - K - left; // right is the count of elements to remove from the end
    
    // Calculate the difference between the max and min of the resulting array after removal
    int result = a[right] - a[left];
    
    cout << result << endl;
    
    return 0;
}