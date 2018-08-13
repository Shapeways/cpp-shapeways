#include <iostream>
#include <string>
#include "swApiClient.h"

static size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp)
{
    ((std::string*)userp)->append((char*)contents, size * nmemb);
    return size * nmemb;
}

int main(void)
{
  swApiClient * client = new swApiClient("CLIENT_KEY", "CLIENT_SECRET");
  client->Authorize();
  return 0;
}
