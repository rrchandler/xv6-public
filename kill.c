#include "types.h"
#include "stat.h"
#include "user.h"

int
main(int argc, char **argv)
{
  int i;

  if(argc < 2){
    printf(2, "usage: kill pid...\n");
    //Modified exit() call to pass in a 1, for error
    exit(1);
  }
  for(i=1; i<argc; i++)
    kill(atoi(argv[i]));
  //Modified exit() call to pass in a 0, for no error
  exit(0);
}
