#ifndef SWAPICLIENT_H
#define SWAPICLIENT_H

#include <iostream>
#include <string>
#include <curl/curl.h>
#include "json.hpp"


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

        swApiClient() {}
        std::string Url( std::string Path ); // URL generator

    public:
        swApiClient( std::string consumerKey, std::string consumerSecret);
        void Authorize();

};

#endif
