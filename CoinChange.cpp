/*Alejandro Jad
October 16, 2024
check if we can give a value of t using coins from
list. Sets a pass-by-reference variable to true/false depending on 
whether the target t can be made or not. returns the coins used to 
make t as a vector.*/

#include <iostream>
#include <vector>
using namespace std;

bool CoinChange(int t, vector<int>& a, vector<int>& result) 
{
    if (t == 0) 
    {
        return true; 
    }
    if (t < 0) 
    {
        return false;  
    }

    for (int i = 0; i < a.size(); ++i) 
    {
        if (CoinChange(t - a[i], a, result)) 
        {
            result.push_back(a[i]);  
            return true;
        }
    }

    return false; 
}

int main() 
{
    int numCoins, target;

    // Input the number of coins
    cout << "Enter the number of coins: ";
    cin >> numCoins;

    // Input the coin denominations
    vector<int> coins(numCoins);
    cout << "Enter the coin denominations: ";
    for (int i = 0; i < numCoins; ++i) {
        cin >> coins[i];
    }

    // Input the target value
    cout << "Enter the target value: ";
    cin >> target;

    // Vector to store the result (coins used)
    vector<int> result;

    // Check if we can make the target value and store the result
    bool canMake = CoinChange(target, coins, result);

    // Output result
    if (canMake) {
        cout << "Target " << target << " can be made using the following coins: ";
        for (int coin : result) {
            cout << coin << " ";
        }
        cout << endl;
    } else {
        cout << "Target " << target << " cannot be made with the given coins." << endl;
    }

    return 0;
}
