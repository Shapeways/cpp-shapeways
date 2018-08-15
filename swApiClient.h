#ifndef SWAPICLIENT_H
#define SWAPICLIENT_H

#include <iostream>
#include <string>
#include <curl/curl.h>
#include "json.hpp"


/*
===============================================================================

    This is a sample client for the Shapeways API.  It is intended to
    illustrate the capabilities of and patterns for interacting with
    the API, not to provide a full reference client.

    We welcome any pull requests to improve or further implement the API
    for the community to use.

    More information available at
    http://developers.shapeways.com/docs

===============================================================================
*/
class swApiClient
{
    private:
        std::string             consumerKey;
        std::string             consumerSecret;
        std::string             accessToken;

        struct curl_slist * SetAuthHeader();

    public:
        swApiClient( std::string consumerKey, std::string consumerSecret );
        void Authorize();
        std::string GetMaterials();
        std::string UploadModel( std::string modelFilePath );
};

#endif
