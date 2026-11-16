#include "AVL.h"


int main(){


    AVL arvore;


    int opcao;


    do{


        cout<<"\n===== RANKING AVL =====\n";

        cout<<"1 - Cadastrar jogador\n";

        cout<<"2 - Buscar jogador\n";

        cout<<"3 - Remover jogador\n";

        cout<<"4 - Atualizar pontuacao\n";

        cout<<"5 - Ranking crescente\n";

        cout<<"6 - Pre ordem\n";

        cout<<"7 - Em ordem\n";

        cout<<"8 - Pos ordem\n";

        cout<<"9 - Altura\n";

        cout<<"10 - Top 5 jogadores\n";

        cout<<"0 - Sair\n";

        cout<<"Opcao: ";

        cin >> opcao;


        if(cin.fail()){

            cin.clear();

            cin.ignore(1000, '\n');

            cout<<"Entrada invalida!\n";

            continue;

        }



        if(opcao==1){

            Jogador j;


            cout << "ID: ";
            cin >> j.id;


            cout << "Nome: ";
            cin.ignore();
            getline(cin, j.nome);


            cout << "Pontuacao: ";
            cin >> j.pontuacao;


            arvore.inserir(j);

        }



        else if(opcao==2){


            int p;


            cout<<"Pontuacao: ";

            cin>>p;



            Node* resultado =
            arvore.buscar(p);



            if(resultado)

                cout<<"Encontrado: "
                <<resultado->jogador.nome
                <<endl;


            else

                cout<<"Nao encontrado\n";

        }



        else if(opcao==3){


            int p;

            cout<<"Pontuacao: ";

            cin>>p;


            arvore.remover(p);

        }



        else if(opcao==4){


            int antiga,nova;


            cout<<"Pontuacao atual: ";

            cin>>antiga;


            cout<<"Nova pontuacao: ";

            cin>>nova;



            arvore.atualizarPontuacao(
                antiga,
                nova
            );

        }



        else if(opcao==5)

            arvore.mostrarEmOrdem();



        else if(opcao==6)

            arvore.mostrarPreOrdem();



        else if(opcao==7)

            arvore.mostrarEmOrdem();



        else if(opcao==8)

            arvore.mostrarPosOrdem();



        else if(opcao==9)

            arvore.mostrarAltura();



        else if(opcao==10)

            arvore.mostrarTop5();



    }while(opcao!=0);



    return 0;

}