/*!
 * @file patrolsensorchangeaddr.ino
 * @brief DFRobot's Patrol Sensor
 * @n [Get the module here](等上架以后添加商品链接)
 * @n This example is modify the hardware address.
 * @n [Connection and Diagram](等上架以后添加wiki链接)
 *
 * @copyright	[DFRobot](http://www.dfrobot.com), 2016
 * @copyright	GNU Lesser General Public License
 *
 * @author [carl](carl.xu@dfrobot.com)
 * @version  V1.0
 * @date  2016-09-19
 */
#include <StratchPatrolSensor.h>
#define DISCOVERY_SINGLE_BUS_PIN 2
SoftwareSinglebus  mySingleBus(DISCOVERY_SINGLE_BUS_PIN);
StratchPatrolSensor patrol(&mySingleBus,0x03);

void PatrolSensorCB( void* p_ ){
    StratchPatrolSensor* psen = (StratchPatrolSensor*)p_;
    //int16_t data = psen->readMiddleLine();
    //if(data != -1)
    //   Serial.println(data);
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  delay(100);
  patrol.setCB(PatrolSensorCB);
  patrol.modifyAddr(0x01);//change PatrolSensor addr
}

void loop() {
  // put your main code here, to run repeatedly:
  int16_t data = patrol.readMiddleLine();
  if(data != -1)
  Serial.println(data);
  //  mySingleBus.callbackfun[0].callback_t( mySingleBus.callbackfun[0].arg);
  delay(100); 
}

