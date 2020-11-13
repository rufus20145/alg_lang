/**
 * @file main.c
 * @author rufus20145 ()
 * @brief работа со структурами
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
#include <locale.h>
#include <windows.h>

#include "input.c"
#include "parser.c"
#include "output.c"


int main(int argc, char *argv[])
{
    struct studentStuct
    {
        int listNumber;
        char surName[MAXSIZE];
        char name[MAXSIZE];
        char middleName[MAXSIZE];
        char group[MAXSIZE];
        int birthDay, birthMonth, birthYear;
    };

    struct studentStuct students[NUMBER_OF_STUDENTS];

    
}