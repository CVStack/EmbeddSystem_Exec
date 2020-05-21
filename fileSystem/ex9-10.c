#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>

void printDirectoryInfo(const char * dictName, const char * current) {

    DIR * dp;
    struct dirent * dent;
    struct stat buf;

    if((dp = opendir(dictName)) == NULL) { //hanbit에 대한 디렉토리 포인터 get
        perror("opendir");
        exit(1);
    }

    while((dent = readdir(dp))) { //디렉토리에 있는 파일 하나씩 읽어옴

        char path[BUFSIZ];
        char next[BUFSIZ];

        if(dent->d_name[0] == '.') continue; //숨김파일 or . .. 파일은 skip

        printf("%d %s%s\n",(int) dent->d_ino, current, dent->d_name); //파일 inode, 이름 출력

        sprintf(path, "%s/%s",dictName, dent->d_name); // 경로 수정
        stat(path, &buf); //buf에 파일정보 담음

        if(S_ISDIR(buf.st_mode)) {
            sprintf(next, "%s%s/", current,dent->d_name);    
            printf("%s\n",path);
            printDirectoryInfo(path, next); //recursive
        }
    }

    closedir(dp);
}

int main(int argc, char ** argv)
{
    printDirectoryInfo(argv[1], "");
}