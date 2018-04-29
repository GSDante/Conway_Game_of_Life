#include "../include/header.h"
/**
* @file main.cpp
* @brief Função main onde teremos aplicação das regras dos jogos e abertura do arquivos
* utilizando dentro do laço e dos testes dentro dele.
* @param Como parâmetro temos dado baseado no que é dado na linha de comando
* @return Retorna a matriz contruida pelas funções a cada geração enquanto estiver de acordo com as regras do jogo
*/
int main(int argc,char *argv[]){

  Life obj;
  char key;
  if(argv[2] != NULL){
    obj = reader_file(argv[1], argv[2]);
  }else{
    argv[2] = (char*)"../data/output.txt";
    obj = reader_file(argv[1], argv[2]);
  }
  while(true){

      obj.print();
      obj.update();
      if(obj.extinct()){
          std::cout << "Extinct configuration, ending software...\n";
          std::exit(0);
      }
      if(obj.stable(argv[2])){
        obj.set_alive(obj.aux_matrix, argv[2]);
        obj.print();
        std::cout << "Se tornou estável na geração: " << (obj.count)-1 << std::endl;
        std::cout << "Stable configuration, ending software...\n";
        std::exit(0);
      }
      std::cout << "Do you wish continue with the generation?\n (y,n)?\n";
      std::cin >> key;
      if(key != 'y' and key !='Y'){
        return -1;
      }

      obj.set_alive(obj.aux_matrix, argv[2]);
  }


  return 0;
}
