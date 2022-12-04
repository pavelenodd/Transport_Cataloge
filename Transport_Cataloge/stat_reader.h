// напишите решение с нуля
// stat_reader.h, stat_reader.cpp — чтение запросов на вывод и сам вывод;
#pragma once
#include <iostream>
#include <string>

#include "transport_catalogue.h"

class StatReader {
 private:
  TransportCatalogue tr_cataloge_;

 public:
  StatReader(TransportCatalogue L_tr_cataloge) {
    tr_cataloge_ = L_tr_cataloge;
    StatRead();
  }
  void StatRead() {
    int i = 0;
    string comand;
    int bus_number;
    for (cin >> i; i > 0; --i) {
      cin >> comand;
      if (comand == "Bus") {
        cin >> bus_number;
        tr_cataloge_.GetRoute(bus_number);
      }
    }
  }
};
