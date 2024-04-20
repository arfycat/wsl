#include <unistd.h>
#include <stdio.h>
#include <sys/file.h>

int main(int argc, char *argv[])
{
  int fd = open("/tmp/wsl.lock", O_CREAT, S_IRUSR | S_IWUSR);
  if (fd == -1)
  {
    printf("Failed to open lock file.\n");
    return -1;
  }

  if (flock(fd, LOCK_EX | LOCK_NB) != 0)
  {
    printf("Process is already running.\n");
    return -1;
  }

  while (1)
  {
    sleep(100000);
  }

  return -1;
}
