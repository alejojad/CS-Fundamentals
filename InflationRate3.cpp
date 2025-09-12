//Alejandro Jad
//September 16, 2022
//Inflation rate: Console program that reads a list of times in HH:MM:SS format, 
//validates input, and computes the minimum and maximum timer values.

#include <iostream>
using namespace std;

void getCPIValues(float&, float&);
float getInflationRate(float, float);
void sort_array(float[], int);
void swap_values(float&, float&);
float findMedianRate(float[], int);
//void print_array(float[], int);
const int max_size = 20;


int main()
{
	//variables
	float ratesArray[max_size], oldCpi, newCpi, inflationRate, numberOfRepeats, averageRate, median;
	char repeat;
	int i, arraySize;
	
	
	//initialization
	numberOfRepeats = 0;
	averageRate = 0;
	i = 0;
	arraySize = 0;

	//input
	do
	{
		
		getCPIValues(oldCpi, newCpi);
		inflationRate = getInflationRate(oldCpi, newCpi);
	
		if(i < max_size)
		{
			ratesArray[i] = inflationRate;
			i++;
			arraySize++;
		}		
		//output
		cout << "Inflation rate is " << inflationRate << endl;
		cout << "Try again? (y or n): ";
		cin >>	repeat;
	
		//calculation to find total number of repeats, and total rate
		numberOfRepeats = numberOfRepeats + 1;
		averageRate = averageRate + inflationRate;
	}
	while(repeat == 'y');
	
	//formula to find the average rate:
	if(numberOfRepeats > 0)
	{
		averageRate = averageRate / numberOfRepeats;
		cout << "Average rate is " << averageRate << endl;
	}	
	
	//function to find median 
	median = findMedianRate(ratesArray, arraySize);
	cout << "Median rate is " << median << endl;
	
	//function to print array
	//print_array(ratesArray, arraySize);
				
	return 0;
}

void getCPIValues(float &old, float &newCpi)
{		
	do
	{
		cout << "Enter the old and new consumer price indices: ";
		cin >> old >> newCpi;

		if(old <=  0)
		{
			cout << "Error: CPI Values Must be greater than 0" << endl;
			cout << "Enter the old and new consumer price indices: ";
			cin >> old >> newCpi;	
		}
		if (newCpi <= 0)
		{		
			cout << "Error: CPI Values Must be greater than 0" << endl;
			cout << "Enter the old and new consumer price indices: ";
			cin >> old >> newCpi;
		}
	}
	while(old <=0 && newCpi <= 0);

}
float getInflationRate(float old, float newCpi)
{	
	if (old <=  0)
	{
		cout << "Error: CPI Values Must be greater than 0" << endl;
		cout << "Enter the old and new consumer price indices: ";
		cin >> old >> newCpi;
	}	
	if (newCpi <= 0)
	{
		cout << "Error: CPI Values Must be greater than 0" << endl;
		cout << "Enter the old and new consumer price indices: ";
		cin >> old >> newCpi;
	}
	

	//calculating inflation rate
	return  ( ( newCpi - old ) / old ) * 100;
}

void swap_values(float &a, float &b)
{

	float temp;
	
	temp = a; 
	a = b;
	b = temp;

}

void sort_array(float r[], int size)
{
	int maxElement, index;
	for(maxElement = size - 1; maxElement > 0; maxElement--)
	{
		for(index = 0; index < maxElement; index++)
		{
			if(r[index] > r[index + 1])
			{
				swap_values(r[index], r[index + 1]);
			}
		}
	}
}

//void print_array(float r[], int size)
//{
//	int i;
	
//	cout << "Sorted inflation rates" << endl;
//	for(i = 0; i <  size; i++)
//	{
//		cout << r[i] << endl;
//	}

	
//}
float findMedianRate(float r[], int size) 
{
	int index;
	float median;
	
	//function to sort the array
	sort_array(r, size);

	if(size % 2 == 0)
	{
		index = size / 2;
		median = (r[index - 1] + r[index])/2;
	}
	else
	{
		index = size / 2;
		median = r[index];
	}

	return median;
}
