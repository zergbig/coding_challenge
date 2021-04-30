#include <iostream>

using namespace std;

// The factorial of a number N is the product of 
// N * (N - 1) * (N - 2) ... 1
// and is represented by the notation N!
// For example, 3! is computed as:
// 3 * 2 * 1 = 6

// The output from calling the following function with an input
// value of 5 was:
//
// The factorial of 5 is 0
//
// I expected that 5! would be 120, not 0. 
// How many things can you find wrong with this function?


// Compute and print out the factorial for a given input
void ComputeFactorial(int input)
{
	int* values = new int[input];

	// Load the values into the array starting with 1
	// i.e. if input == 3 then values will be:
	// values[0] = 1, values[1] = 2, values[2] = 3 
	for (int i = 0; i < input; i++)
	{
		values[i] = i+1;
	}

	// Compute the factorial
	int factorial = 1;
	for (int j = input; j >= 0; j--)
	{
		factorial *= values[j];
	}

	// Print the result
	printf("The factorial of %d is %d\n", input, factorial);
}

int main(int argc, char* argv[]) {
    	if (argc <= 1)
    {
        cout << "Usage: ./factorial <integer>" << endl;
        return 0;
    }
    
    int number = atoi(argv[1]);
    ComputeFactorial(number);
}
