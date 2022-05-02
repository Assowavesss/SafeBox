/**
 * @file Accelerometer.h
 * @brief File which contain the implementation of Accelerometer class in safeboxe namespace
 * @headerfile 
 * @date 2022
 * @see Accelerometer.cpp
 * @see Prototype.h
 * @see Accelerometer.h
 * @see Connection.h
 * @see Action.h
 */
#ifndef ACCELEROMETER_H
#define ACCELEROMETER_H

#include"Prototype.h"

namespace safebox
{
	/**
	 *@class Accelerometer
	 *@brief To use accelerometer for safebox to detect accident
	 *@see Prototype
	 *@see action
	 */
	class Accelerometer : public Prototype
	{
		
		private:
            float x_out;
            float y_out;
            float z_out;
            
            bool accident(void);

        public:
            Accelerometer(void);
			/**
			 * @fn void run(void) const override
			 * @brief Inherited by Prototype::run(void) const, this method is used to run accelerometer
			 * @see Connection::run(void) const
			 */
			void run(void) override;

         
	};
}
	
#endif
