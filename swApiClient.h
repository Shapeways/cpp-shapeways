#ifndef SWAPICLIENT_H
#define SWAPICLIENT_H

#include <iostream>
#include <string>
#include <curl/curl.h>

/*
===============================================================================

    This is a client for the Shapeways API.  More information available at
    http://developers.shapeways.com/docs

===============================================================================
*/
class swApiClient
{
    private:
        static std::string      BASE_URL;
        static std::string      API_VERSION;

        std::string             consumerKey;
        std::string             consumerSecret;
        std::string             callbackUrl;
        std::string             oauthToken;
        std::string             oauth_secret;

        swApiClient() {}
        std::string Url( std::string Path ); // URL generator

    public:
        swApiClient( std::string consumerKey, std::string consumerSecret, std::string callbackUrl);
        void Connect(); // Connect and auth

};

#endif
