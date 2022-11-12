//класс транспортного справочника
#pragma once

#include <deque>
#include <iostream>
#include <set>
#include <string>
#include <unordered_set>

#include "geo.h"

using namespace std;

struct StopsInfo {
  string name;           //назв.остановки
  double latitude = 0;   //широта
  double longitude = 0;  //долгота
};
struct Route {
  int bus_number;       // № маршрута
  deque<string> stops;  //список остановок
};

class TransportCataloge {
 private:
  deque<Route> route_;  //маршруты
  deque<StopsInfo> all_stops_;  //список всех известных остановок
 public:

  // создание кругового маршрута
  void AddBusRouteWithCircularRoute(string &L_stop_info) {
    string cash;
    Route L_route;
    for (int i = 0; L_stop_info.size() + 1 > i; ++i) {
      char ch = L_stop_info[i];
      if (ch == ' ' && cash.empty()) {
        continue;
      } else if (ch == ':' && !cash.empty()) {
        L_route.bus_number = stoi(cash);
        cash.clear();
        continue;
      } else if (ch == '>') {
        L_route.stops.push_back(cash);
        cash.clear();
        continue;
      } else if (L_stop_info.size() == i) {
        L_route.stops.push_back(cash);
        route_.push_back(L_route);
        cash.clear();
        break;
      }
      cash.push_back(ch);
    }
  }
  //создание маршрута с конечой остановкой
  void AddBusRouteWhithFinalStop(string &L_stop_info) {
    string cash;
    Route L_route;
    for (int i = 0; L_stop_info.size() + 1 > i; ++i) {
      char ch = L_stop_info[i];
      if (ch == ' ' && cash.empty()) {
        continue;
      } else if (ch == ':' && !cash.empty()) {
        L_route.bus_number = stoi(cash);
        cash.clear();
        continue;
      } else if (ch == '-') {
        L_route.stops.push_back(cash);
        cash.clear();
        continue;
      } else if (L_stop_info.size() == i) {
        L_route.stops.push_back(cash);
        route_.push_back(L_route);
        cash.clear();
        break;
      }
      cash.push_back(ch);
    }
  }
  
  //добавление остановок в список
  void AddStop(string &L_stop_info) {
    string cash;
    StopsInfo L_stop;
    for (int i = 0; L_stop_info.size() + 1 > i; ++i) {
      char ch = L_stop_info[i];
      if (ch == ' ' && cash.empty()) {
        continue;
      } else if (ch == ':' && !cash.empty()) {
        L_stop.name = cash;
        cash.clear();
        continue;
      } else if (ch == ',' && !cash.empty()) {
        L_stop.latitude = stod(cash);
        cash.clear();
        continue;
      } else if (L_stop_info.size() == i) {
        L_stop.longitude = stod(cash);
        cash.clear();
        all_stops_.push_back(L_stop);
        break;
      }

      cash.push_back(ch);
    }
  }
  //получение значений маршрута
  void GetBusRoute(string &L_stop_info) {}
};
