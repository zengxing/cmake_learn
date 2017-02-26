#include <stdio.h>

extern void printself();
//extern void func1();
extern void func2();
int main()
{
    printf("short file name is %s\n",__FILENAME__);
    printf("main file is %s\n",__FILE__);

    printself();
    //func1();
    func2();
}
