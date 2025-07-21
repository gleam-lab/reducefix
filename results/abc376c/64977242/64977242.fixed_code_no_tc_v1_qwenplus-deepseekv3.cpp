#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<long long> A(N), B(N - 1);
    for (int i = 0; i < N; ++i) cin >> A[i];
    for (int i = 0; i < N - 1; ++i) cin >> B[i];

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    vector<long long> possible_x;

    // Check scenario where the new box is used for the largest toy
    bool possible = true;
    for (int i = 0; i < N - 1; ++i) {
        if (A[i] > B[i]) {
            possible = false;
            break;
        }
    }
    if (possible) {
        possible_x.push_back(A.back());
    }

    // Check scenario where the new box is used for another toy
    possible = true;
    for (int i = 1; i < N; ++i) {
        if (A[i] > B[i - 1]) {
            possible = false;
            break;
        }
    }
    if (possible) {
        possible_x.push_back(A[0]);
    }

    // General case: find the minimal x that is >= A[k] and allows other toys to fit
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    long long min_x = -1;
    int j = 0;
    possible = true;
    for (int i = 0; i < N; ++i) {
        while (j < N - 1 && B[j] < A[i]) {
            ++j;
        }
        if (j >= N - 1) {
            possible_x.push_back(A[i]);
            break;
        }
        ++j;
    }

    if (!possible_x.empty()) {
        min_x = *min_element(possible_x.begin(), possible_x.end());
    }

    cout << min_x << endl;

    return 0;
}