#include "Hyundai.h"

using namespace std;

int main()
{
  // making just car class, for test
  Car stdCar(0, 100.0);

  // making the sonata class
  Hyundai sedanSonata("sonata", 1, 70.2);

  // making the G70 class
  Hyundai sedanG70("G70", 2, 80.12);

  // making the santafe class
  Hyundai suvSantaFe("SantaFe", 3, 50.50);

  // checking the summation status
  suvSantaFe.CurrSumStatus();

  return 0;
}