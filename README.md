# C++ 学习笔记与代码手册

> 一份伴随学习过程持续整理的 C++ 个人知识库。这里既保留练习代码，也用 Markdown 记录概念、常见用法、易错点和复习路径。

## 项目目标

- **以代码为索引**：保留原始学习代码及其中的注释，方便回看当时的思路。
- **以主题为结构**：从基础语法逐步进入面向对象、模板、STL 和多线程。
- **以理解为主**：文档尽量解释“是什么、为什么、怎么用、容易错在哪里”，而不只是罗列语法。
- **持续迭代**：学习到新内容时，先补充对应专题文档，再把示例代码放入相应目录。

## 目录结构

```text
cpp-learning-handbook/
├── README.md                 # 项目入口与学习路线
├── code/                     # 原始学习代码（全部保留）
│   ├── 基础/                 # 基础语法、数组、指针、函数、结构体等
│   ├── 核心/                 # 引用、类与对象、内存模型、文件操作等
│   ├── 模板/                 # 函数模板、类模板
│   ├── STL/                  # 容器、迭代器和算法相关示例
│   └── 线程/                 # C++ 标准线程库示例
├── docs/                     # 按主题组织的 Markdown 笔记
├── SOURCE_INDEX.md           # 全部源文件索引
└── .gitignore
```

## 推荐学习路线

1. [C++ 基础语法](docs/01-basics.md)：数据类型、运算符、流程控制、数组和函数。
2. [指针、引用与内存](docs/02-pointers-references-memory.md)：地址、引用、动态内存及其风险。
3. [结构体与函数组织](docs/03-functions-and-structs.md)：函数声明/定义、模块化、结构体。
4. [类与对象](docs/04-classes-and-oop.md)：封装、构造/析构、拷贝、继承、多态。
5. [运算符重载](docs/05-operator-overloading.md)：让自定义类型支持自然的运算表达式。
6. [模板](docs/06-templates.md)：函数模板、类模板、模板实例化与文件组织。
7. **STL 专题**：先看 [STL 总览](docs/07-stl.md)，再按需学习下面的独立笔记。
   - [容器总览与选择](docs/07-stl-containers.md)
   - 序列容器：[vector](docs/07-stl-vector.md) · [string](docs/07-stl-string.md) · [deque](docs/07-stl-deque.md) · [list](docs/07-stl-list.md)
   - 容器适配器：[stack](docs/07-stl-stack.md) · [queue](docs/07-stl-queue.md) · [priority_queue](docs/07-stl-priority-queue.md)
   - 关联容器：[set / multiset](docs/07-stl-set.md) · [map / multimap](docs/07-stl-map.md) · [无序关联容器](docs/07-stl-unordered.md)
   - 工具类型：[pair](docs/07-stl-pair.md)
   - [STL 算法、迭代器与 lambda](docs/07-stl-algorithms.md)：for_each、sort、find、count、remove、unique、accumulate 等。
8. [文件操作与线程](docs/08-files-and-threads.md)：文本/二进制文件和 `std::thread`。
9. [调试与代码习惯](docs/09-practice-and-debugging.md)：编译、排错、资源管理和 Git 协作。

## 如何使用代码目录

- 每个 `.cpp` 通常是**独立的教学示例**，很多文件各自包含 `main()`，不要把整个 `code/` 一次性编译成同一个程序。
- 推荐一次只编译一个文件，例如：

  ```bash
  g++ -std=c++17 -Wall -Wextra -pedantic "code/基础/数据类型/整型.cpp" -o demo
  ./demo
  ```

- 个别示例依赖同目录的头文件，或需要把相关 `.cpp` 一起编译。请查看文件中的 `#include` 和函数定义。
- 部分源文件可能采用不同的历史编码；若中文注释显示乱码，请在编辑器中尝试 UTF-8、GBK/CP936 编码后确认，再统一转换。不要在未检查的情况下覆盖原文件。
- 原始代码主要用于学习记录，不保证每个例子都已按现代 C++ 风格完善。遇到内存管理、输入校验或编译问题时，可以在保留原始版本的基础上另建改进示例。

## 文档约定

- 代码中的注释体现学习时的理解；专题文档用于补充更系统的解释。
- 讨论语言特性时，优先区分“语法规则”“常见实现方式”和“个人经验”，避免把某种实现细节误认为语言标准保证。
- 示例默认以 C++17 为参考；需要更高版本时会特别注明。
- 推荐用小例子验证理解，并记录编译器错误信息与修复原因。

## 后续可以补充

- 每章增加练习题和参考答案；
- 为较复杂示例增加 `CMakeLists.txt`；
- 将原始练习与经过测试的“推荐写法”分开保存；
- 为进阶主题增加智能指针、RAII、移动语义、异常处理、标准算法和并发同步等笔记。
