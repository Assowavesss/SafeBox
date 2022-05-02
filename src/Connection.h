/**
 * @file Connection.h
 * @brief File which contain the implementation of Connection class in safeboxe namespace
 * @headerfile 
 * @date 2022
 * @see Prototype.h
 * @see Accelerometer.h
 * @see Connection.h
 * @see Action.h
 */
#ifndef CONNECTION_H
#define CONNECTION_H

#include "Prototype.h"

namespace safebox
{
	/**
	 * @class Connection
	 * @brief Used for making connection with database
	 * @see Prototype
	 * @see Action
	 */
	class Connection : public Prototype
	{
		private:
            const char* ssid_;
            const char* password_;
		
		public:
            
            Connection(const char *ssid, const char *password);
			
            /**
			 * @fn virtual void run(void) const override
			 * @brief Inherited by Prototype::run(void) const, this method is used to make connection with database
			 * @see Accelerometer::run(void) const
			 */
			void run(void)  override;
	};
	
}


#endif
