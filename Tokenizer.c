#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef char String[31];

int getNumWords (char * InputString)
{
    char * c;
    int wordcount = 0;

    c = &InputString[0];
    while (*c != '\0')
    {
        if (*c == ' ')
        {
            wordcount++;
        }
        c++;
    }

    wordcount++;

    return wordcount;
}

String * Tokenize (char * InputString, int nWords)
{
    String * Array;
    char * Token;
    int i = 0;

    Array = malloc(sizeof(String) * nWords);

    if (Array == NULL)
    {
        printf("oh no");
    }

    Token = strtok(InputString, " ");
    while (Token != NULL)
    {
        //printf("| %s |", Token);
        strcpy(Array[i], Token);
        printf("| %s |", Array[i]);
        i++;
        Token = strtok(NULL, " ");
    }

    return Array;
}



int main()
{
    String * Array;
    char testString[] = "The quick brown fox jumps over the lazy dog";
    int nwords = getNumWords(testString);
    int i;

    printf("%d : \n", nwords);

    Array = Tokenize(testString, nwords);

    for (i = 0; i < nwords; i++)
    {
        printf("\n%s", Array[i]);
    }

    
    return 0;
}
