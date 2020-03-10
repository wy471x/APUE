#include <func.h>

void bigEndianOrLittleEndian()
{
    int n = 0x04030201;
    char *cp =(char *)&n;
    if(cp[0] == 1 && cp[3] == 4)
        printf("This platform is little endian.\n");
    else if(cp[0] == 4 && cp[3] == 1)
        printf("This platform is big endian.\n");
}

int main(void)
{
    bigEndianOrLittleEndian();
    return 0;
}

