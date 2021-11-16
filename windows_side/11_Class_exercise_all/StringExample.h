#pragma once
#include <stdio.h>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

class StringExample
{
public:
  StringExample();
  ~StringExample();

public:
  void MainLoop();

private:
  string strFilePathWin_;
  string strFilePathLinux_;

  vector<string> SplitFilePath(string strPath, char chrSep);
  string GetFileExt(const string& FileName);
  string GetFileName(const string& fileName);
  void ShowRes(string strFilePath, vector<string>& vecRes);
};

