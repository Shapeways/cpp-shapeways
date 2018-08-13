#include "swApiClient.h"
#include <stdlib.h>
#include <string.h>
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
swApiClient::swApiClient( std::string cKey, std::string cSecret) {
    consumerKey = cKey;
    consumerSecret = cSecret;
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

/*
====================
swApiClient WriteCallback

  Helper function to write down a readbuffer to a string
====================
*/
static size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp)
{
    ((std::string*)userp)->append((char*)contents, size * nmemb);
    return size * nmemb;
}

/*
====================
swApiClient Authorize

  Connect to the Shapeways API using oauth
====================
*/
void swApiClient::Authorize() {

  CURL *curl;
  CURLcode res;
  std::string readBuffer;

  // prepare auth payload
  char *postData = (char*)malloc(250);
  strcpy(postData, "grant_type=client_credentials&client_id=");
  strcat(postData, this->consumerKey.c_str());
  strcat(postData, "&client_secret=");
  strcat(postData, this->consumerSecret.c_str());

  curl = curl_easy_init();
  if(curl) {
    curl_easy_setopt(curl, CURLOPT_URL, "https://api.shapeways.com/oauth2/token");
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
    curl_easy_setopt(curl, CURLOPT_POSTFIELDS, postData);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);
    res = curl_easy_perform(curl);
    std::cout << res << std::endl;
    curl_easy_cleanup(curl);

    std::cout << readBuffer << std::endl;

  }

}
