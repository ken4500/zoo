//
//  NetworkManagerDelegate.h
//  zoo
//
//  Created by Daniel Haaser on 5/26/15.
//
//

#ifndef __Zoo__NetworkManagerDelegate__
#define __Zoo__NetworkManagerDelegate__

enum class ConnectionState
{
    NOT_CONNECTED,
    CONNECTING,
    CONNECTED
};

class NetworkManagerDelegate
{
public:
    virtual void receivedData(const void* data, unsigned long length) = 0;
    virtual void stateChanged(ConnectionState state) = 0;
};

#endif /* defined(__Zoo__NetworkManagerDelegate__) */
