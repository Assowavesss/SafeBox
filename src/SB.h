/**
 * @file SB.h
 * @brief file which contain the implementation of ISB 
 * @headerfile 
 * @date 2022
 * @see ISB.h
 * @see Connection.h
 */
#ifndef SB_H 
#define SB_H 

#include"utility/ISB.h"
#include"utility/Connection.h"

namespace savebox
{
	/**
     	 * @class SB 
     	 * @brief to use accelerometer for savebox to detect accident
     	 * @see Connection.h
     	 */
	class SB : public ISB
    	{
        	private:
            
            		/**
			 * @var x_out
			 * @brief axis x for ADXL345
			 */
			float x_out;
            		
			/**
 			 * @var y_out
			 * @brief axis y for ADXL345
		         */
            		float y_out;
            		
			/**
			 * @var z_out
			 * @brief axis z for ADXL345
			 */
            		float z_out;
            
            		/**
             		 * @var conn_
             		 * @brief create connection object to allow to SB to connect to database
             		 * @see Connection.h
             		 */
            		Connection *conn_;
            
            		/**
             		 * @fn bool accident(void) override
             		 * @brief to detect if there is an accident or not using coordinate of accelerometer
             		 */
            		bool accident(void) override;

            		/**
             		 * @fn void sendData(void) override
             		 * @brief send data of passengers if there is an accident
             		 * @see bool accident(void) ovveride
             		 */
            		void sendData(void) override;

        	public:

            		/**
             		 * @fn explicit SB(void)
			 * @brief make a connection with acceleromter and initialize the connection object conn_ to nullptr
             		 */
            		explicit SB(void);	
            
            		/**
             		 * @fn ~SB(void) noexcept
             	 	 * @brief destruct the connection object conn_ and set it to nullptr
             		 */
            		~SB(void) noexcept;
            
            		/**
             		 * @fn void connection(const char* ssid, const char* password, const char* url, const char* key) override;
             		 * @brief make connection with database using the Adapter pattern
             		 * @see Connection.h
             		 */
            		void connection(const char* ssid, const char* password, const char* url, const char* key) override;

            		/**
             		 * @fn void run(void) const override
             		 * @brief inherited by ISB::run(void) const, this method is used to run accelerometer
             		 */
            		void run(void) override;
	    		
			/**
			 * @fn SB(SB&& other)
			 */
	    		SB(SB&& other) = delete;
	    		
			/**
			 * @fn SB(const SB& other)
			 */
			SB(const SB& other) = delete;
	    		
			/**
			 * @fn SB& operator=(const SB& other)
			 */
			SB& operator=(const SB& other) = delete;
	    		
			/**
			 * @fn SB& operator=(SB&& other)
			 */
			SB& operator=(SB&& other) = delete;
	};
}

#endif
