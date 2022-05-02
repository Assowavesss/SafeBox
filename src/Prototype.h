/**
 * @file Prototype.h
 * @brief Prototype file which contain the Interface Prototype for the safebox
 * @headerfile 
 * @date 2022
 * @see Prototype.h
 * @see Accelerometer.h
 * @see Connection.h
 * @see Action.h
 */
#ifndef PROTOTYPE_H
#define PROTOTYPE_H

/**
 * @namespace safebox
 * @brief namespace which contain all class for safebox
 * @details 
 * We use the strategy design pattern with class implemented in safebox namespace
 * The interface Prototype are inherited by Connection and by Accelerometer
 * The method run is different for Connection and for Accelerometer class
 * Finally, The class Action use run method for Connection and Accelerometer  
 */
namespace safebox
{
	/**
	 * @interface Prototype
	 * @brief Interface which describe the protoype of safebox
	 * @see Prototype
	 * @see Accelerometer
	 */
	class Prototype
	{
		public:
			/**
			 * @fn virtual ~Prototype(void)
			 * @brief virtual Destructor which will be overridden by Accelerometer and Connection
			 */
			virtual ~Prototype(void) {}
			/**
			 * @fn virtual void run(void) const
			 * @brief Method of safebox protype which used to make connection and use accelerometer
			 */
			 virtual void run(void) = 0;
	};
	
	
}

#endif
