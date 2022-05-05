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
            
            float x_out;
            
            float y_out;
            
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
             * @fn SB(void)
             * @brief make a connection with acceleromter and initialize the connection object conn_ to nullptr
             */
            SB(void);
            
            /**
             * @fn ~SB(void)
             * @brief destruct the connection object conn_ and set it to nullptr
             */
            ~SB(void);
            
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
    };
}

#endif
