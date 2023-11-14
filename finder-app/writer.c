#include <syslog.h>
#include <fcntl.h>
#include <unistd.h>
#include "string.h"
#include <sys/stat.h>


int main(int argc, char **argv)
{
    const char *writefile = argv[1];
    const char *writestr = argv[2];

    openlog ("writer", LOG_CONS | LOG_PID | LOG_NDELAY, LOG_USER);

    if (argc < 3)
    {
        syslog(LOG_ERR, "Error, not all arguments are given");
        return 1;
    }

    int fd = open(writefile, O_WRONLY | O_CREAT , S_IRWXU | S_IRWXG | S_IRWXO);

    syslog(LOG_DEBUG , "Writing %s to %s", writestr, writefile);
    size_t num = write(fd, writestr, strlen(writestr));

    if (num < strlen(writestr))
    {
        syslog(LOG_ERR , "Error, writing to file was not successfull");
        return 1;
    }

    close(fd);
    closelog();

    return 0;
}