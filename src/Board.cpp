#include <iostream>
#include <deque>
#include <string>

using namespace std;
class Tabuleiro {
  private:

    int linha,coluna;
    deque<deque<string>> Dimencao;

public:
  Tabuleiro() : linha(0), coluna(0) {}

void IniciaJogo (){

int linha, coluna;

  cout << "Dimenção do Tabuleiro:" << endl; 
  cin >> linha >> coluna;

  Dimencao.resize(linha, deque<string>(coluna, "| |"));

  cout << "Tabuleiro inciado com dimenções: " << linha << "x" << coluna << endl;

}

void ImprimeTabuleiro(){
    for(int i = 0; i < linha; ++i) {
      for(int j = 0; j < coluna; ++j) {
        cout << Dimencao[i][j];
      }
      cout << endl;
     }
} 
