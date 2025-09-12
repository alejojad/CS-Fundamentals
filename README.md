# CS Fundamentals (C++)

A collection of small C++ programs that demonstrate core computer science concepts such as recursion, backtracking, input validation, and algorithm design.  

---

## ♛ N-Queens Problem
**File:** `nqueens.cpp`  
Solves the classic **N-Queens** chess problem: place N queens on an N×N board so that no two queens attack each other. Uses recursive backtracking to explore valid placements and prints solutions as both vectors and full chessboards.  

**Concepts:** recursion, backtracking, constraint satisfaction, combinatorics.  
**Example (n=4):**
Solution 1: 2 4 1 3
SQSS
SSSQ
QSSS
SSQS

------------------------------
## 💰 Coin Change
**File:** `coin_change.cpp`  
Recursive solver for the coin change / subset sum problem. Given a list of coin denominations and a target value, determines whether the target can be made (using unlimited copies of the coins). If possible, outputs one valid combination.  

**Concepts:** recursion, backtracking, pass-by-reference.  
**Limitations:** exponential runtime for large inputs; returns only one solution.  

------------------------------

## ⏱ Marathon Timer Min/Max
**File:** `marathon_timer.cpp`  
Program that accepts timers in `HH:MM:SS` format, validates input, and finds the **minimum** and **maximum** times in the list.  

**Concepts:** structs, input validation, array traversal, min/max search.  
**Example:**
How many Timers do you need? 3
Enter a Timer as hours:minutes:seconds(h:m:s)? 2:03:07
Enter a Timer as hours:minutes:seconds(h:m:s)? 0:59:59
Enter a Timer as hours:minutes:seconds(h:m:s)? 4:10:00
The minimum Timer is: 0:59:59
The maximum Timer is: 4:10:00

------------------------------

## 📈 Inflation Rate Calculator
**File:** `inflation_rate.cpp`  
Reads old and new CPI values, computes the inflation rate, and stores multiple entries. Outputs the **average** and **median** inflation rates.  

**Concepts:** input validation, arrays, bubble sort, median calculation.  

------------------------------

## 🔧 How to Compile & Run
All programs are standard C++ and can be compiled with `g++`:  
```bash
g++ nqueens.cpp -o nqueens
./nqueens
Repeat for each file.
