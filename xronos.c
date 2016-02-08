/*

   UNIX Use: cc xronos.c -o xronos
             ./xronos; ./xronos 1

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

  if (argc == 2){
    (mod_t <= 0)? 
      printf("\n\n \033[22;32mWinter NYC Time: %2i:%02i\033[0m\n\n", (((mod_t-1) % 24+24)%24), (*xronos).tm_min):
      printf("\n\n \033[22;33mWinter NYC Time: %2i:%02i\033[0m\n\n", mod_t-1, (*xronos).tm_min);
  } else {
    (mod_t <= 0)?
      printf("\n\n \033[22;32mSummer NYC Time: %2i:%02i\033[0m\n\n", (mod_t % 24+24)%24, (*xronos).tm_min):
      printf("\n\n \033[22;33mSummer NYC Time: %2i:%02i\033[0m\n\n", mod_t, (*xronos).tm_min);
  }
}
