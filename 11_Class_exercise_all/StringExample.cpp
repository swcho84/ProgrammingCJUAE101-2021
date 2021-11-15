#include "StringExample.h"

using namespace std;

// constructor
StringExample::StringExample()
{
  // file path, windows style
  strFilePathWin_ = "C:\\Windows\\System32\\abstract.dll";

  // file path, linux style
  strFilePathLinux_ = "/home/drswcho/prgmexercise/abstract.so";
}

// destructor
StringExample::~StringExample()
{
}

// main loop for the specified class
void StringExample::MainLoop()
{
  // splitting the file path, windows style
  vector<string> vecResFilePathWin = SplitFilePath(strFilePathWin_, '\\');

  // for debugging
  ShowRes(strFilePathWin_, vecResFilePathWin);

  // generating the file name and extension
  string strFileNameWin = GetFileName(vecResFilePathWin[vecResFilePathWin.size() - 1]);
  string strFileExtWin = GetFileExt(vecResFilePathWin[vecResFilePathWin.size() - 1]);
  printf("File(name,ext):(%s,%s)\n\n", strFileNameWin.c_str(), strFileExtWin.c_str());

  // splitting the file path, linux style
  vector<string> vecResFilePathLinux = SplitFilePath(strFilePathLinux_, '/');

  // for debugging
  ShowRes(strFilePathLinux_, vecResFilePathLinux);

  // generating the file name and extension
  string strFileNameLinux = GetFileName(vecResFilePathLinux[vecResFilePathLinux.size() - 1]);
  string strFileExtLinux = GetFileExt(vecResFilePathLinux[vecResFilePathLinux.size() - 1]);
  printf("File(name,ext):(%s,%s)\n\n", strFileNameLinux.c_str(), strFileExtLinux.c_str());

  return;
}

// splitting the file path 
vector<string> StringExample::SplitFilePath(string strPath, char chrSep)
{ 
  // assigning the result vector
  vector<string> vecRes; 

  // for extracting the string information 
  stringstream streamPath(strPath);
  string strTemp; 
  
  // using getline function
  while (getline(streamPath, strTemp, chrSep))
    vecRes.push_back(strTemp);

  return vecRes;
}

// Getting the file extension by splitting the fine name and extension
string StringExample::GetFileExt(const string& fileName)
{
  string::size_type pos = fileName.find_last_of('.');
  if (pos != string::npos && pos != 0)
    return fileName.substr(pos + 1);
  else return "";
}

// Getting the file name by splitting the fine name and extension
string StringExample::GetFileName(const string& fileName)
{
  string::size_type pos = fileName.find_last_of('.');
  if (pos != string::npos && pos != 0)
    return fileName.substr(0, pos);
  else 
    return "";
}

// for debugging
void StringExample::ShowRes(string strFilePath, vector<string>& vecRes)
{
  if (vecRes.size() > 0)
  {
    printf("SplitFilePath::%s\n", strFilePath.c_str());
    for (auto i = 0; i < vecRes.size(); i++)
      printf("[%d]%s\n", (int)(i), vecRes[i].c_str());
  }
  printf("\n");
}
