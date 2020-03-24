#include <iostream>
#include "math_tools.h"
#include "display_tools.h"

int main() {
  Matrix zeroes_matrix, inversa;
  //crear matriz inicial
  zeroes(zeroes_matrix,3);
  //dar valores a matriz inicial
  zeroes_matrix.at(0).at(0) = 2;
  zeroes_matrix.at(0).at(1) = 2;
  zeroes_matrix.at(0).at(2) = 3;
  zeroes_matrix.at(1).at(0) = 4;
  zeroes_matrix.at(1).at(1) = 5;
  zeroes_matrix.at(1).at(2) = 6;
  zeroes_matrix.at(2).at(0) = 7;
  zeroes_matrix.at(2).at(1) = 8;
  zeroes_matrix.at(2).at(2) = 9;

  //mostrar matriz inicial
    cout<<"Matriz original:";
    cout<<endl;
    cout<<endl;
  showMatrix(zeroes_matrix);
  cout<<endl;
  //crear matriz inversa
  inverse(zeroes_matrix,inversa);
  //mostrar matriz inversa
  cout<<"Matriz inversa:";
  cout<<endl;
  cout<<endl;
  showMatrix(inversa);




  return 0;
}