#include <bits/stdc++.h>
using namespace std;

int n, q, x[200005], p[200005];
map<int, int> sum;

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> x[i];
        // 确保p数组与x数组对应位置的值一致（如果需要）
        // 如果p是累加前缀和，则不需要这一步
    }
    // 计算p的前缀和并存入sum中
    for (int i = 1; i <= n; i++) {
        if (i > 1) p[i] += p[i - 1]; // 假设p是累加前缀和
        sum[i] = sum[i - 1] + p[i]; // 更新sum以存储累加和的差值
    }
    
    cin >> q;
    while (q--) {
        int L, R;
        cin >> L >> R; // 读取查询的左右边界值L和R
        // 使用lower_bound和upper_bound查找边界索引时需要处理x数组的离散性（如果存在重复值）
        auto itL = lower_bound(x + 1, x + n + 1, L); // 找到第一个大于或等于L的元素的位置
        auto itR = upper_bound(x + 1, x + n + 1, R); // 找到第一个大于R的元素的位置
        // 由于C++ STL默认使用小于等于比较，所以实际要找的是左开右开的区间[itL的位置, itR的位置)的元素，所以需要调整一下itR的位置来计算差值
        int c = itL - x - 1; // 修正后的c为左边界的索引（由于我们想用开区间）
        if (itR != x) { // 检查是否真的找到了一个右边界（防止x中只有小于R的值）
            int d = itR - x - 1; // 修正后的d为右边界的索引（由于我们想用开区间）
            // 现在计算sum的差值并输出结果（假设p是累加前缀和）
            cout << sum[d] - sum[c] << endl; // 这里我们计算的是区间内的前缀和差值（因为题目没有具体说明p的含义）
        } else { // 如果右边界没有找到（例如，如果R大于所有x的值），则输出0或其他默认值，视具体情况而定。
            cout << "默认值" << endl; // 这里需要根据实际情况替换为合适的默认值输出逻辑。
        }
    }
    return 0;
}