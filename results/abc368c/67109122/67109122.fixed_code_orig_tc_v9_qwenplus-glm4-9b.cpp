#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> H(N);
    long long T = 0;
    long long multiple_of_three_attacks = 0;

    for (int i = 0; i < N; i++) {
        cin >> H[i];

        // Calculate how many times we can make a full attack of 3
        // and how many times we can't
        multiple_of_three_attacks += H[i] / 3;
        H[i] %= 3;

        // Add the number of full attacks of 3 to T
        T += multiple_of_three_attacks;

        // For remaining health after full attacks, use single attacks
        T += H[i];
    }

    cout << T << endl;

    return 0;
}