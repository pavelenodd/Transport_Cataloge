// напишите решение с нуля
// input_reader.h, input_reader.cpp — чтение запросов на заполнение базы;
#pragma once
#include <algorithm>
#include <iostream>
#include <string>

#include "stat_reader.h"
#include "transport_catalogue.h"

using namespace std;
void InputRead(TransportCatalogue& tr_cataloge) {
  int i = 0;
  for (cin >> i; i > 0; --i) {
    string query;
    string comand;
    cin >> comand;
    getline(cin, query);
    if (comand == "Stop") {
      tr_cataloge.AddBusStop(query);
    } else if (comand == "Bus") {
      if (count(query.begin(), query.end(), '-')) {
        tr_cataloge.AddBusLinerRoute(query);
      } else if (count(query.begin(), query.end(), '>')) {
        tr_cataloge.AddBussCircularRoute(query);
      }
    }
  }
}