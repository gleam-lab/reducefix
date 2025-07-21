#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> A(n);

    for (int i = 0; i < n; ++i) {
        cin >> A[i];
    }

    // Sort the vector
    sort(A.begin(), A.end());

    // Remove the k largest elements by slicing the vector
    A.erase(A.end() - k, A.end());

    // The result is the difference between the maximum and minimum of the remaining elements
    cout << A.back() - A.front() << endl;

    return 0;
}