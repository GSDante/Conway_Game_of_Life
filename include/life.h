/**
* @file life.h
*@details No life.h temos a definição dela que está composta da classe Life cujo a parte privade tem as variaveis necessárias para iterações
*e funcionamento das funções assim como as suas assinaturas.
*/
#ifndef life
#define life
class Life{
 private:
		int nLin;
		int nCol;
		char ** matrix;
	public:
		int count = 1;
    char ** aux_matrix;
		Life(int Lin, int Col);
		Life();
  	char type;
    void set_alive(char **  matrix, char * output);
    void update();
  	void print();
    void copy();
  	bool stable(char * file);
		bool extinct();
};
#endif
