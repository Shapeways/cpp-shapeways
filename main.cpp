#include <iostream>
#include <string>
#include "swApiClient.h"

int main(void)
{
  // Insert your Ouath2 Client ID and Client Secrets here.
  // You can find them at https://developers.shapeways.com/manage-apps
  swApiClient *client = new swApiClient("CLIENT_ID", "CLIENT_SECRET");
  client->Authorize();
  // client->GetMaterials();
}
