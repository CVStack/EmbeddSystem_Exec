#include <unistd.h>
#include <stdio.h>

int main()
{

    char * cwd;
    char wd[BUFSIZ];

    cwd = getcwd(NULL, BUFSIZ);
    printf("Current Directory : %s\n",cwd);

    chdir("hanbit");

    getcwd(wd,BUFSIZ);    
    printf("Current Directory : %s\n",wd);
}