#include<bits/stdc++.h>
using namespace std;
int n, q, x[200005], p[200005], sum[200005]; // 注意sum数组的大小应与p相同

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> x[i];
    }
    sort(x + 1, x + n + 1); // 对x数组进行排序，以便使用lower_bound和upper_bound
    
    // 初始化sum数组为0，并计算前缀和
    sum[0] = 0; // 初始化第一个元素为0，作为前缀和的起始点
    for (int i = 1; i <= n; i++) {
        cin >> p[i]; // 读取p数组的值
        sum[i] = sum[i - 1] + p[i]; // 计算前缀和
    }
    
    cin >> q;
    while (q--) {
        int l, r;
        cin >> l >> r; // 读取l和r的值
        // 使用lower_bound和upper_bound找到l和r的索引，但注意检查边界情况（如l或r不在数组中）
        auto it_l = lower_bound(x + 1, x + n + 1, l) - x; // 找到l的索引（注意是左边界）
        auto it_r = upper_bound(x + 1, x + n + 1, r) - x; // 找到r的索引（注意是右边界）
        // 检查边界情况，确保不会出现负数索引或越界访问的情况
        if (it_l > n || it_r > n) { // 如果索引超出范围，则使用n作为边界值（这里假设n是最大索引）
            it_l = it_r = n; // 这里我们假设如果找不到则使用最后一个元素的索引n作为边界值，这可能需要根据实际情况调整。
        } else if (it_l == n || it_r == n) { // 如果一个边界是n（即超出范围），则使用另一个边界值作为有效索引。
            it_l = it_r - 1; // 这是基于题目的合理假设，需要验证是否符合预期的逻辑。
        } else if (it_l > it_r) { // 如果左边界比右边界大（即未找到左边界），则使用右边界作为有效索引。
            it_l = it_r - 1; // 这里我们假设如果找不到左边界则使用右边界的前一个位置作为有效索引。这可能需要根据实际情况调整。
        } else { // 在这种情况下，我们可以正常访问两个索引。
            // 使用前缀和计算区间内的和并输出结果。注意是i-1而不是i，因为我们的数组是从1开始的。
            cout << sum[it_r - 1] - sum[it_l - 1] << endl; // 输出计算结果
        }
    }
    return 0;
}