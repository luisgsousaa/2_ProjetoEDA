#ifndef INC_2_PROJETOEDA_FICHEIROS_H
#define INC_2_PROJETOEDA_FICHEIROS_H
#include <string>
#include "estruturas.h"

using namespace std;

void le_ficheiro_voo();

void le_ficheiro_destino();
string destino_aleatorio();

void le_ficheiro_modelo();
string modelo_aleatorio();

void le_ficheiro_nacionalidade();
string nacionalidade_aleatoria();

void le_ficheiro_origem();
string origem_aleatoria();

void le_ficheiro_primeiro_nome();
string primeiro_nome_aleatorio();

void le_ficheiro_segundo_nome();
string segundo_nome_aleatorio();


void leitura_dos_ficheiros();
void inserir_nacionalidade_LL(LL_nacionalidades &ll_nacionalidades, string nacionalidade);
void cria_e_preenche_LL_nacionalidades(LL_nacionalidades &ll_nacionalidades);
string numero_de_voo(int &indice_lista_numeros_de_voo);
string escolhe_nacionalidades();
string escolhe_nacionalidades_imprimir();
#endif //INC_2_PROJETOEDA_FICHEIROS_H
