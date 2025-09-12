//Alejandro Jad
//October 16, 2024
//N-queens problem: a chess-based combinatorial problem that 
//involves placing N queens on an NxN chessboard so that no two queens can 
//attack each other with the following specifications:In the base case 
//(r=n+1), after print Q[1…n] as result, also print the placement in the 
//format as the following example shows (here n=4)
//SQSS
//SSSQ
//QSSS
//SSQS
//Where character S denotes an empty square, Q denotes a square with a queen 
//placed in it. Stops after finding 4 answers to the 8 queen problem. */

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int sCount = 0; // To track the number of solutions found

void printBoard(const vector<int>& Q, int n) 
{
    for (int i = 1; i <= n; ++i) 
    {
        for (int j = 1; j <= n; ++j) 
        {
            if (Q[i] == j)
                cout << "Q";
            else
                cout << "S";
        }
        cout << endl;
    }
    cout << endl;
}

void PlaceQueens(vector<int>& Q, int n, int r = 1) 
{
    if (r == n + 1) 
    {
        cout << "Solution " << ++sCount << ": ";
        for (int i = 1; i <= n; ++i)
            cout << Q[i] << " ";
        cout << endl;
        
        printBoard(Q, n);

        if (sCount == 4) 
            return;
    } 
    else 
    {
        for (int col = 1; col <= n; ++col) 
        {
            bool legal = true;
            for (int i = 1; i < r; ++i) 
            {
                if (Q[i] == col || abs(i - r) == abs(Q[i] - col)) 
                {
                    legal = false;
                    break;
                }
            }
            if (legal) 
            {
                Q[r] = col;
                PlaceQueens(Q, n, r + 1);
            }
        }
    }
}

int main() 
{
    int n;
    
    cout << "How many Queens would you like to use" << endl;
    cin >> n;
    
    vector<int> Q(n + 1, 0); 
    PlaceQueens(Q, n);
    return 0;
}

