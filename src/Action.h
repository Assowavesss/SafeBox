/**
 * @file Action.h
 * @brief File which contain the implementation of Action class in safeboxe namespace
 * @headerfile 
 * @date 2022
 * @see Prototype.h
 * @see Accelerometer.h
 * @see Connection.h
 * @see Action.h
 */
#ifndef ACTION_H
#define ACTION_H

#include "Accelerometer.h"
#include "Connection.h"

namespace safebox
{
	/**
	 * @class Action
	 * @brief Singleton Class which contain Prototype Object so, it can use all method of safebox
	 * @see Prototype
	 */
	class Action
	{
		private:
			
			/**
       * @fn Action(Prototype *prototype)
       * @brief Constructor of class Action, private because Action is Singleton and we don't want to use constructor outside the class
       * @param Prototype *prototype
       * @see action_
       */
      Action(Prototype *prototype);
			
			/**
			 * @var prototype_
			 * @brief pointer of prototype which can used to be casted by Connection or Accelerometer
			 * @see Prototype
			 */
			Prototype *prototype_;

      /**
       * @var action_
       * @brief pointer to instance of singleton Action
       * @see static Action *getInstance(Prototype *prototype)
       */
      static Action *action_;
        
		public:
			
			/**
       * @fn Action(Action &other)  
       * @brief delete copy constructor
       * @param Action &other
			 */
			Action(Action &other) = delete;

      /**
       * @fn void operator=(const Action &other)
       * @brief avoid the overloading of operator =
       * @param const Action &other
       */
      void operator=(const Action &other)=delete;

      /**
       * @fn static Action *getInstance(Prototype *prototype)
       * @brief 
       */
      static Action *getInstance(Prototype *prototype);
			
			/**
			 * @fn ~Action(void)
			 * @brief Destructor of Action, used to destroy the pointer in prototype
			 */
			~Action(void);
			
			/**
			 * @fn void setPrototype(Prototype *prototype)
			 * @brief setter on attribute prototype, allow to change method of action
			 * @param Prototype *prototype
			 */
			void setPrototype(Prototype *prototype);
			
			/**
			 * @fn void Action::run(void)
			 * @brief used to use the method run of prototype
			 * @see virtual void Prototype::run(void) const
			 */
			void run(void);

	};
}




#endif
