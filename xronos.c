/*

   UNIX Use: cc xronos.c -o xronos
             ./xronos; ./xronos d
	OR     xronos d; xronos

*/

#include <stdio.h>
#include <math.h>
#include <time.h>

#define NYC       (4)
#define DAY "python date.py || python /Users/<user>/bin/date.py"

main(int argc, char *argv[]){

  time_t raw_t;
  signed int mod_t;
  struct tm *xronos;

  time(&raw_t);
  xronos = gmtime(&raw_t);
  mod_t = (xronos->tm_hour-NYC);

  if (argc == 2) system(DAY);
  else {
    (mod_t <= 0)?
      printf("\033[22;32mχρόνος (EST) -> %2i:%02i:%02i\033[0m\n", (mod_t % 24+24)%24, (*xronos).tm_min, (*xronos).tm_sec):
      printf("\033[22;33mχρόνος (EST) -> %2i:%02i:%02i\033[0m\n", mod_t, (*xronos).tm_min, (*xronos).tm_sec);
    printf("\033[22;33mχρόνος (GMT) -> %2i:%02i:%02i\033[0m\n", (*xronos).tm_hour, (*xronos).tm_min, (*xronos).tm_sec);
  }
}
[22;33mχρόνος (EST) -> 18:08:31[0m
[22;33mχρόνος (GMT) -> 22:08:31[0m
