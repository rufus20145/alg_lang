#ifndef STRUCT
#define STRUCT

#define GROUP_SIZE 32
#define NUMBER_OF_SUBJECTS 5
#define NUMBER_OF_MARKS 16
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
    int numberOfSubjects, numberOfMarks[NUMBER_OF_SUBJECTS];
    char subjectName[NUMBER_OF_SUBJECTS][SUBJECT_NAME_SIZE];
    int marks[NUMBER_OF_SUBJECTS][NUMBER_OF_MARKS];
    float averageMark[NUMBER_OF_SUBJECTS];
} studentStruct;

#endif // !STRUCT