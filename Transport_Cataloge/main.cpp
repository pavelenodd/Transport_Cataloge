#include "input_reader.h"
#include "stat_reader.h"
#include "transport_catalogue.h"

int main() {
  TransportCatalogue tr_cataloge;
  InputRead(tr_cataloge);
  StatRead(tr_cataloge);
}
