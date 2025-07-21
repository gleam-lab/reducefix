#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, q;
    cin >> n; // 读取n值
    vector<int> x(n), p(n), sum(n); // 定义与n等长的向量
    
    // 读取x和p的值
    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }
    for (int i = 0; i < n - 1; i++) { // 注意循环范围调整为n-1
        p[i] = p[i + 1] - p[i]; // 这里根据题意调整了p的逻辑，计算差分数组p的元素值
        sum[i] = (i > 0) ? sum[i - 1] + p[i] : p[i]; // 计算前缀和sum[i]
    }
    // 注意：如果p数组是累加的和，则不需要计算差分数组p，直接计算sum即可。
    // 否则需要确保p的逻辑与sum的计算相匹配。
    
    cin >> q; // 读取查询次数q
    while (q--) {
        int l, r; // 定义查询的左右边界变量l和r
        cin >> l >> r; // 读取左右边界值
        // 使用二分搜索找到x中值的下界和上界索引（这里假设x是排序的）
        auto it_lower = lower_bound(x.begin(), x.end(), l); // 注意这里的类型和参数需要与实际一致（C++11）
        auto it_upper = upper_bound(x.begin(), x.end(), r); // 同理，注意类型和参数的一致性
        int l_index = it_lower - x.begin(); // 计算下标索引（注意减去begin指针）
        int r_index = it_upper - x.begin() - 1; // 上界索引需要减1，因为upper_bound指向的是"下一个"元素的位置（不包括该元素）
        // 注意：如果r在x中不存在，则r_index为x的末尾位置（即n），因此需要确保r_index是合法的。这里假定x足够大或者已排序以处理边界情况。
        if (l_index > 0 && r_index < n) { // 检查边界条件是否满足（即l和r都在x中）
            cout << sum[r_index - 1] - sum[l_index - 1] << endl; // 输出sum的差值结果（注意下标减一）
        } else {
            // 如果l或r不在x中，根据需求决定如何处理（例如输出特殊值或跳过此查询）
            // 这里不做特殊处理，但应确保程序能够正确处理这些情况。
        }
    }
    return 0; // 主函数返回0表示程序正常结束。
}