#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>

int main()
{
  int fdSrc = 0, fdDest = 0, iRet= 0;
  char fSource[100] = {'\0'};
  char fDest[100] = {'\0'};
  char Buffer[100] = {'\0'};

  printf("Enter the name of Source file : \n");
  scanf("%s",fSource);

  printf("Enter the name of Destination file : \n");
  scanf(" %s",fDest);

  fdSrc = open(fSource,O_RDONLY);
  if(fdSrc == -1)
  {
    printf("Unable to open the source file \n");
    return -1;
  }

  fdDest= creat(fDest,0777);

 if(fdDest == -1)
  {
    printf("Unable to open the Destination file \n");
    close(fdSrc);
    return -1;
  }

  while ((iRet = read(fdSrc, Buffer, sizeof(Buffer))) != 0)
  {
    write(fdDest, Buffer,iRet);
  }
  
  close(fdSrc);
  close(fdDest);

  printf("FIle Copied Succesfully...\n");

  return 0;
}