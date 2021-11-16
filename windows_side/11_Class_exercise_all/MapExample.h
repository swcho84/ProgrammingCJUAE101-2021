#pragma once
#include <stdio.h>
#include <iostream>
#include <map>

using namespace std;

enum Fruit
{
  apple = 1,
  banana,
  cherry,
  durian,
  elderberries
};

class MapExample
{
public:
  MapExample();
  ~MapExample();

public:
  void MainLoop();

private:
  map<string, Fruit> mapFruit_;
};

