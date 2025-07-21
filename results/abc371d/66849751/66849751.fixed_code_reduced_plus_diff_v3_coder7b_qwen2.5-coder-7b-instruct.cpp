#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<long long> A(N), B(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    for (int i = 0; i < N; ++i) {
        cin >> B[i];
    }

    map<long long, int> prefix_sum_map;
    prefix_sum_map[0] = 0;
    long long prefix_sum = 0;
    for (int i = 0; i < N; ++i) {
        prefix_sum += A[i];
        prefix_sum_map[prefix_sum] = i + 1;
    }

    int Q;
    cin >> Q;
    while (Q--) {
        long long L, R;
        cin >> L >> R;
        if (prefix_sum_map.find(L) == prefix_sum_map.end()) {
            cout << B[N - 1] << '\n';
        } else {
            long long left_index = prefix_sum_map[L];
            long long right_index = prefix_sum_map[R];
            cout << B[right_index - 1] << '\n';
        }
    }

    return 0;
}