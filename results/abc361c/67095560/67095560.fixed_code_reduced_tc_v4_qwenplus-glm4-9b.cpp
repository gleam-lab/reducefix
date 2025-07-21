#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    
    vector<int> a(n);
    for (int &x : a) cin >> x;
    
    sort(a.begin(), a.end());
    
    // The best choice is to remove the K largest elements if we want to minimize the max of B
    // and the K smallest elements if we want to maximize the min of B.
    // However, we need to consider both cases since we want the minimum possible value.
    
    // Case 1: Remove the K largest elements
    int max_value_case1 = a[n - k - 1]; // second largest element
    int min_value_case1 = a[k]; // (k+1)th smallest element
    int range_case1 = max_value_case1 - min_value_case1;
    
    // Case 2: Remove the K smallest elements
    int max_value_case2 = a[n - 1]; // largest element
    int min_value_case2 = a[n - k - 1]; // second largest element
    int range_case2 = max_value_case2 - min_value_case2;
    
    // The answer is the minimum of the two ranges
    int answer = min(range_case1, range_case2);
    
    cout << answer << endl;
    
    return 0;
}