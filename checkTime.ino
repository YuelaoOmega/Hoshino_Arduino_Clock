/*
这个程序是用来校准RTC的，在写入该程序后再写入主程序，否则内存会不足
*/
#include<DS1302.h>

//RTC针脚
#define TIME_RST_PIN 5
#define TIME_DAT_PIN 3
#define TIME_CLK_PIN 4

//定义rtc模块
DS1302 rtc(TIME_RST_PIN,TIME_DAT_PIN,TIME_CLK_PIN);


//获得编译时间的
void get_Compile_Time(int* year, int* month, int* day, int* hour, int* minute, int* second) {
  char compileDate[] = __DATE__;
  char compileTime[] = __TIME__;

  char monthStr[4];
  strncpy(monthStr, compileDate, 3);
  monthStr[3] = '\0';

  const char* months[] = {"Jan","Feb","Mar","Apr","May","Jun",
                         "Jul","Aug","Sep","Oct","Nov","Dec"};
  *month = 0;
  for (int i = 0; i < 12; i++) {
    if (strcmp(monthStr, months[i]) == 0) { // 修复条件
      *month = i + 1;
      break;
    }
  }

  //解析日期时间
  sscanf(compileDate + 4, "%d %d", day, year);
  sscanf(compileTime, "%d:%d:%d", hour, minute, second);
}

//计算这天是周几的
int week_day(unsigned int yr,unsigned int mn,unsigned int day){
  int week = 0;
  if(mn == 1 || mn == 2){
    mn += 12;
    yr--;
  }
  //基姆拉尔森计算公式
  week = ( day + 2 * mn + 3 * ( mn + 1 ) / 5 + yr + yr / 4 - yr / 100 + yr / 400) % 7;
  return week + 1; 
}

//初始化时钟
void init_RTC_Time(void){
  
  rtc.writeProtect(false);
  rtc.halt(false);

  int compileYear, compileMonth, compileDay;
  int compileHour, compileMinute, compileSecond;
  
  get_Compile_Time(&compileYear, &compileMonth, &compileDay,
              &compileHour, &compileMinute, &compileSecond);


  int weekday = week_day(compileYear,compileMonth,compileDay);
      
  Time t(compileYear, compileMonth, compileDay, compileHour, compileMinute, compileSecond, weekday);

  rtc.time(t); // 写入时间
  
  
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  init_RTC_Time();
  Serial.println("OKAY");
}

void loop() {
  // put your main code here, to run repeatedly:


}
