#include <func.h>
int f1(int);
int main()
{
    int val = 0;
    int i = f1(val);
    printf("i = %d\n", i);
    return 0;
}

int f1(int val)
{
    int num = 0;
    int *ptr = &num;
    if(val == 0)
    {
        int val;
        val = 5;
        ptr = &val;
    }
    return (*ptr + 1);
}
