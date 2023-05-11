import os
import time
from playsound import playsound
import notificaciones

alarmaPath = os.path.realpath('alarma.wav')

contadorCiclo : int = 0 

def sonido():
    playsound(str(alarmaPath), False)

def cerrar():
    print("Hasta pronto!")
    time.sleep(2)

def aviso():
    global contadorCiclo
    notificaciones.notificar()
    sonido()
    
    if contadorCiclo != 4:
        print("\nHan pasado 30 minutos, debes descansar mínimo 5 minutos tus ojos. Distráete un rato.")
        valorContinuar = input("¿Deseas continuar? (S/N): ")
        
        if valorContinuar.lower() == 's':
            iniciarTiempo()
        elif valorContinuar.lower() == 'n':
            cerrar()
        else:
            print("Opcion invalida.")
            aviso()
    else:
        print("\nHan pasado 2 horas, debes relajarte y dejar de ver la computadora al menos 15 minutos, para evitar problemas visuales a largo plazo.")
        valorContinuar = input("¿Deseas continuar? (S/N): ")
        
        if valorContinuar.lower() == 's':
            valorContinuar = 0
            iniciarTiempo()
        elif valorContinuar.lower() == 'n':
            cerrar()
        else:
            print("Opcion invalida.")
            aviso()

def iniciarTiempo():
    global contadorCiclo
    print("\nEl tiempo empezó a contar. (30 minutos)")
    print("Por favor, no cierres la consola.")
    time.sleep(10) # Tiempo de espera de contador
    contadorCiclo += 1
    aviso()
    
def main():
    def preguntar():
        
        valorContinuar = input("¿Deseas iniciar? (S/N): ")
        if valorContinuar.lower() == 's':
            iniciarTiempo()
        elif valorContinuar.lower() == 'n':
            cerrar()
        else:
            print("ERROR: Opción inválida.")
            preguntar()
            
    print("¡Bienvenido a la alarma eyeHealth!")
    print("Autores: De la Cruz J.W., Gomez A.F., Lucano D.A., Novoa B.J., Quezada R.E. & Velasquez T.J.")
    print("Esperamos esta herramienta sea de tu agrado.")

    preguntar()
    
main()