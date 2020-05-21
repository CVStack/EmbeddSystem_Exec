#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>

int main(int argc, char ** argv) 
{


    struct stat buf;

    stat(argv[1],&buf); //buf에 정보 담아옴

    printf("File : ");
    if(S_ISREG(buf.st_mode))
        printf("Y");
    else
        printf("N");
    printf("\n");

    printf("Directory : ");
    if(S_ISDIR(buf.st_mode))
        printf("Y");
    else
        printf("N");
    printf("\n");

    printf("Inode = %d\n", (int)buf.st_ino); //Inode 번호 --> file을 구별할때 사용
    printf("Mode = %o\n", (unsigned int)buf.st_mode);
    printf("Nlink = %o\n",(unsigned int) buf.st_nlink);
    printf("UID = %d\n", (int)buf.st_uid);
    printf("GID = %d\n", (int)buf.st_gid);
    printf("SIZE = %d\n", (int)buf.st_size);
    printf("Atime = %d\n", (int)buf.st_atime); //access time
    printf("Mtime = %d\n", (int)buf.st_mtime); //modify time 
    printf("Ctime = %d\n", (int)buf.st_ctime); //create time   
    printf("Blksize = %d\n", (int)buf.st_blksize);
    printf("Blocks = %d\n", (int)buf.st_blocks);

    chmod(argv[1], 0700);

}