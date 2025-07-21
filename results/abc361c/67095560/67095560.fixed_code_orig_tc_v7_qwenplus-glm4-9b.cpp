#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    
    // Reading the sequence A
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    // Sort the sequence A
    sort(a.begin(), a.end());
    
    // Calculate the answer by checking both removing the smallest and largest K elements
    int answer1 = a[n - 1] - a[k];   // Removing K smallest elements
    int answer2 = a[k - 1] - a[0];   // Removing K largest elements
    
    // The minimum possible value of the maximum of B minus the minimum of B
    int result = min(answer1, answer2);
    
    // Output the result
    cout << result << endl;
    
    return 0;
}