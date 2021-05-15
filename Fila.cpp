#include <iostream>
using namespace std;
class Fila{
private:
	const int tamanho = 1023;
	int *vetFila;
	int total;
	int primeiro;
	int ultimo;
public:
	Fila(){
		vetFila = new int[tamanho];
		primeiro = 0;
		ultimo = 0;
		total = 0;
	}
	void eEnfileirar(int elemento){
		if(Fila::eCheio()){throw std::string("\n--------------->Fila Cheia<---------------\n");}
		vetFila[ultimo] = elemento;
		ultimo = ((ultimo + 1)%tamanho); 
		total++;
	}
	int eDesenfileirar(){
		if(Fila::eVazio()){throw std::string("\n--------------->Fila vazia<---------------\n");}
		int elemento = vetFila[primeiro];
		primeiro = ((primeiro + 1)%tamanho);
		total --;
		return elemento;
	}
	bool eVazio(){return total == 0;}
	bool eCheio(){return total == tamanho;}	 
};

int menu(){
	int opcao;
	cout<<"\n1 - Enfileirar"<<endl;
	cout<<"2 - Desenfileirar"<<endl;
	cout<<"3 - Mostrar Fila"<<endl;
	cout<<"0 - Sair"<<endl;
	cin>>opcao;
	return opcao;
}

int main(){
	Fila *fila = new Fila();
	int valor;
	int opcao = menu();
	while(opcao != 0){
		switch(opcao){
			case 1:
				try{
					cout<<"\nDigite um valor para enfileirar-> ";
				    cin>>valor;
			    	fila->eEnfileirar(valor);
				}catch(string &erro){
					cout<<erro<<endl;
				}
			break;
			case 2:
				try{
					cout<<"\nValor desenfileirado-> "<<fila->eDesenfileirar()<<endl;
				}catch(string &erro){
					cout<<erro<<endl;
				}
			break;
			default:
			cout<<"Opcao invalida"<<endl;
			break;
		}
		opcao = menu();
	}
	cout<<"\nFinalizado!"<<endl;
	return 0;
}
