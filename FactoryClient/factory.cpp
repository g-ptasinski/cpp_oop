#include <memory>
#include "factory.h"


int main()
{

    Client* client = new Client();

    for(int i = 0; i<100000000; i++)
    {
        if(i%2==0)
            client->BuildVehicle(VT_Car);
        else
            client->BuildVehicle(VT_Boat);
    }

    client->DeleteElements();

    delete client;


    return 0;
}

