
// transport_catalogue.h, transport_catalogue.cpp — класс транспортного
// справочника; Он должен иметь методы для выполнения следующих задач
//: добавление маршрута в базу, добавление остановки в базу,поиск маршрута по
//: имени,
//поиск остановки по имени,получение информации о маршруте.Методы
//классаTransportCatalogue не должны выполнять никакого ввода -вывода.

#pragma once

#include <string>
#include <utility>
#include <vector>

using namespace std;

struct Coordinate {
  double lat;
  double lng;
};

struct StopCoordinate {
  string StopName;
  Coordinate coordinate;
};
class TransportCatalogue {
 private:
  //список остановок
  vector<StopCoordinate> stop_coordinates_;

 public:
  TransportCatalogue() {}
  ~TransportCatalogue() {}
  //добавить остановку
  void AddBusStop(string &s) {
    StopCoordinate L_stop_coordinate;
    string L_stopname;
    string L_lat;
    string L_lng;
    auto ptr = s.begin() + 1;

    for (; ptr != s.end(); ++ptr) {
      if (*ptr != ':') {
        L_stopname.push_back(*ptr);
      } else {
        ++ptr;
        break;
      }
    }
    for (++ptr; ptr != s.end(); ++ptr) {
      if (*ptr != ',') {
        L_lat.push_back(*ptr);
      } else {
        ++ptr;
        break;
      }
    }
    for (++ptr; ptr != s.end(); ++ptr) {
      L_lng.push_back(*ptr);
    }
    L_stop_coordinate.StopName = L_stopname;
    L_stop_coordinate.coordinate.lat = stod(L_lat);
    L_stop_coordinate.coordinate.lng = stod(L_lng);
    stop_coordinates_.push_back(L_stop_coordinate);
  }
  //добавить круговой маршрут автобусу
  void AddBussCircularRoute(string &s) {}
  //добавть линейный маршрут автобусу
  void AddBusLinerRoute(string &s) {}
  //поиск автобуса
  void GetRoute(string &s) {}
};
