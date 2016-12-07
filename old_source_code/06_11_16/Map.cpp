#include "Map.h"
using namespace std;

Map::Map() //ctor
{
        nbOfElements=0;
        loadMap();
}

Map::~Map()
{
        int i=0;

        for(i=0; i<nbOfElements; i++)
        {
                delete elementsOfTheMap[i];
        }
        delete [] elementsOfTheMap;
}


Lamp** Map::loadLamps()
{
        int i=0;
        //f is a FileStream Object to read informations about the lamps
        FileStream f("lamps.txt",LAMP);
        nbLamps = f.LineCounters();
        if (nbLamps==0)
                exit(-1);
        Lamp **lamps = new Lamp*[nbLamps];

        string *names=NULL;
        double *posX = NULL;
        double *posY = NULL;

        names = new string[nbLamps];
        posX = new double[nbLamps];
        posY = new double[nbLamps];

        f.fill_ObjectsInfo_Into_Arrays(nbLamps,names,posX,posY);
        for(i=0; i<nbLamps; i++)
        {
                lamps[i] = new Lamp(names[i],posX[i],posY[i]);
                nbOfElements++;
        }
        delete [] posX;
        delete [] posY;
        delete [] names;

        return lamps;
}
Provider** Map::loadProviders()
{
        int i=0;
        string *names=NULL;
        double *posX = NULL;
        double *posY = NULL;


        //f is a FileStream Object to read informations about the providers
        FileStream f("providers.txt",PROVIDER);
        nbProviders = f.LineCounters();
        if (nbProviders==0)
                exit(-1);
        Provider **providers = new Provider*[nbProviders];

        names = new string[nbProviders];
        posX = new double[nbProviders];
        posY = new double[nbProviders];

        f.fill_ObjectsInfo_Into_Arrays(nbProviders,names,posX,posY);
        for(i=0; i<nbProviders; i++)
        {
                providers[i] = new Provider(names[i],posX[i],posY[i]);
                nbOfElements++;
        }
        delete [] posX;
        delete [] posY;
        delete [] names;

        return providers;
}

TrafficLight** Map::loadTrafficLights()
{
        int i=0;
        string *names=NULL;
        double *posX = NULL;
        double *posY = NULL;

        //f is a FileStream Object to read informations about the trafficLights
        FileStream f("trafficLights.txt",PROVIDER);
        nbTrafficLight = f.LineCounters();
        if (nbTrafficLight==0)
                exit(-1);
        TrafficLight **trafficLights = new TrafficLight*[nbTrafficLight];

        names = new string[nbTrafficLight];
        posX = new double[nbTrafficLight];
        posY = new double[nbTrafficLight];


        f.fill_ObjectsInfo_Into_Arrays(nbTrafficLight,names,posX,posY);
        for(i=0; i<nbTrafficLight; i++)
        {
                trafficLights[i] = new TrafficLight(names[i],posX[i],posY[i]);
                nbOfElements++;
        }
        delete [] posX;
        delete [] posY;
        delete [] names;

        return trafficLights;
}

void Map::loadMap()
{
        int i,j;

        //regroupper tous les elements:
        Lamp **lamps= loadLamps();
        Provider **providers=loadProviders();
        TrafficLight **trafficLights=loadTrafficLights();
        elementsOfTheMap = new Node*[nbOfElements];

        i=j=0;
        for(i=0; i<nbLamps; i++)
        {
                elementsOfTheMap[j]=lamps[i];
                j++;
        }

        for(i=0; i<nbProviders; i++)
        {
                elementsOfTheMap[j]=providers[i];
                j++;
        }

        for(i=0; i<nbTrafficLight; i++)
        {
                elementsOfTheMap[j]=trafficLights[i];
                j++;
        }

        delete [] lamps;
        delete [] providers;
        delete [] trafficLights;
}

void Map::addNode(Node *n)
{
        if(n==NULL)
                return;
        int i=0;
        nbOfElements++;
        Node **temp = new Node*[nbOfElements];
        for(i=0; i<nbOfElements - 1; i++)
        {
                temp[i] = elementsOfTheMap[i];
        }
        delete [] elementsOfTheMap;
        elementsOfTheMap = new Node*[nbOfElements];
        for(i=0; i<nbOfElements - 1; i++)
        {
                elementsOfTheMap[i] = temp[i];
        }

        elementsOfTheMap[i] = n;
        delete [] temp;
}

Node** Map::getNodes()
{
        return elementsOfTheMap;
}


int Map::getNumOfElements()
{
        return nbOfElements;
}


void Map::PrintMap()
{
        int i;
        for(i=0; i< nbOfElements; i++ )
        {
                cout << "---------------------------------------------------"<<endl;
                cout << "ID : " << elementsOfTheMap[i]->getId() <<" | Name : " << elementsOfTheMap[i]->getName() << " | Position : "<<"("<<elementsOfTheMap[i]->getLocationX() << "," << elementsOfTheMap[i]->getLocationY() << ")" <<endl;
                cout << "available Nodes : " << endl;
                elementsOfTheMap[i]->printAvailableNodes();
        }
}
