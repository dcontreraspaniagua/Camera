#include <Python.h>
PyObject *pyName, *pyModule, *pyFunc;
PyObject *pyArgs, *pyValue;
int caminit(){
	Py_Initialize();
	PyRun_SimpleString("from picamera import PiCamera\n" "from time import sleep, localtime, strftime\n" "camera = PiCamera()\n"
			"from picamera.array import PiRGBArray\n" "import time\n" "import cv2\n");
	PyRun_SimpleString("resolucion= camera.resolution\n");
	PyRun_SimpleString("framerate= camera.framerate\n");
	PyRun_SimpleString("rawCapture = PiRGBArray(camera, size=(640, 480))\n");
	//PyRun_SimpleString("print(resolucion)\n");
	//PyRun_SimpleString("print(framerate)\n");
	PyRun_SimpleString("from gpiozero import MotionSensor\n" "pir = MotionSensor(4)");
}
int sensorinit()
{
	PyRun_SimpleString("detection=0\n");
	PyRun_SimpleString("count=0\n");
	//pyName = PyUnicode_FromString("sensor.py");
	//pyModule = PyImport_Import(pyName);
	//if (pyModule ==NULL){
	//	printf("error module");
	//}
	//pyFunc = PyObject_GetAttrString(pyModule, (char*)"detect");
}
int camend(){
	Py_Finalize();
}
int campreview(char *time){
	PyRun_SimpleString("camera.framerate=30\n");
	PyRun_SimpleString("camera.resolution = (1920, 1080)");
	char str[200];
	strcpy(str, "camera.start_preview()\n" "sleep(");
	strcat(str, time);
	strcat(str,")\n" "camera.stop_preview()\n");
	PyRun_SimpleString(str);

}

int camstartpreview(){
	PyRun_SimpleString("camera.framerate=30\n");
	PyRun_SimpleString("camera.resolution = (1920, 1080)");
	PyRun_SimpleString("camera.start_preview()\n");
}
int camstoppreview(){
	PyRun_SimpleString("camera.stop_preview()\n");
	PyRun_SimpleString("count=0\n");
}
int camstartrecording(){
	PyRun_SimpleString("camera.resolution = (1920, 1080)");
	PyRun_SimpleString("camera.framerate=30\n");
	PyRun_SimpleString("videofilename=strftime(\"video/%Y_%m_%d_%H:%M:%S.h264\",localtime())\n");
	PyRun_SimpleString("camera.start_recording(videofilename)");
}

int camstoprecording(){
	//PyRun_SimpleString("print(detection)");
	PyRun_SimpleString("while(count<=30000):\n"
						//"	print(detection)\n"
						//"	print(count)\n"
						"	count+=1\n"
						"	if pir.motion_detected:\n"
							"		print(\"Motion detected!\")\n"
							"		detection+=1\n"
						"	if(detection >= 50):\n"
						"			count=0\n"
						"			detection=1\n"
						"			print(\"Keep Recording\")\n"
						//"print(detection)\n"
						"detection=0\n"
						"count=0\n"
						"camera.stop_recording()\n");
}

int camtakepicture(){
	PyRun_SimpleString("camera.framerate=30\n");
	PyRun_SimpleString("camera.resolution = (1920, 1080)");
	PyRun_SimpleString("picname=strftime(\"pictures/%Y_%m_%d_%H:%M:%S.jpg\",localtime())\n");
	PyRun_SimpleString("camera.capture(picname)");

}

int camstreaming(){
	PyRun_SimpleString("camera.framerate=32\n");
	PyRun_SimpleString("camera.resolution = (640, 480)\n");
	PyRun_SimpleString("sleep(0.1)\n");
	PyRun_SimpleString("for frame in camera.capture_continuous(rawCapture, format=\"bgr\", use_video_port=True):\n" "	image = frame.array\n"
			"	cv2.imshow(\"Frame\", image)\n" "	key = cv2.waitKey(1) & 0xFF\n" "	rawCapture.truncate(0)\n"
			"	if key == ord(\"q\"):\n" "		break\n" "	if pir.motion_detected:\n" "		detection=1\n" "		break\n");
}

int motionsensor(){
	PyRun_SimpleString("if pir.motion_detected:\n" "	print(\"Motion detected!\")\n" "	detection=1\n" "else:\n"
			"	detection=0\n");
	PyRun_SimpleString("print(detection)");
	//strcpy(str, PyRun_SimpleString("print(motion)") );
	//int m;
	//m=PyRun_SimpleString("motion");
	//printf("%d", m);
	//printf("%c", m);
	//if(m[0]=="0"){
	//	printf("0\n");
	//}
	//else if(m[0]=="1"){
	//	printf("1\n");
	//}
	//printf("%d", m[0]);
	//pyValue = PyObject_CallObject(pyFunc, pyArgs);
	//printf("%d",pyValue);
}

int stop(){
	char key="0";
	int x = 0;
	scanf("%s" , key);
	if(key == "q"){
		x=1;
	}
	printf("%s", key);
	return x;
}
