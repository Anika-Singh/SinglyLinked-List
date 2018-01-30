//
//  main.cpp
//  LLTemplate
//
//  Created by James Shockey on 12/6/16.
//  Copyright © 2016 James Shockey. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <cmath>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "slist.h"
#include "airport.h"

using namespace std;

void simpleSortTotal(Airport* s[], int c);
double distanceEarth(double lat1d, double lon1d, double lat2d, double lon2d);

int main()
{
    ifstream infile;
    int i=0;
    char cNum[10] ;
    Airport* airportArr[13500];
    int   airportCount =0;
    //Airport* a[13500];

    infile.open ("./USAirportCodes.csv", ifstream::in);
    if (infile.is_open())
    {
        int   c=0;
        while (infile.good())
        {
            airportArr[c] = new Airport();
            infile.getline(airportArr[c]->code, 256, ',');
            infile.getline(cNum, 256, ',');
            airportArr[c]->longitude = atof(cNum);
            infile.getline(cNum, 256, '\n');
            airportArr[c]->latitude = atof(cNum);

            if ( strncmp(airportArr[c]->code, "locat", 5) == 0 )
                continue;

            if (!(c % 1000))
                cout << airportArr[c]->code << " long: " << airportArr[c]->longitude << " lat: " << airportArr[c]->latitude <<  endl;

            /*
            if (!(c % 1000))
            {
                cout << airportArr[c]->code << " long: " << airportArr[c]->longitude << " lat: " << airportArr[c]->latitude <<  endl;
                cout << airportArr[c+1]->code << endl; //" long: " << airportArr[c+1]->longitude << " lat: " << airportArr[c+1]->latitude <<  endl;
            }
            */


            i++ ;
            c++;
        }
        airportCount = c-1;
        infile.close();

         for (int c=0; c < airportCount; c++)
         {

            /*
            if (!(c % 1000))
            {
                cout << airportArr[c]->code << " long: " << airportArr[c]->longitude << " lat: " << airportArr[c]->latitude <<  endl;
                cout << airportArr[c+1]->code << " long: " << airportArr[c+1]->longitude << " lat: " << airportArr[c+1]->latitude <<  endl;
                cout <<"Distance between " << airportArr[c]->code << " and " << airportArr[c+1]->code << " is "
                  << distanceEarth( airportArr[c]->longitude, airportArr[c]->latitude , airportArr[c+1]->longitude, airportArr[c+1]->latitude) << endl;
            }
            */
            airportArr[c]->distance = distanceEarth( airportArr[c]->longitude, airportArr[c]->latitude , 30.1944, 97.67);
            //cout <<"Distance from austin for " << airportArr[c]->code << " is " << airportArr[c]->distance << endl;
         }

    }
    else
    {
        cout << "Error opening file";
    }

     simpleSortTotal(airportArr,  airportCount);

     LinkedList* list = new LinkedList();
     for (int c=0; c < airportCount; c++)
     {
        list->add(airportArr[c]);
     }


    list->display();

     //What is the farthest airport registered by the FAA from the reference point.
     // get the last element in the list
    Node *last = list->get(list->length -1 );
    if ( last != NULL )
        cout <<"Farthest airport: " << ((Airport *)(last->d))->code << ", Distance: " << ((Airport *)(last->d))->distance << endl;

    // All airports within a 100 miles of the reference point.
     for (int c=0; c < airportCount; c++)
     {
        Node *n = list->get(c);
        if ( n != NULL && ((Airport *)(n->d))->distance <= 100 )
           cout  << ((Airport *)(n->d))->code << " distinct is " << ((Airport *)(n->d))->distance << endl;
     }


}



#define pi 3.14159265358979323846
#define earthRadiusKm 6371.0

// This function converts decimal degrees to radians
double deg2rad(double deg) {
  return (deg * pi / 180);
}

//  This function converts radians to decimal degrees
double rad2deg(double rad) {
  return (rad * 180 / pi);
}


/**
 * Returns the distance between two points on the Earth.
 * Direct translation from http://en.wikipedia.org/wiki/Haversine_formula
 * @param lat1d Latitude of the first point in degrees
 * @param lon1d Longitude of the first point in degrees
 * @param lat2d Latitude of the second point in degrees
 * @param lon2d Longitude of the second point in degrees
 * @return The distance between the two points in kilometers
 */
double distanceEarth(double lat1d, double lon1d, double lat2d, double lon2d) {
  double lat1r, lon1r, lat2r, lon2r, u, v;
  lat1r = deg2rad(lat1d);
  lon1r = deg2rad(lon1d);
  lat2r = deg2rad(lat2d);
  lon2r = deg2rad(lon2d);
  u = sin((lat2r - lat1r)/2);
  v = sin((lon2r - lon1r)/2);
  return 2.0 * earthRadiusKm * asin(sqrt(u * u + cos(lat1r) * cos(lat2r) * v * v));
}




void simpleSortTotal(Airport* s[], int c)
{
    for (int i=0; i < c; i++)
    {
        int iMin = i;
        for (int j=i; j < c; j++)
        {
            if ( s[j]->distance < s[iMin]->distance )
                iMin = j;
        }

        if (iMin != i)
        {
            Airport* temp;
            temp = s[iMin];
            s[iMin] = s[i];
            s[i] = temp;
        }
    }
}

