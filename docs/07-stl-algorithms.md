# 07B · STL 算法、迭代器与 lambda

STL 算法通常通过迭代器接收一个范围，而不是直接接收整个容器。大多数常用算法定义在 `<algorithm>`，数值算法如 `accumulate` 定义在 `<numeric>`。

## 1. 迭代器的基本形式

```cpp
std::vector<int> nums{4, 1, 3};
auto it = nums.begin();
std::cout << *it; // 4
++it;
std::cout << *it; // 1
```

`begin()` 指向第一个元素；`end()` 指向最后一个元素之后的位置。空容器中 `begin() == end()`，不能解引用 `end()`。

常见迭代器类别可以先粗略理解为：

- 输入 / 输出迭代器：读取或写入数据流式范围。
- 前向迭代器：可多次向前遍历。
- 双向迭代器：可以 `++` 和 `--`，例如 `list`、`set`。
- 随机访问迭代器：支持跳跃、下标偏移和距离计算，例如 `vector`、`deque`。

通用写法优先使用 `++it` 和 `it != container.end()`，不要假定所有容器都支持 `it + 1`。

## 2. `for_each`

对 `[first, last)` 中的每个元素执行一个可调用对象。可调用对象可以是普通函数、函数对象或 lambda。

```cpp
#include <algorithm>
#include <iostream>
#include <vector>

int main() {
    std::vector<int> nums{1, 2, 3};
    std::for_each(nums.begin(), nums.end(), [](int value) {
        std::cout << value << ' ';
    });
}
```

如果要修改原元素，参数应接收引用：

```cpp
std::for_each(nums.begin(), nums.end(), [](int& value) {
    value *= 2;
});
```

`for_each` 返回传入的函数对象（按值返回）。若只是遍历并输出，范围 `for` 也很清楚；学习 `for_each` 的意义是理解算法如何接受可调用对象。

## 3. lambda 表达式

基本结构：

```cpp
[capture](parameters) -> return_type {
    // 函数体
};
```

返回类型在编译器能够推导时可以省略。

- `[]`：不捕获外部变量。
- `[x]`：按值捕获 `x`。
- `[&x]`：按引用捕获 `x`。
- `[=]`：按值捕获用到的外部局部变量。
- `[&]`：按引用捕获用到的外部局部变量。

例：

```cpp
int limit = 5;
auto is_large = [limit](int value) {
    return value > limit;
};
```

按值捕获意味着 lambda 保存一份捕获对象的副本；按引用捕获需要确保被引用的对象在 lambda 使用期间仍然存在。

## 4. `sort`：排序

```cpp
#include <algorithm>
#include <vector>
std::vector<int> nums{4, 1, 3, 2};
std::sort(nums.begin(), nums.end()); // 升序
std::sort(nums.begin(), nums.end(), std::greater<int>()); // 降序，需 <functional>
```

自定义排序规则时，比较器应表达严格弱序关系。排序结构体示例：

```cpp
struct Student {
    std::string name;
    int score;
};
std::sort(students.begin(), students.end(),
          [](const Student& a, const Student& b) {
              return a.score > b.score; // 分数从高到低
          });
```

`std::sort` 需要随机访问迭代器，因此可用于 `vector` / `deque`，不能直接用于 `list`；`list` 有自己的 `sort()` 成员函数。

## 5. `find`、`count`、`reverse`、`accumulate`

```cpp
#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

int main() {
    std::vector<int> nums{1, 2, 2, 4};

    auto it = std::find(nums.begin(), nums.end(), 2);
    if (it != nums.end()) std::cout << "找到：" << *it << '\n';

    std::cout << std::count(nums.begin(), nums.end(), 2) << '\n';
    std::reverse(nums.begin(), nums.end());
    int total = std::accumulate(nums.begin(), nums.end(), 0);
    std::cout << total << '\n';
}
```

`find` 未找到时返回 `end()`；`count` 返回匹配数量；`reverse` 原地反转；`accumulate` 的初始值类型会影响累加结果类型。求和 `int` 时初始值可写 `0`，需要更宽类型时可使用 `0LL` 等。

## 6. `remove` 与真正删除元素的区别

`std::remove` 不会改变容器的 `size()`，而是把不需要的值移到逻辑范围尾部，并返回新的逻辑结尾。对于 `vector`，常用“erase-remove”写法：

```cpp
#include <algorithm>
#include <vector>
std::vector<int> nums{1, 2, 3, 2, 4};
auto new_end = std::remove(nums.begin(), nums.end(), 2);
nums.erase(new_end, nums.end()); // 这一步才真正缩短 vector
```

如果是 C++20，可使用 `std::erase(nums, 2)`；但本笔记示例以 C++17 为基准。

## 7. `transform` 与 `unique`

```cpp
#include <algorithm>
#include <vector>
std::vector<int> nums{1, 2, 3};
std::transform(nums.begin(), nums.end(), nums.begin(),
               [](int x) { return x * x; }); // 原地平方
```

`std::unique` 只消除**相邻**重复元素，并返回新的逻辑结尾。若要去掉所有重复值，通常先排序再 `unique + erase`：

```cpp
std::vector<int> nums{3, 1, 2, 1, 3};
std::sort(nums.begin(), nums.end());
nums.erase(std::unique(nums.begin(), nums.end()), nums.end());
```

如果必须保留原始出现顺序，需要另行设计去重策略，不能直接套用“先排序”的方法。

## 8. 算法与容器的配合

- `std::sort`：需要随机访问迭代器；`list` 用 `list.sort()`。
- `std::find`、`std::count`：可用于许多标准容器的迭代器范围。
- `set` / `map` 已按键排序；查找键时优先使用其 `find()` 成员函数。
- 对容器进行 `insert` / `erase` 等结构修改后，要关注迭代器是否失效；不同容器的规则不同。

## 9. 练习

1. 创建 `vector<int>`，输入 8 个整数，输出最大值、最小值和总和。
2. 使用 `sort` 将一组整数升序和降序各排序一次。
3. 用 `count` 统计某个数字出现次数，用 `find` 判断某数字是否存在。
4. 用 lambda 按学生成绩从高到低排序；成绩相同时按姓名字典序排序。
5. 用 `map<string, int>` 统计输入文本中每个单词出现的次数。
6. 使用 `queue<int>` 模拟任务队列，说明为什么 `pop()` 之前要先读取 `front()`。
7. 对比 `remove + erase` 与 `vector::erase`，解释它们的行为区别。
