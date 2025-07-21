#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    vector<int> a(M), b(M);
    for (int i = 0; i < M; ++i) {
        cin >> a[i] >> b[i];
    }

    long long total_squares = N * N;
    long long captured_squares = 0;

    // Count captured squares by each piece
    for (int i = 0; i < M; ++i) {
        captured_squares += (N - 1) + (N - 1) + (N - (a[i] + b[i] - 2)) + (N - (2 - (abs(a[i] - b[i]))));
    }

    // Calculate the number of empty squares where we can place a new piece
    long long empty_squares = total_squares - captured_squares;
    cout << empty_squares << endl;

    return 0;
}