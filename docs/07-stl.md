# 07 · STL：容器、迭代器与算法

STL（标准模板库）提供通用容器、迭代器和算法。可以先把它理解为三个协作部分：

- **容器**：管理数据，如 `std::vector`、`std::string`、`std::queue`。
- **迭代器**：提供访问容器元素的统一方式，常被类比为广义指针。
- **算法**：对迭代器范围进行操作，如排序、查找、遍历。

## 1. `std::vector`

`vector` 是可动态扩展的连续存储序列。常用接口：

| 接口 | 含义 |
|---|---|
| `push_back(x)` | 在末尾添加元素 |
| `size()` | 当前元素数量 |
| `capacity()` | 当前无需重新分配即可容纳的容量 |
| `empty()` | 是否为空 |
| `at(i)` | 带边界检查的访问 |
| `operator[](i)` | 下标访问，不进行边界检查 |
| `front()` / `back()` | 首元素 / 尾元素 |
| `begin()` / `end()` | 首元素迭代器 / 尾后迭代器 |
| `clear()` | 清空元素，不保证容量缩小 |
| `reserve(n)` | 预留容量，不会直接创建 n 个元素 |
| `resize(n)` | 改变元素数量，必要时创建或移除元素 |
| `assign(...)` | 用给定范围或数量/值替换当前元素 |

`end()` 指向最后一个元素之后的位置，不是最后一个元素。遍历区间通常采用左闭右开 `[begin(), end())`。

`reserve` 和 `resize` 不同：前者调整容量，后者调整元素数量。`vector` 扩容可能使指向元素的指针、引用和迭代器失效；在修改容器前后，应确认是否可能发生重新分配。

## 2. `std::string`

`std::string` 是标准字符串类，常用操作包括拼接、长度查询、访问字符、查找和子串。它管理自己的存储，通常比手动操作字符数组更安全方便。注意下标访问仍然需要保证索引有效。

## 3. `std::queue`

`queue` 是先进先出（FIFO）适配器，常见接口为 `push`、`pop`、`front`、`back`、`empty` 和 `size`。`pop()` 只移除队首元素，不返回该元素；需要先读取 `front()`，再调用 `pop()`。访问 `front()` 前应确保队列非空。

## 4. 迭代器和算法

很多标准算法接受一对迭代器表示范围，例如 `[first, last)`。这意味着 `first` 指向首个待处理元素，而 `last` 是尾后位置。

`std::for_each(first, last, callable)` 会对范围内的元素调用可调用对象。可调用对象可以是函数、函数对象或 lambda。若只需要遍历并执行简单操作，现代 C++ 的范围 `for` 也常常更清晰。

```cpp
#include <algorithm>
#include <iostream>
#include <vector>

int main() {
    std::vector<int> values{1, 2, 3};
    std::for_each(values.begin(), values.end(),
                  [](int value) { std::cout << value << ' '; });
}
```

算法不一定会改变容器大小；具体行为要看算法本身。有些算法要求迭代器满足特定能力，例如随机访问迭代器。

## 5. 本章代码

对应 `code/STL/`，包括 STL 概念、容器/算法/迭代器、`vector`、`string`、`queue` 及容量、访问、修改和预留空间等示例。
