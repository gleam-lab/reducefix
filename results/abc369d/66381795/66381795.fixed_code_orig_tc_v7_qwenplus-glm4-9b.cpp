#include <iostream>
#include <vector>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    int n;
    cin >> n;
    vector<int> data(n);
    rep(i, n) {
        cin >> data[i];
    }

    long long sum = 0;
    int evenIndex = 0;
    rep(i, n) {
        if (i % 2 == 0) { // Current index is even
            if (evenIndex == 0 || (data[i] * 2 > data[i - 1] + data[i])) {
                sum += data[i] * 2; // Double the value if the condition holds
            } else {
                sum += data[i]; // Otherwise, just add the value
            }
            evenIndex++; // Increment the even index counter
        }
    }

    cout << sum << endl;
    return 0;
}