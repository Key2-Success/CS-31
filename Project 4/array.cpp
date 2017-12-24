// Name: Kitu Komya
// UID: 404-491-375
// Class: CS 31 - Winter 2017
// Dis: 1B
// Project: Project 4
// Due Date: 2/21/2017

#include <iostream>
#include <string>
#include <cassert>

using namespace std;

// locateMinimum function
int locateMinimum(const string array[], int n)
{
	int min = 0;
	if (n <= 0)
	{
		return -1;
	}
	else
	{
		for (int a = 0; a < n; a++)
		{
			if (array[a] < array[min])
			{
				min = a;
			}
		}
	}
	return min;
}

// findLastOccurrence function
int findLastOccurrence(const string array[], int n, string target)
{
	int max = -1;
	if (n <= 0)
	{
		return -1;
	}
	else
	{
		for (int b = 0; b < n; b++)
		{
			if (array[b] == target)
			{
				max = b;
			}
		}
	}
	return max;
}

// flipAround function
int flipAround(string array[], int n)
{
	int count = 0;
	if (n <= 0)
	{
		return -1;
	}
	else
	{
		for (int c = 0; c <= n / 2; c++)
		{
			if (c != n - c - 1)
			{
				count++;
				string temp = array[c];
				array[c] = array[n - c - 1];
				array[n - c - 1] = temp;
			}
		}
	}
	return count;
}

// hasNoDuplicates function
bool hasNoDuplicates(const string array[], int n) 
{
	if (n < 0) 
	{
		return false;
	}
	else 
	{
		for (int d = 0; d < n; d++) 
		{
			for (int e = 0; e < n; e++) 
			{
				if (d != e && array[d] == array[e]) 
				{
					return false;
				}
			}
		}
		return true;
	}
}

// unionWithNoDuplicates function
void unionWithNoDuplicates(const string array1[], int n1, const string array2[], int n2, string resultingString[], int& resultingSize)
{
	if (n1 < 0 || n2 < 0) 
	{
		resultingSize = -1;
	}
	else 
	{
		resultingSize = 0;
		for (int f = 0; f < n1; f++) 
		{
			bool found = false;
			for (int g = 0; g < resultingSize; g++) 
			{
				if (resultingString[g] == array1[f]) 
				{
					found = true;
				}
			}
			if (!found) 
			{
				resultingString[resultingSize++] = array1[f];
			}
		}
		for (int h = 0; h < n2; h++) 
		{
			bool found = false;
			for (int i = 0; i < resultingSize; i++) 
			{
				if (resultingString[i] == array2[h]) 
				{
					found = true;
				}
			}
			if (!found) 
			{
				resultingString[resultingSize++] = array2[h];
			}
		}
	}
}

// shiftRight function
int shiftRight(string array[], int n, int amount, string placeholderToFillEmpties)
{
	if (amount < 0 || amount > n || n < 0) 
	{
		return -1;
	}
	else {
		for (int k = 1; k < amount; k++) 
		{
			array[k] = array[k - 1];
		}
		return n - amount;
	}
}

// isInIncreasingOrder function
bool isInIncreasingOrder(const string array[], int n)
{
	if (n < 0) 
	{
		return false;
	}
	else if ((n == 0) || (n == 1)) 
	{
		return true;
	}
	else 
	{
		for (int l = 1; l < n; l++) 
		{
			if (array[l] <= array[l - 1]) 
			{
				return false;
			}
		}
		return true;
	}
}

int main()
{
	// string people[5] = { "samwell", "jon", "margaery", "daemerys", "tyrion" };
	// cout << isInIncreasingOrder(people, 3) << endl;

	return 0;
}	