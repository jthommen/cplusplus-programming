// compile: gcc try_this01.c -o try_this01.out

#include<string.h>
#include<stdlib.h>
#include<stdio.h>

char* cat(const char* id, const char* addr)
{
    int sz = strlen(id)+strlen(addr)+2; // getting size for result string +2 for email and 0 terminator
    char* res = (char*)malloc(sz); // allocating memory for result
    strcpy(res, id); // copy first part into result
    res[strlen(id)] ='@'; // copy @ to result + not necessary, size starts 1
    strcpy(res+strlen(id)+1, addr); // copy second part, +1 not +2 size starts at 1 not 0
    res[sz-1]=0; // inserting 0 terminator
    return res; // returning result
}

int main()
{
    char* p = "this";
    char* q = "that.com";
    char* email = cat(p,q); // caller needs to free the string when not used anymore
    printf("My email: %s\n", email);
}