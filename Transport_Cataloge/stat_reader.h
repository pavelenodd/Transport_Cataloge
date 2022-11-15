// напишите решение с нуля
// stat_reader.h, stat_reader.cpp — чтение запросов на вывод и сам вывод;
#pragma once
#include <iostream>

#include "transport_catalogue.h"

class StatReader {
 private:
  TransportCatalogue tr_cataloge_;

 public:
  StatReader(TransportCatalogue L_tr_cataloge) { tr_cataloge_ = L_tr_cataloge; }
  ~StatReader() {}
};
