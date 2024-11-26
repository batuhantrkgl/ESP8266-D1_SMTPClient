#ifndef SMTPCLIENT_H
#define SMTPCLIENT_H

#include <ESP8266WiFi.h>
#include <WiFiClientSecure.h>
#include <FS.h>

class SMTPClient {
private:
    WiFiClientSecure client;
    String server;
    uint16_t port;
    String username;
    String password;

    bool sendCommand(const String& command, const String& expectedResponse);
    String readResponse();
    String encodeFileToBase64(const String& filePath); // New method to encode file

public:
    SMTPClient();
    bool begin(const String& server, uint16_t port);
    void setCredentials(const String& username, const String& password);
    bool sendMail(const String& sender, const String& recipient, const String& subject, const String& message);
    bool sendMailWithAttachment(const String& sender, const String& recipient, const String& subject, const String& message, const String& filePath); // New method to send mail with attachment
};

#endif