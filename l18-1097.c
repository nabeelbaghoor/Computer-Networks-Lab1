

// Computer Networks Lab 15-Session @#! Final
// Welcome Legends 420 & Go on#include<iostream>
// #include<conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

// using namespace std;
#pragma warning(disable : 4996)

const int Size = 100;

char* getIntegers(char* str)
{
    char* integers;
    integers = malloc(Size * sizeof(*integers));
    int currIndex = 0, endIndex = strlen(str) - 1;
    int i = 0;
    while (currIndex <= endIndex)
    {
        if (str[currIndex] >= '0' && str[currIndex] <= '9')
        {
            integers[i++] = str[currIndex];
        }
        currIndex++;
    }
    integers[i] = 0;
    return integers;
}

char* getNonAlphabetsWordsString(char* str)
{
    char* nonAlphabets;
    nonAlphabets = malloc(Size * sizeof(*nonAlphabets));

    int size = strlen(str);
    int startIndex = 0;
	
	int nonAlphabetsIndex = 0;
    for (int i = 0; i <= size; i++)
    {

        if (str[i] == ' '  || str[i] == '\n' || i == size)
        {
            int endIndex = i - 1;

            //check if the this word has vowels
            bool alphabetFound = false;
            int currIndex = startIndex;
            while (currIndex <= endIndex)
            {
                if (isalpha(str[currIndex]))
                {
                    alphabetFound = true;
                    break;
                }
                currIndex++;
            }
            if (!alphabetFound)
            {
                while (startIndex <= endIndex)
                {
                    nonAlphabets[nonAlphabetsIndex++] = str[startIndex];
                    startIndex++;
                }
                nonAlphabets[nonAlphabetsIndex++] = ' ';
                nonAlphabets[nonAlphabetsIndex] = 0;
            }
            startIndex = i + 1;
        }
    }
	if(nonAlphabetsIndex && nonAlphabets[nonAlphabetsIndex - 1] == ' ')
		nonAlphabets[nonAlphabetsIndex - 1] = 0;
    return nonAlphabets;
}

void reverseWordsWithVowels(char* str)
{
    int size = strlen(str);
    int startIndex = 0;
    for (int i = 0; i <= size; i++)
    {

        if (str[i] == ' ' || str[i] == '\n'  || i == size)
        {

            int endIndex = i - 1;
            //check if the this word has vowels
            bool vowelFound = false;
            int currIndex = startIndex;
            while (currIndex <= endIndex)
            {
                if (str[currIndex] == 'a' || str[currIndex] == 'e' || str[currIndex] == 'i'
                    || str[currIndex] == 'o' || str[currIndex] == 'u' || str[currIndex] == 'A' || str[currIndex] == 'E' || str[currIndex] == 'I'
                    || str[currIndex] == 'O' || str[currIndex] == 'U')
                {
                    vowelFound = true;
                    break;
                }
                currIndex++;
            }
            //if vowel found,reverse that word
            if (vowelFound)
            {
                //reverse that word
                while (startIndex < endIndex)
                {
                    char temp;
                    temp = str[startIndex];
                    str[startIndex] = str[endIndex];
                    str[endIndex] = temp;
                    // swap(str[startIndex], str[endIndex]);
                    startIndex++;
                    endIndex--;
                }
            }
            startIndex = i + 1;
        }
    }
}

void readStringFromFile(char* str, char* filename)
{
    FILE* file;
    file = fopen(filename, "r");
    if (file != NULL)
    {
        char character;
        int index = 0;
        printf("File opened successfully.\n");
		character = fgetc(file);
        while (character != EOF)
        {
            str[index++] = character;
            character = fgetc(file);

        } 
        fclose(file);

        str[index] = 0;
    }
    else
    {
        printf("Unable to open file.\n");
    }
}

void writeStringToFile(char* str, char* filename)
{
    FILE* file;
    file = fopen(filename, "w");
    if (file != NULL)
    {
        printf("File opened successfully.\n");
        fprintf(file, "%s", str);
        fclose(file);
    }
    else
    {
        printf("Unable to open file.\n");
    }
}



int main()
{
    //create string str
    char* str;
    str = malloc(Size * sizeof(*str));

    //read string from File in str
    readStringFromFile(str, (char*)"Input File.txt");

    //display string str
    printf("%s\n", str);

    //get integers in string str
    char* integers;
    integers = malloc(Size * sizeof(*integers));
    integers = getIntegers(str);
    writeStringToFile(integers, (char*)"integers.txt");

    //get nonAlphabets in string str
    char* nonAlphabets;
    nonAlphabets = malloc(Size * sizeof(*nonAlphabets));
    nonAlphabets = getNonAlphabetsWordsString(str);
    writeStringToFile(nonAlphabets, (char*)"nonAphabets.txt");

    //reverseWordsWithVowels
    reverseWordsWithVowels(str);
    writeStringToFile(str, (char*)"reversed.txt");

    return 0;
    //system("pause");
}



