#define logInfo(x, ...)  MyLog("[%s] "x, __FUNCTION__, ##__VA_ARGS__);
#define logWarning(x, ...)  MyLog("[Warning][%s] "x, __FUNCTION__, ##__VA_ARGS__);
#define logError(x, ...)  MyLog("[Error][%s] "x, __FUNCTION__, ##__VA_ARGS__);

static int g_counter = 0;
const byte LED = 13;
int angle = 0;

extern void MyLog(const char *fmt, ... );
extern int floatToStr(char *str, size_t size, double f, int precision);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial.println("Hello Arduino!");
  pinMode(LED, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly: 
//  logInfo("%s g_counter is %d, %s\n", __FUNCTION__, g_counter, g_counter%2 == 0 ? "even" : "odd");
//  g_counter++;
//  delay(1000);
//  digitalWrite(LED, HIGH);   // turn the LED on (HIGH is the voltage level)
//  delay(1000);               // wait for a second
//  digitalWrite(LED, LOW);    // turn the LED off by making the voltage LOW
//  delay(1000);               // wait for a second
    
    float radius = angle*PI/180;
    double out = sin(radius);
    logInfo("angle=%d, out=%d.%d\n", angle, (int)out, (int)(out*100)%100);
    angle++;
    if (angle == 360)
    {
      angle = 0;
    }
    delay(100);
}

void MyLog(const char *fmt, ... ){
    char buff[128]; // resulting string limited to 128 chars
    va_list args;
    va_start (args, fmt );
    vsnprintf(buff, 128, fmt, args);
    va_end (args);
    Serial.print(buff);
}
