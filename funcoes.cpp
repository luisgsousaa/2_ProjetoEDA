#include "funcoes.h"
#include "estruturas.h"
#include "ficheiros.h"
#include <stdlib.h>
#include "fstream"
#include <iostream>
#include "simulacao.h"
#include "filesystem"

using namespace std;

/** Luis
 * Função que retorna um número aleatório entre 5 e 15 para decidir a capacidade de um avião.
 * @return capacidade do avião
 */
int capacidade_aviao(){
    return rand()% 11 + 5;
}


/** Sara
 * Criação de uma nova lista ligada vazia de aviões
 * Recebe uma lista e atribui ao topo NULL, ficando a lista inicializada, mas vazia
 * @param lista ligada de aviões
 */
void nova_lista_avioes(LL_avioes &lista){
    lista.topo = NULL;
}

/** Sara
 * Verificação de listas ligadas vazias
 * Verifica se a lista ligada de aviões está vazia ou não
 * @param lista ligada de aviões
 * @return true ou false
 */
bool vazia_lista_avioes (LL_avioes &lista){
    return lista.topo==NULL;
}

/** Sara
 * Verifica se a lista de passageiros num avião é vazia
 * @param novo avião
 * @return true ou false
 */
bool vazia_aviao (aviao &novo){
    return novo.topo==NULL;
}


/** Sara
 * Insere um novo avião no início da lista ligada de aviões
 * A função cria um novo nó para o avião, recebido como argumento, na lista de aviões e insere-o no topo da lista de aviões
 * @param lista ligada de destino do novo avião
 * @param novo avião a ser inserido
 */
void inserir_aviao(LL_avioes &lista, aviao &novo){
    LL_avioes::Item * novo_no = new LL_avioes::Item;
    novo_no->dados=novo;
    novo_no->seguinte=NULL;
    if (vazia_lista_avioes(lista))
        lista.topo = novo_no;
    else{
        novo_no->seguinte=lista.topo;
        lista.topo=novo_no;
    }
}

/** Sara
 * Insere um novo passageiro no início da lista ligada de passageiros associada a um avião
 * A função cria um novo nó para o passageiro, recebido como argumento, e insere-o no topo
 * da lista de passageiros associada ao avião indicado
 * @param aviao avião onde inserir o novo passageiro
 * @param novo passageiro a inserir
 */
void inserir_passageiro(aviao &aviao, passageiro &novo){
    aviao::Item * novo_no = new aviao::Item;
    novo_no->LL_passageiros=novo;
    novo_no->seguinte=NULL;
    if (vazia_aviao(aviao))
        aviao.topo = novo_no;
    else{
        novo_no->seguinte=aviao.topo;
        aviao.topo=novo_no;
    }
}

/** Sara
 * Remove o último avião da lista ligada de aviões
 * A função remove o último nó da lista ligada de aviões.
 * Se a lista estiver vazia é exibida uma mensagem de erro.
 * É utilizada para remover 1 avião à lista ligada de aviões descolados.
 * @param lista ligada de aviões
 */
void retirar_avioes (LL_avioes &lista){
    if (vazia_lista_avioes(lista))
        cout << "Erro, lista vazia" << endl;
    else {
        LL_avioes::Item*iterator=lista.topo;
        LL_avioes::Item*aux=lista.topo;
        while (iterator->seguinte!=NULL){
            iterator=iterator->seguinte;
        }

        while(aux->seguinte->seguinte!=NULL){
            aux=aux->seguinte;
        }
        aux->seguinte=NULL;
        delete iterator;
    }
}

/** Sara
 * Contagem de elementos na lista ligada
 * Retorna o tamanho de uma lista
 * @param lista de aviões
 * @return tamanho da lista
 */
int comprimento(LL_avioes &lista){
    int tam=0;
    LL_avioes::Item*aux=lista.topo;
    while (aux!=NULL){
        tam++;
        aux=aux->seguinte;
    }
    return tam;
}


/** Sara
 * Inicialização da lista ligada de aproximação ao aeroporto
 * São formados 10 novos aviões e cada um destes aviões é preenchido com passageiros.
 * Quando um avião chega à sua capacidade máxima de passageiros é inserido na lista ligada de aviões em aproximação.
 * O processo repete-se para os 10 aviões.
 * @param ll_aproximacao lista ligada de aviões em aproximação, vazia
 * @param numero_bilhete_novo Número do proximo bilhete a ser criado
 * @param indice_lista_numeros_de_voo Índice usado para a atribuição de novos números de voo
 * @return retorna a lista ligada de aviões em aproximação
 */
LL_avioes inicializar_aproximacao(LL_avioes &ll_aproximacao,int &numero_bilhete_novo,int &indice_lista_numeros_de_voo){
    aviao * novo = new aviao[10];
    for(int i=0;i<10;i++) {
        novo[i] = criar_aviao(indice_lista_numeros_de_voo);
    }
    for (int j=0;j<10;j++) {
        int k=0;
        while (k<novo[j].capacidade){
            passageiro mais_um =criar_passageiro(numero_bilhete_novo);
            inserir_passageiro(novo[j], mais_um);
            k++;
        }
        inserir_aviao(ll_aproximacao, novo[j]);
    }
    delete []novo;
    return ll_aproximacao;
}

/** Sara
 * Adiciona 1 avião à lista ligada de aproximação
 * Criação de um novo avião que é preenchido com passageiros de acordo com a sua capacidade.
 * De seguida é adicionado à ll_aproximacao utilizando o algoritmo "inserir_aviao".
 * É utilizada quando um avião passa de aproximação para a pista, sendo necessário formular um novo avião.
 * @param ll_aproximacao lista ligada de aviões em aproximação
 * @param numero_bilhete_novo Número do proximo bilhete a ser criado
 * @param indice_lista_numeros_de_voo Índice usado para a atribuição de novos números de voo
 * @return retorna a lista de aviões em aproximação
 */
LL_avioes adiciona_aproximacao(LL_avioes &ll_aproximacao,int &numero_bilhete_novo,int &indice_lista_numeros_de_voo){
    aviao novo = criar_aviao(indice_lista_numeros_de_voo);
    for (int i=0; i<novo.capacidade; i++) {
        passageiro mais_um = criar_passageiro(numero_bilhete_novo);
        inserir_passageiro(novo, mais_um);
    }
    inserir_aviao(ll_aproximacao,novo);

    return ll_aproximacao;
}


/** Sara e Luís
 * Adicionar aviões à pista
 * Verifica se o número de aviões em pista é superior a 8 (com a função "comprimento", caso seja inferior vai adicionar um avião à pista
 * vindo da lista de aviões em aproximação. Esse avião é "retirado" da lista de aproximação e colocado na pista.
 * É atribuído um novo número de voo ao avião e é alterado o destino do avião para um destino aleatório, assim como a sua origem.
 * Os passageiros são retirados do avião em aproximação e aqueles de nacionalidade estrangeira
 * são organizados em árvores de pesquisa binária, árvores essas associadas a cada nacionalidade.
 * São adicionados novos passageiros ao avião que entra na pista, sendo que 3 destes são passageiros estrangeiros a realizar "escala".
 * Os passageiros estrangeiros em "escala" são adicionados ao avião escolhidos aleatoriamente, retirando-os das árvores de pesquisa
 * binária associada a cada nacionalidade, onde estavam guardados.
 * Os passageiros selecionados nas suas árvores são por sua vez removidos das mesmas através da remoção por cópia.
 *
 * @param ll_aproximacao Lista ligadada de aviões na aproximação
 * @param ll_pista lista ligada de aviões em pista
 * @param indice_lista_numeros_de_voo Índice usado para a atribuição de novos números de voo
 * @param numero_bilhete_novo Número do proximo bilhete a ser criado
 * @param ll_nacionalidades Lista ligada de todas as nacionalidades
 * @return a lista de avioes na pista
 */
LL_avioes adiciona_pista (LL_avioes &ll_aproximacao,LL_avioes &ll_pista,int &indice_lista_numeros_de_voo,int &numero_bilhete_novo,LL_nacionalidades &ll_nacionalidades){
    LL_avioes::Item * iterator = ll_aproximacao.topo;
    LL_avioes::Item * iterator_aux = ll_aproximacao.topo;
    string aux;

    if (comprimento(ll_pista)<8) {
        while (iterator->seguinte != NULL) {
            iterator = iterator->seguinte;
        }
        while (iterator_aux->seguinte->seguinte != NULL) {
            iterator_aux = iterator_aux->seguinte;
        }
        iterator_aux->seguinte = NULL;
        iterator->seguinte = ll_pista.topo;
        ll_pista.topo = iterator;

        ll_pista.topo->dados.nome_voo= numero_de_voo(indice_lista_numeros_de_voo);
        ll_pista.topo->dados.origem = "AeroportoEDA - Madeira, Portugal";
        ll_pista.topo->dados.destino = destino_aleatorio();


        aviao::Item * iterator_passageiros = ll_pista.topo->dados.topo;
        passageiro * retirados = new passageiro[ll_pista.topo->dados.capacidade];

        int i = 0;
        passageiro novo;
        while(iterator_passageiros != NULL) {
            novo = criar_passageiro(numero_bilhete_novo);
            retirados[i] = iterator_passageiros->LL_passageiros;
            i++;
            iterator_passageiros->LL_passageiros = novo;
            iterator_passageiros = iterator_passageiros->seguinte;
        }
        adiciona_passageiros_estrangeiros(retirados,ll_pista.topo->dados.capacidade,ll_nacionalidades);

        LL_nacionalidades::Item * procura;
        passageiro array_estr[3];
        passageiro * estrangeiro;
        int j = 0;

        while (j < 3) {

            procura = ll_nacionalidades.topo;
            string nacionalidade = nacionalidade_aleatoria();

            while (nacionalidade == "Portuguese")
                nacionalidade = nacionalidade_aleatoria();

            while (procura->nacionalidade != nacionalidade)
                procura = procura->seguinte;


            estrangeiro = procura_passageiro_random(procura->raiz);
            if(estrangeiro==NULL) {
                continue;
            }

            array_estr[j].primeiro_nome = estrangeiro->primeiro_nome;
            array_estr[j].segundo_nome = estrangeiro->segundo_nome;
            array_estr[j].nacionalidade = estrangeiro->nacionalidade;
            array_estr[j].numero_bilhete = estrangeiro->numero_bilhete;
            remover_copia(procura->raiz, estrangeiro->segundo_nome);


            j++;
        }

        int k = 0;
        iterator_passageiros = ll_pista.topo->dados.topo;
        passageiro escala;
        while (k < 3) {
            escala = array_estr[k];
            iterator_passageiros->LL_passageiros = escala;
            iterator_passageiros = iterator_passageiros->seguinte;
            k++;
        }

        delete[] retirados;
    }
    return ll_pista;
}

/** Sara
 * Algoritmo que utiliza o número de nós de uma árvore para encontrar um passageiro aleatório.
 * É gerado um número aleatório entre 1 e o número de nós da árvore que é comparado com o número de
 * nós da subárvore esquerda da raiz.
 * O algoritmo decide se retorna a raiz ou se continua a procurar na subárvore esquerda ou direita até
 * encontrar o nó desejado.
 * @param raiz raiz da árvore
 * @return passageiro aleatório
 */
passageiro * procura_passageiro_random (passageiro * raiz){
    if (raiz == NULL)
        return NULL;
    int num_nodos = conta_nos_arvore(raiz);
    int num_random = rand() % num_nodos+1;
    int contador_esq = conta_nos_arvore(raiz->esq);
    if (num_random == contador_esq+1)
        return raiz;
    else if (num_random <= contador_esq+1)
        return procura_passageiro_random(raiz->esq);
    else
        return procura_passageiro_random(raiz->dir);
}


/** Sara e Luis
 * Transfere aviões da pista que descolaram para a lista ligada de aviões descolados.
 * Verifica se o comprimento da lista de aviões em pista é superior a 7, caso seja, o avião
 * há mais tempo em pista é transferido para a lista de aviões descolados.
 * Quando o comprimento da lista ligada dos descolados é superior a 5 é eliminado do sistema o avião que descolou há mais tempo.
 * @param ll_pista lista ligada de aviões em pista
 * @param ll_descolados lista ligada de aviões descolados
 * @return lista ligada de aviões descolados
 */
LL_avioes adiciona_descolados (LL_avioes &ll_pista, LL_avioes &ll_descolados){
    if (comprimento(ll_pista)>=7){
        LL_avioes::Item * iterator = ll_pista.topo;
        LL_avioes::Item * iterator_aux = ll_pista.topo;
        LL_avioes::Item aux;
        while (iterator->seguinte != NULL){
            iterator = iterator -> seguinte;
        }
        while (iterator_aux->seguinte->seguinte != NULL){
            iterator_aux = iterator_aux -> seguinte;
        };
        iterator_aux->seguinte = NULL;
        iterator->seguinte=ll_descolados.topo;
        ll_descolados.topo=iterator;
    }
    if (comprimento(ll_descolados)>5){
        retirar_avioes(ll_descolados);
    }
    return ll_descolados;
}


int pos = 0; // váriavel usada nas duas funções, na da travessia para guardar o indice do array, e na passa_array para dar o valor 0(dar reset) quando está função é chamada
/** Luis
 * Esta função percorre todos os nós de uma árvore recursivamente usando uma travessia prefixa, cada um destes nós tem os seus detalhes guardados num array que é passado como parâmetro.
 * @param no
 * @param array
 */
void travessia_prefixa_arvore_passageiros_para_array(passageiro * no,passageiro *array){
    if(no == NULL) {
        return;
    }

    array[pos].numero_bilhete = no->numero_bilhete;
    array[pos].segundo_nome = no->segundo_nome;
    array[pos].primeiro_nome = no->primeiro_nome;
    array[pos].nacionalidade = no->nacionalidade;
    pos++;
    travessia_prefixa_arvore_passageiros_para_array(no->esq,array);
    travessia_prefixa_arvore_passageiros_para_array(no->dir,array);
}
/** Luis
 * Função que percorre todos os nós de uma árvore recursivamente e conta-os.
 * @param no raiz da árvore
 * @return número total de nós da árvore
 */
int conta_nos_arvore(passageiro * no){
    if(no == NULL)
        return 0;
    int contaesq = conta_nos_arvore(no->esq);
    int contadir = conta_nos_arvore(no->dir);

    return contadir + contaesq + 1;
}

/**Luis
 * Função que passa todos os nodos das árvores de pesquisa binária(todos os passageiros estrangeiros) do programa para um array
 * Usando um iterador para percorrer todas as árvores e a função conta_nos_arvore, são contados e somados todos os nós e um array é criado com essa capacidade.
 * O iterador volta ao topo da lista ligada e volta a percorrê-la desta vez adicionando todos os nós ao array criado anteriormente.
 * @param ll_nacionalidades lista ligada de nacionalidades
 * @param conta_array_passageiros tamanho do array criado
 * @return array preenchido com todos os nós das árvores de pesquisa binária
 */
passageiro * passa_array(LL_nacionalidades &ll_nacionalidades, int &conta_array_passageiros){
    conta_array_passageiros = 0;
    LL_nacionalidades::Item * iterator = ll_nacionalidades.topo;
    while(iterator->seguinte != NULL){
        conta_array_passageiros+=conta_nos_arvore(iterator->raiz);
        iterator = iterator->seguinte;
    }

    passageiro * array = new passageiro[conta_array_passageiros];
    iterator = ll_nacionalidades.topo;
    pos = 0;
    while(iterator->seguinte != NULL) {
        travessia_prefixa_arvore_passageiros_para_array(iterator->raiz, array);
        iterator = iterator->seguinte;
    }

   return array;
}
/** Luis
 * Função que passa todos os nodos de uma das árvores de pesquisa binária do programa para um array
 * Usando um iterador encontra a árvore com a nacionalidade pretendida, conta os seus nós e cria um array com um tamanho necessário.
 * Depois faz uma travessia prefixa pelos nodos da árvore, adicionando-os todos a um array
 * @param ll_nacionalidades lista ligada de nacionalidades
 * @param conta_array_passageiros tamanho do array criado
 * @param nacionalidade nacionalidade da arvore a ser lida
 * @return array preenchido com os passageiros
 */
passageiro * passa_array_nacionalidade(LL_nacionalidades ll_nacionalidades, int &conta_array_passageiros, string nacionalidade){
    conta_array_passageiros = 0;
    LL_nacionalidades::Item * iterator = ll_nacionalidades.topo;
    while(iterator->nacionalidade != nacionalidade){
        iterator = iterator->seguinte;
    }

    conta_array_passageiros = conta_nos_arvore(iterator->raiz);

    passageiro * array = new passageiro[conta_array_passageiros];

    pos = 0;

    travessia_prefixa_arvore_passageiros_para_array(iterator->raiz, array);

    return array;
}


/** Luis
 * Esta função lê os ficheiros criados na função guardar_aeroportoEDA() tendo em conta a sua formatação e carrega o estado do momento em que foi guardado o aeroportoEDA.
 * A função efetua uma verificação que percorre os argumentos do programa e iguala as variáveis do tipo string ao caminho do ficheiro caso o nome do ficheiro seja igual ao esperado,
 * deste modo pode ser passado apenas o nome do ficheiro(usando o .txt no final) ou o caminho do ficheiro. Após isto é verificado se alguma das variáveis continua a "1", caso isto aconteça quer
 * dizer que não foi encontrado pelo menos um dos ficheiros pretendidos e uma mensagem de erro será apresentada.
 *
 * O ficheiro caracteristicas.txt é aberto e são lidos todos as informações necessárias para o funcionamento do programa.
 *
 * De seguida usando os comprimentos das listas ligadas que foram obtidos a partir do ficheiro anterior é lido o ficheiro avioes.txt.
 * Aqui corre um ciclo for para cada lista ligada tendo em conta o comprimento das listas no momento em que foi guardado o aeroportoEDA, deste modo podemos saber a que lista pertence cada avião.
 * Dentro deste ciclo for está outro que percorre o ficheiro tendo em conta quantos passageiros cada avião tem, deste modo podemos saber quando é que a proxima linha do ficheiro corresponde a um avião, de modo a passar para a próxima iteração do primeiro ciclo for.
 *
 * Ao fim de cada ciclo referente aos passageiros é adicionado o passageiro à lista ligada dentro do avião e o mesmo acontece com os aviões na sua respetiva lista, este processo ocorre para a aproximação, pista e descolados.(As ultimas duas caso estejam preenchidas)
 * Por fim cada lista é invertida após o fim do seu preenchimento devido ao formato em que são guardados os ficheiros, deste modo não há trocas de prioridades entre os aviões ao carregar um estado anterior.
 * A lista dos passageiros dentro dos aviões também é invertida por uma questão de ficar semelhante ao estado no momento em que foi guardado embora a sua ordem não afete o funcionamento do aeroportoEDA.
 *
 * Os passageiros que irão ficar nas árvores de pesquisa binária tendo em conta a sua nacionalidade estão no ficheiro passageiros.txt, a função conta as linhas e cria um array com o tamanho necessário
 * de seguida lê os dados de todos os passageiros e guarda-os no array. Este array de seguida é passado para a função que adiciona os passageiros às respetivas àrvores, tal como o seu tamanho.
 * Após a inserção nas árvores a memória do array é desalocada e uma mensagem a informar o sucesso do carregamento do aeroporto é apresentada.
 *
 * @param argv argumentos passados na execução do programa
 * @param ll_aproximacao Lista Ligada onde estão os aviões em aproximação
 * @param ll_pista Lista Ligada onde estão os aviões em pista
 * @param ll_descolados Lista Ligada onde estão os aviões descolados
 * @param ll_nacionalidades Lista Ligada de nacionalidades
 * @param numero_bilhete_novo Número do proximo bilhete a ser criado
 * @param indice_lista_numeros_de_voo Índice usado para a atribuição de novos números de voo
 * @param ciclos Contagem dos ciclos da simulação
 * @param fechado booleano que guarda se o aeroporto está fechado ou não
 * @param ciclos_fechado número de ciclos que faltam para o aeroporto abrir
 */
void carrega_aeroportoEDA(char* argv[],LL_avioes &ll_aproximacao,LL_avioes &ll_pista,LL_avioes &ll_descolados,LL_nacionalidades &ll_nacionalidades,int &numero_bilhete_novo, int &indice_lista_numeros_de_voo, int &ciclos,bool &fechado, int &ciclos_fechado){
    string f_caracteristicas = "1";
    string f_avioes = "1";
    string f_passageiros = "1";

    for (int p=1;p<4;p++){
        filesystem::path f(argv[p]);
        if(f.filename()=="caracteristicas.txt"){
            f_caracteristicas=argv[p];
            continue;
        }
        if(f.filename()=="avioes.txt"){
            f_avioes=argv[p];
            continue;
        }
        if(f.filename()=="passageiros.txt"){
            f_passageiros=argv[p];
            continue;
        }
    }
    if(f_caracteristicas == "1" or f_avioes == "1" or f_passageiros == "1" ){
        cerr << "Houve um erro na leitura dos ficheiros, verifique se os nomes dos ficheiros estao corretos.";
        exit(-1);
    }
    char ignora;

////////////////////////caracteristicas//////////////////////////////
    ifstream caracteristicas(f_caracteristicas);
    int comprimento_aproximacao, comprimento_pista, comprimento_descolados;

    if(caracteristicas.is_open()){
        caracteristicas >> comprimento_aproximacao
                        >> comprimento_pista
                        >> comprimento_descolados
                        >> ciclos
                        >> numero_bilhete_novo
                        >> indice_lista_numeros_de_voo
                        >> fechado
                        >> ciclos_fechado;
        caracteristicas.close();
    }
    else{
        cerr << "Erro ao abrir o ficheiro caracteristicas.txt";
        exit(-1);
    }
////////////////////////Voos////////////////////////////////////
    //aviao
    string numero_voo_temp;
    string modelo_temp;
    int capacidade_temp;
    string origem_temp;
    string destino_temp;
    //passageiros
    string bilhete_temp;
    string primeiro_nome_temp;
    string segundo_nome_temp;
    string nacionalidade_temp;



    ifstream avioes(f_avioes);
    if(avioes.is_open()){
        //Preenchimento Lista Ligada Aproximação
        for (int i = 0; i < comprimento_aproximacao;i++){
            aviao novo;
            getline(avioes,numero_voo_temp,'|');
            getline(avioes,modelo_temp,'|');
            avioes >> capacidade_temp >> ignora;
            getline(avioes,origem_temp,'|');
            getline(avioes,destino_temp);
            novo.nome_voo = numero_voo_temp;
            novo.modelo_aviao = modelo_temp;
            novo.capacidade = capacidade_temp;
            novo.origem = origem_temp;
            novo.destino = destino_temp;

            novo.topo = NULL;
            for (int j = 0; j < capacidade_temp;j++){
                passageiro novo_passageiro;
                getline(avioes,bilhete_temp,'|');
                getline(avioes,primeiro_nome_temp,'|');
                getline(avioes,segundo_nome_temp,'|');
                getline(avioes,nacionalidade_temp);

                novo_passageiro.numero_bilhete = bilhete_temp;
                novo_passageiro.primeiro_nome = primeiro_nome_temp;
                novo_passageiro.segundo_nome = segundo_nome_temp;
                novo_passageiro.nacionalidade = nacionalidade_temp;
                inserir_passageiro(novo,novo_passageiro);
            }
            inverte_LL_passageiros(novo);
            inserir_aviao(ll_aproximacao,novo);
        }
        inverte_LL_avioes(ll_aproximacao);

        //Fim Aproximação

        //Preenchimento Lista Ligada Pista

        for (int i = 0; i < comprimento_pista;i++){
            aviao novo;
            getline(avioes,numero_voo_temp,'|');
            getline(avioes,modelo_temp,'|');
            avioes >> capacidade_temp >> ignora;
            getline(avioes,origem_temp,'|');
            getline(avioes,destino_temp);
            novo.nome_voo = numero_voo_temp;
            novo.modelo_aviao = modelo_temp;
            novo.capacidade = capacidade_temp;
            novo.origem = origem_temp;
            novo.destino = destino_temp;

            novo.topo = NULL;
            for (int j = 0; j < capacidade_temp;j++){
                passageiro novo_passageiro;
                getline(avioes,bilhete_temp,'|');
                getline(avioes,primeiro_nome_temp,'|');
                getline(avioes,segundo_nome_temp,'|');
                getline(avioes,nacionalidade_temp);

                novo_passageiro.numero_bilhete = bilhete_temp;
                novo_passageiro.primeiro_nome = primeiro_nome_temp;
                novo_passageiro.segundo_nome = segundo_nome_temp;
                novo_passageiro.nacionalidade = nacionalidade_temp;
                inserir_passageiro(novo,novo_passageiro);
            }
            inverte_LL_passageiros(novo);
            inserir_aviao(ll_pista,novo);
        }
        inverte_LL_avioes(ll_pista);

        //Fim Pista

        //Preenchimento Lista Ligada Descolados

        for (int i = 0; i < comprimento_descolados;i++){
            aviao novo;
            getline(avioes,numero_voo_temp,'|');
            getline(avioes,modelo_temp,'|');
            avioes >> capacidade_temp >> ignora;
            getline(avioes,origem_temp,'|');
            getline(avioes,destino_temp);
            novo.nome_voo = numero_voo_temp;
            novo.modelo_aviao = modelo_temp;
            novo.capacidade = capacidade_temp;
            novo.origem = origem_temp;
            novo.destino = destino_temp;

            novo.topo = NULL;
            for (int j = 0; j < capacidade_temp;j++){
                passageiro novo_passageiro;
                getline(avioes,bilhete_temp,'|');
                getline(avioes,primeiro_nome_temp,'|');
                getline(avioes,segundo_nome_temp,'|');
                getline(avioes,nacionalidade_temp);

                novo_passageiro.numero_bilhete = bilhete_temp;
                novo_passageiro.primeiro_nome = primeiro_nome_temp;
                novo_passageiro.segundo_nome = segundo_nome_temp;
                novo_passageiro.nacionalidade = nacionalidade_temp;
                inserir_passageiro(novo,novo_passageiro);
            }
            inverte_LL_passageiros(novo);
            inserir_aviao(ll_descolados,novo);
        }
        inverte_LL_avioes(ll_descolados);

        avioes.close();

        cout << "O estado do AeroportoEDA foi carregado a partir dos ficheiros." << endl;
    }
    else{
        cerr << "Erro ao abrir o ficheiro avioes.txt";
        exit(-1);
    }

//////////////////////Passageiros//////////////////////////////////
    ifstream passageiros(f_passageiros);
    int n_linhas_passageiros = 0;
    if(passageiros.is_open()){
        string linha;
        while (getline(passageiros, linha)) {
            n_linhas_passageiros++;
        }

        passageiros.clear();
        passageiros.seekg(0, ios::beg);

        passageiro * array_passageiros = new passageiro[n_linhas_passageiros];

        for (int j = 0; j < n_linhas_passageiros;j++) {
            passageiro novo_passageiro;
            getline(passageiros, novo_passageiro.numero_bilhete, '|');
            getline(passageiros, novo_passageiro.primeiro_nome, '|');
            getline(passageiros, novo_passageiro.segundo_nome, '|');
            getline(passageiros, novo_passageiro.nacionalidade, '|');

            array_passageiros[j] = novo_passageiro;
        }


        adiciona_passageiros_estrangeiros(array_passageiros,n_linhas_passageiros,ll_nacionalidades);
        delete[] array_passageiros;

    }
    else{
        cerr << "Erro ao abrir o ficheiro passageiros.txt";
        exit(-1);
    }

}


////////////////////////////////Inverter LL's///////////////////////////////////////
/** Luis
 * Esta função inverte a lista ligada que recebe.
 * Cria uma lista temporária e preenche-a com os nodos da lista original, adicionando um à temp e de seguida eliminando-o da lista original até a lista original estar vazia deste modo invertendo-a.
 * Quando a inversão estiver completa o apontador para o topo da lista original passa a apontar para o topo da lista temp;
 * @param p lista ligada de aviões
 */
void inverte_LL_avioes(LL_avioes& p){
    LL_avioes temp;
    nova_lista_avioes(temp);
    while(p.topo!=NULL){
        adiciona_nodo_LL_avioes(temp, p.topo->dados);
        retira_nodo_LL_avioes(p);
    }
    p.topo=temp.topo;
}
/** Luis
 * Esta função cria um novo nodo, guarda o valor de dados neste nodo e liga-o ao topo da lista ligada que recebe.
 * Por fim o topo da lista ligada passa a ser o nodo que foi criado.
 * @param p lista ligada de avioes onde serão adicionados os nodos
 * @param dados dados a serem transferidos para o novo nodo
 */
void adiciona_nodo_LL_avioes(LL_avioes& p, aviao dados){
    LL_avioes::Item* novo = new LL_avioes::Item;
    novo->dados=dados;
    novo->seguinte=p.topo;
    p.topo=novo;
}
/** Luis
 * Esta função elimina um nodo de uma lista que recebe.
 * É criado um apontador aux para o topo da lista e o nodo seguinte passa a ser o topo da lista.
 * O antigo topo da lista passa a apontar para NULL e de seguida é eliminado.
 * @param p lista ligada de avioes
 */
void retira_nodo_LL_avioes(LL_avioes& p){
    LL_avioes::Item * aux = p.topo;
    p.topo=aux->seguinte;
    aux->seguinte=NULL;
    delete aux;
}


/** Luis
 * Esta função inverte a lista ligada que recebe.
 * Cria uma lista temporária e preenche-a com os nodos da lista original, adicionando um à temp e de seguida eliminando-o da lista original até a lista original estar vazia deste modo invertendo-a.
 * Quando a inversão estiver completa o apontador para o topo da lista original passa a apontar para o topo da lista temp;
 * @param p apontador para um avião onde está contida uma lista ligada com passageiros
 */
void inverte_LL_passageiros(aviao &p){
    aviao temp;
    temp.topo = NULL;
    while(p.topo!=NULL){
        (temp, p.topo->seguinte);
        adiciona_nodo_LL_passageiros(temp,p.topo->LL_passageiros);
        retira_nodo_LL_passageiros(p);
    }
    p.topo=temp.topo;
}

/** Luis
 * Esta função cria um novo nodo, guarda o valor de dados neste nodo e liga-o ao topo da lista ligada que recebe.
 * Por fim o topo da lista ligada passa a ser o nodo que foi criado.
 * @param p apontador para um avião onde está contida uma lista ligada com passageiros
 * @param dados dados a serem transferidos para o novo nodo
 */
void adiciona_nodo_LL_passageiros(aviao& p, passageiro dados){
    aviao::Item* novo = new aviao::Item;
    novo->LL_passageiros=dados;
    novo->seguinte=p.topo;
    p.topo=novo;
}
/** Luis
 * Esta função elimina um nodo de uma lista que recebe.
 * É criado um apontador aux para o topo da lista e o nodo seguinte passa a ser o topo da lista.
 * O antigo topo da lista passa a apontar para NULL e de seguida é eliminado.
 * @param p apontador para um avião onde está contida uma lista ligada de passageiros
 */
void retira_nodo_LL_passageiros(aviao& p){
    aviao::Item * aux = p.topo;
    p.topo=aux->seguinte;
    aux->seguinte=NULL;
    delete aux;
}
//////////////////////////////// FIM Inverter LL's///////////////////////////////////////

/** Luis e Sara
 * Esta função recebe um array de passageiros e adiciona-os a árvores de pesquisa binária tendo em conta a sua nacionalidade.
 * Um ciclo for percorre o array e para cada passageiro, guarda a sua nacionalidade numa string. Um iterador percorre
 * a lista ligada de nacionalidades até encontrar o nodo pretendido equivalente à nacionalidade guardada, quando este nodo é encontrado o ciclo while acaba.
 * Como a condição de paragem do ciclo while é se o iterador for igual a NULL, de modo a percorrer todos os nodos da lista,
 * é verificado se o iterador é NULL antes de tentar inserir o passageiro numa árvore.
 * Caso o iterador não seja NULL o passageiro em questão é inserido na árvore de pesquisa binária correspondete à sua nacionalidade
 * e a raiz desta atualizada com o endereço retornado pela função de inserção.
 * @param retirados array com os passageiros que foram retirados do avião
 * @param tamanho_array tamanho do array recebido
 * @param ll_nacionalidades Lista ligada de nacionalidades
 */
void adiciona_passageiros_estrangeiros(passageiro *&retirados,int tamanho_array,LL_nacionalidades &ll_nacionalidades){
    LL_nacionalidades::Item * iterator;
    for (int i = 0; i < tamanho_array; i++){
        iterator = ll_nacionalidades.topo;
        string nacionalidade = retirados[i].nacionalidade;

        while(iterator != NULL){
            if (iterator->nacionalidade == nacionalidade){
                break;
            }
            iterator = iterator->seguinte;
        }
        if(iterator!=NULL){
            iterator->raiz = inserir_passageiros_arvore(iterator->raiz,retirados[i]);
        }
    }
}

/** Luis e Sara
 * Cria um nodo para a árvore dando-lhe todas as informações do passageiro a ser inserido
 * @param novo_passageiro passageiro a ser introduzido na árvore
 * @return novo nodo da árvore
 */
passageiro* novo_nodo_arvore(passageiro novo_passageiro){
    passageiro* novo = new passageiro;
    novo->primeiro_nome = novo_passageiro.primeiro_nome;
    novo->segundo_nome = novo_passageiro.segundo_nome;
    novo->numero_bilhete = novo_passageiro.numero_bilhete;
    novo->nacionalidade = novo_passageiro.nacionalidade;
    novo->esq = NULL;
    novo->dir = NULL;
    return novo;
}

/** Luis e Sara
 * Adiciona passageiros a uma determinada árvore de pesquisa binária que é passada na função.
 * Esta função funciona recursivamente, verifica se o endereço que recebeu é NULL, o nodo será posto nesse endereço.
 * Caso não seja irá verificar se o nome é "maior" ou "menor" por ordem alfabetica, caso seja maior irá chamar a função
 * novamente para a direita do nodo atual, caso contrário irá chamar para a esquerda, até o nodo ser colocado.
 * @param pass Raiz da árvore
 * @param novo_passageiro passageiro a ser inserido
 * @return Raiz da árvore
 */
passageiro * inserir_passageiros_arvore(passageiro  *&pass, passageiro novo_passageiro){
    if (pass == NULL){
        pass = novo_nodo_arvore(novo_passageiro);
    }
    else{
        if(novo_passageiro.segundo_nome >= pass->segundo_nome)
            pass->dir = inserir_passageiros_arvore(pass->dir,novo_passageiro);
        else
            pass->esq = inserir_passageiros_arvore(pass->esq,novo_passageiro);
    }
    return pass;
}

/** Luis e Sara
 * Impressão de uma árvore de pesquisa binária
 * Faz a impressão de uma árvore de pesquisa binária com o segundo nome dos passageiros presentes na árvore.
 * Chama-se recursivamente e incrementa o nível em 1 para imprimir as subárvores esquerda e direita
 * @param pass raiz da árvore
 * @param nivel nível da árvore de pesquisa binária a imprimir
 */
void imprime_arvore(passageiro* pass, int nivel) {
    if (pass == NULL){
        cout << "" << endl;
        return;
    }
    imprime_arvore(pass->dir, nivel + 1);
    for (int i = 1; i < nivel; i++)
    {
        cout << "\t";
    }
    cout << pass->segundo_nome << endl;
    imprime_arvore(pass->esq, nivel + 1);
}

/** Sara
 * Função que remove um passageiro de uma árvore de pesquisa binária
 * Algoritmo que percorre a árvore até encontrar o passageiro a remover e efetua a sua remoção por cópia.
 * @param raiz raiz da árvore
 * @param nome nome do passageiro a remover
 */
passageiro * remover_copia(passageiro *&raiz, string nome) {
    passageiro* no = raiz;
    passageiro* ant = NULL;
    while (no != NULL) {
        if (nome == no->segundo_nome) {
            return raiz = remover_copia(raiz, no, ant);
        }
        else if (nome < no->segundo_nome) {
            ant = no;
            no = no->esq;
        }
        else {
            ant = no;
            no = no->dir;
        }
    }
    return raiz;
}

/**
 * Função que remove um passageiro de uma árvore de pesquisa binária
 * Algoritmo que percorre a árvore até encontrar o passageiro a remover e efetua a sua remoção por cópia.
 * @param raiz raiz da árvore
 * @param no nodo a remover
 * @param ant nodo anterior
 * @return nodo que foi removido
 */
passageiro* remover_copia(passageiro* raiz, passageiro* no, passageiro* ant) {
    if (ant == NULL) { //remover a raiz
        if (no->esq == NULL && no->dir == NULL)
            raiz = NULL;
        else if (no->esq != NULL && no->dir == NULL)
            raiz = no->esq;
        else if (no->esq == NULL && no->dir != NULL)
            raiz = no->dir;
        else { //efetuar copia
            passageiro* temp = no->esq;
            ant = raiz;
            while (temp->dir != NULL) {
                ant = temp;
                temp = temp->dir;
            }
            swap(temp->segundo_nome, raiz->segundo_nome);
            swap(temp->primeiro_nome, raiz->primeiro_nome);
            swap(temp->numero_bilhete, raiz->numero_bilhete);
            swap(temp->nacionalidade, raiz->nacionalidade);
            if (ant->segundo_nome >= raiz->segundo_nome || ant == raiz)
                ant->esq = temp->esq;
            else
                ant->dir = temp->esq;
            no = temp;
        }
    }
    else { // remover qualquer outro nó
        if (no->esq == NULL && no->dir == NULL) {
            if (ant->segundo_nome > no->segundo_nome)
                ant->esq = NULL;
            else
                ant->dir = NULL;
        }
        else if (no->esq == NULL && no->dir != NULL) {
            if (ant->segundo_nome > no->segundo_nome)
                ant->esq = no->dir;
            else
                ant->dir = no->dir;
        }
        else if (no->esq != NULL && no->dir == NULL) {
            if (ant->segundo_nome > no->segundo_nome)
                ant->esq = no->esq;
            else
                ant->dir = no->esq;
        }
        else { // efetuar copia
            passageiro* temp = no->esq;
            ant = no;
            while (temp->dir != NULL) {
                ant = temp;
                temp = temp->dir;
            }
            swap(temp->segundo_nome, no->segundo_nome);
            swap(temp->primeiro_nome, raiz->primeiro_nome);
            swap(temp->numero_bilhete, raiz->numero_bilhete);
            swap(temp->nacionalidade, raiz->nacionalidade);
            if (ant->segundo_nome > no->segundo_nome || ant == no)
                ant->esq = temp->esq;
            else
                ant->dir = temp->esq;
            no = temp;
        }

    }
    delete no;
    return raiz;
}
