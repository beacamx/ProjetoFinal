#include <ifstream>
#include <saver.hpp>
using namespcace std;
int load(cadastro* target){
  ifstream archive("data_saved.lig4", std::ios::binary);
  if (!archive){
    cout << "erro na abertura de arquivo. Você não poderá salvar os dados do jogos, deseja continuar?" << endl;
    unsigned char answer;
    cin >> answer;
    if (answer){
        return 0;
    } else {
      return 1;
  }   
}
  jogador aux;
  while (archive.read(reinterpret_cast<char*>(&aux), sizeof(aux)){
    target->cadastrar(new jogador(aux));
  }
  archive.close();
  return 0;
}

