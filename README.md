# Hoshino Arduino Clock


它能做什么？
-
1. 显示时间
2. 根据温度播放音频
3. 播放动画并根据时间切换

硬件如下
-
1. 开发板:Arduino UNO
2. 显示屏:ssd1309 2.24''（128x64）
3. 时钟模块:DS1302
4. 温度检测模块:DS18B20
5. 高电平触发的喇叭

接线
-
可以看代码的宏定义

如何使用？
-
1. 先接好相应的接线，连接你的Arduino，打开`Serial Monitor`，`Brand`设为`9600`
2. 将`Checktime`上传并运行
3. 等待`Serial Monitor` 输出 **Okay**
4. 将主程序写入

就像一个普通的电子钟一样，上面会播放动画，动画会随时间改变（两种状态）

具体可以在代码里看到（应该没人会想读这坨长达911行的石山的

涉及的库
-
1. Arduino.h [点击跳转](https://github.com/arduino/ArduinoCore-avr)
2. OneWire.h [点击跳转](https://github.com/PaulStoffregen/OneWire)
3. Rtc by Makuna [点击跳转](https://github.com/Makuna/Rtc/wiki)
4. DallasTemperature [点击跳转](https://github.com/milesburton/Arduino-Temperature-Control-Library)
5. U8g2 [点击跳转](https://github.com/olikraus/u8g2)

能找到来源的我全都找到了TwT
如果有遗漏的欢迎issue补充

涉及角色
-
小鸟游星野（蔚蓝档案/BLUE ARCHIVE）

废话
-
目前程序已经完成啦
有什么问题/建议欢迎提交ISSU
该项目开源协议以License为主，其余不做过多赘述
图有的是描的有的是自己画的

喜欢的话可以为这个仓库点个Star毕竟它写起来真的超级不容易TWT
人之初性本善不写注释是好汉^^

