#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> A(N), B(N-1);

    for(int i = 0; i < N; ++i) cin >> A[i];
    for(int i = 0; i < N-1; ++i) cin >> B[i];

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    int minBoxSize = -1;
    for(int i = 0; i < N-1; ++i) {
        if(A[i] <= B[i]) {
            minBoxSize = B[i];
            break;
        }
    }

    if(minBoxSize == -1 && A[N-1] <= B[0]) {
        minBoxSize = A[N-1];
    }

    cout << minBoxSize << endl;

    return 0;
}