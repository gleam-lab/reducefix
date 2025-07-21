#include<iostream>
#include<set>

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::set<int> s;
    int q;
    std::cin >> q;

    while(q--){
        int n, x;
        std::cin >> n;

        if(n == 1){
            std::cin >> x;
            s.insert(x); // Add element to the set
        } else if(n == 2){
            std::cin >> x;
            s.erase(s.find(x)); // Remove element from the set
        } else {
            std::cout << s.size() << "\n"; // Output the number of unique elements
        }
    }

    return 0;
}