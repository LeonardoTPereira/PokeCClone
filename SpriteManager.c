#include "SpriteManager.h"

int getNDigits(int number)
{
    int nDigits = 0;
    while (number != 0) {
        number /= 10;
        ++nDigits;
    }
    return nDigits;
}

int getFileSize(char* fileName)
{
    FILE* pFile;

    pFile = fopen(fileName, "r");

    // checking if the file exist or not
    if (pFile == NULL) {
        printf("File Not Found!\n");
        return -1;
    }

    fseek(pFile, 0, SEEK_END);

    // calculating the size of the file
    long int fileSize = ftell(pFile);
    fclose(pFile);
    return fileSize;
}

char* getFilePathFromDexNumber(int dexNumber)
{
    char *filePath, *sizeAsString;
    int filePathSize, nDigits;
    nDigits = getNDigits(3);
    filePathSize = strlen(ASCIISPRITEDIR) + nDigits + strlen(ASCIIEXTENSION) + 1;

    sizeAsString = (char*) malloc((sizeof(char)*nDigits)+1);
    sprintf(sizeAsString, "%03d", dexNumber);

    filePath = (char*) malloc(sizeof(char)*filePathSize);

    //Directory + Base File Name + Vector Size + Extension
    strcpy(filePath, ASCIISPRITEDIR);
    strcat(filePath, sizeAsString);
    strcat(filePath, ASCIIEXTENSION);

    #ifdef DEBUG
        printf("Sprite file Path: %s\n", filePath);
    #endif

    free(sizeAsString);

    return filePath;
}

char* loadASCII(int dexNumber)
{

    FILE* pFile;
    char *fileName, *spriteASCII;
    int fileSize;

    fileName = getFilePathFromDexNumber(dexNumber);

    fileSize = getFileSize(fileName)/sizeof(char);

    pFile = fopen(fileName, "r");
    size_t result;

    // checking if the file exist or not
    if (pFile == NULL) {
        printf("Dex Number: %d\n", dexNumber);
        printf("FileName: %s\n", fileName);
        printf("File Not Found!\n");
        exit(EXIT_FAILURE);
    }

    spriteASCII = (char*) malloc(sizeof(char)*fileSize);

    result = fread(spriteASCII, sizeof(char), fileSize, pFile);
    if (result != fileSize)
        printf("Reading error\n");
    // closing the file
    fclose(pFile);

    return spriteASCII;
}


void printBoxLine(pokemon_t **pokeBoxLine, int lineSize)
{
    char** spritesASCII;
    int currentIndex, startIndex = 0;
    spritesASCII = (char**) malloc(sizeof(char*)*lineSize);
    int dexNumber, hasFinished = 0;
    for(int i = 0; i < lineSize; ++i)
    {
        if(pokeBoxLine[i] != NULL)
            dexNumber = pokeBoxLine[i]->dexNumber-1;
        else
            dexNumber = -1;
        spritesASCII[i] = loadASCII(dexNumber);
    }
    while(!hasFinished)
    {
        for(int i = 0; i < lineSize; ++i)
        {
            currentIndex = startIndex;
            while(spritesASCII[i][currentIndex] != '\n' && spritesASCII[i][currentIndex] != '\r' && spritesASCII[i][currentIndex] != '\0')
            {
                printf("%c", spritesASCII[i][currentIndex]);
                if(spritesASCII[i][currentIndex] != '\0')
                    currentIndex++;
                else
                    hasFinished = 1;
            }
            printf("\t");
        }
        if(spritesASCII[lineSize-1][currentIndex] == '\0')
            startIndex = currentIndex;
        else if(spritesASCII[lineSize-1][currentIndex] == '\r')
            currentIndex++;
        if(spritesASCII[lineSize-1][currentIndex] == '\n')
            startIndex = ++currentIndex;
        if(spritesASCII[lineSize-1][currentIndex] == '\0')
            hasFinished = 1;
        printf("\n");
    }
    for(int i = 0; i < lineSize; ++i)
    {
        if(pokeBoxLine[i] != NULL)
            printf("\t\t\t #%03d - %-30s\t\t", pokeBoxLine[i]->dexNumber, pokeBoxLine[i]->species);
        else
            printf("\t\t\t\t\t\t\t\t\t");
    }
    printf("\n");
    free(spritesASCII);
}
