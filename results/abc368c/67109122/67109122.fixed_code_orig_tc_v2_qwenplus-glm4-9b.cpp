#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<long long> H(N);
    for (int i = 0; i < N; ++i) {
        cin >> H[i];
    }

    // Calculate the total number of 3-hits needed
    long long three_hits = 0;
    for (int i = 0; i < N; ++i) {
        three_hits += (H[i] + 2) / 3;  // ceil division
    }

    // Calculate the remainder that needs 1-hits
    long long one_hits = 0;
    for (int i = 0; i < N; ++i) {
        one_hits += H[i] % 3;
    }

    // Total T is the sum of three_hits and one_hits
    long long T = three_hits + one_hits;
    cout << T << endl;

    return 0;
}