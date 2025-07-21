#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<long long> H(N);
    for (int i = 0; i < N; ++i) {
        cin >> H[i];
    }

    long long T = 0;
    for (int i = 0; i < N; ++i) {
        long long h = H[i];
        // For each enemy, determine how many attacks of each type are needed
        // We need to solve: a*3 + b*1 >= h where a is number of triple attacks and b regular ones
        // And we want to minimize total actions T' = a + b
        
        // Let's find minimal number of attacks required
        // Try all possible values of a from 0 to ceil(h / 3)
        // The optimal solution will be when we use as many triple attacks as possible
        // at time points that are multiples of 3

        // Full triple attacks possible
        long long full_triples = h / 5;
        T += full_triples * 3;
        long long rem = h % 5;

        if (rem == 0) {
            // No additional attack needed
        } else if (rem <= 2) {
            // Can be handled with one or two normal attacks
            T += 1;
        } else {
            // Need to use one triple attack
            T += 1;
        }
    }

    cout << T << endl;
    return 0;
}