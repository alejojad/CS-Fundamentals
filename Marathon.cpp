//Alejandro jad
//November 2, 2022
//Timer comparison: Program to calculate inflation rates from Consumer Price Index (CPI) values, 
//storing results in an array, and then computing the average and median rate across multiple entries.
#include <iostream>
#include <limits>
using namespace std;

//Declaring and defining struct timer
struct Timer
{
	
	int hours;
	int minutes;
	int seconds;
};

//Two parameters that are timers, both type timer
//Compares the hours, then minutes, then seconds
//Returns the difference between the two timers
int compareTimes(Timer timer1, Timer timer2)
{
	int diff = timer1.hours - timer2.hours;
    if (diff != 0) return diff;

    diff = timer1.minutes - timer2.minutes;
    if (diff != 0) return diff;

    diff = timer1.seconds - timer2.seconds; 
    return diff;
}

//parameter: Pointer to array of timers
//parameter: size of array
//Parameter: lowest timer= call by reference
//parameter highest timer= call by reference
//Find the minimum and maximum Timer in array of Timers
void findMinMaxTimer(Timer* array, int size, Timer& lowest, Timer& highest)
{   
    lowest = array[0];
    highest = array[0];

    for (int i = 1; i < size; i++)
    {
        int dLow = compareTimes(lowest, array[i]);
        if (dLow > 0)
        {
            lowest = array[i]; 
        }

        int dHigh = compareTimes(highest, array[i]);
        if (dHigh < 0)
        {
            highest = array[i]; 
        }
    }

}
//Paramater: array of Timers, type Timer
//Parameter: size, type int
//checks to see if inputs are valid
//returns Timer inputs to the array
void readTimer(Timer* array, int size)
{
	char aChar;
	for(int i = 0; i < size; i++)
	{
		cout << "Enter a Timer as hours:minutes:seconds(h:m:s)? ";
		cin >> array[i].hours >> aChar >> array[i].minutes >> aChar >> array[i].seconds;
		
		while(true)
		{
			cout << "Invalid Timer!" << endl;
			cout << "Enter a Timer as hours:minutes:seconds(h:m:s)? ";
			cin >> array[i].hours >> aChar >> array[i].minutes >> aChar >> array[i].seconds;
			
			while(array[i].seconds > 59)
			{
				cout << "Invalid Timer!" << endl;
				cout << "Enter a Timer as hours:minutes:seconds(h:m:s)? ";
				cin >> array[i].hours >> aChar >> array[i].minutes >> aChar >> array[i].seconds;
			}
		}
	}
}
//Parameter: size pf the array
//returns pointer to array
Timer* createTimerArray(int& size)
{
	Timer *arrayPtr= NULL;
	
	do
	{
		cout << "How many Timers do you need? ";//asking for size of the array
		cin >> size;
		if(size < 0)//check to see if value is valid
		{
			cout << "Enter a positive value!" << endl;
		}
	}
	while(size < 0);
	arrayPtr = new Timer [size];
	
	readTimer(arrayPtr, size);
		
	return arrayPtr;
}



int main()
{
	int sizeOfArray = 0;
	Timer timer;
	Timer *ptr;
	Timer lowestTimer;
	Timer highestTimer;
    
    
	ptr = createTimerArray(sizeOfArray);
	
	lowestTimer = ptr[0];
	highestTimer = ptr[0];	
	findMinMaxTimer(ptr, sizeOfArray, lowestTimer, highestTimer);
	
	cout << "The minimum Timer is: " << lowestTimer.hours << ":" << lowestTimer.minutes << ":" << lowestTimer.seconds << endl;
	cout << "The maximum Timer is: " << highestTimer.hours << ":" << highestTimer.minutes << ":" << highestTimer.seconds << endl;
	

	return 0;
}	


