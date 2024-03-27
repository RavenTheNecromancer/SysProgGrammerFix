#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

int main() {

    setlocale(LC_ALL, "Bulgarian");

    FILE* filePointerReader, * filePointerWrite;
    filePointerReader = fopen("C:\\Users\\dimit\\Desktop\\SP AAAAAAAAA\\SysProgGrammerFix\\test.txt", "r");
    filePointerWrite = fopen("C:\\Users\\dimit\\Desktop\\SP AAAAAAAAA\\SysProgGrammerFix\\output.txt", "w");

    if (filePointerReader == NULL) {
        printf("Error opening file\n");
        return 1;
    }

    // Determine the size of the file
    fseek(filePointerReader, 0, SEEK_END);
    long fileSize = ftell(filePointerReader);
    rewind(filePointerReader);

    // Read the entire file into memory
    char* buf = (char*)malloc(fileSize + 1);
    if (buf == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }
    fread(buf, sizeof(char), fileSize, filePointerReader);
    buf[fileSize] = '\0'; // Null-terminate the buffer

    // Apply the rules to the buffer
    for (int i = 0; i < fileSize; i++) {
        // Rule 1: Remove spaces before "..."
        if (buf[i] == ' ' && buf[i+1] == '.' && buf[i+2] == '.' && buf[i+3] == '.') {
            memmove(&buf[i], &buf[i+1], fileSize - i);
        }
            // Rule 2: Correct ".." or "...." to "..."
        else if (buf[i] == '.' && buf[i+1] == '.' && (buf[i+2] != '.' || (buf[i+2] == '.' && buf[i+3] == '.'))) {
            memmove(&buf[i+2], &buf[i+3], fileSize - i - 1);
        }
            // Rule 3: Remove space between punctuation marks
        else if ((buf[i] == '!' || buf[i] == '?' || buf[i] == '.') && buf[i+1] == ' ' && (buf[i+2] == '!' || buf[i+2] == '?' || buf[i+2] == '.')) {
            memmove(&buf[i+1], &buf[i+2], fileSize - i - 1);
        }
            // Rule 4: Remove space before punctuation mark and add space after punctuation mark
        else if ((buf[i] == ' ' && (buf[i+1] == '!' || buf[i+1] == '?' || buf[i+1] == '.')) || ((buf[i] == '!' || buf[i] == '?' || buf[i] == '.') && buf[i+1] != ' ')) {
            memmove(&buf[i], &buf[i+1], fileSize - i);
            memmove(&buf[i+2], &buf[i+1], fileSize - i - 1);
            buf[i+1] = ' ';
        }
            // Rule 5: Remove comma before or after punctuation mark
        else if ((buf[i] == ',' && (buf[i+1] == '!' || buf[i+1] == '?' || buf[i+1] == '.')) || ((buf[i] == '!' || buf[i] == '?' || buf[i] == '.') && buf[i+1] == ',')) {
            memmove(&buf[i], &buf[i+1], fileSize - i);
        }
            // Rule 6: Add space after comma
        else if (buf[i] == ',' && buf[i+1] != ' ') {
            memmove(&buf[i+2], &buf[i+1], fileSize - i - 1);
            buf[i+1] = ' ';
        }

//            // Rule 7: Remove comma after specific words
        else if (strncmp(&buf[i], "Например,", 9) == 0
        || strncmp(&buf[i], "Всъщност,", 9) == 0
        || strncmp(&buf[i], "Според мен,", 9) == 0
        || strncmp(&buf[i], "Наистина,", 9) == 0
        || strncmp(&buf[i], "Следователно,", 9) == 0
        || strncmp(&buf[i], "Действително,", 9) == 0
        || strncmp(&buf[i], "Реално,", 9) == 0
        || strncmp(&buf[i], "Практически,", 9) == 0
        || strncmp(&buf[i], "Така,", 9) == 0
        || strncmp(&buf[i], "Може би,", 9) == 0
        || strncmp(&buf[i], "Значи,", 9) == 0
        || strncmp(&buf[i], "Вероятно,", 9) == 0
        || strncmp(&buf[i], "Очевидно,", 9) == 0
        || strncmp(&buf[i], "Навярно,", 9) == 0
        || strncmp(&buf[i], "По всяка вероятност,", 9) == 0
        || strncmp(&buf[i], "В действителност,", 9) == 0
        || strncmp(&buf[i], "В края на краищата,", 9) == 0/* NO MORE */) {
            if(strncmp(&buf[i], "Например,", 9) == 0){
                memmove(&buf[i+strlen("Например")], &buf[i+strlen("Например,")], fileSize - i - strlen("Например"));
            }
            if(strncmp(&buf[i], "Всъщност,", 9) == 0){
                memmove(&buf[i+strlen("Всъщност")], &buf[i+strlen("Всъщност,")], fileSize - i - strlen("Всъщност"));
            }
            if(strncmp(&buf[i], "Според мен,", 9) == 0){
                memmove(&buf[i+strlen("Според мен")], &buf[i+strlen("Според мен,")], fileSize - i - strlen("Според мен"));
            }
            if(strncmp(&buf[i], "Наистина,", 9) == 0){
                memmove(&buf[i+strlen("Наистина")], &buf[i+strlen("Наистина,")], fileSize - i - strlen("Наистина"));
            }
            if(strncmp(&buf[i], "Следователно,", 9) == 0){
                memmove(&buf[i+strlen("Следователно")], &buf[i+strlen("Следователно,")], fileSize - i - strlen("Следователно"));
            }
            if(strncmp(&buf[i], "Действително,", 9) == 0){
                memmove(&buf[i+strlen("Действително")], &buf[i+strlen("Действително,")], fileSize - i - strlen("Действително"));
            }
            if(strncmp(&buf[i], "Реално,", 9) == 0){
                memmove(&buf[i+strlen("Реално")], &buf[i+strlen("Реално,")], fileSize - i - strlen("Реално"));
            }
            if(strncmp(&buf[i], "Практически,", 9) == 0){
                memmove(&buf[i+strlen("Практически")], &buf[i+strlen("Практически,")], fileSize - i - strlen("Практически"));
            }
            if(strncmp(&buf[i], "Така,", 9) == 0){
                memmove(&buf[i+strlen("Така")], &buf[i+strlen("Така,")], fileSize - i - strlen("Така"));
            }
            if(strncmp(&buf[i], "Може би,", 9) == 0){
                memmove(&buf[i+strlen("Може би")], &buf[i+strlen("Може би,")], fileSize - i - strlen("Може би"));
            }
            if(strncmp(&buf[i], "Значи,", 9) == 0){
                memmove(&buf[i+strlen("Значи")], &buf[i+strlen("Значи,")], fileSize - i - strlen("Значи"));
            }
            if(strncmp(&buf[i], "Вероятно,", 9) == 0){
                memmove(&buf[i+strlen("Вероятно")], &buf[i+strlen("Вероятно,")], fileSize - i - strlen("Вероятно"));
            }
            if(strncmp(&buf[i], "Очевидно,", 9) == 0){
                memmove(&buf[i+strlen("Очевидно")], &buf[i+strlen("Очевидно,")], fileSize - i - strlen("Очевидно"));
            }
            if(strncmp(&buf[i], "Навярно,", 9) == 0){
                memmove(&buf[i+strlen("Навярно")], &buf[i+strlen("Навярно,")], fileSize - i - strlen("Навярно"));
            }
            if(strncmp(&buf[i], "По всяка вероятност,", 9) == 0){
                memmove(&buf[i+strlen("По всяка вероятност")], &buf[i+strlen("По всяка вероятност,")], fileSize - i - strlen("По всяка вероятност"));
            }
            if(strncmp(&buf[i], "В действителност,", 9) == 0){
                memmove(&buf[i+strlen("В действителност")], &buf[i+strlen("В действителност,")], fileSize - i - strlen("В действителност"));
            }
            if(strncmp(&buf[i], "В края на краищата,", 9) == 0){
                memmove(&buf[i+strlen("В края на краищата")], &buf[i+strlen("В края на краищата,")], fileSize - i - strlen("В края на краищата"));
            }
        }

        // Rule 8: Add comma after specific words
        else if (strncmp(&buf[i], "Казват", 6) == 0
        || strncmp(&buf[i], "Напротив", 8) == 0
        || strncmp(&buf[i], "Разбира се", 8) == 0
        || strncmp(&buf[i], "Изглежда", 8) == 0
        || strncmp(&buf[i], "Струва ми се", 8) == 0
        || strncmp(&buf[i], "Види се", 8) == 0
        || strncmp(&buf[i], "Общо взето", 8) == 0
        || strncmp(&buf[i], "Тъй да се каже", 8) == 0
        || strncmp(&buf[i], "Между нас казано", 8) == 0
        || strncmp(&buf[i], "Както казват", 8) == 0
        || strncmp(&buf[i], "Първо", 8) == 0
        || strncmp(&buf[i], "Второ", 8) == 0
        || strncmp(&buf[i], "Трето", 8) == 0
        || strncmp(&buf[i], "Естествено", 8) == 0/* add other words here */) {
            if(strncmp(&buf[i], "Казват", 6) == 0){
                memmove(&buf[i+strlen("Казват")+1], &buf[i+strlen("Казват")], fileSize - i - strlen("Казват"));
                buf[i+strlen("Казват")] = ',';
            }
            if(strncmp(&buf[i], "Напротив", 8) == 0){
                memmove(&buf[i+strlen("Напротив")+1], &buf[i+strlen("Напротив")], fileSize - i - strlen("Напротив"));
                buf[i+strlen("Напротив")] = ',';
            }
            if(strncmp(&buf[i], "Разбира се", 8) == 0){
                memmove(&buf[i+strlen("Разбира се")+1], &buf[i+strlen("Разбира се")], fileSize - i - strlen("Разбира се"));
                buf[i+strlen("Разбира се")] = ',';
            }
            if(strncmp(&buf[i], "Изглежда", 8) == 0){
                memmove(&buf[i+strlen("Изглежда")+1], &buf[i+strlen("Изглежда")], fileSize - i - strlen("Изглежда"));
                buf[i+strlen("Изглежда")] = ',';
            }
            if(strncmp(&buf[i], "Струва ми се", 8) == 0){
                memmove(&buf[i+strlen("Струва ми се")+1], &buf[i+strlen("Струва ми се")], fileSize - i - strlen("Струва ми се"));
                buf[i+strlen("Струва ми се")] = ',';
            }
            if(strncmp(&buf[i], "Види се", 8) == 0){
                memmove(&buf[i+strlen("Види се")+1], &buf[i+strlen("Види се")], fileSize - i - strlen("Види се"));
                buf[i+strlen("Види се")] = ',';
            }
            if(strncmp(&buf[i], "Общо взето", 8) == 0){
                memmove(&buf[i+strlen("Общо взето")+1], &buf[i+strlen("Общо взето")], fileSize - i - strlen("Общо взето"));
                buf[i+strlen("Общо взето")] = ',';
            }
            if(strncmp(&buf[i], "Тъй да се каже", 8) == 0){
                memmove(&buf[i+strlen("Тъй да се каже")+1], &buf[i+strlen("Тъй да се каже")], fileSize - i - strlen("Тъй да се каже"));
                buf[i+strlen("Тъй да се каже")] = ',';
            }
            if(strncmp(&buf[i], "Между нас казано", 8) == 0){
                memmove(&buf[i+strlen("Между нас казано")+1], &buf[i+strlen("Между нас казано")], fileSize - i - strlen("Между нас казано"));
                buf[i+strlen("Между нас казано")] = ',';
            }
            if(strncmp(&buf[i], "Както казват", 8) == 0){
                memmove(&buf[i+strlen("Както казват")+1], &buf[i+strlen("Както казват")], fileSize - i - strlen("Както казват"));
                buf[i+strlen("Както казват")] = ',';
            }
            if(strncmp(&buf[i], "Първо", 8) == 0){
                memmove(&buf[i+strlen("Първо")+1], &buf[i+strlen("Първо")], fileSize - i - strlen("Първо"));
                buf[i+strlen("Първо")] = ',';
            }
            if(strncmp(&buf[i], "Второ", 8) == 0){
                memmove(&buf[i+strlen("Второ")+1], &buf[i+strlen("Второ")], fileSize - i - strlen("Второ"));
                buf[i+strlen("Второ")] = ',';
            }
            if(strncmp(&buf[i], "Трето", 8) == 0){
                memmove(&buf[i+strlen("Трето")+1], &buf[i+strlen("Трето")], fileSize - i - strlen("Трето"));
                buf[i+strlen("Трето")] = ',';
            }
            if(strncmp(&buf[i], "Естествено", 8) == 0){
                memmove(&buf[i+strlen("Естествено")+1], &buf[i+strlen("Естествено")], fileSize - i - strlen("Естествено"));
                buf[i+strlen("Естествено")] = ',';
            }
        }
        //analogically should be done for с и със, IF WE MANAGE TO MAKE IT THE FUCKING CUNT
        //Rule 9 в и във
        else if ((strncmp(&buf[i], "в", 1) == 0 || strncmp(&buf[i], "В", 1) == 0) && buf[i+1] == ' ') {
            if(strncmp(&buf[i+2], "в", 1) == 0){
                memmove(&buf[i+strlen("в")+2], &buf[i+strlen("във")], fileSize - i - strlen("във"));
            }
        }
    }

    // Write the modified buffer to the output file
    fprintf(filePointerWrite, "%s", buf);

    fclose(filePointerReader);
    fclose(filePointerWrite);
    free(buf);
    return 0;
}

