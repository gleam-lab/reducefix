#include<bits/stdc++.h>
using namespace std;

int main() {
    int a, m;
    cin >> a >> m;

    vector<int> nums(a);
    for (int i = 0; i < a; i++) {
        cin >> nums[i];
    }

    vector<int> prefixSum(a + 1, 0);
    for (int i = 0; i < a; i++) {
        prefixSum[i + 1] = prefixSum[i] + nums[i];
    }

    vector<int> remainderCounts(m, 0);

    for (int s = 0; s <= a; s++) {
        for (int t = s + 1; t <= a; t++) {
            int remainder = (prefixSum[t] - prefixSum[s]) % m;
            if (remainder < 0) remainder += m;
            remainderCounts[remainder]++;
        }
    }

    long long count = 0;
    for (int remainder : remainderCounts) {
        count += (long long)remainder * (remainder - 1) / 2;  // nC2 = n * (n-1) / 2
    }

    cout << count << endl;
    return 0;
}