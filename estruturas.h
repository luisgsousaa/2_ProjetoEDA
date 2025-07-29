#ifndef INC_2_PROJETOEDA_ESTRUTURAS_H
#define INC_2_PROJETOEDA_ESTRUTURAS_H
#include <string>

using namespace std;

struct passageiro{
    string numero_bilhete;
    string primeiro_nome;
    string segundo_nome;
    string nacionalidade;
    passageiro * esq;
    passageiro * dir;
};

struct aviao{
    string nome_voo;
    string modelo_aviao;
    string origem;
    string destino;
    int capacidade;
    struct Item{
        passageiro LL_passageiros;
        Item *seguinte;
    };
    Item *topo;
};

struct LL_avioes{
    struct Item {
        aviao dados;
        Item *seguinte;
    };
    Item *topo;
};

struct LL_nacionalidades{
    struct Item {
        string nacionalidade;
        Item *seguinte;
        passageiro * raiz;
    };
    Item *topo;
};





aviao criar_aviao(int &indice_lista_numeros_de_voo);
int bilhete_novo(int &numero_bilhete_novo);
passageiro criar_passageiro(int &numero_bilhete_novo);
#endif //INC_2_PROJETOEDA_ESTRUTURAS_H
