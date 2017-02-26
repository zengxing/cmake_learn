#include <stdio.h>

typedef struct tag_Person
{
    char * name;
    int    age;
}Person;
void printself()
{
    Person person;
    
    person.age = 1;
    person.name = "anna";
    printf("short file name is %s\n",__FILENAME__);
    printf("test file is %s\n",__FILE__);
}