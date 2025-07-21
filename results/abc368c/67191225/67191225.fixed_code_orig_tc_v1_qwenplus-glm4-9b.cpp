#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<long long> H(N);
    for (int i = 0; i < N; i++) cin >> H[i];

    long long total_deaths = 0;
    for (long long health : H) {
        if (health % 3 == 0) {
            total_deaths += health / 3;  // If health is already a multiple of 3, attack once.
        } else {
            total_deaths += (health / 3) + 1; // If health is not a multiple of 3, attack once and then add the remainder.
        }
    }

    cout << total_deaths << endl;
    return 0;
}