//Create a library of the following functions:
// 
//[■] int mystrlen(const char *str); - the function determines the length of the string
// 
//[■] char * mystrcpy (char *str1, const char *str2); - the function copies the string str2 y str1 and returns a pointer to str1
// 
//[■] char * mystrcat (char *str1, const char *str2); the function appends the string str2 to the string str 1. 
//		The function returns a pointer to the first string str1
// 
//[■] char * mystrchr (char *str, char s); - the function searches for character 5 in the string str. 
//		The function returns a pointer to the first occurrence of a character in a string, otherwise - 0.
// 
//[■] char * mystrstr (char *str1, char *str2); - the function searches for the substring str2 in the string str1. 
//		The function returns a pointer to the first occurrence of the substring str2 in the string str1, otherwise - 0.
//

#include <iostream>
using namespace std;

int mystrlen(const char* str);// the function determines the length of the string
char* mystrcpy (char *str1, const char *str2);// the function copies the string str2 y str1 and returns a pointer to str1
char* mystrcat (char *str1, const char *str2);// the function appends the string str2 to the string str 1. The function returns a pointer to the first string str1
char* mystrchr (char *str, char s);// the function searches for character 5 in the string str. The function returns a pointer to the first occurrence of a character in a string, otherwise - 0.
char* mystrstr (char *str1, char *str2);// the function searches for the substring str2 in the string str1. The function returns a pointer to the first occurrence of the substring str2 in the string str1, otherwise - 0.


int main()
{
	char str[] = "This is a test message. This is not a test message.";
	char message[] = "message";

	printf_s("\n\n\tTest string =>\t %s\n\tTest word =>\t %s\n\n\tmystrlen(message)\t test => %d\n\tmystrcpy(str, message)\t test => %s", str, message, mystrlen(message), mystrcpy(str, message));
	printf_s("\n\tmystrcat(str, message)\t test => %s\n\tmystrchr(str, '.')\t test => %s\n\tmystrstr(str, message)\t test => %s\n\t", mystrcat(str, message), mystrchr(str, '.'), mystrstr(str, message));
}

int mystrlen(const char* str)// -the function determines the length of the string
{
	int counter = 0;
	for (int i = 0; str[i] != '\0'; i++)
	{
		counter++;
	}
	if (str[counter] == '\0')
	{
		return ++counter;
	}
}

char* mystrcpy(char* str1, const char* str2)// -the function copies the string str2 y str1 and returns a pointer to str1
{
	int size = mystrlen(str1) + mystrlen(str2) - 1;
	int j = 0;
	bool first = true;

	char* str_new = new char[size];

	for (int i = 0; i <= size; i++)
	{
		if (str1[i] == '\0')
		{
			first = false;
		}
		if (first)
		{
			str_new[i] = str1[i];
		}
		else
		{
			str_new[i] = str2[j];
			j++;
		}
	}
	return str_new;
}

char* mystrcat(char* str1, const char* str2)
{
	int size = mystrlen(str1) + mystrlen(str2) - 1;
	int j = 0;
	bool first = true;

	char* str_new = new char[size];

	for (int i = 0; i <= size; i++)
	{
		if (str1[i] == '\0')
		{
			first = false;
		}
		if (first)
		{
			str_new[i] = str1[i];
		}
		else
		{
			str_new[i] = str2[j];
			j++;
		}
	}
	//delete str2;
	return str_new;
}

char* mystrchr(char* str, char s)
{
	for (int i = 0; i < mystrlen(str); i++)
	{
		if (str[i] == s)
		{
			char* a = &str[i];
			return a;
		}
	}
	return 0;
}

char* mystrstr(char* str1, char* str2)
{
	for (int i = 0; i < mystrlen(str1); i++)
	{
		if (str1[i] == str2[0])
		{
			for (int j = 0; j < mystrlen(str2) + 1; j++)
			{
				if (str1[i + j] != str2[j] && str2[j] == '\0')
				{
					char* result = &str1[i];
					return result;
				}
			}
			
		}
	}
	return 0;
}