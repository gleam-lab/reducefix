#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    long long n, k;
    cin >> n >> k;
    vector<long long> a(n);
    for (long long &val : a) cin >> val;

    // Sort the vector
    sort(a.begin(), a.end());

    // The remaining elements after removing the smallest and largest K elements
    vector<long long> remaining(a.begin() + k, a.end() - k);

    // The minimum possible value of max(B) - min(B) is the difference between
    // the (N-K)-th largest and the K-th smallest element after removing K elements
    cout << remaining[remaining.size() - 1] - remaining[0] << endl;

    return 0;
}