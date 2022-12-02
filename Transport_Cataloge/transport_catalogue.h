
// transport_catalogue.h, transport_catalogue.cpp — класс транспортного
// справочника; Он должен иметь методы для выполнения следующих задач
//: добавление маршрута в базу, добавление остановки в базу,поиск маршрута по
//: имени,
//поиск остановки по имени,получение информации о маршруте.Методы
//классаTransportCatalogue не должны выполнять никакого ввода -вывода.
// Tolstopaltsevo: 55.611087, 37.208290
#pragma once

#include <iostream>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

using namespace std;

struct Coordinate {
  double lat;
  double lng;
};

struct BusRoute {
  int bus_nuber;
  vector<string> bus_stops;
};
struct StopCoordinate {
  string StopName;
  Coordinate coordinate;
};
class TransportCatalogue {
 private:
  //список остановок
  vector<StopCoordinate> stop_coordinates_;
  //список маршрутов
  vector<BusRoute> bus_route_;

 public:
  //добавить остановку
  void AddBusStop(string &s) {
    StopCoordinate L_stop_coordinate;
    string L_stopname;
    string L_lat;
    string L_lng;
    auto ptr = s.begin() + 1;
    for (; ptr != s.end(); ++ptr) {
      if (*ptr == ':') {
        L_stop_coordinate.StopName = L_stopname;
        ptr = ptr + 2;
        break;
      } else {
        L_stopname.push_back(*ptr);
      }
    }
    for (; ptr != s.end(); ++ptr) {
      if (*ptr == ',') {
        L_stop_coordinate.coordinate.lat = stod(L_lat);
        ptr = ptr + 2;
        break;
      } else {
        L_lat.push_back(*ptr);
      }
    }
    for (; ptr != s.end() + 1; ++ptr) {
      if (ptr == s.end()) {
        L_stop_coordinate.coordinate.lng = stod(L_lng);
        break;
      } else {
        L_lng.push_back(*ptr);
      }
    }
    stop_coordinates_.push_back(L_stop_coordinate);
  }
  //добавить круговой маршрут автобусу
  void AddBussCircularRoute(string &s) {
    BusRoute L_bus_route;
    auto ptr = s.begin() + 1;
    for (string cash; ptr != s.end(); ++ptr) {
      if (*ptr == ':') {
        L_bus_route.bus_nuber = stoi(cash);
        ptr = ptr + 2;
        break;
      } else {
        cash.push_back(*ptr);
      }
    }
    for (string cash; ptr != s.end() + 1; ++ptr) {
      if (*(ptr + 1) == '>') {
        L_bus_route.bus_stops.push_back(cash);
        cash.clear();
        ptr = ptr + 2;
      } else if (ptr == s.end()) {
        L_bus_route.bus_stops.push_back(cash);
        break;
      } else {
        cash.push_back(*ptr);
      }
    }
    bus_route_.push_back(L_bus_route);
  }
  //добавть линейный маршрут автобусу
  void AddBusLinerRoute(string &s) {
    BusRoute L_bus_route;
    vector<string> L_bus_stops;
    auto ptr = s.begin() + 1;
    for (string cash; ptr != s.end(); ++ptr) {
      if (*ptr == ':') {
        L_bus_route.bus_nuber = stoi(cash);
        ptr = ptr + 2;
        break;
      } else {
        cash.push_back(*ptr);
      }
    }
    for (string cash; ptr != s.end() + 1; ++ptr) {
      if (*(ptr + 1) == '-') {
        L_bus_stops.push_back(cash);
        cash.clear();
        ptr = ptr + 2;
      } else if (ptr == s.end()) {
        L_bus_stops.push_back(cash);
        break;
      } else {
        cash.push_back(*ptr);
      }
    }
    for (int i = 0; i > L_bus_stops.size(); ++i) {
      
    }
  }
  //поиск автобуса
  void GetRoute(string &s) {}
};
