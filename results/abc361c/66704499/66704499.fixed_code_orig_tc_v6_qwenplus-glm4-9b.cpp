#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    // Sort the array
    sort(a.begin(), a.end());

    // Vector to store the remaining elements
    vector<int> remaining_elements;

    // Iterate from the end to remove elements
    for (int i = n - 1; i >= 0 && k > 0; --i) {
        remaining_elements.push_back(a[i]);
        --k;
    }

    // Calculate the minimum possible value of (max(B) - min(B))
    int min_possible_value = remaining_elements.back() - *remaining_elements.begin();

    // Output the result
    cout << min_possible_value << endl;

    return 0;
}