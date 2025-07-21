#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    int sum = 0;
    unordered_map<int, int> prefix_count;

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        sum = (sum + a[i]) % m;
        prefix_count[sum]++;
    }

    int result = 0;
    for (int i = 0; i < n; ++i) {
        result += prefix_count[(sum - a[i]) % m];
    }

    cout << result << endl;
    return 0;
}