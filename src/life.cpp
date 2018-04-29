#include "../include/header.h"
/**
* @file life.cpp
* @brief Função life que passará as linhas e colunas da generate grid para classe life
* @param Lin e Col, linhas e colunas passadas pela generate grid respectivamente
*/
Life::Life(int Lin, int Col){

        nLin = Lin;
        nCol = Col;
}

Life::Life(){}

/**
* @brief Função que "setará" as condições de cada célula de acordo com os updates
* @param Matrix e output que são os parâmetros dados pelas próximas gerações
*/

void Life::set_alive(char **  matrix, char * output){
      this->matrix = matrix;
      std::ofstream outfile (output, std::ios::app);

      for(auto i(1); i< nLin+1; i++){
        for(auto j(1); j < nCol+1; j++){
          outfile << matrix[i][j];
        }
          outfile << "\n";
      }

      outfile.close();
}

/**
* @details Função que servirá para atualizar a matriz das células de acordo com as vizinhanças, a determinada célula vive ou morre
*/

void Life::update(){

  int alive, survive;
  for (auto i(1); i < nLin + 1; i++){
    for (auto j(1); j < nCol + 1; j++){
      alive = 0;
      survive = 0;
      if(matrix[i][j] == '.'){
        if(matrix[i-1][j-1] == type){
          alive++;
        }
        if(matrix[i-1][j] == type){
          alive++;
        }
        if(matrix[i-1][j+1] == type){
          alive++;
        }
        if(matrix[i][j-1] == type){
          alive++;
        }
        if(matrix[i][j+1] == type){
          alive++;
        }
        if(matrix[i+1][j-1] == type){
          alive++;
        }
        if(matrix[i+1][j] == type){
          alive++;
        }
        if(matrix[i+1][j+1] == type){
          alive++;
        }

        if(alive == 3){
          aux_matrix[i][j] = type;
        }
      }else{

        if(matrix[i-1][j-1] == type){
          survive++;
        }
        if(matrix[i-1][j] == type){
          survive++;
        }
        if(matrix[i-1][j+1] == type){
          survive++;
        }
        if(matrix[i][j-1] == type){
          survive++;
        }
        if(matrix[i][j+1] == type){
          survive++;
        }
        if(matrix[i+1][j-1] == type){
          survive++;
        }
        if(matrix[i+1][j] == type){
          survive++;
        }
        if(matrix[i+1][j+1] == type){
          survive++;
        }

        if(survive != 3 and survive != 2){
          aux_matrix[i][j] = '.';
        }
      }
    }
  }

  count++;

}

/**
* @details Função que imprime as novas matrizes
*/

void Life::print(){
    std::cout << "\nThe "<< count <<"° conjecture of the life generation is:\n";
       for(auto i(1); i< nLin+1; i++){
         for(auto j(1); j < nCol+1; j++){
           std::cout << matrix[i][j];
         }
         std::cout << "\n";
    	}
      copy();
}

/**
* @details Função que guarda a primeira matriz gerada para determinar futuramente se houve estabilidade
*/

void Life::copy(){
  aux_matrix = new char * [nLin + 2];
  for(auto i(0); i < nLin +2; i++){
    aux_matrix[i] = new char [nCol + 2];
    for(auto j(0); j < nCol + 2; j++){
      aux_matrix[i][j] = (matrix[i][j]);
    }
  }

}

/**
* @details Função que testa se há igualdade entre a primeira matriz e a nova matriz gerada
* @return Caso sejam iguais,ela retorna "true" paro laço da main.
*/

bool Life::stable(char * filename){
  std::ifstream file (filename);

  if(file.is_open()){
      for (auto i(0); i < count-1; i++){
        int counting = 0;
        for(auto j(1); j < nLin+1; j++){
          for(auto k(1); k < nCol+1; k++){
            char aux;
            file >> aux;
            if(aux == aux_matrix[j][k]){
              counting++;
            }
          }
        }
        if(counting == nLin*nCol){
          return true;
        }
      }
  }
/*for(auto i(0); i < nLin + 2; i++)
		for(auto j(0); j < nCol + 2; j++)
			if(matrix[i][j] != aux_matrix[i][j]){
      			return false;
			}*/
      /*for(auto i(0); i < nLin; i++)
    		for(auto j(0); j < nCol; j++)
    		  std::cout << aux[i][j];
        std::cout << "\n";*/
  return false;
}

/**
* @details Função que testa se há extinção das células na nova matriz gerada
* @return Caso não há mais células,ela retorna "true" para o laço da main
*/

bool Life::extinct(){
  for(auto i(0); i < nLin + 2; i++)
		for(auto j(0); j < nCol + 2; j++)
			if(matrix[i][j] == type){
      			return false;
			}
  return true;
}
