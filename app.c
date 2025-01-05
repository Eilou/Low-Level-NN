#include <stdio.h>
#include <stdbool.h>

#include "staticNN.h"
#include "dynamicNN.h"

int main() {
   
   printf("Low Level Neural Network Program\n");

   bool staticNotDynamic = true;

   if (staticNotDynamic) {
      staticNN();
   }
   else {
      dynamicNN();
   }

   return 0;
}