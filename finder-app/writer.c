#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <syslog.h>
#include <errno.h>

int write_to_file(char *filename, char *string)
{
  FILE *fptr;
  fptr = fopen(filename, "w");
  if (fptr == NULL) {
    syslog(LOG_ERR, "Could not create %s, errno: %d, %s", filename, errno, strerror(errno));
    return 1;
  }
  fprintf(fptr, "%s", string);
  fclose(fptr);
  syslog(LOG_USER | LOG_INFO | LOG_DEBUG, "wrote %s to %s", string, filename);

  return 0;
}

int main(int argc, char *argv[])
{
  if (argc != 3) {
    syslog(LOG_ERR, "Invalid number of arguments: %d!", argc-1);
    return 1;
  }
  char *filename = argv[1];
  char *string = argv[2];
  write_to_file(filename, string);
  return 0;
}