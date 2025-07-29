#include "ficheiros.h"
#include "estruturas.h"
#include <string>
#include <fstream>
#include <iostream>

using namespace std;

/** Luis
 * Função que conta as linhas do ficheiro a ser lido e guarda o seu contéudo num array com o tamanho dado pelo número de linhas.
 * O ficheiro a ser lido está contido numa pasta "ficheiros" de modo a ficar separado dos ficheiros usados para guardar o estado do aeroportoEDA.
 * Caso o ficheiro não consiga ser aberto uma mensagem de erro irá ser apresentada ao utilizador.
 */
int n_linhas_voos = 0;
string * array_voos;
void le_ficheiro_voo(){
    fstream voos;
    voos.open("ficheiros/voo.txt");
    if (voos.is_open()){
        string linha;
        while (getline(voos, linha)) {
            n_linhas_voos++;
        }

        voos.clear();
        voos.seekg(0, ios::beg);

        array_voos = new string[n_linhas_voos] ;


        for (int i = 0; i < n_linhas_voos; i++) {
            getline(voos, linha);
            array_voos[i] = linha;
        }
        voos.close();
    }
    else{
        cerr << "Erro. Nao foi possivel abrir o ficheiro voo.txt";
        exit(1);
    }
}

/** Luis
 * Função que conta as linhas do ficheiro a ser lido e guarda o seu contéudo num array com o tamanho dado pelo número de linhas.
 * O ficheiro a ser lido está contido numa pasta "ficheiros" de modo a ficar separado dos ficheiros usados para guardar o estado do aeroportoEDA.
 * Caso o ficheiro não consiga ser aberto uma mensagem de erro irá ser apresentada ao utilizador.
 */
int n_linhas_destinos = 0;
string * array_destinos;
void le_ficheiro_destino(){

    fstream destinos;
    destinos.open("ficheiros/destino.txt");
    if (destinos.is_open()){
        string linha;
        while (getline(destinos, linha)) {
            n_linhas_destinos++;
        }

        destinos.clear();
        destinos.seekg(0, ios::beg);

        array_destinos = new string[n_linhas_destinos] ;


        for (int i = 0; i < n_linhas_destinos; i++) {
            getline(destinos, linha);
            array_destinos[i] = linha;
        }
        destinos.close();
    }
    else{
        cerr << "Erro. Nao foi possivel abrir o ficheiro destino.txt";
        exit(1);
    }

}

/** Luis
 * Função que escolhe um número aleatório como índice do array onde estam contidos os destinos que foram retirados do ficheiro e retorna a string presente nessa posição.
 * @return string contida na posição aleatória
 */
string destino_aleatorio(){
    int indice = rand() % n_linhas_destinos;
    return array_destinos[indice];
}

/** Luis
 * Função que conta as linhas do ficheiro a ser lido e guarda o seu contéudo num array com o tamanho dado pelo número de linhas.
 * O ficheiro a ser lido está contido numa pasta "ficheiros" de modo a ficar separado dos ficheiros usados para guardar o estado do aeroportoEDA.
 * Caso o ficheiro não consiga ser aberto uma mensagem de erro irá ser apresentada ao utilizador.
 */
int n_linhas_modelos = 0;
string * array_modelos;
void le_ficheiro_modelo(){
    fstream modelos;
    modelos.open("ficheiros/modelo.txt");
    if (modelos.is_open()){
        string linha;
        while (getline(modelos, linha)) {
            n_linhas_modelos++;
        }

        modelos.clear();
        modelos.seekg(0, ios::beg);

        array_modelos = new string[n_linhas_modelos] ;


        for (int i = 0; i < n_linhas_modelos; i++) {
            getline(modelos, linha);
            array_modelos[i] = linha;
        }
        modelos.close();
    }
    else{
        cerr << "Erro. Nao foi possivel abrir o ficheiro modelo.txt";
        exit(1);
    }
}

/** Luis
 * Função que escolhe um número aleatório como índice do array onde estam contidos os modelos que foram retirados do ficheiro e retorna a string presente nessa posição.
 * @return string contida na posição aleatória
 */
string modelo_aleatorio(){
    int indice = rand() % n_linhas_modelos;
    return array_modelos[indice];
}

/** Luis
 * Função que conta as linhas do ficheiro a ser lido e guarda o seu contéudo num array com o tamanho dado pelo número de linhas.
 * O ficheiro a ser lido está contido numa pasta "ficheiros" de modo a ficar separado dos ficheiros usados para guardar o estado do aeroportoEDA.
 * Caso o ficheiro não consiga ser aberto uma mensagem de erro irá ser apresentada ao utilizador.
 */
int n_linhas_nacionalidades = 0;
string * array_nacionalidades;
void le_ficheiro_nacionalidade(){
    fstream nacionalidades;
    nacionalidades.open("ficheiros/nacionalidade.txt");
    if (nacionalidades.is_open()){
        string linha;
        while (getline(nacionalidades, linha)) {
            n_linhas_nacionalidades++;
        }

        nacionalidades.clear();
        nacionalidades.seekg(0, ios::beg);

        array_nacionalidades = new string[n_linhas_nacionalidades] ;


        for (int i = 0; i < n_linhas_nacionalidades; i++) {
            getline(nacionalidades, linha);
            array_nacionalidades[i] = linha;
        }
        nacionalidades.close();
    }
    else{
        cerr << "Erro. Nao foi possivel abrir o ficheiro nacionalidade.txt";
        exit(1);
    }
}
/** Luis
 * Função que escolhe um número aleatório como índice do array onde estam contidas as nacionalidades que foram retiradas do ficheiro e retorna a string presente nessa posição.
 * @return string contida na posição aleatória
 */
string nacionalidade_aleatoria(){
    int indice = rand() % n_linhas_nacionalidades;
    return array_nacionalidades[indice];
}

/** Luis
 * Função que conta as linhas do ficheiro a ser lido e guarda o seu contéudo num array com o tamanho dado pelo número de linhas.
 * O ficheiro a ser lido está contido numa pasta "ficheiros" de modo a ficar separado dos ficheiros usados para guardar o estado do aeroportoEDA.
 * Caso o ficheiro não consiga ser aberto uma mensagem de erro irá ser apresentada ao utilizador.
 */
int n_linhas_origens = 0;
string * array_origens;
void le_ficheiro_origem(){
    fstream origens;
    origens.open("ficheiros/origem.txt");
    if (origens.is_open()){
        string linha;
        while (getline(origens, linha)) {
            n_linhas_origens++;
        }

        origens.clear();
        origens.seekg(0, ios::beg);

        array_origens = new string[n_linhas_origens] ;


        for (int i = 0; i < n_linhas_origens; i++) {
            getline(origens, linha);
            array_origens[i] = linha;
        }
        origens.close();
    }
    else{
        cerr << "Erro. Nao foi possivel abrir o ficheiro origem.txt";
        exit(1);
    }
}
/** Luis
 * Função que escolhe um número aleatório como índice do array onde estam contidas as origens que foram retiradas do ficheiro e retorna a string presente nessa posição.
 * @return string contida na posição aleatória
 */
string origem_aleatoria(){
    int indice = rand() % n_linhas_origens;
    return array_origens[indice];
}
/** Luis
 * Função que conta as linhas do ficheiro a ser lido e guarda o seu contéudo num array com o tamanho dado pelo número de linhas.
 * O ficheiro a ser lido está contido numa pasta "ficheiros" de modo a ficar separado dos ficheiros usados para guardar o estado do aeroportoEDA.
 * Caso o ficheiro não consiga ser aberto uma mensagem de erro irá ser apresentada ao utilizador.
 */
int n_linhas_primeiros_nomes = 0;
string * array_primeiros_nomes;
void le_ficheiro_primeiro_nome(){
    fstream primeiros_nomes;
    primeiros_nomes.open("ficheiros/primeiro_nome.txt");
    if (primeiros_nomes.is_open()){
        string linha;
        while (getline(primeiros_nomes, linha)) {
            n_linhas_primeiros_nomes++;
        }

        primeiros_nomes.clear();
        primeiros_nomes.seekg(0, ios::beg);

        array_primeiros_nomes = new string[n_linhas_primeiros_nomes] ;


        for (int i = 0; i < n_linhas_primeiros_nomes; i++) {
            getline(primeiros_nomes, linha);
            array_primeiros_nomes[i] = linha;
        }
        primeiros_nomes.close();
    }
    else{
        cerr << "Erro. Nao foi possivel abrir o ficheiro primeiro_nome.txt";
        exit(1);
    }
}
/** Luis
 * Função que escolhe um número aleatório como índice do array onde estam contidos os primeiros nomes que foram retirados do ficheiro e retorna a string presente nessa posição.
 * @return string contida na posição aleatória
 */
string primeiro_nome_aleatorio(){
    int indice = rand() % n_linhas_primeiros_nomes;
    return array_primeiros_nomes[indice];
}
/** Luis
 * Função que conta as linhas do ficheiro a ser lido e guarda o seu contéudo num array com o tamanho dado pelo número de linhas.
 * O ficheiro a ser lido está contido numa pasta "ficheiros" de modo a ficar separado dos ficheiros usados para guardar o estado do aeroportoEDA.
 * Caso o ficheiro não consiga ser aberto uma mensagem de erro irá ser apresentada ao utilizador.
 */
int n_linhas_segundos_nomes = 0;
string * array_segundos_nomes;
void le_ficheiro_segundo_nome(){
    fstream segundos_nomes;
    segundos_nomes.open("ficheiros/segundo_nome.txt");
    if (segundos_nomes.is_open()){
        string linha;
        while (getline(segundos_nomes, linha)) {
            n_linhas_segundos_nomes++;
        }

        segundos_nomes.clear();
        segundos_nomes.seekg(0, ios::beg);

        array_segundos_nomes = new string[n_linhas_segundos_nomes] ;


        for (int i = 0; i < n_linhas_segundos_nomes; i++) {
            getline(segundos_nomes, linha);
            array_segundos_nomes[i] = linha;
        }
        segundos_nomes.close();
    }
    else{
        cerr << "Erro. Nao foi possivel abrir o ficheiro segundo_nome.txt";
        exit(1);
    }
}

/** Luis
 * Função que escolhe um número aleatório como índice do array onde estam contidos os segundos nomes que foram retirados do ficheiro e retorna a string presente nessa posição.
 * @return string contida na posição aleatória
 */
string segundo_nome_aleatorio(){
    int indice = rand() % n_linhas_segundos_nomes;
    return array_segundos_nomes[indice];
}

/** Luis
 * Função que chama todas as funções de leitura de ficheiros de uma só vez.
 */
void leitura_dos_ficheiros(){
    le_ficheiro_voo();
    le_ficheiro_destino();
    le_ficheiro_modelo();
    le_ficheiro_nacionalidade();
    le_ficheiro_origem();
    le_ficheiro_primeiro_nome();
    le_ficheiro_segundo_nome();
}

/** Luis
 * Esta função adiciona um nodo à lista passada como argumento cada vez que é chamada,
 * é usada para preencher a Lista Ligada de nacionalidade onde os passageiros estrangeiros irão ficar ao chegar ao aeroportoEDA
 * @param ll_nacionalidades Lista ligada que é preenchida pela função
 * @param nacionalidade String que será posta no nodo a ser criado
 */
void inserir_nacionalidade_LL(LL_nacionalidades &ll_nacionalidades, string nacionalidade){
    LL_nacionalidades::Item * novo = new LL_nacionalidades::Item;
    novo->nacionalidade = nacionalidade;
    novo->raiz = NULL;
    novo->seguinte=NULL;
    if (ll_nacionalidades.topo ==NULL){
        ll_nacionalidades.topo = novo;
    }
    else{
        novo->seguinte=ll_nacionalidades.topo;
        ll_nacionalidades.topo = novo;
    }
}

/**LUIS
 * Função que cria uma lista ligada que contem nacionalidades onde serão postos os passageiros estrangeiros que chegam ao aeroportoEDA
 * A função usa um ciclo for para verificar se a nacionalidade a ser lida é Portuguesa, caso seja o ciclo irá passar para a próxima iteração, caso contrário é adicionada a nacionalidade à Lista ligada
 * Deste modo todos as nacionalidades estrangeiras irão ficar nesta lista ligada e a ordem das nacionalidades não irá interferir("Portuguese" pode estar em qualquer linha do ficheiro basicamente)
 * @param ll_nacionalidades Lista ligada que é preenchida pela função
 */
void cria_e_preenche_LL_nacionalidades(LL_nacionalidades &ll_nacionalidades){

    ll_nacionalidades.topo = NULL;

    for (int i = 0; i < n_linhas_nacionalidades; i++){
        if (array_nacionalidades[i] == "Portuguese"){
            continue;
        }
        else{
            inserir_nacionalidade_LL(ll_nacionalidades,array_nacionalidades[i]);
        }
    }
}

/** Luis
 * Função que percorre o array obtido a partir do ficheiro que contém números de voo, retorna a string contida no índice em questão e incrementa este índice para a próxima vez que a função
 * for chamada. Caso o índice seja igual ao número de linhas do ficheiro(a capacidade do array), irá voltar a 0, recomeçando a leitura dos elementos do array no seu ínicio.
 * @param indice_lista_numeros_de_voo Índice usado para a atribuição de novos números de voo
 * @return numero de voo que vai ser usado num avião
 */
string numero_de_voo(int &indice_lista_numeros_de_voo){
    if(indice_lista_numeros_de_voo == n_linhas_voos)
        indice_lista_numeros_de_voo = 0;

    return array_voos[indice_lista_numeros_de_voo++];
}

/** Luis
 * Função usada para auxiliar na mudança da nacionalidade de um passageiro.
 * Imprime todas as nacionalidades e pede ao utilizador para escolher uma, caso não seja uma opção válida uma mensagem de erro aparece até o utilizador apresentar uma opção válida.
 * Por fim retorna o elemento do array de nacionalidades no indice opcao-1.
 * @return string com a nacionalidade que o utilizador escolheu
 */
string escolhe_nacionalidades(){
    cout << endl;
    for (int i = 0; i < n_linhas_nacionalidades ; i++){
        cout << i+1 << " - " << array_nacionalidades[i] << endl;
    }
    cout << "Escolha uma das nacionalidades para atribuir ao passageiro: ";

    int opcao;
    bool sair = false;
    do{
        cin >> opcao;
        if (opcao > n_linhas_nacionalidades or opcao < 1){
            cout << "Escolha uma opcao valida!" << endl;
        }
        else{
            sair = true;
        }
    }while(!sair);

    return array_nacionalidades[opcao-1];
};

/** Luis
 * Função usada para auxiliar na impressão de passageiros por nacionalidade
 * Imprime todas as nacionalidades e pede ao utilizador para escolher uma, caso não seja uma opção válida uma mensagem de erro aparece até o utilizador apresentar uma opção válida.
 * Por fim retorna o elemento do array de nacionalidades no indice opcao-1.
 * @return string com a nacionalidade que o utilizador escolheu
 */
string escolhe_nacionalidades_imprimir(){
    cout << endl;
    for (int i = 0; i < n_linhas_nacionalidades ; i++){
        if (array_nacionalidades[i] == "Portuguese")
            continue;
        cout << i+1 << " - " << array_nacionalidades[i] << endl;
    }
    cout << "Escolha uma das nacionalidades para imprimir os passageiros: ";

    int opcao;
    bool sair = false;
    do{
        cin >> opcao;
        if (opcao > n_linhas_nacionalidades -1 or opcao < 1){
            cout << "Escolha uma opcao valida!" << endl;
        }
        else{
            sair = true;
        }
    }while(!sair);

    return array_nacionalidades[opcao-1];
};
