#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<long long> data(n);
    for(int i = 0; i < n; ++i) {
        cin >> data[i];
    }

    long long sum = 0;
    for(int i = 0; i < n; ++i) {
        if((i + 1) % 2 == 0 && i > 0 && data[i] * 2 <= data[i - 1] + data[i + 1]) {
            sum += data[i] * 2;
        } else {
            sum += data[i];
        }
    }

    cout << sum << endl;
    return 0;
}