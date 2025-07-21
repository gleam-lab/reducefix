#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, k;
vector<int> A, B;

int main() {
    cin >> n >> k;
    A.resize(n);
    B.resize(n);

    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> B[i];
    }

    sort(A.begin(), A.end(), greater<int>());
    vector<int> prefix(A.size());
    prefix[0] = A[0];
    for (int i = 1; i < A.size(); i++) {
        prefix[i] = prefix[i - 1] + A[i];
    }

    int min_value = INT_MAX;
    for (int i = 0; i < n; i++) {
        int sum_A = (i + 1 >= k) ? prefix[i - k + 1] : 0;
        int product = (i + 1 >= k) ? sum_A * B[i] : 0;
        min_value = min(min_value, product);
    }

    cout << min_value << endl;
    return 0;
}