#include <bits/stdc++.h>
using namespace std;

int main() {
    // Fast input/output
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, K;
    cin >> N >> K;
    vector<int> A(N);
    
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    // Sort the array to make it easier to find the smallest K elements
    sort(A.begin(), A.end());

    // Remove the K smallest elements
    A.erase(A.begin(), A.begin() + K);

    // The minimum possible value of this is the difference between the
    // maximum and minimum values of the remaining sequence
    cout << *max_element(A.begin(), A.end()) - *min_element(A.begin(), A.end()) << endl;

    return 0;
}