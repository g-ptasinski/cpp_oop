#include <memory>
#include "factory.h"
 
int main()
{

    Client *client = new Client();

    for(int i = 0; i<10 ; i++)
    {
        client->BuildVehicle(VT_Car);
    }

    client->IterateOverElements();

    delete client;

    return 0;
}

