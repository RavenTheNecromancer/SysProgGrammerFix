#include "stdio.h"
#include <stdlib.h>
#include <locale.h>
#include "string.h"

#define INITIAL_BUFFER_SIZE 100
#define BUFFER_INCREMENT 100

int main (){

    setlocale(LC_ALL, "Bulgarian");

<<<<<<< Updated upstream
    FILE *filePointerReader, *filePointerWrite ;
=======
    //open the files
    FILE* filePointerReader, * filePointerWrite;
>>>>>>> Stashed changes
    filePointerReader = fopen("C:\\Users\\dimit\\Desktop\\SP AAAAAAAAA\\SysProgGrammerFix\\test.txt", "r");
    filePointerWrite = fopen("C:\\Users\\dimit\\Desktop\\SP AAAAAAAAA\\SysProgGrammerFix\\output.txt", "w");

    if (filePointerReader == NULL) {
        printf("Error opening file\n");
        return 1;
    }

<<<<<<< Updated upstream
    char *buf = (char *)malloc(INITIAL_BUFFER_SIZE + 1);
=======
    // Determine the size of the file
    fseek(filePointerReader, 0, SEEK_END);//set file pointer to end of file
    long fileSize = ftell(filePointerReader);//set size of file
    rewind(filePointerReader);//bring back file pointer to start

    // Read the entire file into memory
    char* buf = (char*)malloc(fileSize + 1);
>>>>>>> Stashed changes
    if (buf == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }
<<<<<<< Updated upstream
=======
    fread(buf, sizeof(char), fileSize, filePointerReader);//store read stream to buffer
    buf[fileSize] = '\0'; // Null-terminate the buffer
>>>>>>> Stashed changes

    size_t bufSize = INITIAL_BUFFER_SIZE;
    size_t bytesRead;
    int foundSentenceEnd = 0;

    int sentanceFound = 0;

    fpos_t positionCurrent;
    fpos_t positionStart;

    fgetpos(filePointerReader, &positionStart);//current position on file

    while ((bytesRead = fread(buf, sizeof(char), bufSize, filePointerReader)) > 0)
    {

        buf[bytesRead] = '\0'; // Null-terminate the buffer

        char find = '.';

        const char *ptr = strchr(buf, find);

        int offset = ptr - buf;

        fseek(filePointerReader,offset, SEEK_SET);


        // Search for the end of sentence in the buffer
        char *sentenceEnd = strstr(buf, ".");
        if (!sentenceEnd)
            sentenceEnd = strstr(buf, "!");
        if (!sentenceEnd)
            sentenceEnd = strstr(buf, "?");


        if (sentenceEnd) {
<<<<<<< Updated upstream
            // If sentence end found, write up to the end of the sentence to output file
            *sentenceEnd = '\0'; // Null-terminate at the end of the sentence
            fsetpos(filePointerReader, &positionCurrent);
            fputs(buf, filePointerWrite);

            foundSentenceEnd = 1;
=======
            // If sentence end found, write up to the end of the sentence to the output file
            *(sentenceEnd+1) = '\0'; // Null-terminate at the end of the sentence

            fprintf(filePointerWrite, "%s", bufStart); //Write buffer content to file

            // Move the start of the buffer to the start of the next sentence
            bufStart = sentenceEnd + 2;
            //while (*bufStart == ' ' || *bufStart == '\n') {
            //    bufStart++;
            // }
>>>>>>> Stashed changes
        } else {
            // If sentence end not found, increase buffer size and read more characters
            bufSize += BUFFER_INCREMENT;
            buf = realloc(buf, bufSize + 1);
            if (buf == NULL) {
                printf("Memory reallocation failed\n");
                return 1;
            }
        }

    }

    fclose(filePointerReader);
    return 0;
}