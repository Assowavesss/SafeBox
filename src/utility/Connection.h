/**
 * @file Connection.h
 * @brief File which contain the implementation of Connection class which allow to make connection with database
 * @headerfile 
 * @date 2022
 * @see SB.h
 */
#ifndef CONNECTION_H
#define CONNECTION_H

namespace savebox
{
    /**
     * @class Connection
     * @brief Used for making connection with database
     */
    class Connection
    {
        private:
            
            /**
             * @var ssid_
             * @brief name of network
             */
            const char* ssid_;
            
            /**
             * @var password_
             * @brief password of network
             */
            const char* password_;
            
            /**
             * @var url_
             * @brief name of url of database
             */
            const char* url_;
            
            /**
             * @var key_db_
             * @brief password of database
             */
            const char* key_db_;

        public:
            
            /**
             * @fn Connection(const char *ssid, const char *password, const char *url, const char* key_db)
             * @brief just set variable in argument to attributes
             */
            Connection(const char *ssid, const char *password, const char *url, const char* key_db);

            /**
             * @fn void connection(void)
             * @brief to make a connection with database
             * @see SB::connection(void)
             */
            void connection(void);
     };
}

#endif
