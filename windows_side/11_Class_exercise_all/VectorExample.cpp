#include "VectorExample.h"
#include "RandNum.h"

using namespace std;

// constructor
VectorExample::VectorExample()
{

}

// destructor
VectorExample::~VectorExample()
{
}

// main loop for the specified class
void VectorExample::MainLoop()
{
  // case #1. generate int/float/double type single vector
  vector<int> vecIntEx = GenVecInteger(10, 10);
  vector<float> vecFloatEx = GenVecFloat(100, 5);
  vector<double> vecDoubleEx = GenVecDouble(50, 8);

  // for debugging
  PrintVec(vecIntEx);
  PrintVec(vecFloatEx);
  PrintVec(vecDoubleEx);

  // case #2. generate the customized structure vector
  vector<PtDTwoD> vecPtDTwoDEx = GenVecTwoD(10, 7);
  vector<PtDThrD> vecPtDThrDEx = GenVecThrD(20, 10);

  // for debugging
  PrintVec(vecPtDTwoDEx);
  PrintVec(vecPtDThrDEx);

  // case #3. for your exercise...

  return;
}

// generating the vector, 3D point
vector<PtDThrD> VectorExample::GenVecThrD(int nRange, int nSize)
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
vector<PtDTwoD> VectorExample::GenVecTwoD(int nRange, int nSize)
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

// generating the vector, double type
vector<double> VectorExample::GenVecDouble(int nRange, int nSize)
{
  vector<double> vecRes;

  for (int i = 0; i < nSize; i++)
	vecRes.push_back(this->GenRandDoubleNum(nRange));

  return vecRes;
}

// generating the vector, float type
vector<float> VectorExample::GenVecFloat(int nRange, int nSize)
{
  vector<float> vecRes;

  for (int i = 0; i < nSize; i++)
	vecRes.push_back(this->GenRandFloatNum(nRange));

  return vecRes;
}

// generating the vector, integer type
vector<int> VectorExample::GenVecInteger(int nRange, int nSize)
{
  vector<int> vecRes;

  for (int i = 0; i < nSize; i++)
	vecRes.push_back(this->GenRandIntNum(nRange));

  return vecRes;
}

// for debugging, 3D type
void VectorExample::PrintVec(vector<PtDThrD>& vec)
{
  if (vec.size() > 0)
  {
	for (auto i = 0; i < vec.size(); i++)
	  printf("[%d](%.4lf, %.4lf, %.4lf)\n", (int)(i), vec[i].dX, vec[i].dY, vec[i].dZ);
  }
  printf("\n");
}

// for debugging, 2D type
void VectorExample::PrintVec(vector<PtDTwoD>& vec)
{
  if (vec.size() > 0)
  {
	for (auto i = 0; i < vec.size(); i++)
	  printf("[%d](%.4lf, %.4lf)\n", (int)(i), vec[i].dX, vec[i].dY);
  }
  printf("\n");
}

// for debugging, double type
void VectorExample::PrintVec(vector<double>& vec)
{
  if (vec.size() > 0)
  {
	for (auto i = 0; i < vec.size(); i++)
	  printf("[%d]%.4lf\n", (int)(i), vec[i]);
  }
  printf("\n");
}

// for debugging, float type
void VectorExample::PrintVec(vector<float>& vec)
{
  if (vec.size() > 0)
  {
	for (auto i = 0; i < vec.size(); i++)
	  printf("[%d]%.4f\n", (int)(i), vec[i]);
  }
  printf("\n");
}

// for debugging, integer type
void VectorExample::PrintVec(vector<int>& vec)
{
  if (vec.size() > 0)
  {
	for (auto i = 0; i < vec.size(); i++)
	  printf("[%d]%d\n", (int)(i), vec[i]);
  }
  printf("\n");
}