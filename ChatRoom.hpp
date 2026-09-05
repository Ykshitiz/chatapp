#include<iostream>
#include"message.hpp"
#include<set>
#include<memory>
#include<sys/socket.h>
#include<unistd.h>
#include<boost/asio.hpp>


#ifndef CHATROOM_HPP
#define CHATROOM_HPP

using boost::asio::ip::tcp;

class Participant{
    public:
    virtual void deliver(Message &message) = 0;
    virtual void write(Message &message) =0 ;
    virtual ~Participant()=delete;
        

};

#endif