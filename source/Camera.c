#include <stdio.h>
#include <stdlib.h>
#include <Python.h>
#include <string.h>
#include "../interface/pycam.h"
int x = 0;
int main ()
{
printf("Camera 1\n");
caminit();
sensorinit();
while(1){
camstreaming();
printf("Caution movement detected\n");
camstartpreview();
printf("Taking Picure, Smile :) \n");
camtakepicture();
printf("Recording video...\n");
camstartrecording();
PyRun_SimpleString("sleep(10)\n");
camstoprecording();
camstoppreview();
printf("Done..\n");
printf("Streaming again\n");
//x = stop();
}
}
