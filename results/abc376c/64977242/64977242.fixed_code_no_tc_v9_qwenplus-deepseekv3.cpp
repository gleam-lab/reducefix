#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<long long> A, B;

bool isPossible(long long x) {
    vector<long long> boxes = B;
    boxes.push_back(x);
    sort(boxes.begin(), boxes.end());
    sort(A.begin(), A.end());

    int i = 0, j = 0;
    while (i < N && j < N) {
        if (A[i] <= boxes[j]) {
            i++;
            j++;
        } else {
            j++;
        }
    }
    return i == N;
}

int main() {
    cin >> N;
    A.resize(N);
    B.resize(N - 1);
    for (int i = 0; i < N; i++) cin >> A[i];
    for (int i = 0; i < N - 1; i++) cin >> B[i];

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    long long low = 1, high = 1e18;
    long long answer = -1;

    while (low <= high) {
        long long mid = (low + high) / 2;
        if (isPossible(mid)) {
            answer = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    cout << answer << endl;

    return 0;
}