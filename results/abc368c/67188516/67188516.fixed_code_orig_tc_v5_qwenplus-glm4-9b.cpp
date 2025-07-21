#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<long long> health(N);
    long long ans = 0;

    for (int i = 0; i < N; ++i) {
        cin >> health[i];

        // Calculate the number of hits needed to defeat the enemy
        long long hits = (health[i] + 2) / 3; // +2 for rounding up the division
        ans += hits;

        // Calculate the number of skips due to the multiple of 3
        long long skips = hits / 3;
        if (health[i] % 3 == 1) {
            // If the remainder is 1, we need to skip the next 3(T+1) hits
            // so subtract 1 from the total hits and +1 to the answer
            ans -= 1;
        }
    }

    cout << ans << endl;

    return 0;
}