# CLAUDE.md

This file provides guidance to Claude Code (claude.ai/code) when working with code in this repository.

## What this repo is

A personal archive of LeetCode solutions in C++, organized by algorithmic pattern/topic rather than by date or difficulty. There is no build system, no test suite, and no package manifest — this is not a conventional application.

## Repository structure

- Top-level directories are pattern categories: `Arrays`, `Backtracking`, `BinarySearch`, `Bits`, `DynamicProgramming`, `Graphs`, `Greedy`, `Heaps`, `LinkedList`, `Math`, `Matrix`, `SlidingWindow`, `Stack`, `Stocks`, `Strings`, `Trees` (with sub-patterns in `Trees/BST`, `Trees/LCA`, `Trees/Paths`, `Trees/Traversals`, `Trees/Views`), `Trie`, `TwoPointers`, `Design`.
- `Blind75/` duplicates solutions for problems on the Blind 75 list — a separate copy, not a symlink, so a fix to a shared problem (e.g. `121. Best Time to Buy and Sell Stock.cpp`) typically needs to be applied in both its pattern folder and in `Blind75/` if both copies exist.
- Files are named `<LeetCode number>. <Problem Title>.cpp` matching the official LeetCode title, and placed in whichever folder matches the primary technique used to solve them. A problem may legitimately appear in more than one folder if it's a good example of more than one pattern.
- `TODO` — flat list of problems still to solve, grouped by loose category.
- `Notes` — complexity cheat sheet (time complexity vs. max feasible `n`) and small C++ snippets for reference.

## Two different code styles — know which one you're writing

1. **LeetCode-submission style** (the vast majority of files, e.g. `Arrays/1.Two_Sum.cpp`): just a `class Solution { public: ... };` body with no `#include`s and no `using namespace std;`. These rely on LeetCode's judge environment, which already provides the standard includes and `using namespace std`. Do not add includes/`main()` to files in this style — it would be inconsistent with every other file and isn't needed to submit on LeetCode.
2. **Standalone mock-design programs** (`Design/*`, `Graphs/PortfolioSimulator.cpp`): full, self-contained `.cpp`/`.h` files with explicit includes, `std::` qualification or `using namespace std;`, and a `main()` that exercises the class with sample input. These model "object-oriented design" interview questions (e.g. a stock brokerage system, a portfolio price simulator, a logger) rather than single-function LeetCode problems. New files of this kind should stay consistent with this pattern: a class/struct implementing the behavior, plus a `main()` demonstrating it.

## Building / running

There is no CMakeLists.txt, Makefile, or test runner despite the `.idea` CMake module marker — that marker is stale/unused. In practice, standalone programs (style 2 above) are compiled and run ad hoc with g++, e.g.:

```sh
g++ -std=c++17 -o /tmp/out "Design/Stock_Brokerage_System.cpp" && /tmp/out
```

For multi-file programs like the `Logger` (split across `Design/Logger.h`/`Design/Logger.cpp`), compile all relevant `.cpp` files together:

```sh
g++ -std=c++17 -o /tmp/out Design/Logger.cpp <other .cpp files using it> && /tmp/out
```

LeetCode-submission style files (style 1) are not meant to be compiled standalone — verify them by pasting into LeetCode's editor, or by wrapping in a scratch file with includes/`main()` added only in a temp/scratch location, not committed to the repo.

## Linting

`.clang-tidy` at the repo root defines the enabled clang-tidy checks (bugprone-*, cert-*, cppcoreguidelines-*, modernize-*, performance-*, readability-*, etc.). Run it against a specific file when editing C++ rather than assuming it's wired into any CI (there is none):

```sh
clang-tidy "Arrays/1.Two_Sum.cpp" --
```

## Conventions observed in existing code

- Most files open with a `// Created by <name> on <date>.` comment header.
- Two-space indentation.
- `vector`, `unordered_map`, etc. used unqualified in LeetCode-style files (style 1); `std::` is used explicitly or via `using namespace std;` in standalone programs (style 2).
