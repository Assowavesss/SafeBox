/**
 * @file ISB.h
 * @brief Interface of the SaveBox
 * @headerfile 
 * @date 2022
 * @see ISB.h
 * @see SB.h 
 * @see Connection.h
 */
#ifndef ISB_H
#define ISB_H 

/**
 * @namespace savebox
 * @brief namespace which contain all class for savebox
 * @details 
 * We use the Adapter design pattern with class implemented in savebox namespace
 * The Interface ISB are inherited by SB
 */
namespace savebox
{
    /**
     * @interface ISB
     * @brief Interface which describe the protoype of savebox
     * @see SB 
     */
    class ISB 
    {
        public:
            
            /**
             * @fn virtual ~ISB(void)
             * @brief virtual Destructor which will be overridden by SB 
             */
             virtual ~ISB(void) {}

            /**
             * @fn  virtual void connection(const char* ssid, const char* password, const char* url, const char* key) const
             * @brief method of savebox to make a connectio with database
             */
            virtual void connection(const char* ssid, const char* password, const char* url, const char* key) = 0;
            
            /**
             * @fn virtual void run(void) const
             * @brief method of savebox to use accelerometer
             */
             virtual void run(void) = 0;

        private:

            /**
             * @fn virtual bool accident(void)
             * @brief method of savebox to see if there is an accident or not
             */
            virtual bool accident(void) = 0;
            
            /**
             * @fn virtual void sendData(void) const
             * @brief method of savebox to send data of passenger is there is an accident
             */
            virtual void sendData(void) = 0;
    };
}

#endif
