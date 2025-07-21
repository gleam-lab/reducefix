#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long N, M;
    cin >> N >> M;
    
    set<pair<long long, long long>> unsafe;
    
    for (long long i = 0; i < M; ++i) {
        long long a, b;
        cin >> a >> b;
        unsafe.insert({a, b});
        
        // Check all 8 possible knight moves
        if (a + 2 <= N && b + 1 <= N) unsafe.insert({a + 2, b + 1});
        if (a + 1 <= N && b + 2 <= N) unsafe.insert({a + 1, b + 2});
        if (a - 1 >= 1 && b + 2 <= N) unsafe.insert({a - 1, b + 2});
        if (a - 2 >= 1 && b + 1 <= N) unsafe.insert({a - 2, b + 1});
        if (a - 2 >= 1 && b - 1 >= 1) unsafe.insert({a - 2, b - 1});
        if (a - 1 >= 1 && b - 2 >= 1) unsafe.insert({a - 1, b - 2});
        if (a + 1 <= N && b - 2 >= 1) unsafe.insert({a + 1, b - 2});
        if (a + 2 <= N && b - 1 >= 1) unsafe.insert({a + 2, b - 1});
    }
    
    long long total = N * N;
    long long unsafe_count = unsafe.size();
    long long safe = total - unsafe_count;
    
    cout << safe << '\n';
    
    return 0;
}