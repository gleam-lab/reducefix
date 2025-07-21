#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> A(n);
    for (int &x : A) cin >> x;

    // Use multiset to maintain the elements in an ordered form
    multiset<int> s(A.begin(), A.end());

    // The initial range we are considering is the first k elements and the last k elements
    // Initialize the max and min values for the current range
    int currentMax = *s.rbegin();
    int currentMin = *s.begin();
    int currentRange = currentMax - currentMin;

    for (int i = k; i < n; ++i) {
        // Remove the element at the end of the current range and add the next element
        if (i > k) {
            currentMax = *s.rbegin();
        }
        if (i == k) {
            currentMin = *s.begin();
        }
        auto it = s.lower_bound(currentMin + 1); // Find the first element that is greater than currentMin + 1
        if (it != s.end()) {
            currentMax = *it;
        }
        currentRange = currentMax - currentMin;
    }

    cout << currentRange << endl;
    return 0;
}