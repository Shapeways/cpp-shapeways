#include <iostream>
#include <string>
#include "swApiClient.h"

int main(void)
{
  swApiClient * client = new swApiClient("CLIENT_KEY", "CLIENT_SECRET");
  client->Authorize();
  client->GetMaterials();
}
