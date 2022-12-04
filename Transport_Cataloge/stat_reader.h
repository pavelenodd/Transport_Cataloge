// напишите решение с нуля
// stat_reader.h, stat_reader.cpp — чтение запросов на вывод и сам вывод;
#pragma once
#include <iostream>
#include <string>

#include "transport_catalogue.h"

using namespace std;

void StatRead(TransportCatalogue const &tr_cataloge) {
  int i = 0;
  string comand;
  int bus_number;
  for (cin >> i; i > 0; --i) {
    cin >> comand;
    if (comand == "Bus") {
      cin >> bus_number;
      tr_cataloge.GetRoute(bus_number);
    }
  }
}
