#include "swApiClient.h"
#include <iostream>


/* static member init */
std::string swApiClient::BASE_URL = "http://api.shapeways.com";
std::string swApiClient::API_VERSION = "v1";

/*
====================
swApiClient Constructor

  Constructs swApiClient
====================
*/
swApiClient::swApiClient( std::string cKey, std::string cSecret, std::string cbUrl) {
    consumerKey = cKey;
    consumerSecret = cSecret;
    callbackUrl = cbUrl;
}

/*
====================
swApiClient Url

  Generate the full URL for an API path 
====================
*/
std::string swApiClient::Url( std::string path ) {
    if ( path[0] != '/' ) {
        path = '/' + path;
    }
    if ( path[path.length() - 1] != '/' ) {
        path += '/';
    }

    return BASE_URL + path + API_VERSION;
}

