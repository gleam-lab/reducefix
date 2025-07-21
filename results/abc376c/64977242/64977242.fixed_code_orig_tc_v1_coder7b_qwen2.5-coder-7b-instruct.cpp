#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> A(N), B(N - 1);

    for (int i = 0; i < N; i++)
        cin >> A[i];
    for (int i = 0; i < N - 1; i++)
        cin >> B[i];

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    int minBoxSize = INT_MAX;

    for (int i = 0; i < N - 1; i++) {
        if (A[i] > B[i])
            minBoxSize = min(minBoxSize, A[i]);
    }

    if (minBoxSize == INT_MAX) 
        cout << "-1" << endl;
    else
        cout << minBoxSize << endl;

    return 0;
}