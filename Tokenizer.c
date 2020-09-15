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

int returnValidTokenASCII (char key)
{
    if (key >= 48 && key <= 57)
      return 1; // 0 to 9
    else if (key >= 65 && key <= 90)
      return 2; // uppercase letters
    else if (key >= 97 && key <= 122)
      return 3; // lowercase letters
    else
      return 0;
}

char convertToLower (char key)
{
    if (returnValidTokenASCII(key) == 2)
      return key + 32;
    return key;
}

int checkIfValidToken (char * token)
{
    int i = 0, result = 1;
    do
    {
        (PRINT_LOGS) ? (printf("\ntoken[%d]: %c\n", i, token[i])) : printf(" ");
        if (returnValidTokenASCII(token[i])) { // checks if the character is alphanumerical
          if (returnValidTokenASCII(token[i]) == 2)
            token[i] = convertToLower(token[i]); // convert any captal letters to lowercase
        }
        else
          result = 0;
        i++;
    } while (token[i] != '\0');
    (PRINT_LOGS) ? (printf("\nresult: %d\n", result)) : printf(" ");
    return result; // returns false if there is any single token that is not alphanumerical
}

void cropToken (char * token, int * nChars)
{
    int i;
    char * tempStr;
    for (i = 0; i < strlen(token); i++)
    {
        if (returnValidTokenASCII(token[i]) == 0) {
            tempStr = strtok(token, token + i); // remove non-alphanumerical symbol
        }
    }

    strcpy(token, tempStr);
}

String * Tokenize (char * InputString, int nWords)
{
    String * Array;
    char * Token;
    int i = 0;

    Array = malloc(sizeof(String) * nWords);

    if (Array == NULL)
    {
        (PRINT_LOGS) ? (printf("\nArray is NULL!\n")) : printf(" ");
    }

    Token = strtok(InputString, " ");

    while (Token != NULL)
    {
        if (checkIfValidToken(Token)) // checks if the token contains non-alphanumerical characters
        {
            strcpy(Array[i], Token);
            (PRINT_LOGS) ? (printf("| %s |", Array[i])) : printf(" ");
            i++;
            Token = strtok(NULL, " ");
        }
        else
        {
            (PRINT_LOGS) ? (printf("| (cropped) |")) : printf(" ");
            cropToken(Token, &nWords);
            if (strlen(Token) < 3)
            {
                (PRINT_LOGS) ? (printf("| (removed) |")) : printf(" ");
                Token = NULL;
            }
            else
            {
                strcpy(Array[i], Token);
                (PRINT_LOGS) ? (printf("| %s |", Array[i])) : printf(" ");
            }
            
        }
    }

    return Array;
}

int readFile(String * strArray)
{
    FILE *src;
    String fileName, inputStr;
    int i = 0;

    printf("Input filename: ");
    scanf("%s", fileName);
    if ((src = fopen(fileName, "r")) != NULL)
    {
        while (fscanf(src, "%s", inputStr) != EOF)
        {
            strArray = Tokenize(inputStr, getNumWords(inputStr));
            i++;
        }
        (PRINT_LOGS) ? (printf("\n")) : printf(" ");
        fclose(src);
        return 1;
    }
    else
    {
        printf("\n%s not found.\n", fileName);
        return 0;
    }
}

/*
  TODO: Finish output file saving
*/
void printToFile(String * strArray)
{ 
    FILE *dest;
    dest = fopen("OUTPUT.TXT", "w");

/*
    while (fprintf(dest, "%s\t\t%d\n", ) != 0)
    {
        
    }
*/

}