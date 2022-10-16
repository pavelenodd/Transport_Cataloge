//чтение запросов на заполнение базы
#pragma once

#include <iostream>
#include <string>
#include <set>

#include"stat_reader.h"
#include"transport_catalogue.h"

using namespace std;

class InputReader{
private:
TransportCataloge tr_cataloge;
public:

    void GetQuery(){
        int it=0;
        cin>>it;
        while (--it>0) {
            string comand;
            cin>>comand;

            if(comand=="Stop"){
                string cash;
                getline(cin,cash);
                tr_cataloge.AddStop (cash);
            }else if(comand=="Bus"){
                if(comand.find(':')){
                    string cash;
                    getline(cin,cash);
                    int a=0;
                    a=cash.find_first_of ('-');
                    if(a>0){
                        tr_cataloge.AddBusRouteWhithFinalStop (cash);
                    }else{
                        tr_cataloge.AddBusRouteWithCircularRoute (cash);
                    }

                }else{
                    string cash;
                    getline(cin,cash);
                    tr_cataloge.GetBusRoute (cash);
                }
            }
        }
    }
};
