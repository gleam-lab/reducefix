#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;
    std::vector<int> a(n), b(n-1);
    
    for(int i = 0; i < n; ++i) 
        std::cin >> a[i];
    
    for(int i = 0; i < n-1; ++i) 
        std::cin >> b[i];
    
    std::sort(a.begin(), a.end());
    std::sort(b.begin(), b.end());

    int ans = -1;

    for(int i = 0; i < n-1; ++i) {
        if(b[i] >= a[n-1]) {
            ans = a[n-1];
            break;
        } else if(i == n-2 && b[i] < a[n-1]) {
            ans = -1;
            break;
        }
    }

    std::cout << ans << std::endl;

    return 0;
}