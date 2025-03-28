#include <Arduino.h>

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  while(!Serial) 
    ;

  delay(1000);

  // WIO_LIGHT引脚是连接到板载光敏传感器的GPIO引脚的编号
  // 设置为INPUT，这意味着它连接到一个传感器，并且将从这个引脚读取数据
  pinMode(WIO_LIGHT,INPUT);

  // 配置用于通过Grove接口与LED进行通信的引脚
  // D0引脚是一个数字引脚，用于连接Grove接口
  // 引脚被设置为输出模式，意味着它连接到了一个执行器，并且数据将被写入到这个引脚，从而通过输出信号来控制执行器的动作
  pinMode(D0, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

  // 从板载光敏传感器读取一个值，这个值的范围是从0到1023
  // 光敏传感器会根据环境光线的强度输出不同的模拟值，0通常表示没有光线，而1023表示光线最强
  int light=analogRead(WIO_LIGHT);

  // 打印输出亮度值
  Serial.print("Light value: ");
  Serial.println(light);

  // 在向执行器发送数字信号时，低电平（LOW）对应的电压值是0伏特，高电平（HIGH）对应的电压值是该设备的最大电压
  // 对于Wio Terminal设备来说，其高电平（HIGH）的电压是3.3伏特。
  if(light<300)
  {
    Serial.println("light");
    digitalWrite(D0,HIGH);
  }
  else
  {
    Serial.println("dark");
    digitalWrite(D0,LOW);
  }

  // 延迟1秒，以节省能量消耗
  delay(1000);
}

