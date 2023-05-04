#include "outputVTK.hpp"
#include <fstream>

int calculateCellNodeSize(const Mesh& mesh)
{
    const std::vector<std::shared_ptr<Cell>>& cellList = mesh.getCellList();
    int num = 0;

    for (int i = 0; i < cellList.size(); i++)
    {
        num += (1 + cellList[i]->nodesIndex.size());
    }
    
    return num;
}

void outputVTK(std::string filename, const Mesh& mesh, const Field<Compressible>& w)
{
    const std::vector<Vector3>& nodeList = mesh.getNodeList();
    const std::vector<std::shared_ptr<Cell>>& cellList = mesh.getCellList();

    int cellSize = mesh.getCellsSize();

	std::ofstream f;
	f.open(filename, std::ios::out);
	
	f << "# vtk DataFile Version 1.0\n";
	f << "unstructured grid\n";
	f << "ascii\n";
	f << "DATASET UNSTRUCTURED_GRID\n";
	
	f << "points " << mesh.getNodesSize() << " float\n";
	
	for (int i = 0; i < mesh.getNodesSize(); i++)
    {
		f << nodeList[i] << "\n";
	}
	
	f << "cells " << cellSize << " " << calculateCellNodeSize(mesh) << "\n";
	
	for (int i = 0; i < cellSize; i++)
    {
		f << *cellList[i] << "\n";
	}
	
	f << "cell_types " << cellSize << "\n";
	
	for (int i = 0; i < cellSize; i++)
    {
		f << cellList[i]->getVtkType() << "\n";
	}
	
	f << "CELL_DATA " << cellSize << "\n";
 	f << "SCALARS rho float\n"; 
	f << "LOOKUP_TABLE default\n";

    for (int i = 0; i < cellSize; i++)
    {
		f << w[i].density() << "\n";
	}

 	//f << "SCALARS |u| float\n"; 
	//f << "LOOKUP_TABLE default\n";

    //for (int i=0; i<m.nc; i++) {
	//	f << u[i].u().norm() << "\n";
	//}		

	//f << "VECTORS u float\n"; 
 	f << "SCALARS u float 3\n"; 
	f << "LOOKUP_TABLE default\n";

    for (int i = 0; i < cellSize; i++)
    {
		f << w[i].velocityU() << " " << w[i].velocityV() << " " << w[i].velocityW() << "\n";
	}	

 	f << "SCALARS e float\n"; 
	f << "LOOKUP_TABLE default\n";

    for (int i = 0; i < cellSize; i++)
    {
		f << w[i].internalEnergy() << "\n";
	}
	
	f << "SCALARS p float\n"; 
	f << "LOOKUP_TABLE default\n";

    for (int i = 0; i < cellSize; i++)
    {
		f << w[i].pressure() << "\n";
	}
	
 	f << "SCALARS x float 3\n"; 
	f << "LOOKUP_TABLE default\n";

    for (int i = 0; i < cellSize; i++)
    {
		f << cellList[i]->center << "\n";
	}	

	f.close();
}