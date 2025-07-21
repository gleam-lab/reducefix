#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    
    // Sort the array to easily pick the largest and smallest values
    sort(a.begin(), a.end());

    // Case 1: Remove the smallest K elements
    vector<int> a_small(n - k);
    copy(a.begin() + k, a.end(), a_small.begin());

    int min_a_small = *min_element(a_small.begin(), a_small.end());
    int max_a_small = *max_element(a_small.begin(), a_small.end());

    // Case 2: Remove the largest K elements
    vector<int> a_large(n - k);
    copy(a.begin(), a.begin() + n - k, a_large.begin());

    int min_a_large = *min_element(a_large.begin(), a_large.end());
    int max_a_large = *max_element(a_large.begin(), a_large.end());

    // Choose the minimum of both cases
    int min_possible_diff = min(max_a_small - min_a_small, max_a_large - min_a_large);

    cout << min_possible_diff << endl;

    return 0;
}