/*
 * WebSocket.h
 *
 Copyright (c) 2020 Michael Neuweiler

 Permission is hereby granted, free of charge, to any person obtaining
 a copy of this software and associated documentation files (the
 "Software"), to deal in the Software without restriction, including
 without limitation the rights to use, copy, modify, merge, publish,
 distribute, sublicense, and/or sell copies of the Software, and to
 permit persons to whom the Software is furnished to do so, subject to
 the following conditions:

 The above copyright notice and this permission notice shall be included
 in all copies or substantial portions of the Software.

 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
 IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY
 CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
 TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
 SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

 */


#ifndef WEBSOCKET_H_
#define WEBSOCKET_H_

#include <ESPAsyncWebServer.h>
#include "Configuration.h"
#include "Logger.h"

class WebSocketObserver
{
public:
    virtual void event(String message);
};

class WebSocket
{
public:
    WebSocket();
    virtual ~WebSocket();
    void init(AsyncWebServer *server);
    void loop();
    void send(String data);
    void onWebsocketEvent(AsyncWebSocket *server, AsyncWebSocketClient *client, AwsEventType type, void *arg, uint8_t *data, size_t len);
    void subscribe(WebSocketObserver *observer);
    bool isConnected();

private:
    AsyncWebSocket *webSocketHandler;
    WebSocketObserver *observer;
    bool connected;
};

extern WebSocket webSocket;

#endif /* WEBSOCKET_H_ */
