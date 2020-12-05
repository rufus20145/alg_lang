#ifndef STRUCT
typedef struct
{
    int number;
    char surName[MAXSIZE];
    char name[MAXSIZE];
    char middleName[MAXSIZE];
    char group[MAXSIZE];
    int birthDay, birthMonth, birthYear;
    char email[MAXSIZE];
} studentStruct;

#endif // !STRUCT