//Universidad: UNED
//Curso:       Introducción a la programación
//Tema:        Tarea 1, programa para determinar múltiplos de 3 y 5
//Estudiante:  Carlos Garita Campos
//Periodo:     III Cuatrimestre 2019

// Declaración de bibliotecas necesarias para el programa
#include <iostream>
#include <locale>
#include <bits/stdc++.h>

// Declaración de los nombres pertenecientes al "espacio de nombre" std
using namespace std;
using std::cout;
using std::cin;
using std::endl;


void encabezado(); // Definición de la función  "encabezado"
void ingresarDatos(int[], int[]); // Definición de la función  "ingresarDatos"
void validarRepetidos (int, int[]); // Definición de la función  "validarRepetidos"
void categorizarNumeros(int, int[], int[] ); // Definición de la función  "categorizarNumeros"
void imprimirTotales(int[]); // Definición de la función  "imprimirTotales"

int leerEntero(); // Definición de la función  "leerEntero"

int main() // Función que da inicio al programa
{
    // Establece el idioma a español
    setlocale(LC_CTYPE,"Spanish");

    // Declaración de variables
    int entero[15], cantidad[4] = {0, 0, 0, 0}, i;

    // Llamada a la función "encabezado"
    encabezado();

    // Llamada a la función "ingresarDatos"
    ingresarDatos(entero, cantidad);

    // Llamada a la función "imprimirTotales"
    imprimirTotales(cantidad);

    return 0;
}

// Función que muestra el encabezado del programa
void encabezado()
{
    // Se imprime información del encabezado en pantalla
    cout << "Universidad: Universidad Estatal a Distancia" << endl;
    cout << "Curso:       Introducción a la programación" << endl;
    cout << "Tema:        Tarea 1" << endl;
    cout << "Estudiante:  Carlos Garita Campos" << endl;
    cout << "Periodo:     III Cuatrimestre" << endl;
    cout << "________________________________________________" << endl;
}

// Función que ejecuta la solicitud de ingreso de los datos al usuario
void ingresarDatos(int entero[], int cantidad[])
{
    // Ciclo for que se encarga de llenar un arreglo con los 15 números enteros ingresados por el usuario
    for (int i = 0; i < 15; i++)
    {
        cout << "\nIntroduzca un número entero  positivo (o digite 68 para salir): [ha ingresado " << i << " número(s)]" << endl;
        entero[i] = leerEntero(); // Se llama a la función "leeEntero" y el valor del entero que devuelve se ingresa en el arreglo en la posición "i"

        validarRepetidos(i, entero); // Se llama a la función "validarRepetidos" para determinar si el número ingresado está repetido, y la función
                                     // solicita ingresar un nuevo número en caso de que se encuentre repetido

        // Condicional if que se encarga de salir del for antes de que el ciclo termine en caso de que el usuario ingrese el 68
        if (entero[i] == 68)
        {
            cout << "------------------------------------------------" << endl;
            break; // Obliga a salir del ciclo for antes de que se complete
        }

        categorizarNumeros(i, entero, cantidad); // Se llama a la función "categorizarNumeros" para determinar si es múltiplo de 3, de 5 o ambos

        cout << "------------------------------------------------" << endl;
    }
}

// Función que valida si el número ingresado por el usuario se enuentra repetido
void validarRepetidos(int i, int entero[])
{
    // Declaración de variable y asignación del valor "false" a la variable
    bool salida = false;

    // Ciclo while que se encarga de repetir el proceso de comparación del dato ingresado por el usuario hasta que la variable "salida"
    // posea un valor de "true"
    while (salida == false)
    {
        // Se asigna el valor "true" a la variable "salida"
        salida = true;

        // Ciclo for que se encarga de recorrer el arreglo para comparar el dato ingresado por el usuario con los datos que ya se encuentran en el arreglo
        for (int j = 0; j <= i; ++j)
        {
            // Declaración de variable y asignación del valor del arreglo en la posición "j" a la variable
            int prueba = entero[j];

            // Condicional que valora si las posiciones correspondientes a los valores de "i" y "j" son iguales, y si el valor de la variable "prueba" es
            // igual al valor del arreglo en la posición "i"
            if ((j != i) && (prueba == entero[i]))
                {
                    cout << "\nError!, El número " << entero[i] << " se encuentra repetido." << endl; // Imprime en pantalla texto y el valor del arreglo en la posición "i"
                    cout << "\nFavor introduzca nuevamente un número entero positivo: [ha ingresado " << i << " número(s)]" << endl;
                    entero[i] = leerEntero(); // Se llama a la función "leeEntero" y el valor del entero que devuelve se ingresa en el arreglo
                                              //en la posición "i"
                    salida = false; // Asigna el valor "false" a la variable "salida"
                    break; // Obliga a salir del ciclo for antes de que se complete
                }
        }
    }
}

// Función que clasifica los números según sean múltiplos de 3 o 5 o ninguno
void categorizarNumeros (int i, int entero[], int cantidad[])
{
    // Declaración de variables
    int mult3;
    int mult5;

    // Condicional que valora si el valor del arreglo en la posición "i" es igual a cero
    if (entero[i] == 0)
    {
        // Asignación del valor "1" a las variables "mult3" y "mult5"
        mult3 = 1;
        mult5 = 1;
    }else
    {
        // Obtención del módulo de 3 y de 5 para el valor del arreglo en la posición "i" y asignación de dicho valor a las variables "mult3" y "mult5"
        mult3 = entero[i]%3;
        mult5 = entero[i]%5;
    }

    // Condicional que valora si las variables "mult3" o "mult5" son iguales a cero
    if ((mult3 == 0) && (mult5 == 0))
    {
        cout << "\nEl número " << entero[i] << " es múltiplo de 3 y 5." << endl; // Imprime en pantalla texto y el valor del arreglo en la posición "i"
        cantidad[0]++; // Suma "1" al valor que posea el arreglo en la posición cero
    }else
    {
        // Condicional que valora si la variable "mult3" es igual a cero
        if ((mult3 == 0))
        {
            cout << "\nEl número " << entero[i] << " es múltiplo de 3." << endl; // Imprime en pantalla texto y el valor del arreglo en la posición "i"
            cantidad[1]++; // Suma "1" al valor que posea el arreglo en la posición "1"
        }

        // Condicional que valora si la variable "mult5" es igual a cero
        if ((mult5 == 0))
        {
            cout << "\nEl número " << entero[i] << " es múltiplo de 5." << endl; // Imprime en pantalla texto y el valor del arreglo en la posición "i"
            cantidad[2]++; // Suma "1" al valor que posea el arreglo en la posición "2"
        }

        // Condicional que valora si las variable "mult3" y "mult5" son iguales a cero
        if ((mult3 != 0) && (mult5 != 0))
        {
            cout << "\nEl número " << entero[i] << " no es múltiplo de 3 ni de 5." << endl; // Imprime en pantalla texto y el valor del arreglo en la posición "i"
            cantidad[3]++; // Suma "1" al valor que posea el arreglo en la posición "3"
        }
    }
}

// Función que imprime el resumen de la clasificación de los datos en pantalla
void imprimirTotales(int cantidad[])
{
    cout << "\nSe ingresaron " << cantidad[1] << " números múltiplos de 3." << endl; // Imprime en pantalla texto y el valor del arreglo en la posición "1"
    cout << "Se ingresaron " << cantidad[2] << " números múltiplos de 5." << endl; // Imprime en pantalla texto y el valor del arreglo en la posición "2"
    cout << "Se ingresaron " << cantidad[0] << " números múltiplos de 3 y de 5." << endl; // Imprime en pantalla texto y el valor del arreglo en la posición "0"
    cout << "Se ingresaron " << cantidad[3] << " números sin categoria." << endl; // Imprime en pantalla texto y el valor del arreglo en la posición "3"
}

// Función que se encarga de leer y validar el dato ingresado por el usuario devuelve un entero o un mensaje de error en caso de que
// no se ingrese un entero
int leerEntero()
{
    // Declaración de variables y asignación de valores
  	int numero, i = 0, longitud;
  	bool prueba;
  	char valor[50] = "";

  	// Ciclo do-while que se encargará de repetir la validación del dato ingresado por el usuario hasta que el valor de la variable "prueba"
  	// sea diferente de "false"
    do{
        // Asignación del valor "true" en la variable prueba
        prueba = true;

        // Asignación del dato ingresado por el usuario como caracteres en el arreglo "valor"
        cin >> valor;

        // Obtención de la longitud de la cadena de caracteres ingresados en el arreglo "valor"
        longitud = strlen(valor);

        // Ciclo while que se encarga de repetir el recorrido del arreglo hasta que "i" sea mayor que la longitud obtenida de la cadena o
        // prueba sea igual a false
        while (i < longitud && prueba == true)
            {
                // Condicional que valora si el dato en la posición "i" del arreglo es igual a cada uno de los números del "1" al 9
                if (valor[i] == '1' or valor[i] == '2' or valor[i] == '3' or valor[i] == '4' or valor[i] == '5' or valor[i] == '6' or valor[i] == '7' or valor[i] == '8' or valor[i] == '9')
                {
                    i++; // Suma "1" al valor que posea la variable "i"
                }else
                {
                    prueba = false; // Asignación del valor "false" en la variable prueba
                }
            }

        // Condicional que valora si la variable "prueba" es igual a "true" y si la variable "longitud" es diferentes de "0"
        if (prueba == true && longitud != 0)
        {
            numero = atoi(valor); // Convierte la cadena de caracteres que se encuentra en el arreglo a número y lo asigna a la variable "número"
            return numero; // Devuelve el valor de la variable "número" para la función "leerEntero"
        }else
        {
            cout << "\nError!, favor ingrese un número entero positivo:" << endl;
        }
    }while (prueba == false); //Condición del ciclo do-while
}
