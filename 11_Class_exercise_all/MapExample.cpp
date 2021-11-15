#include "MapExample.h"

using namespace std;

// constructor
MapExample::MapExample()
{
  // mapping the string and enum (key and value)
  //mapFruit_["apple"] = Fruit::apple;
  //mapFruit_["banana"] = Fruit::banana;
  //mapFruit_["cherry"] = Fruit::cherry;
  //mapFruit_["durian"] = Fruit::durian;
  //mapFruit_["elderberries"] = Fruit::elderberries;

  // another style for stl::map setting
  mapFruit_ =
  {
    {"apple", Fruit::apple},
    {"banana", Fruit::banana},
    {"cherry", Fruit::cherry},
    {"durian", Fruit::durian},
    {"elderberries", Fruit::elderberries}
  };

  // Print map contents with a range-based for loop
  for (auto& iter : mapFruit_) 
    printf("[%s]%d\n", iter.first.c_str(), iter.second);
  printf("\n");
}

// destructor
MapExample::~MapExample()
{
}

// main loop for the specified class
void MapExample::MainLoop()
{
  // input the string, C-and C++-style
  char chrInput[100]; // C-style
  string strInput; // C++-style

  printf("Input the arbitrary fruit name:\n");
  int nRes = scanf("%s", &chrInput);  // C-style
  //cin >> strInput;  // C++-style
  //strcpy(chrInput, strInput.c_str());  // swapping..

  // for debugging
  printf("map[%s]:%d\n\n", chrInput, mapFruit_[chrInput]);

  // making the switch-case by using the string
  switch (mapFruit_[chrInput])
  {
    case Fruit::apple:
    {
      printf("Selection::Apple\n");
      break;
    }
    case Fruit::banana:
    {
      printf("Selection::Banana\n");
      break;
    }
    case Fruit::cherry:
    {
      printf("Selection::Cherry\n");
      break;
    }
    case Fruit::durian:
    {
      printf("Selection::Durian\n");
      break;
    }
    case Fruit::elderberries:
    {
      printf("Selection::Elderberries\n");
      break;
    }
    default:
    {
      printf("Selection::check your input...\n");
      break;
    }
  }
  return;
}