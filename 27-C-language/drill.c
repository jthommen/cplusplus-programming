// compile: gcc drill.c -o drill.out

#include<string.h>
#include<stdlib.h>
#include<stdio.h>

void my_output(char* p, int x)
{
    printf("p is \"%s\" and x is %i\n", p, x);
}

int main()
{
    // #1
    char* greeting = "Hello World!";
    printf("%s\n", greeting);

    // #2
    char* hello = "Hello";
    char* world = "World!";
    printf("%s %s\n", hello, world);

    // #3
    my_output("Hello", 4);
    my_output("This is it!", 42);
    my_output("And another", 1);

}