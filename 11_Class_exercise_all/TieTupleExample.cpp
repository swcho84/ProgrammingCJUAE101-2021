#include "TieTupleExample.h"

using namespace std;

// constructor
TieTupleExample::TieTupleExample()
{

}

// destructor
TieTupleExample::~TieTupleExample()
{
}

// main loop for the specified class
void TieTupleExample::MainLoop()
{
  // assigning variables
  vector<PtDTwoD> vecPtDTwoDEx;
  vector<PtDThrD> vecPtDThrDEx;

  // using tie function
  tie(vecPtDTwoDEx, vecPtDThrDEx) = GetPoints(10, 10);

  // for debugging
  PrintVec(vecPtDTwoDEx);
  PrintVec(vecPtDThrDEx);
  return;
}

// making the tuple, temporary
tuple<vector<PtDTwoD>, vector<PtDThrD>> TieTupleExample::GetPoints(int nRange, int nSize)
{
  return make_tuple(GenVecTwoD(nRange, nSize), GenVecThrD(nRange, nSize));
}

// generating the vector, 3D point
vector<PtDThrD> TieTupleExample::GenVecThrD(int nRange, int nSize)
{
  vector<PtDThrD> vecRes;

  for (int i = 0; i < nSize; i++)
  {
	PtDThrD ptTemp;
	ptTemp.dX = (this->GenRandDoubleNum(nRange));
	ptTemp.dY = (this->GenRandDoubleNum(nRange));
	ptTemp.dZ = (this->GenRandDoubleNum(nRange));
	vecRes.push_back(ptTemp);
  }

  return vecRes;
}

// generating the vector, 2D point
vector<PtDTwoD> TieTupleExample::GenVecTwoD(int nRange, int nSize)
{
  vector<PtDTwoD> vecRes;

  for (int i = 0; i < nSize; i++)
  {
	PtDTwoD ptTemp;
	ptTemp.dX = (this->GenRandDoubleNum(nRange));
	ptTemp.dY = (this->GenRandDoubleNum(nRange));
	vecRes.push_back(ptTemp);
  }

  return vecRes;
}

// for debugging, 3D type
void TieTupleExample::PrintVec(vector<PtDThrD>& vec)
{
  if (vec.size() > 0)
  {
	for (auto i = 0; i < vec.size(); i++)
	  printf("[%d](%.4lf, %.4lf, %.4lf)\n", (int)(i), vec[i].dX, vec[i].dY, vec[i].dZ);
  }
  printf("\n");
}

// for debugging, 2D type
void TieTupleExample::PrintVec(vector<PtDTwoD>& vec)
{
  if (vec.size() > 0)
  {
	for (auto i = 0; i < vec.size(); i++)
	  printf("[%d](%.4lf, %.4lf)\n", (int)(i), vec[i].dX, vec[i].dY);
  }
  printf("\n");
}