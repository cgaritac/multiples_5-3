//Universidad: UNED
//Curso:       Introducci�n a la programaci�n
//Tema:        Tarea 1, programa para determinar m�ltiplos de 3 y 5
//Estudiante:  Carlos Garita Campos
//Periodo:     III Cuatrimestre 2019

// Declaraci�n de bibliotecas necesarias para el programa
#include <iostream>
#include <locale>
#include <bits/stdc++.h>

// Declaraci�n de los nombres pertenecientes al "espacio de nombre" std
using namespace std;
using std::cout;
using std::cin;
using std::endl;


void encabezado(); // Definici�n de la funci�n  "encabezado"
void ingresarDatos(int[], int[]); // Definici�n de la funci�n  "ingresarDatos"
void validarRepetidos (int, int[]); // Definici�n de la funci�n  "validarRepetidos"
void categorizarNumeros(int, int[], int[] ); // Definici�n de la funci�n  "categorizarNumeros"
void imprimirTotales(int[]); // Definici�n de la funci�n  "imprimirTotales"

int leerEntero(); // Definici�n de la funci�n  "leerEntero"

int main() // Funci�n que da inicio al programa
{
    // Establece el idioma a espa�ol
    setlocale(LC_CTYPE,"Spanish");

    // Declaraci�n de variables
    int entero[15], cantidad[4] = {0, 0, 0, 0}, i;

    // Llamada a la funci�n "encabezado"
    encabezado();

    // Llamada a la funci�n "ingresarDatos"
    ingresarDatos(entero, cantidad);

    // Llamada a la funci�n "imprimirTotales"
    imprimirTotales(cantidad);

    return 0;
}

// Funci�n que muestra el encabezado del programa
void encabezado()
{
    // Se imprime informaci�n del encabezado en pantalla
    cout << "Universidad: Universidad Estatal a Distancia" << endl;
    cout << "Curso:       Introducci�n a la programaci�n" << endl;
    cout << "Tema:        Tarea 1" << endl;
    cout << "Estudiante:  Carlos Garita Campos" << endl;
    cout << "Periodo:     III Cuatrimestre" << endl;
    cout << "________________________________________________" << endl;
}

// Funci�n que ejecuta la solicitud de ingreso de los datos al usuario
void ingresarDatos(int entero[], int cantidad[])
{
    // Ciclo for que se encarga de llenar un arreglo con los 15 n�meros enteros ingresados por el usuario
    for (int i = 0; i < 15; i++)
    {
        cout << "\nIntroduzca un n�mero entero  positivo (o digite 68 para salir): [ha ingresado " << i << " n�mero(s)]" << endl;
        entero[i] = leerEntero(); // Se llama a la funci�n "leeEntero" y el valor del entero que devuelve se ingresa en el arreglo en la posici�n "i"

        validarRepetidos(i, entero); // Se llama a la funci�n "validarRepetidos" para determinar si el n�mero ingresado est� repetido, y la funci�n
                                     // solicita ingresar un nuevo n�mero en caso de que se encuentre repetido

        // Condicional if que se encarga de salir del for antes de que el ciclo termine en caso de que el usuario ingrese el 68
        if (entero[i] == 68)
        {
            cout << "------------------------------------------------" << endl;
            break; // Obliga a salir del ciclo for antes de que se complete
        }

        categorizarNumeros(i, entero, cantidad); // Se llama a la funci�n "categorizarNumeros" para determinar si es m�ltiplo de 3, de 5 o ambos

        cout << "------------------------------------------------" << endl;
    }
}

// Funci�n que valida si el n�mero ingresado por el usuario se enuentra repetido
void validarRepetidos(int i, int entero[])
{
    // Declaraci�n de variable y asignaci�n del valor "false" a la variable
    bool salida = false;

    // Ciclo while que se encarga de repetir el proceso de comparaci�n del dato ingresado por el usuario hasta que la variable "salida"
    // posea un valor de "true"
    while (salida == false)
    {
        // Se asigna el valor "true" a la variable "salida"
        salida = true;

        // Ciclo for que se encarga de recorrer el arreglo para comparar el dato ingresado por el usuario con los datos que ya se encuentran en el arreglo
        for (int j = 0; j <= i; ++j)
        {
            // Declaraci�n de variable y asignaci�n del valor del arreglo en la posici�n "j" a la variable
            int prueba = entero[j];

            // Condicional que valora si las posiciones correspondientes a los valores de "i" y "j" son iguales, y si el valor de la variable "prueba" es
            // igual al valor del arreglo en la posici�n "i"
            if ((j != i) && (prueba == entero[i]))
                {
                    cout << "\nError!, El n�mero " << entero[i] << " se encuentra repetido." << endl; // Imprime en pantalla texto y el valor del arreglo en la posici�n "i"
                    cout << "\nFavor introduzca nuevamente un n�mero entero positivo: [ha ingresado " << i << " n�mero(s)]" << endl;
                    entero[i] = leerEntero(); // Se llama a la funci�n "leeEntero" y el valor del entero que devuelve se ingresa en el arreglo
                                              //en la posici�n "i"
                    salida = false; // Asigna el valor "false" a la variable "salida"
                    break; // Obliga a salir del ciclo for antes de que se complete
                }
        }
    }
}

// Funci�n que clasifica los n�meros seg�n sean m�ltiplos de 3 o 5 o ninguno
void categorizarNumeros (int i, int entero[], int cantidad[])
{
    // Declaraci�n de variables
    int mult3;
    int mult5;

    // Condicional que valora si el valor del arreglo en la posici�n "i" es igual a cero
    if (entero[i] == 0)
    {
        // Asignaci�n del valor "1" a las variables "mult3" y "mult5"
        mult3 = 1;
        mult5 = 1;
    }else
    {
        // Obtenci�n del m�dulo de 3 y de 5 para el valor del arreglo en la posici�n "i" y asignaci�n de dicho valor a las variables "mult3" y "mult5"
        mult3 = entero[i]%3;
        mult5 = entero[i]%5;
    }

    // Condicional que valora si las variables "mult3" o "mult5" son iguales a cero
    if ((mult3 == 0) && (mult5 == 0))
    {
        cout << "\nEl n�mero " << entero[i] << " es m�ltiplo de 3 y 5." << endl; // Imprime en pantalla texto y el valor del arreglo en la posici�n "i"
        cantidad[0]++; // Suma "1" al valor que posea el arreglo en la posici�n cero
    }else
    {
        // Condicional que valora si la variable "mult3" es igual a cero
        if ((mult3 == 0))
        {
            cout << "\nEl n�mero " << entero[i] << " es m�ltiplo de 3." << endl; // Imprime en pantalla texto y el valor del arreglo en la posici�n "i"
            cantidad[1]++; // Suma "1" al valor que posea el arreglo en la posici�n "1"
        }

        // Condicional que valora si la variable "mult5" es igual a cero
        if ((mult5 == 0))
        {
            cout << "\nEl n�mero " << entero[i] << " es m�ltiplo de 5." << endl; // Imprime en pantalla texto y el valor del arreglo en la posici�n "i"
            cantidad[2]++; // Suma "1" al valor que posea el arreglo en la posici�n "2"
        }

        // Condicional que valora si las variable "mult3" y "mult5" son iguales a cero
        if ((mult3 != 0) && (mult5 != 0))
        {
            cout << "\nEl n�mero " << entero[i] << " no es m�ltiplo de 3 ni de 5." << endl; // Imprime en pantalla texto y el valor del arreglo en la posici�n "i"
            cantidad[3]++; // Suma "1" al valor que posea el arreglo en la posici�n "3"
        }
    }
}

// Funci�n que imprime el resumen de la clasificaci�n de los datos en pantalla
void imprimirTotales(int cantidad[])
{
    cout << "\nSe ingresaron " << cantidad[1] << " n�meros m�ltiplos de 3." << endl; // Imprime en pantalla texto y el valor del arreglo en la posici�n "1"
    cout << "Se ingresaron " << cantidad[2] << " n�meros m�ltiplos de 5." << endl; // Imprime en pantalla texto y el valor del arreglo en la posici�n "2"
    cout << "Se ingresaron " << cantidad[0] << " n�meros m�ltiplos de 3 y de 5." << endl; // Imprime en pantalla texto y el valor del arreglo en la posici�n "0"
    cout << "Se ingresaron " << cantidad[3] << " n�meros sin categoria." << endl; // Imprime en pantalla texto y el valor del arreglo en la posici�n "3"
}

// Funci�n que se encarga de leer y validar el dato ingresado por el usuario devuelve un entero o un mensaje de error en caso de que
// no se ingrese un entero
int leerEntero()
{
    // Declaraci�n de variables y asignaci�n de valores
  	int numero, i = 0, longitud;
  	bool prueba;
  	char valor[50] = "";

  	// Ciclo do-while que se encargar� de repetir la validaci�n del dato ingresado por el usuario hasta que el valor de la variable "prueba"
  	// sea diferente de "false"
    do{
        // Asignaci�n del valor "true" en la variable prueba
        prueba = true;

        // Asignaci�n del dato ingresado por el usuario como caracteres en el arreglo "valor"
        cin >> valor;

        // Obtenci�n de la longitud de la cadena de caracteres ingresados en el arreglo "valor"
        longitud = strlen(valor);

        // Ciclo while que se encarga de repetir el recorrido del arreglo hasta que "i" sea mayor que la longitud obtenida de la cadena o
        // prueba sea igual a false
        while (i < longitud && prueba == true)
            {
                // Condicional que valora si el dato en la posici�n "i" del arreglo es igual a cada uno de los n�meros del "1" al 9
                if (valor[i] == '1' or valor[i] == '2' or valor[i] == '3' or valor[i] == '4' or valor[i] == '5' or valor[i] == '6' or valor[i] == '7' or valor[i] == '8' or valor[i] == '9')
                {
                    i++; // Suma "1" al valor que posea la variable "i"
                }else
                {
                    prueba = false; // Asignaci�n del valor "false" en la variable prueba
                }
            }

        // Condicional que valora si la variable "prueba" es igual a "true" y si la variable "longitud" es diferentes de "0"
        if (prueba == true && longitud != 0)
        {
            numero = atoi(valor); // Convierte la cadena de caracteres que se encuentra en el arreglo a n�mero y lo asigna a la variable "n�mero"
            return numero; // Devuelve el valor de la variable "n�mero" para la funci�n "leerEntero"
        }else
        {
            cout << "\nError!, favor ingrese un n�mero entero positivo:" << endl;
        }
    }while (prueba == false); //Condici�n del ciclo do-while
}
