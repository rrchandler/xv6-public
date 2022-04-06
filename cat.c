#include "types.h"
#include "stat.h"
#include "user.h"

char buf[512];

void
cat(int fd)
{
  int n;

  while((n = read(fd, buf, sizeof(buf))) > 0) {
    if (write(1, buf, n) != n) {
      printf(1, "cat: write error\n");
      //Modified exit() call to pass in a 1, for error
      exit(1);
    }
  }
  if(n < 0){
    printf(1, "cat: read error\n");
    //Modified exit() call to pass in a 1, for error
    exit(1);
  }
}

int
main(int argc, char *argv[])
{
  int fd, i;

  if(argc <= 1){
    cat(0);
    //Modified exit() call to pass in a 1, for error
    exit(1);
  }

  for(i = 1; i < argc; i++){
    if((fd = open(argv[i], 0)) < 0){
      printf(1, "cat: cannot open %s\n", argv[i]);
      //Modified exit() call to pass in a 1, for error
      exit(1);
    }
    cat(fd);
    close(fd);
  }
  //Modified exit() call to pass in a 0, for no error
  exit(0);
}
