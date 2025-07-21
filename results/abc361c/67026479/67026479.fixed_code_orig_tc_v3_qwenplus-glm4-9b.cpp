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

    // Create a vector with only the elements of B, by excluding the k largest elements of A
    vector<int> b(n - k);
    copy(a.begin() + k, a.end(), b.begin());

    // Sort the vector b to find the minimum and maximum values
    sort(b.begin(), b.end());

    // The answer is the difference between the maximum and minimum values of the sequence B
    cout << b.back() - b.front() << endl;

    return 0;
}