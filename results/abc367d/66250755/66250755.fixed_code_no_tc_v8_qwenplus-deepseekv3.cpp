#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> a(2 * n + 1);
    vector<int> prefix(2 * n + 1, 0);
    
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i] %= m;
        if (a[i] < 0) a[i] += m;
        a[i + n] = a[i];
    }
    
    for (int i = 1; i <= 2 * n; i++) {
        prefix[i] = (prefix[i - 1] + a[i]) % m;
        if (prefix[i] < 0) prefix[i] += m;
    }
    
    unordered_map<int, int> count;
    int result = 0;
    
    for (int i = 1; i <= 2 * n; i++) {
        if (i > n) {
            int val = prefix[i - n];
            count[val]--;
            if (count[val] == 0) {
                count.erase(val);
            }
        }
        
        if (i >= n) {
            int target = prefix[i];
            result += count[target];
        }
        
        count[prefix[i]]++;
    }
    
    cout << result << endl;
    return 0;
}