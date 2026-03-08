#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>

int main()
{
    int fd = 0;

    fd = open("PPA.txt", O_RDWR);

    if(fd == -1)
    {
        printf("Unable to open file");
    }
    else
    {
        write(fd, "Jay Ganesh", 10);
        printf("File gets succesfully opened with fd : %d\n", fd);
        close(fd);
    }

    return 0;
}