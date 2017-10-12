#include "Terrain.h"



#define _ROWS 128
#define _COLUMNS 512

using Row = std::vector<char>;
using Matrix = std::vector<Row>;

Terrain::Terrain() {
  Matrix terrain(_COLUMNS, Row(_ROWS));
}

