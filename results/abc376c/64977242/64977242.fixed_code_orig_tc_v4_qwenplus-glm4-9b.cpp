#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<long long> A(N), B(N - 1);
    
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    for (int i = 0; i < N - 1; ++i) {
        cin >> B[i];
    }

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    // If any toy cannot fit into the smallest box size of any given box, return -1
    for (int i = 0; i < N; ++i) {
        bool isStorable = false;
        for (int j = 0; j < N - 1; ++j) {
            if (A[i] <= B[j]) {
                isStorable = true;
                break;
            }
        }
        if (!isStorable) {
            cout << -1 << endl;
            return 0;
        }
    }

    // Now we need to find the smallest box size x that can fit the largest toy
    long long x = 0;
    for (int i = 0; i < N; ++i) {
        bool isStorable = false;
        for (int j = 0; j < N - 1; ++j) {
            if (A[i] <= B[j]) {
                x = B[j];
                isStorable = true;
                break;
            }
        }
        if (isStorable) {
            break;
        } else {
            x = A[i] + 1;
        }
    }

    cout << x << endl;
    return 0;
}