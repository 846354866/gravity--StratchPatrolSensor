#ifndef StratchPatrolSensor_h
#define StratchPatrolSensor_h
/*!
 * @file StratchPatrolSensor.h
 * @brief StratchPatrolSensor
 * @n Header file for DFRobot's patrol sensors
 *
 * @copyright	[DFRobot](http://www.dfrobot.com), 2016
 * @copyright	GNU Lesser General Public License
 *
 * @author [carl](carl.xu@dfrobot.com)
 * @version  V1.0
 * @date  2016-09-19
 */

#include <SoftwareSinglebus.h>


#define REG_ADDR     0x13 ///<parrol sensor read register address.
#define REG_CHANGE   0x04   ///<parrol sensor change hardware register address.

class StratchPatrolSensor
{
	public:
	
		/*!
		*  @brief Constructor.
		*  @param bus_  single bus .
		*  @param addr_  hardware address.
		*/
		StratchPatrolSensor(SoftwareSinglebus *bus_,int addr_=0x01);
		
		/*!
		*  @brief Modify the ultrasonic hardware address.
		*  @param id  new  hardware address.
		*/
		int16_t modifyAddr(uint8_t id); 
		/*!
		*  @brief Set the interrupt the callback function.
		*  @param cb  callback function.
		*/
		int16_t setCB( void (*cb)( void* p_ ) );
		
		/*!
		*
		*@brief read left patrol sensor data.
		*
		*/
		int8_t readLeftLine(void);
		
		/*!
		*
		*@brief read middle patrol sensor data.
		*
		*/
		int8_t readMiddleLine(void);
		
		/*!
		*
		*@brief read right patrol sensor data.
		*
		*/
		int8_t readRightLine(void);
		
	private:
		SoftwareSinglebus *bus;///<single bus.
		uint8_t addr; ///<parrol sensor hardware address.
};
#endif
