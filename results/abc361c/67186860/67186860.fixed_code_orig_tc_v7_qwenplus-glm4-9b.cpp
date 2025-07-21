#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());

    // We remove elements from the ends first since those will likely reduce the range the most.
    int left = 0, right = n - 1;
    while (k > 0 && (left < right)) {
        a.pop_back(); // Remove the largest element.
        a.erase(a.begin()); // Remove the smallest element.
        k -= 2;
    }

    // If we still have to remove more elements and k is odd, remove one from the end.
    if (k > 0) {
        a.pop_back();
        k--;
    }

    // The range of the resulting array is the difference between the max and min elements.
    int min_val = *min_element(a.begin(), a.end());
    int max_val = *max_element(a.begin(), a.end());
    cout << max_val - min_val << endl;

    return 0;
}