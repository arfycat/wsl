/*
   Copyright 2024 arfycat (https://github.com/arfycat)

   Licensed under the Apache License, Version 2.0 (the "License");
   you may not use this file except in compliance with the License.
   You may obtain a copy of the License at

       http://www.apache.org/licenses/LICENSE-2.0

   Unless required by applicable law or agreed to in writing, software
   distributed under the License is distributed on an "AS IS" BASIS,
   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
   See the License for the specific language governing permissions and
   limitations under the License.
*/

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
