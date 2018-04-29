/**
 * @file reader_file.cpp
 * @brief Inclusão da header que tem todas as bibliotecas necessárias
*/
#include "../include/header.h"
/**
*@brief assinatura da função leitora do arquivo para gerar a matriz
*/
char ** generate_grid(int line, int column, std::ifstream& file);
/**
* @details Função leitora do arquivo que irá passar as caracteristicas das células, servirar também para testa se
* os parâmetros passado na linha de comando na mais estão corretos
* @param Filename que é o nome do arquivo de entrada e output o de saída
* @return Obj com as caracteristas repassada pelo arquivo dado
*/
Life reader_file(char* filename, char * output){

  int line, column;
  char type;
  std::ifstream file (filename);
  char ** matrix;

  if(file.is_open()){
    file >> line;
    file >> column;
    file >> type;

    matrix = generate_grid(line, column, file);

  }else{
    std::cout<< "Wrong syntaxe!\n";
    std::exit(0);
  }

  Life obj {line,column};
  obj.set_alive(matrix, output);
  obj.type = type;

  file.close();
  return obj;
}
/**
* @brief Função geradora da grade de acordo com as colunas,linhas dada pelo arquivo
* @param Line que são as linhas , column as colunas e file que é o arquivo dado
* @return Matrix que será a matriz gerada de acordo com o arquivo
*/
char ** generate_grid(int line, int column, std::ifstream& file){

  char ** matrix;
  matrix = new char * [line+2];
  for(auto i(0); i < line+2; i++){
    matrix[i] = new char [column+2];
    for(auto j(0); j < column+2; j++){
      if(i==0 or i==line+1 or j==0 or j==column+1){
        matrix[i][j] = '/';
      }else{
        file >> matrix[i][j];
      }
    }
  }

  return matrix;
}
