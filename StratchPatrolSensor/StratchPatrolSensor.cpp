/*!
 * @file StratchPatrolSensor.cpp
 * @brief StratchPatrolSensor
 * @n Header file for DFRobot's Patrol sensors
 *
 * @copyright	[DFRobot](http://www.dfrobot.com), 2016
 * @copyright	GNU Lesser General Public License
 *
 * @author [carl](carl.xu@dfrobot.com)
 * @version  V1.0
 * @date  2016-09-19
 */
#include<StratchPatrolSensor.h>
#include<Arduino.h>
int16_t StratchPatrolSensor::setCB( void (*cb)( void* p_ ) )
{
    bus->registerCB( addr, cb, this );
	
    return 0;
}

StratchPatrolSensor::StratchPatrolSensor(SoftwareSinglebus *bus_,int addr_)
	:bus(bus_),addr(addr_)
{
	bus->begin();// start single bus
}

int8_t StratchPatrolSensor::readLeftLine()
{
	int8_t data = -1;
	bus->beginTransmission(addr,READ);
	bus->write(REG_ADDR);//register address
	bus->write(0x01);//length
	bus->endTransmission();
	bus->requestFrom(addr,0x01);
	if(bus->available() == 0x01)
	{
		data = bus->read(); 	
	}
	if(data != -1)
	{
		data = (data & 0x04)>>2;
	}
	bus->endTransmission();
	return data;
}

int8_t StratchPatrolSensor::readMiddleLine()
{
	int8_t data = -1;
	bus->beginTransmission(addr,READ);
	bus->write(REG_ADDR);//register address
	bus->write(0x01);//length
	bus->endTransmission();
	bus->requestFrom(addr,0x01);
	if(bus->available() == 0x01)
	{
		data = bus->read(); 	
	}
	if(data != -1)
	{
		data = (data & 0x02)>>1;
	}
	bus->endTransmission();
	return data;
}

int8_t StratchPatrolSensor::readRightLine()
{
	int8_t data = -1;
	bus->beginTransmission(addr,READ);
	bus->write(REG_ADDR);//register address
	bus->write(0x01);//length
	bus->endTransmission();
	bus->requestFrom(addr,0x01);
	if(bus->available() == 0x01)
	{
		data = bus->read(); 	
	}
	if(data != -1)
	{
		data = data & 0x01;
	}
	bus->endTransmission();
	return data;
}

int16_t StratchPatrolSensor::modifyAddr(uint8_t newAddr)
{
  bus->beginTransmission(addr,WRITE);
  bus->write(REG_CHANGE);
  bus->write(newAddr);
  bus->endTransmission();
  addr = newAddr;
  return 0;
}
