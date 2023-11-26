#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>

enum VehicleType {
    VT_Car,
    VT_Plane,
    VT_Boat
};

class Vehicle{

public:
	
	Vehicle(){/*std::cout<<"Creating vehicle"<<std::endl;*/}
	virtual ~Vehicle(){} ;

	virtual void PrintVehicleInfo() = 0;
};

class Car : public Vehicle{

public:
	
	Car(){/*std::cout<<"Creating car"<<std::endl;*/}
	~Car(){/*std::cout<<"Deleting car"<<std::endl;*/}
	
	void PrintVehicleInfo() 
	{
		//std::cout<<"Im a car"<<std::endl;
	}
};

class Plane : public Vehicle{

public:
	
	Plane(){std::cout<<"Creating car"<<std::endl;}

	void PrintVehicleInfo()
	{
		std::cout<<"Im a plane"<<std::endl;
	}
};

class Boat : public Vehicle{

public:

	Boat(){/*std::cout<<"Creating boat"<<std::endl;*/}
	~Boat(){/*std::cout<<"Deleting boat"<<std::endl;*/}
	void PrintVehicleInfo()
	{
		std::cout<<"Im a boat"<<std::endl;
	}
};

class Factory{

public:

	Factory(){};
	~Factory(){};

	Vehicle* CreateVehicle(VehicleType VehicleType)
    {
        if (VehicleType == VT_Car)
            {	
            	Vehicle* tmp = new Car();
            	return tmp;
    		}
        else if (VehicleType == VT_Plane)
            {	
            	Vehicle* tmp = new Plane();
            	return tmp;
    		}
        else if (VehicleType == VT_Boat)
            {	
            	Vehicle* tmp = new Boat();
            	return tmp;
    		}
        else
            return nullptr;
    }

};

class Client{
public:
	Client(){
		iCurrentObjectIndex = 0;
		iTotalMemoryAllocated = 0;
	};
	~Client(){std::cout<<"Deleting client"<<std::endl;};

	void BuildVehicle(VehicleType vehicleType)
    {
        Factory* vf = new Factory();
        vehicles.push_back(vf->CreateVehicle(vehicleType));
 		iCurrentObjectIndex++;

        delete vf;
    }

    void IterateOverElements()
    {
    	for(auto & element : vehicles)
    	{
      		element->PrintVehicleInfo();
      		std::cout<<&element<<std::endl;
    	}

    	std::cout<<sizeof(vehicles)<<std::endl;
    }

    void DeleteElements()
    {
    	for(auto & element : vehicles)
    	{
      		delete element;
    	}
    	vehicles.clear();
    }

    void CalculateMemory()
    {
    	for(auto & element : vehicles)
    	{
      		iTotalMemoryAllocated+=sizeof(element);
    	}
    	iTotalMemoryAllocated+=sizeof(vehicles);

    	std::cout<<iTotalMemoryAllocated<<std::endl;
    }


    void SwapElements()
    {
    	std::swap(vehicles[1], vehicles[2]);
    }
private:
	int iCurrentObjectIndex;
	int iTotalMemoryAllocated;
	std::vector<Vehicle*> vehicles;
};