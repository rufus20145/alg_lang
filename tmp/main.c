#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <ctype.h>
#include <string.h>
#include <conio.h>
#include <windows.h>
#define NUM 1024
#define NUM_M 32

// Функция сортировки прямым выбором
void sort(int *num, int size)
{
    int min, buff;
    for (int i = 0; i < size - 1; i++)
    {
        min = i; // запоминаем индекс текущего элемента
        // ищем минимальный элемент чтобы поместить на место i-ого
        for (int j = i + 1; j < size; j++) // для остальных элементов после i-ого
        {
            if (num[j] < num[min]) // если элемент меньше минимального,
                min = j;           // запоминаем его индекс в min
        }
        buff = num[i]; // меняем местами i-ый и минимальный элементы
        num[i] = num[min];
        num[min] = buff;
    }
}

void sort2 (int* num, int size) {
    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size; j)
        if(num[i] > num[j])
        {
            swapNumbers(num[i], num[j]);
        }
    }
}



int main()
{

    setlocale(LC_ALL, "");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    struct StudentStruct
    {
        unsigned char Sname[NUM];
        unsigned char name[NUM];
        unsigned char Mname[NUM];
        char kurs[NUM];
        char group[NUM];
        char mail[NUM];
        float marks[NUM];
        float Smark;
        int size;
    };
    struct StudentStruct Student[NUM_M];
    char NEWFile[NUM], Line[1024];
    int num, func1, func2, check, CheckKurs, CheckGroup, CheckEmail, CheckFile, i, j, k;
    FILE *IOFile;
    int a[10];
    int size, b, *array;
    float sum = 0;
    printf("Введите команду:\n1-ввести путь к файлу\n2-создать файл\n\n");

    do
    {
        scanf("%d", &func1);
        switch (func1)
        {

        case 1:
            printf("Введите путь к файлу: ");
            scanf("%s", NEWFile);
            IOFile = fopen(NEWFile, "r");
            if (IOFile == 0)
            {
                printf("Файл не найден!\n");
                printf("Введите команду:\n1-ввести путь к файлу\n2-создать файл\n\n");
                CheckFile = 0;
            }
            else
            {
                printf("Файл найден.\n\n");
                CheckFile = 1;
            }
            fclose(IOFile);
            break;

        case 2:
            printf("Задайте путь файлу: ");
            scanf("%s", NEWFile);
            IOFile = fopen(NEWFile, "a");
            printf("Файл создан.\n\n");
            fclose(IOFile);
            CheckFile = 1;
            break;
        default:
            printf("Ошибка. Введите команду:\n1-ввести путь к файлу\n2-создать файл\n\n");
        }
        if (CheckFile == 1)
            break;
    } while (func1 != 1 || func1 != 2);

    do
    {
        printf("\nВведите команду:\n1-добавить студента\n2-вывести список студентов\n3-очистить список студентов\n4-выйти из программы\n\n");
        scanf("%d", &func2);
        switch (func2)
        {

        case 1:
        {

            do
            {
                printf("Введите количество добавляемых студентов от 1 до 10 вкл.: ");
                scanf("%d", &num);
            } while (isalpha(num) || num < 1 || num > 10);

            do
            {
                for (i = 0; i < num; i++)
                {
                    check = 0;
                    printf("Введите фамилию %d студента: ", i + 1);
                    scanf("%s", &Student[i].Sname);
                    for (j = 0; j < strlen(Student[i].Sname); j++)
                    {
                        if (isalpha(Student[i].Sname[j]))
                        {
                        }
                        else
                        {
                            check++;
                            printf("Введите еще раз.\n");
                            i--;
                        }
                    }
                }
            } while (check != 0);

            do
            {
                for (i = 0; i < num; i++)
                {
                    check = 0;
                    printf("Введите имя %d студента: ", i + 1);
                    scanf("%s", &Student[i].name);
                    for (j = 0; j < strlen(Student[i].name); j++)
                    {
                        if (isalpha(Student[i].name[j]) || Student[i].name[j] == '\0')
                        {
                        }
                        else
                        {
                            check++;
                            printf("Введите еще раз.\n");
                            i--;
                        }
                    }
                }
            } while (check != 0);

            do
            {
                for (i = 0; i < num; i++)
                {
                    check = 0;
                    printf("Введите отчество %d студента: ", i + 1);
                    scanf("%s", &Student[i].Mname);
                    for (j = 0; j < strlen(Student[i].Mname); j++)
                    {
                        if (isalpha(Student[i].Mname[j]) || Student[i].Mname[j] == '\0')
                        {
                        }
                        else
                        {
                            check++;
                            printf("Введите еще раз.\n");
                            i--;
                        }
                    }
                }
            } while (check != 0);

            do
            {
                for (i = 0; i < num; i++)
                {
                    CheckKurs = 0;
                    printf("Введите номер курса %d студента: ", i + 1);
                    scanf("%s", &Student[i].kurs);
                    for (j = 0; j < strlen(Student[i].kurs); j++)
                    {
                        if (isdigit(Student[i].kurs[j]) || Student[i].kurs[j] == '\0')
                        {
                        }
                        else
                        {
                            CheckKurs++;
                            printf("Введите еще раз.\n");
                            i--;
                        }
                    }
                }
            } while (CheckKurs != 0);

            for (i = 0; i < num; i++)
            {
                sum = 0;
                printf("Введите количество оценок %d студента: ", i + 1);
                scanf("%d", &Student[i].size);
                printf("Введите оценки: ");
                for (b = 0; b < Student[i].size; b++)
                {
                    scanf("%f", &Student[i].marks[b]);
                    sum += Student[i].marks[b];
                }
                Student[i].Smark = sum / Student[i].size;
            }
            do
            {
                for (i = 0; i < num; i++)
                {
                    CheckGroup = 0;
                    printf("Введите группу %d студента: ", i + 1);
                    scanf("%s", &Student[i].group);
                    for (j = 0; j < strlen(Student[i].group); j++)
                    {
                        if (isalpha(Student[i].group[0]) && isdigit(Student[i].group[1]) && isalpha(Student[i].group[2]) && isdigit(Student[i].group[4]) && isdigit(Student[i].group[5]) && isdigit(Student[i].group[6]) && isalpha(Student[i].group[7]) && isdigit(Student[i].group[9]) && isdigit(Student[i].group[10]))
                        {
                        }
                        else
                        {
                            CheckGroup++;
                            printf("Введите еще раз.\n");
                            i--;
                        }
                    }
                }
            } while (CheckGroup != 0);

            do
            {
                for (i = 0; i < num; i++)
                {
                    CheckEmail = 0;
                    printf("Введите e-mail %d студента: ", i + 1);
                    scanf("%s", &Student[i].mail);
                    char StringMail = strlen(Student[i].mail);
                    if ((Student[i].mail[0] != '@') && (Student[i].mail[StringMail - 1] != '@') && (Student[i].mail[StringMail - 2] != '@') && ((Student[i].mail[StringMail - 3] == '.') || (Student[i].mail[StringMail - 4] == '.')) && (Student[i].mail[StringMail - 4] != '@'))
                    {
                    }
                    else
                    {
                        CheckEmail++;
                        printf("Введите еще раз.\n");
                        i--;
                    }
                }
            } while (CheckEmail != 0);

            printf("Введите элементы массива:\n");
            for (int i = 0; i < 10; i++)
            {
                printf("a[%d] = ", i);
                scanf("%d", &a[i]);
            }
            sort(a, 10); // вызываем функцию сортировки

            IOFile = fopen(NEWFile, "a");

            printf("Добавляем записи в файл:\n");
            for (k = 0; k < num; k++)
            {
                if (islower(Student[k].name[0]))
                    Student[k].name[0] = toupper(Student[k].name[0]);
                if (islower(Student[k].Sname[0]))
                    Student[k].Sname[0] = toupper(Student[k].Sname[0]);
                if (islower(Student[k].Mname[0]))
                    Student[k].Mname[0] = toupper(Student[k].Mname[0]);

                printf("\nСтудент: %s %s %s", Student[k].Sname, Student[k].name, Student[k].Mname);
                printf("\nкурс: %s\nгруппа: %s\ne-mail: %s", Student[k].kurs, Student[k].group, Student[k].mail);

                printf("\nОценки: ");
                for (b = 0; b < Student[k].size; b++)
                {
                    printf("%.0f ", Student[k].marks[b]);
                }
                printf("\nСредний балл: %.2f", Student[k].Smark);
                printf("\nОтсортированный массив: ");
                for (int i = 0; i < 10; i++)
                    printf("%d ", a[i]);

                fprintf(IOFile, "Студент: %s %s %s,", Student[k].Sname, Student[k].name, Student[k].Mname);
                fprintf(IOFile, " курс: %s, группа: %s, e-mail: %s,", Student[k].kurs, Student[k].group, Student[k].mail);
                fprintf(IOFile, "Средний балл: %.2f,", Student[k].Smark);
                fprintf(IOFile, "\nОценки: ");
                for (b = 0; b < Student[k].size; b++)
                {
                    fprintf(IOFile, "%.0f ", Student[k].marks[b]);
                }
                fprintf(IOFile, "\nОтсортированный массив: ");
                for (int i = 0; i < 10; i++)
                {
                    fprintf(IOFile, "%d", a[i]);
                    if (i < 9)
                    {
                        fprintf(IOFile, ",");
                    }
                    else
                    {
                        fprintf(IOFile, "\n");
                    }
                }
            }
            fclose(IOFile);
        }
        break;
        // case 'f':
        //     for (i = 0; i < a1; i++)
        //     {
        //         for (j = 0; j < a2; j++)
        //         {
        //             fpintf(IOFile, "%d ", a[i][j]);
        //         }
        //         fprintf(IOFile, "\n");
        //     }
        //     break;

        case 2:
        {
            IOFile = fopen(NEWFile, "r");
            while (!feof(IOFile))
            {
                fgets(Line, 1024, IOFile);
                if (!feof(IOFile))
                    puts(Line);
            }
            fclose(IOFile);
        }
        break;

        case 3:
        {
            IOFile = fopen(NEWFile, "w");
            printf("Список успешно очищен.\n");
            fclose(IOFile);
        }
        break;

        case 4:
            return 0;
            break;

        default:
            printf("\nОшибка. Введите команду:\n1-добавить студента\n2-вывести список студентов\n3-очистить список студентов\n4-выйти из программы\n\n");
            break;
        }
    } while (func2 != 4);

    return 0;
}
