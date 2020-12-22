#ifndef STRUCT
#define STRUCT

#define GROUP_SIZE 32
#define NUMBER_OF_SUBJECTS 5
#define SUBJECT_NAME_SIZE 64
typedef struct
{
    int number;
    char surName[MAXSIZE];
    char name[MAXSIZE];
    char middleName[MAXSIZE];
    char group[GROUP_SIZE];
    int birthDay, birthMonth, birthYear;
    char email[MAXSIZE];
    char subjectNames[NUMBER_OF_SUBJECTS][SUBJECT_NAME_SIZE];
} studentStruct;

#endif // !STRUCT