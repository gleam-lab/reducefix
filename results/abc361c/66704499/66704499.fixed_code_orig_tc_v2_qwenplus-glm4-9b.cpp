#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for (int &i : a) cin >> i;

    sort(a.begin(), a.end());

    // Remove K largest elements from the end
    for (int i = 0; i < k; ++i) {
        a.pop_back();
    }

    // Output the difference between the maximum and minimum of the remaining elements
    cout << *max_element(a.begin(), a.end()) - *min_element(a.begin(), a.end()) << endl;

    return 0;
}