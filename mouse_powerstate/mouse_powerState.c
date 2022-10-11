#include <stdio.h>
#include <linux/input.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "mouse_powerState.h"

void suspend_RAM(int argc, char **argv)
{
    int fd;
    struct input_event ev;

    fd = open(argv[1], O_RDONLY);

    for (int i = 0; i < 100; ++i)
    {
        read(fd, &ev, sizeof(struct input_event));
        printf("############## Entry %d ##########\n", i);
        printf("value=%u\n", ev.value);
        printf("time=%li\n", ev.time.tv_sec);
        printf("type=%u\n", ev.type);
        printf("code=%u\n", ev.code);
    }

    close(fd);

    // suspend system
    fd = open("/sys/power/state", O_RDWR);
    write(fd, "mem", 3);
    close(fd);
}