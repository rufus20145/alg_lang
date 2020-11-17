/**
 * @file main.c
 * @author rufus20145 (ivan20027749@gmail.com)
 * @brief работа со структурами (программма читает из файла базу данных студентов, записывает её в стурктуру и позволяет вносить изменения, а записывает изменения в файл)
 * @version 0.1
 * @date 2020-11-06
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#define MAXSIZE 256
#define NUMBER_OF_STUDENTS 32

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
// #include <conio.h>
#include <locale.h>
#include <windows.h>

#include "input.c"
#include "parser.c"
#include "output.c"
#include "functions.c"

typedef struct
    {
        int listNumber;
        char surName[MAXSIZE];
        char name[MAXSIZE];
        char middleName[MAXSIZE];
        char group[MAXSIZE];
        int birthDay, birthMonth, birthYear;
        char email[MAXSIZE];
    } studentStuct;

int checkDatabase(char* fileName){
    FILE* currFile;
    char buffer[MAXSIZE];

    currFile = fopen(fileName, "r");
    fgets(buffer, MAXSIZE, currFile);
    if('0' == buffer[0]) {//попробуй через strsrt() и strchr() https://server.179.ru/tasks/cpp/total/051.html
    }
    return 0;
}

void readDatabase(char* fileName, studentStuct* students) {

}

int main()
{
    
    studentStuct students[NUMBER_OF_STUDENTS];
    char fileName[MAXSIZE] = "";
    FILE *currFile = NULL;
    char action = '\0';
    int errorCode = 0;

    system("cls"); //очищаем консоль перед стартом программы

    setlocale(LC_ALL, "RUSSIAN");
    if (GetConsoleCP() != 1251)
    {
        SetConsoleCP(1251);
        SetConsoleOutputCP(1251);
        printf("ConsoleCP was changed.\n");
    }

    //выбираем файл, который будет использоваться
    do
    {
        errorCode = chooseFie(fileName);
    } while (1 == errorCode);

    checkDatabase(fileName);

    // freadDatabase(fileName, students);

    printf(" Успех!");
    return 0;
}