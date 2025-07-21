#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Process {
    int a, p, b, q;
};

int binary_search(vector<Process>& processes, int budget) {
    int left = 0, right = 1e9 + 1;
    while (left < right) {
        int mid = left + (right - left) / 2;
        bool feasible = true;
        for (const auto& proc : processes) {
            // Calculate the minimum cost to achieve mid products per day
            int cost = 0;
            if (mid > 0) {
                cost = ((mid - 1) / proc.a / proc.b + 1) * min(proc.p * proc.b, proc.q * proc.a);
            }
            if (cost > budget) {
                feasible = false;
                break;
            }
        }
        if (feasible) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    return left - 1;
}

int main() {
    int n, x;
    cin >> n >> x;
    
    vector<Process> processes(n);
    for (auto& proc : processes) {
        cin >> proc.a >> proc.p >> proc.b >> proc.q;
        if (proc.a * proc.q > proc.b * proc.p) swap(proc.a, proc.b), swap(proc.p, proc.q);
    }
    
    cout << binary_search(processes, x) << endl;
    
    return 0;
}