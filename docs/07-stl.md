# 07 · STL：标准模板库总览

STL（Standard Template Library，标准模板库）是 C++ 标准库中一组可复用的通用组件。学习 STL 的关键不是背函数名，而是理解**容器负责存数据、迭代器负责定位元素、算法负责处理范围**。

## 1. STL 的三个核心部分

- **容器（container）**：保存和组织数据，例如 `vector`、`list`、`map`。
- **迭代器（iterator）**：类似广义指针，用来访问容器中的元素。`begin()` 指向第一个元素，`end()` 指向最后一个元素之后的位置。
- **算法（algorithm）**：通过迭代器范围处理元素，例如 `sort`、`find`、`count`、`for_each`。

标准算法常用的范围是左闭右开区间 `[first, last)`：包含 `first`，不包含 `last`。

## 2. 常用头文件

| 头文件 | 常见内容 |
|---|---|
| `<vector>` | `std::vector` 动态数组 |
| `<string>` | `std::string` 字符串 |
| `<deque>` | `std::deque` 双端队列 |
| `<list>` | `std::list` 双向链表 |
| `<stack>` | `std::stack` 栈适配器 |
| `<queue>` | `std::queue` 队列、`std::priority_queue` 优先队列 |
| `<set>` | `std::set`、`std::multiset` |
| `<map>` | `std::map`、`std::multimap` |
| `<unordered_set>` | 哈希集合 |
| `<unordered_map>` | 哈希映射 |
| `<algorithm>` | `sort`、`find`、`count`、`for_each` 等算法 |
| `<numeric>` | `accumulate` 等数值算法 |
| `<iterator>` | 迭代器辅助工具 |

初学时建议显式写 `std::vector` 等名称，能更清楚地看出它们属于标准库；不必急着使用 `using namespace std;`。

## 3. `std::vector`：动态数组

`vector` 的元素在逻辑上连续存储，适合按下标访问以及在末尾添加元素。

```cpp
#include <iostream>
#include <vector>

int main() {
    std::vector<int> nums{10, 20, 30};
    nums.push_back(40);

    for (std::size_t i = 0; i < nums.size(); ++i) {
        std::cout << nums[i] << ' ';
    }
    std::cout << '\n';
}
```

| 接口 | 作用 |
|---|---|
| `push_back(x)` / `pop_back()` | 末尾添加 / 删除一个元素 |
| `size()` / `empty()` | 元素数量 / 是否为空 |
| `capacity()` | 当前容量，即无需重新分配时可容纳的元素数量 |
| `v[i]` / `v.at(i)` | 下标访问；`at` 会进行边界检查 |
| `front()` / `back()` | 首元素 / 尾元素 |
| `begin()` / `end()` | 首元素迭代器 / 尾后迭代器 |
| `clear()` | 删除所有元素，但不保证容量缩小 |
| `reserve(n)` | 至少预留 n 个元素的容量，不会把元素数量改为 n |
| `resize(n)` | 把元素数量改为 n，必要时创建或删除元素 |
| `assign(...)` | 用给定数量和值、迭代器范围或初始化列表替换当前内容 |
| `insert` / `erase` | 在指定位置插入 / 删除元素 |

### `reserve()` 和 `resize()` 的区别

```cpp
std::vector<int> a;
a.reserve(5); // size() 仍然是 0，只预留容量

a.resize(5);  // size() 变成 5，新增的 int 元素值为 0
```

`reserve` 不会创建可通过 `a[0]` 访问的元素；只有元素实际存在时才能通过下标访问。

### 迭代器失效

`vector` 因扩容重新分配内存时，指向其元素的指针、引用和迭代器可能全部失效。即使没有扩容，在中间插入或删除元素，也可能使插入/删除位置及其后的迭代器失效。修改容器后不要盲目继续使用旧迭代器。

## 4. `std::string`：字符串容器

`string` 可以看作管理字符序列的标准类，支持拼接、查找、截取和修改。

```cpp
#include <iostream>
#include <string>

int main() {
    std::string name = "C++";
    name += " STL";
    std::cout << name << '\n';
    std::cout << "长度：" << name.size() << '\n';
    std::cout << name.substr(4, 3) << '\n';
}
```

常见成员：`size()` / `length()`、`empty()`、`clear()`、`append()`、`find()`、`substr()`、`insert()`、`erase()`、`replace()`、`at()`。`find()` 找不到时返回 `std::string::npos`。

注意：`string` 的 `size()` 统计的是 `char` 元素数量，不等同于中文字符数量或屏幕显示宽度；UTF-8 中文字符通常占多个字节。

## 5. 其他常见容器概览

容器选择与操作复杂度的完整对照见 [STL 常用容器](07-stl-containers.md)。先记住：

- `vector`：连续动态数组，默认优先考虑的序列容器。
- `deque`：双端队列，首尾插入删除方便。
- `list`：双向链表，已知位置的插入删除方便，但不支持下标随机访问。
- `stack`：后进先出（LIFO）。
- `queue`：先进先出（FIFO）。
- `priority_queue`：优先级最高的元素先取出，默认最大堆。
- `set` / `map`：按键排序，通常基于平衡树；`set` 保存唯一键，`map` 保存键值对。
- `unordered_set` / `unordered_map`：基于哈希表，平均查找通常较快，但不保证遍历顺序。

## 6. 迭代器与范围 `for`

```cpp
std::vector<int> nums{1, 2, 3};

for (auto it = nums.begin(); it != nums.end(); ++it) {
    std::cout << *it << ' '; // *it 访问迭代器所指元素
}

for (const auto& value : nums) {
    std::cout << value << ' '; // 只读访问，不复制元素
}
```

- `auto` 让编译器推导变量类型。
- `auto&` 是引用，可用于修改元素；`const auto&` 避免复制且不允许通过该引用修改元素。
- `*it` 解引用，`++it` 移动到下一个位置。
- 并非所有迭代器都支持 `it + 1` 或 `<` 比较；通用遍历优先使用 `++it` 和 `it != end()`。

## 7. 常见算法入口

算法通常不属于某个容器，而是通过迭代器与多种容器配合。详细说明和例子见 [STL 算法与 lambda](07-stl-algorithms.md)。

| 算法 | 典型用途 |
|---|---|
| `std::for_each` | 对范围中的元素逐个执行操作 |
| `std::sort` | 排序，要求随机访问迭代器，不能直接用于 `list` |
| `std::find` | 查找指定值 |
| `std::count` | 统计指定值出现次数 |
| `std::reverse` | 反转范围 |
| `std::accumulate` | 累加范围中的值，定义在 `<numeric>` |
| `std::remove` | 把要“移除”的元素移动到范围尾部，并返回新的逻辑结尾；本身不改变容器大小 |

## 8. 本章原始代码

本仓库 `code/STL/` 保留了原始学习示例，包括 STL 概念、容器/算法/迭代器、`vector` 容量/访问/数据操作/预留空间、`string` 和 `queue`。新增的系统讲解放在本章及其子文档中，不覆盖原始练习代码。

## 9. 建议学习顺序

1. 先练熟 `vector` 的 `size`、`capacity`、`reserve`、`resize`、迭代器和 `assign`。
2. 学会使用 `string` 和 `queue`，理解 FIFO 与 LIFO。
3. 学习 `sort`、`find`、`count`、`for_each`，再学习 lambda。
4. 对比 `deque`、`list`、`set`、`map` 和哈希容器，知道它们各自适合什么问题。
5. 最后练习 `pair`、`map` 遍历、删除元素与迭代器失效等组合问题。
