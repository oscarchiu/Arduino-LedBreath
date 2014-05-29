// #define DEBUG

#ifdef DEBUG
  #define logDebug(x, ...)  MyLog("[Debug][%s] "x, __FUNCTION__, ##__VA_ARGS__);
#else
  #define logDebug(x, ...) 
#endif
#define logInfo(x, ...)  MyLog("[%s] "x, __FUNCTION__, ##__VA_ARGS__);
#define logWarning(x, ...)  MyLog("[Warning][%s] "x, __FUNCTION__, ##__VA_ARGS__);
#define logError(x, ...)  MyLog("[Error][%s] "x, __FUNCTION__, ##__VA_ARGS__);

const byte LED = 9;
int angle = 180;

extern void MyLog(const char *fmt, ... );

void setup() {
  // put your setup code here, to run once:
  pinMode(LED, OUTPUT);
  Serial.begin(115200);
  Serial.println("Hello Arduino!");
}

void loop() {
  // put your main code here, to run repeatedly: 
    float radius = angle*PI/180;
    byte brightness = (int)((cos(radius)+1) * 255) >> 1;
    logInfo("angle=%d, brightness=%d\n", angle, brightness);
    analogWrite(LED, brightness);
    angle++;
    if (angle == 360)
    {
      angle = 0;
    }
    delay(30);
}

void MyLog(const char *fmt, ... ){
    char buff[128]; // resulting string limited to 128 chars
    va_list args;
    va_start (args, fmt );
    vsnprintf(buff, 128, fmt, args);
    va_end (args);
    Serial.print(buff);
}
