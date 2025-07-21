#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> A(n);
    
    // Reading the sequence A
    for (int i = 0; i < n; ++i) {
        cin >> A[i];
    }

    // Using a sorted multiset to maintain the order of elements
    multiset<int> B(A.begin(), A.end());

    // The minimum difference will be at least the difference between the smallest and largest remaining elements
    int min_diff = *max_element(B.rbegin(), B.rend()) - *B.begin();

    // To find the minimum possible value of the difference after removing exactly K elements,
    // we will try to minimize the largest and the smallest values remaining in the multiset by removing elements
    for (int i = 0; i < k; ++i) {
        // Remove the element that will give us the minimum difference
        if (B.size() > 1) { // If there are at least two elements left in B
            min_diff = min(min_diff, (*B.rbegin() - *B.begin()));
            B.erase(B.find(*B.rbegin())); // Remove the largest element
        } else {
            break; // If there's only one element left, we can't remove any more elements
        }
    }

    // Output the result
    cout << min_diff << endl;
    return 0;
}