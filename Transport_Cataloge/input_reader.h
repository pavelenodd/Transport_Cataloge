// напишите решение с нуля
// input_reader.h, input_reader.cpp — чтение запросов на заполнение базы;
#pragma once
#include <algorithm>
#include <iostream>
#include <string>

#include "stat_reader.h"
#include "transport_catalogue.h"

using namespace std;
class InputReader {
 private:
  TransportCatalogue tr_cataloge_;

 public:
  InputReader(TransportCatalogue L_tr_cataloge) {
    tr_cataloge_ = L_tr_cataloge;
  }
  ~InputReader() {}

  void InputRead() {
    string query;
    string comand;
    cin >> comand;
    getline(cin, query);
    if (comand == "Stop") {
      tr_cataloge_.AddBusStop(query);
    } else if (comand == "Bus") {
      if (query.back() != query.find('-')) {
        tr_cataloge_.AddBusLinerRoute(query);
      } else if (query.back() != query.find('>')) {
        tr_cataloge_.AddBussCircularRoute(query);
      } else {
        tr_cataloge_.GetRoute(query);
      }
    }
  }
};
