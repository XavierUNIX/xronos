/*

   UNIX Use: cc xronos.c -o xronos
             ./xronos

*/

#include <stdio.h>
#include <math.h>
#include <time.h>

#define NYC      (4)

main(int argc, char *argv[]){

  time_t raw_t;
  signed int mod_t;
  struct tm *xronos;

  time(&raw_t);
  xronos = gmtime(&raw_t);
  mod_t = (xronos->tm_hour-NYC);

  (mod_t <= 0)?
    printf("\n\n \033[22;32mMachine Time: %2i:%02i:%02i\033[0m\n\n", (mod_t % 24+24)%24, (*xronos).tm_min, (*xronos).tm_sec):
    printf("\n\n \033[22;32mMachine Time: %2i:%02i:%02i\033[0m\n\n", mod_t, (*xronos).tm_min, (*xronos).tm_sec);

}
