/*
 * Filename: test.c
 */

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/mman.h>
#include "cdata_ioctl.h"

int main(void)
{
    int fd;
    int i;
    //char chardat[4]={0x30,0x31,0x32,0x3f};
    pid_t child;
    child = fork();
    //if fork are befor than open devices then it's easy to control reentrantcy ,but if it's later ,it need becarefully.
    fd = open("/dev/cdata", O_RDWR);
    ioctl(fd,IOCTL_EMPTY,NULL);
    //ioctl(fd,IOCTL_WRITE,&chardat[0]);
    //ioctl(fd,IOCTL_WRITE,&chardat[2]);
    //ioctl(fd,IOCTL_WRITE,&chardat[1]);
    for (i=0;i<300;i++)
	{
    		write(fd,"hello",5);
	}
    //ioctl(fd,IOCTL_SYNC,NULL);
    //child = fork();
    //ioctl(fd, CDATA_CLEAR, &i);
    //while(1) {
    //	write(fd, pix, 4);
    //}
    //fb = (char *)mmap(0, 1024, PROT_READ|PROT_WRITE, MAP_SHARED, fd, 0);
    close(fd);
}


