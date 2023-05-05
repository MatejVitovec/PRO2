#ifndef OUTPUTVTK_HPP
#define OUTPUTVTK_HPP

#include "Mesh/Mesh.hpp"
#include "Field.hpp"
#include "Compressible.hpp"
#include <string>

void outputVTK(std::string filename, const Mesh& m, const Field<Compressible>& u);

#endif //OUTPUT_HPP