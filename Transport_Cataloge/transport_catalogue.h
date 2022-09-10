// напишите решение с нуля
// код сохраните в свой git-репозиторий

#include <deque>
#include <string>
#include <set>
#include <unordered_set>
#include <iostream>

#include "geo.h"
using namespace std;


struct StopInfo{
    string name;//назв.остановки
    double latitude;//широта
    double longitude;//долгота
};
struct Route{
    int bus_number;// № маршрута
    deque <StopInfo> stops;//список остановок
};

class TransportCataloge{
private:
    Route route_;
public:
    void AddRoute(int number){
        route_.bus_number=number;
    }

    void AddBusStop(const string &L_bus_name,const double &L_latitude,const double &L_longitude){
        StopInfo L_stop_info;
        L_stop_info.latitude=L_latitude;
        L_stop_info.longitude=L_longitude;
        L_stop_info.name=L_bus_name;
        route_.stops.push_back(L_stop_info);
    }
    void GetRoute(int number_route){
        if(number_route==route_.bus_number){
            double L_length=0;
            unordered_set <string> uniq_stop;
            Coordinates last_coordinates;
            Coordinates next_coordinates;

            cout<<"Bus "s<<number_route<<": "s;
            for(int i=0;route_.stops.size()>i;++i){
                if(i!=0){
                    last_coordinates.lat=route_.stops[i-1].latitude;
                    last_coordinates.lng=route_.stops[i-1].longitude;
                    next_coordinates.lat=route_.stops[i].latitude;
                    next_coordinates.lng=route_.stops[i].longitude;
                }
                L_length=+ComputeDistance(last_coordinates,next_coordinates);
            }
            cout<<route_.stops.size()<<" stops on route, "s<<uniq_stop.size()<<" unique stops, "s<<L_length<<" route length"s<<endl;
        }
    }
};

/*Bus 256: 6 stops on route, 5 unique stops, 4371.02 route length*/
