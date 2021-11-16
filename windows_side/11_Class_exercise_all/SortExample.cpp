#include "SortExample.h"

using namespace std;

// constructor
SortExample::SortExample()
{

}

// destructor
SortExample::~SortExample()
{
}

// main loop for the specified class
void SortExample::MainLoop()
{
  // assigning variables
  vector<PtDTwoD> vecPtDTwoDExBeforeSort;
  vector<PtDThrD> vecPtDThrDExBeforeSort;
  vector<PtDTwoD> vecPtDTwoDExAfterSortX;
  vector<PtDThrD> vecPtDThrDExAfterSortZ;

  // using tie function
  tie(vecPtDTwoDExBeforeSort, vecPtDThrDExBeforeSort) = GetPoints(10, 10);

  // for debugging
  printf("before sorting:\n");
  PrintVec(vecPtDTwoDExBeforeSort);
  printf("\n");

  // sorting, x-axis
  sort(vecPtDTwoDExBeforeSort.begin(), vecPtDTwoDExBeforeSort.end(), &(Sort2DX));
  vecPtDTwoDExAfterSortX.clear();
  vecPtDTwoDExAfterSortX.assign(vecPtDTwoDExBeforeSort.begin(), vecPtDTwoDExBeforeSort.end());

  // for debugging
  printf("after sorting, 2D, x-axis:\n");
  PrintVec(vecPtDTwoDExAfterSortX);

  // for debugging
  printf("before sorting:\n");
  PrintVec(vecPtDThrDExBeforeSort);
  printf("\n");

  // sorting, z-axis
  sort(vecPtDThrDExBeforeSort.begin(), vecPtDThrDExBeforeSort.end(), &(Sort3DZ));
  vecPtDThrDExAfterSortZ.clear();
  vecPtDThrDExAfterSortZ.assign(vecPtDThrDExBeforeSort.begin(), vecPtDThrDExBeforeSort.end());

  // for debugging
  printf("after sorting, 3D, z-axis:\n");
  PrintVec(vecPtDThrDExAfterSortZ);
  printf("\n");

  return;
}

// sort reference, 3D, z-axis, descending
bool SortExample::Sort3DZ(const PtDThrD& a, const PtDThrD& b)
{
  return a.dZ > b.dZ;
}

// sort reference, 2D, x-axis, descending
bool SortExample::Sort2DX(const PtDTwoD& a, const PtDTwoD& b)
{
  return a.dX > b.dX;
}

// making the tuple, temporary
tuple<vector<PtDTwoD>, vector<PtDThrD>> SortExample::GetPoints(int nRange, int nSize)
{
  return make_tuple(GenVecTwoD(nRange, nSize), GenVecThrD(nRange, nSize));
}

// generating the vector, 3D point
vector<PtDThrD> SortExample::GenVecThrD(int nRange, int nSize)
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
vector<PtDTwoD> SortExample::GenVecTwoD(int nRange, int nSize)
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
void SortExample::PrintVec(vector<PtDThrD>& vec)
{
  if (vec.size() > 0)
  {
	for (auto i = 0; i < vec.size(); i++)
	  printf("[%d](%.4lf, %.4lf, %.4lf)\n", (int)(i), vec[i].dX, vec[i].dY, vec[i].dZ);
  }
  printf("\n");
}

// for debugging, 2D type
void SortExample::PrintVec(vector<PtDTwoD>& vec)
{
  if (vec.size() > 0)
  {
	for (auto i = 0; i < vec.size(); i++)
	  printf("[%d](%.4lf, %.4lf)\n", (int)(i), vec[i].dX, vec[i].dY);
  }
  printf("\n");
}