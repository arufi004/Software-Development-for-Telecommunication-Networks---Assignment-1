/*
Name:			Anthony Rufin
Panther ID:		6227314

Class:			TCN5440
Section:		U01
Semester:		Spring 2025

Assignment:		Programming Assignment 1
Due:			February 13, 2025

Honesty Statement:	I have done this assignment completely on my own. I have not copied it, nor have I given my solution to anyone else.
			I understand that if I am involved in plagiarism or cheating I will receive the penalty specified in the FIU regulations.
*/
#include <stdio.h>

int myStrStr(char haystack[], char needle[], char buffer[])
{
	int i, j, k;
	if (needle[0] == '\0')//if needle is empty, return 0
	{
		printf("needle is empty\n");
		return 0;
	}

	for(i = 0; haystack[i] != '\0'; i++)//iterate through the haystack until we reach the null value at the end of the string
	{
		j = 0;
		while(haystack[i + j] == needle[j] && needle[j] != '\0')//compares characters in haystack to needle. starting from i in haystack
		{
			j++;
		}

		if(needle[j] == '\0')//all characters in needle matched a set of characters in haystack
		{
			k = 0;
			while(k < j)//copy substring found in haystack based on needle into the buffer.
			{
				buffer[k] = haystack[i + k];
				k++;
			}
			buffer[k] = '\0';//null terminate char at the end of the string
			return 1;//match found

		}
	}

	buffer[0] = '\0';
	return 0;//no match found

}

int main ()
{
	//Part 1a
	//In your main function, write code to evaluate the following two expressions and print the results
	//3x^3-5x^2+6 for x = 2.55 & (3.31 x 10^-8 x 2.01 x 10^-7)/(7.16 x 10^-6 + 2.01 x 10^-8)
	printf("Part 1A\n");
	double x;
	double result;
	x = 2.55;
	result = (3 * x * x *x) - (5 * x * x) + 6;
	printf("Result of 3x^3 - 5x^2 +6 is %lf\n", result);

	double numerator = 3.31e-8 * 2.01e-7;//3.31 * 10^-8 * 2.01 * 10^-7
	double denominator = 7.16e-6 + 2.01e-8;//7.16 * 10^-6 + 2.01 * 10^-8
	double secondResult = numerator/denominator;
	printf("Result of (3.31 * 10^-8 * 2.01 * 10^-7/(7.16 * 10^-6 + 2.01 * 10^-8) = %e\n", secondResult);

	//Part 1B
	printf("\n\nPart 1B\n");
	int i = 256;
	int j = 7;
	int nextMultiple = i + j - i % j;
	//printf("%d days next evenly divisible by %d is %d\n", i, j, nextMultiple);
	i = 365, j = 7, nextMultiple = i + j - i % j;
	printf("i\t\tj\t\tNext Multiple\n");
	printf("%d\t\t%d\t\t%d\n", i, j, nextMultiple);
	i = 12258, j = 28;
	int nextMultiple_2 = i + j - i % j;
	//printf("i\t\tj\t\tNext Multiple\n");
	printf("%d\t\t%d\t\t%d\n", i, j, nextMultiple_2);
	i = 996, j = 4;
	int nextMultiple_3 = i + j - i % j;
	//printf("i\t\tj\t\tNext Multiple\n");
	printf("%d\t\t%d\t\t%d\n", i, j, nextMultiple_3);

	//Part 1C
	printf("\n\nResult from part 1a as an int: %d, as a double: %.2lf, and as a char: %c\n", (int) result, (double) result, (char) result);
	printf("Result from part 1a as an int: %d, as a double: %.2lf, and as a char: %c\n", (int) secondResult, (double) secondResult, (char) secondResult);
	printf("Result from part 1b as an int: %d, as a double: %.2lf, and as a char: %c\n", (int) nextMultiple, (double) nextMultiple, (char) nextMultiple);
	printf("Result from part 1b as an int: %d, as a double: %.2lf, and as a char: %c\n", (int) nextMultiple_2, (double) nextMultiple_2, (char) nextMultiple_2);
	printf("Result from part 1b as an int: %d, as a double: %.2lf, and as a char: %c\n", (int) nextMultiple_3, (double) nextMultiple_3, (char) nextMultiple_3);


	//Part 2
	printf("\n\nPart 2\n");
	int Fib_0 = 0, Fib_1 = 1, Fib_2;
	for (i = 1; i <=20; i++)//for loop that prints the first 20 terms of the fibonacci series
	{
		if(i > 2)//when number of terms is greater than 2. take the empty variable Fib_2 and add the previous term, Fib_1, and the term before that one Fib_0
		{
			Fib_2 = Fib_1 + Fib_0;
			Fib_0 = Fib_1;//the previous value is now the term before the previous value
			Fib_1 = Fib_2;//Fib_2, our temporary value, is given to Fib_1, after which it is printed out
			printf("%d, ", Fib_2);
		}
		else if (i == 1)//If i equals 1, print the very first value of the fibonacci sequence (0)
		{
			printf("%d, ", Fib_0);
		}
		else if (i == 2)//If i equals 2, print the second value of the fibonacci sequence (1)
		{
			printf("%d, ", Fib_1);
		}
	}
	printf("\n\n");


	//Part 3
	printf("\nPart 3\n");
	char haystack[] = "apple";//haystack, needle, and buffer variables. Buffer in each example is given 100 empty elements, in order to accommodate for larger words.
	char needle[] = "app";
	char buffer[100];
	if(myStrStr(haystack, needle, buffer))
	{
		printf("Found in haystack %s, needle %s, buffer: %s\n",haystack, needle, buffer);
	}
	else
	{
		printf("No Match Found\n\n");
	}
	char haystack1[] = "orange";
	char needle1[] = "ge";
	char buffer1[100];
	if(myStrStr(haystack1, needle1, buffer1))
	{
		printf("Found in haystack %s, needle %s, buffer: %s\n",haystack1, needle1, buffer1);
	}
	else
	{
		printf("No Match Found\n\n");
	}
	char haystack2[] = "blueberry";
	char needle2[] = "ueber";
	char buffer2[100];
	if(myStrStr(haystack2, needle2, buffer2))
	{
		printf("Found in haystack %s, needle %s, buffer: %s\n",haystack2, needle2, buffer2);
	}
	else
	{
		printf("No Match Found\n\n");
	}
	char haystack3[] = "strawberry";
	char needle3[] = "strawberry";
	char buffer3[100];
	if(myStrStr(haystack3, needle3, buffer3))
	{
		printf("Found in haystack %s, needle %s, buffer: %s\n",haystack3, needle3, buffer3);
	}
	else
	{
		printf("No Match Found\n\n");
	}
	char haystack4[] = "grapefruit";
	char needle4[] = "terrible";
	char buffer4[100];
	if(myStrStr(haystack4, needle4, buffer4))
	{
		printf("Found in haystack %s, needle %s, buffer: %s\n",haystack4, needle4, buffer4);
	}
	else
	{
		printf("No Match Found\n\n");
	}

	return 0;
}

