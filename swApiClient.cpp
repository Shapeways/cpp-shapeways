#include <stdlib.h>
#include <string.h>
#include <iostream>
#include "swApiClient.h"

using namespace std;
using json = nlohmann::json;

/* Helper Functions */
struct curl_slist * swApiClient::SetAuthHeader() {
  char *headerStr = (char*)malloc(250);
  strcpy(headerStr, "Authorization: Bearer ");
  strcat(headerStr, this->accessToken.c_str());
  cout << headerStr << endl;
  struct curl_slist *headers = NULL;
  headers = curl_slist_append(headers, headerStr);
  return headers;
}

static size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp)
{
    ((string*)userp)->append((char*)contents, size * nmemb);
    return size * nmemb;
}

/*
====================
swApiClient Constructor

  Constructs swApiClient
====================
*/
swApiClient::swApiClient( string cKey, string cSecret) {
    consumerKey = cKey;
    consumerSecret = cSecret;
    accessToken = "";
}

/*
====================
swApiClient Authorize

  Connect to the Shapeways API using oauth2
====================
*/
void swApiClient::Authorize() {

  CURL *curl;
  CURLcode res;
  string readBuffer;

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
    if (res != 0) {
      throw runtime_error(curl_easy_strerror(res));
    }
    curl_easy_cleanup(curl);
    json j = json::parse(readBuffer);
    this->accessToken = j["access_token"];
  }
}

/*
====================
swApiClient GetMaterials

  Connect to the Shapeways API using oauth2
====================
*/
string swApiClient::GetMaterials() {
  CURL *curl;
  CURLcode res;
  string readBuffer;
  curl = curl_easy_init();
  struct curl_slist *headers = NULL;
  if(curl) {

    headers = this->SetAuthHeader();
    curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
    curl_easy_setopt(curl, CURLOPT_URL, "https://api.shapeways.com/materials/v1");
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
    curl_easy_setopt(curl, CURLOPT_HTTPGET, 1L);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);
    res = curl_easy_perform(curl);
    if (res != 0) {
      string error = curl_easy_strerror(res);
      cout << error << endl;
      cout << readBuffer << endl;
      throw runtime_error(error);
    }
    curl_slist_free_all(headers);
    curl_easy_cleanup(curl);
  }
  json j = json::parse(readBuffer);
  cout << j << endl;
  return j.dump();
}
