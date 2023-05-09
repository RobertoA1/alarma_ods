#include <iostream>
#include <windows.h>
#include <mmsystem.h>
#pragma comment(lib,"winmm.lib")

using namespace std;

#include <iostream>
#include <thread>
#include <chrono>
using namespace std::chrono_literals;
using namespace std;
int sonido30Minutos(){
    PlaySound(TEXT("alarma.wav"), NULL, SND_SYNC);
    return 0;
}

/* int continuar(){
    char valorContinuar;
    cout << "Deseas continuar? (S/N)";
    cin >> valorContinuar;

    if (valorContinuar == 'S' || valorContinuar == 's'){
        iniciar();
    }
} */

int iniciar(int status){ // * 0 = "Inicia o confirmó continuar" y si es 1 = "Continua"
    char valorContinuar;
    if (status == 0){
        int n;
        cout<<"El tiempo empieza a correr desde ahora. (30 minutos)" << endl;
        cout<<"Por favor, no cierres la consola." << endl;
        std::this_thread::sleep_for(std::chrono::seconds(10));
        sonido30Minutos();
        iniciar(1);
        // continuar();
    } else {
        cout << "Deseas continuar? (S/N): ";
        cin >> valorContinuar;
        cout << endl;
        if (valorContinuar == 'S' || valorContinuar == 's'){
            iniciar(0);
        } else if (valorContinuar == 'N' || valorContinuar == 'n'){
            cout << "Hasta pronto.";
            std::this_thread::sleep_for(std::chrono::seconds(2));
        } else {
            cout << "Opcion invalida.";
            iniciar(1);
        }
    }
}

int main() {
	char n, valorContinuar;
	cout << "Bienvenido a la alarma eyeHealth." << endl;
    cout << "Autores: De la Cruz J.W., Gomez A.F., Lucano D.A., Novoa B.J., Quezada R.E. & Velasquez T.J." << endl;
	cout<<"Quieres iniciar? (S/N): ";
	cin>>n;

    if (n == 'S' || n == 's'){
        iniciar(0);
    } else if (n == 'N' || n == 'n') {
        cout << "Hasta pronto.";
        std::this_thread::sleep_for(std::chrono::seconds(2));
    }
	
	return 0;
}

