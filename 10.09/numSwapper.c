/*
функция обмена элементов
*/
void swapNumbers(int num1, int num2, int *location1, int *location2)
{
#ifdef DEBUG
    printf("    Entered swapNumbers fuction with such arguments:\n  num1 = %d, num2 = %d, location1 = %d, location2 = %d pointers.\n", num1, num2, *location1, *location2);
#endif
    *location1 = num2;
#ifdef DEBUG
    printf("Num1 was %d. Now it is %d.\n", num1, *location1);
#endif
    *location2 = num1;
#ifdef DEBUG
    printf("Num2 was %d. Now it is %d.\n", num2, *location2);
    printf("    Function swapNumbers was completed\n\n");
#endif
}