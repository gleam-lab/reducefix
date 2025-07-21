#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<long long> A(N);
    vector<long long> B(N - 1);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    for (int i = 0; i < N - 1; ++i) {
        cin >> B[i];
    }

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    long long low = 1;
    long long high = 1e18;
    long long answer = -1;

    while (low <= high) {
        long long mid = low + (high - low) / 2;
        vector<long long> boxes = B;
        boxes.push_back(mid);
        sort(bboxes.begin(), boxes.end());

        bool possible = true;
        int toy_ptr = 0;
        for (int box_ptr = 0; box_ptr < boxes.size(); ++box_ptr) {
            if (toy_ptr < N && A[toy_ptr] <= boxes[box_ptr]) {
                toy_ptr++;
            }
        }
        if (toy_ptr >= N) {
            answer = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    cout << answer << endl;

    return 0;
}