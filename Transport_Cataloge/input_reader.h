//чтение запросов на заполнение базы
#pragma once

#include <iostream>
#include <set>
#include <string>

#include "stat_reader.h"
#include "transport_catalogue.h"

using namespace std;

class InputReader {
 private:
  TransportCataloge tr_cataloge;

 public:
  void GetQuery() {
    int it = 0;
    cin >> it;
    while (it-- > 0) {
      string comand;
      cin >> comand;
      string cash;
      getline(cin, cash);

      if (comand == "Stop") {
        tr_cataloge.AddStop(cash);
      } else if (comand == "Bus") {
        if (comand.find(':')) {
          int a = 0;
          a = cash.find_first_of('-');
          if (a > 0) {
            tr_cataloge.AddBusRouteWhithFinalStop(cash);
          } else {
            tr_cataloge.AddBusRouteWithCircularRoute(cash);
          }

        } else {
          tr_cataloge.GetBusRoute(cash);
        }
      }
    }
  }
};
