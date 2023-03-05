// Yago Oliveira Silva
#include<iostream>
#include<iomanip>
#include <locale>
using namespace std;
int main(){
    setlocale(LC_ALL, "portuguese");            // setando idioma para portugues
    int linha,i,j,k;
    cout.precision(2);                          //setando a precisão de casas decimais
    cout.setf(ios::fixed);
    cout << "Bem vindo ao Gauss Eliminator - ";
    cout << "Metodo autonomo de eliminacao de Gauss para sistemas lineares" << endl;
    cout << "powered by Yago O." << endl;
    cout << endl;

    cout << "Para comecar, insira uma proporcao para a matriz: ";
    cin>>linha;                             //insere o numero de equacoes
    float a[linha][linha+1],x[linha];     //declarando um array para armazenar os elementos da matriz aumentada
    cout << endl;

    cout<<"Por favor, insira os numeros da sua matriz " << linha << "x" << linha << ":" << endl;
    for (i=0;i<linha;i++)
        for (j=0;j<=linha;j++)
            if (linha + 1 != j+1){
                cout << "Insira o termo independente da posicao " << j+1 << " da " << i+1 << "º equacao" << endl;
                cin >> a[i][j];                 // escaneando termo independente
                cout << endl;
            }
            else {
                cout << "Insira o resultado da "  << i+1 << "° equacao" << endl;
                cin >> a[i][j];             //escaneando resultado da equaçao
                cout << endl;
            }

    cout << endl;
    cout << " <<<< Matriz inicial >>>> " << endl;
    for (i=0;i<linha;i++){              // imprimindo a matriz inicial
        for (j=0;j<=linha;j++)
            cout<<a[i][j]<<setw(10);
            cout<<"\n";
    }

    cout << endl;
    cout << " <<<< Equacao inicial >>>> " << endl;
       for(int i = 0; i < linha; i++) {     // imprimindo a equacao inicial em ocasiões específicas de cada índice
        for(int j = 0; j < linha + 1; j++) {
            if(j < linha){
                if (i >= 0 && j > 0){
                        if ( j > 0){
                            if (a[i][j] > 0)
                                cout << "+ " << a[i][j] << " x" << j+1 <<  " ";
                                 else
                                    cout << a[i][j] << " x" << j+1 <<  " ";
                        }
                            else{
                                if (a[i][j] < 0)
                                    cout << "- " << a[i][j] << " x" << j+1 <<  " ";
                                else
                                    cout << a[i][j] << " x" << j+1 <<  " ";
                            }
                    }
                    else
                        cout << a[i][j] << " x" << j+1 <<  " ";
            }
            else
                    cout << " = " << a[i][j];
        }
        cout << endl;
      }

    for (i=0;i<linha;i++)                       //processo de pivorizacao
        for (k=i+1;k<linha;k++)
            if ((a[i][i])<(a[k][i]))
                for (j=0;j<=linha;j++){
                    double temp=a[i][j];
                    a[i][j]=a[k][j];
                    a[k][j]=temp;
                }

    cout << endl;
    cout<<" <<<< Matriz pivo >>>> " << endl;
    for (i=0;i<linha;i++){                      //imprimindo a matriz pivo
        for (j=0;j<=linha;j++)
            cout<<a[i][j]<<setw(10);
            cout<<"\n";
    }

    for (i=0;i<linha-1;i++)                     //loop para realizar a eliminacao de gauss
        for (k=i+1;k<linha;k++){
            double t=a[k][i]/a[i][i];           //encontrando valor das variáveis x's, ao dividir pelo seu coeficiente;
                for (j=0;j<=linha;j++)
                    a[k][j]=a[k][j]-t*a[i][j];  //torna os elementos abaixo dos pivos iguais a zero ou elimina as variáveis
        }

    cout << endl;
    cout<<" <<<< Matriz final >>>> " << endl;
    for (i=0;i<linha;i++){                       //imprimindo a nova matriz (final)
        for (j=0;j<=linha;j++)
            cout<<a[i][j]<<setw(10);
            cout<<"\n";
    }
    cout << endl;
    cout << " <<<< Equacao final >>>> " << endl;
     for(int i = 0; i < linha; i++) {           // imprimindo a equacao final em ocasiões específicas de cada índice
        for(int j = 0; j < linha + 1; j++) {
            if(j < linha){
                if (i >= 0 && j > 0){
                        if ( j > 0){
                            if (a[i][j] > 0)
                                cout << "+ " << a[i][j] << " x" << j+1 <<  " ";
                                 else
                                    cout << a[i][j] << " x" << j+1 <<  " ";
                        }
                            else{
                                if (a[i][j] < 0)
                                    cout << "- " << a[i][j] << " x" << j+1 <<  " ";
                                else
                                    cout << a[i][j] << " x" << j+1 <<  " ";
                            }
                }
                else
                    cout << a[i][j] << " x" << j+1 <<  " ";
            }
            else
                    cout << " = " << a[i][j];
        }
        cout << endl;
    }

    for (i=linha-1;i>=0;i--){            //substituicão de volta
                                        //x e um array cujos valores correspondem aos valores de x1,x2, x3,...
        x[i]=a[i][linha];              //torna a variavel a ser calculada igual ao lado direito da ultima equacao
        for (j=i+1;j<linha;j++)
            if (j!=i)                 //entao subtrai todos os valores do lado esquerdo exceto o coeficiente da variavel cujo valor esta sendo calculado
                x[i]=x[i]-a[i][j]*x[j];
                x[i]=x[i]/a[i][i];      //finalmente o lado direito e divido pelo coeficiente da variavel a ser calculada
    }

    cout << endl;
    cout<< " <<<< Resultado final >>>> " << endl;
    for(int i = 0; i < linha ; i++) {
        cout << "x" << i+1 << " = " << x[i] << endl;
    }
    cout << endl;                       // Imprime os valores de x1, x2,.... xn
    return 0;
}

