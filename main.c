#include <stdio.h>

#define LONG_SIZE sizeof(long) * 8

void printCharArr(char arr[], int size)
{
	for (int i = 0; i < size; i++)
	{
		printf("%c", arr[i]);
	}
}

void TaskZero()
{
	char word[100];
	int charIndex = 0;
	printf("Enter a characters: ");

	scanf_s("%c", &word[charIndex]);
	while (word[charIndex] != '\n')
	{
		if ('a' <= word[charIndex])
			word[charIndex] -= 32;
		scanf_s("%c", &word[++charIndex]);
	}

	for (int i = 0; i < charIndex / 2; i++)
	{
		word[i] -= word[charIndex - 1 - i];
		word[charIndex - 1 - i] += word[i];
		word[i] = word[charIndex - 1 - i] - word[i];
		//printf("%c", word[i]);
	}

	printCharArr(word, charIndex);
}

void TaskOne()
{
	char word[100];
	char s1[] = "abcdefghijklmnopqrstuvwxyz";
	char s2[] = "zyxwvutsrqponmlkjihgfedcba";

	int charIndex = 0;
	printf("Enter a characters: ");

	scanf_s("%c", &word[charIndex]);
	while (word[charIndex] != '\n')
	{
		scanf_s("%c", &word[++charIndex]);
	}

	for (int i = 0; i < charIndex; i++)
	{
		for (int j = 0; j < sizeof(s1) / sizeof(s1[0]); j++)
		{
			if (s1[j] == word[i])
			{
				word[i] = s2[j];
				break;
			}
		}
	}

	printCharArr(word, charIndex);
}

void TaskThree()
{
	int nums[2];
	char num1Str[100];
	int length;

	scanf_s("%d %d", &nums[0], &nums[1]);

	for (int i = 0; i < 2; i++)
	{
		length = 0;

		printf("Num %d:", i);
		if (nums[i] < 0)
			printf("minus ");
		
		while (nums[i] >= 1)
		{
			length++;
			int digit = nums[i] % 10;
			num1Str[100 - length] = digit + '0';
			nums[i] /= 10;
		}

		for (int i = 0; i < length; i++)
		{
			switch (num1Str[100 - length + i])
			{
			case '0':
				printf("zero ");
				break;
			case '1':
				printf("one ");
				break;
			case '2':
				printf("two ");
				break;
			case '3':
				printf("three ");
				break;
			case '4':
				printf("four ");
				break;
			case '5':
				printf("five ");
				break;
			case '6':
				printf("six ");
				break;
			case '7':
				printf("seven ");
				break;
			case '8':
				printf("eight ");
				break;
			case '9':
				printf("nine ");
				break;
			default:
				printf("NAN");
			}
		}

		printf("\n");
	}
}

int countzeros(long num)
{
	int zeros = 0;

	for (int i = 0; i < LONG_SIZE; i++)
	{
		if (!(num & 1))   zeros++;
		num >>= 1;
	}

	return zeros;
}

void TaskFour()
{
	int num;

	/* Input number from user */
	printf(">> ");
	scanf_s("%d", &num);

	printf("\nzeros num: %d ",countzeros(num));
}

int main()
{

	//TaskZero();
	TaskFour();

	return 0;
}