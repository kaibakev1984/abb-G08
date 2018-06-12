#include "abb.h"
#include "testing.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

static void pruebas_tester(){
    abb_t *arbol = abb_crear(strcmp, NULL);
    char *clave1 = "1", *valor1 = "1";
    char *clave2 = "2", *valor2 = "2";
    char *clave3 = "3", *valor3 = "3";
    char *clave4 = "4", *valor4 = "4";
    char *clave5 = "5", *valor5 = "5";

    /* Procedo a insertar todas las claves en el abb */
    print_test("Se inserto clave1", abb_guardar(arbol, clave1, valor1));
    print_test("Se inserto clave2", abb_guardar(arbol, clave2, valor2));
    print_test("Se inserto clave4", abb_guardar(arbol, clave4, valor4));
    print_test("Se inserto clave3", abb_guardar(arbol, clave3, valor3));
    print_test("Se inserto clave5", abb_guardar(arbol, clave5, valor5));

    /* Se procede a borrar los elementos del abb */
    print_test("Se borro clave1", valor1 == abb_borrar(arbol, clave1));
    print_test("Se borro clave2", valor2 == abb_borrar(arbol, clave2));
    print_test("Se borro clave4", valor4 == abb_borrar(arbol, clave4));
    print_test("Se borro clave3", valor3 == abb_borrar(arbol, clave3));
    print_test("Se borro clave5", valor5 == abb_borrar(arbol, clave5));

    abb_destruir(arbol);
}

void prueba_crear_abb_vacio(){
	abb_t *arbol = abb_crear(NULL, NULL);
	print_test("abb fue creado", arbol);
	print_test("Prueba abb cantidad de elementos es 0", !abb_cantidad(arbol));
	print_test("Prueba abb obtener clave A, es NULL, no existe", !abb_obtener(arbol, "A"));
	print_test("Prueba abb pertenece clave A, es NULL, no existe", !abb_pertenece(arbol, "A"));
	print_test("Prueba abb borrar con clave A, es NULL, no existe", !abb_borrar(arbol, "A"));

	abb_destruir(arbol);
}

void prueba_abb_insertar(){
	abb_t *arbol = abb_crear(strcmp, NULL);

	char *clave1 = "perro", *valor1 = "guau";
	char *clave2 = "gato", *valor2 = "miau";
	char *clave3 = "vaca", *valor3 = "mu";

	/* Inserta un valor, y luego lo borra */
	print_test("Prueba abb insertar clave1", abb_guardar(arbol, clave1, valor1));
	print_test("Prueba abb la cantidad de elementos es 1", abb_cantidad(arbol) == 1);
	print_test("Prueba abb obtener clave1 es valor1", abb_obtener(arbol, clave1) == valor1);
	print_test("Prueba abb pertenece clave1, es true", abb_pertenece(arbol, clave1));
	print_test("Prueba abb borrar clave1, es valor1", abb_borrar(arbol, clave1) == valor1);
	print_test("Prueba abb cantidad de elementos es 0", !abb_cantidad(arbol));

	/* Inserta otros 2 valores y no los borra (se destruye con el abb) */
	print_test("Prueba abb insertar clave2", abb_guardar(arbol, clave2, valor2));
	print_test("Prueba abb la cantidad de elementos es 1", abb_cantidad(arbol) == 1);
	print_test("Prueba abb obtener clave2 es valor2", abb_obtener(arbol, clave2) == valor2);
	print_test("Prueba abb pertenece clave1, es true", abb_pertenece(arbol, clave2));
	
	print_test("Prueba abb insertar clave3", abb_guardar(arbol, clave3, valor3));
	print_test("Prueba abb la cantidad de elementos es 2", abb_cantidad(arbol) == 2);
	print_test("Prueba abb obtener clave3 es valor3", abb_obtener(arbol, clave3) == valor3);
	print_test("Prueba abb pertenece clave3, es true", abb_pertenece(arbol, clave3));
	
	abb_destruir(arbol);
}

void prueba_abb_reemplazar(){
	abb_t *arbol = abb_crear(strcmp, NULL);

    char *clave1 = "perro", *valor1a = "guau", *valor1b = "warf";
    char *clave2 = "gato", *valor2a = "miau", *valor2b = "meaow";

    /* Inserta 2 valores y luego los reemplaza */
    print_test("Prueba abb insertar clave1", abb_guardar(arbol, clave1, valor1a));
    print_test("Prueba abb obtener clave1 es valor1a", abb_obtener(arbol, clave1) == valor1a);
    print_test("Prueba abb insertar clave2", abb_guardar(arbol, clave2, valor2a));
    print_test("Prueba abb obtener clave2 es valor2a", abb_obtener(arbol, clave2) == valor2a);
    print_test("Prueba abb la cantidad de elementos es 2", abb_cantidad(arbol) == 2);

    print_test("Prueba abb insertar clave1 con otro valor", abb_guardar(arbol, clave1, valor1b));
    print_test("Prueba abb obtener clave1 es valor1b", abb_obtener(arbol, clave1) == valor1b);
    print_test("Prueba abb obtener clave1 es valor1b", abb_obtener(arbol, clave1) == valor1b);
    print_test("Prueba abb insertar clave2 con otro valor", abb_guardar(arbol, clave2, valor2b));
    print_test("Prueba abb obtener clave2 es valor2b", abb_obtener(arbol, clave2) == valor2b);
    print_test("Prueba abb obtener clave2 es valor2b", abb_obtener(arbol, clave2) == valor2b);
    print_test("Prueba abb la cantidad de elementos es 2", abb_cantidad(arbol) == 2);

    abb_destruir(arbol);
}

void prueba_abb_reemplazar_con_destruir(){
	abb_t *arbol = abb_crear(strcmp, free);

    char *clave1 = "perro", *valor1a, *valor1b;
    char *clave2 = "gato", *valor2a, *valor2b;

    /* Pide memoria para 4 valores */
    valor1a = malloc(10 * sizeof(char));
    valor1b = malloc(10 * sizeof(char));
    valor2a = malloc(10 * sizeof(char));
    valor2b = malloc(10 * sizeof(char));

    /* Inserta 2 valores y luego los reemplaza (debe liberar lo que reemplaza) */
    print_test("Prueba abb insertar clave1", abb_guardar(arbol, clave1, valor1a));
    print_test("Prueba abb obtener clave1 es valor1a", abb_obtener(arbol, clave1) == valor1a);
    print_test("Prueba abb obtener clave1 es valor1a", abb_obtener(arbol, clave1) == valor1a);
    print_test("Prueba abb insertar clave2", abb_guardar(arbol, clave2, valor2a));
    print_test("Prueba abb obtener clave2 es valor2a", abb_obtener(arbol, clave2) == valor2a);
    print_test("Prueba abb obtener clave2 es valor2a", abb_obtener(arbol, clave2) == valor2a);
    print_test("Prueba abb la cantidad de elementos es 2", abb_cantidad(arbol) == 2);

    print_test("Prueba abb insertar clave1 con otro valor", abb_guardar(arbol, clave1, valor1b));
    print_test("Prueba abb obtener clave1 es valor1b", abb_obtener(arbol, clave1) == valor1b);
    print_test("Prueba abb obtener clave1 es valor1b", abb_obtener(arbol, clave1) == valor1b);
    print_test("Prueba abb insertar clave2 con otro valor", abb_guardar(arbol, clave2, valor2b));
    print_test("Prueba abb obtener clave2 es valor2b", abb_obtener(arbol, clave2) == valor2b);
    print_test("Prueba abb obtener clave2 es valor2b", abb_obtener(arbol, clave2) == valor2b);
    print_test("Prueba abb la cantidad de elementos es 2", abb_cantidad(arbol) == 2);

    /* Se destruye el abb (se debe liberar lo que quedó dentro) */
    abb_destruir(arbol);
}

void prueba_abb_borrar(){
    abb_t *arbol = abb_crear(strcmp, NULL);

    
    char *clave1 = "perro", *valor1 = "guau";
    char *clave2 = "gato", *valor2 = "miau";
    char *clave3 = "vaca", *valor3 = "mu";

    /* Inserta 3 valores y luego los borra */
    print_test("Prueba abb insertar clave1", abb_guardar(arbol, clave1, valor1));
    print_test("Prueba abb insertar clave2", abb_guardar(arbol, clave2, valor2));
    print_test("Prueba abb insertar clave3", abb_guardar(arbol, clave3, valor3));

    /* Al borrar cada elemento comprueba que ya no está pero los otros sí. */
    print_test("Prueba abb pertenece clave3, es verdadero", abb_pertenece(arbol, clave3));
    print_test("Prueba abb borrar clave3, es valor3", abb_borrar(arbol, clave3) == valor3);
    print_test("Prueba abb borrar clave3, es NULL", !abb_borrar(arbol, clave3));
    print_test("Prueba abb pertenece clave3, es falso", !abb_pertenece(arbol, clave3));
    print_test("Prueba abb obtener clave3, es NULL", !abb_obtener(arbol, clave3));
    print_test("Prueba abb la cantidad de elementos es 2", abb_cantidad(arbol) == 2);

    print_test("Prueba abb pertenece clave1, es verdadero", abb_pertenece(arbol, clave1));
    print_test("Prueba abb borrar clave1, es valor1", abb_borrar(arbol, clave1) == valor1);
    print_test("Prueba abb borrar clave1, es NULL", !abb_borrar(arbol, clave3));
    print_test("Prueba abb pertenece clave1, es falso", !abb_pertenece(arbol, clave1));
    print_test("Prueba abb obtener clave1, es NULL", !abb_obtener(arbol, clave1));
    print_test("Prueba abb la cantidad de elementos es 1", abb_cantidad(arbol) == 1);

    print_test("Prueba abb pertenece clave2, es verdadero", abb_pertenece(arbol, clave2));
    print_test("Prueba abb borrar clave2, es valor2", abb_borrar(arbol, clave2) == valor2);
    print_test("Prueba abb borrar clave2, es NULL", !abb_borrar(arbol, clave3));
    print_test("Prueba abb pertenece clave2, es falso", !abb_pertenece(arbol, clave2));
    print_test("Prueba abb obtener clave2, es NULL", !abb_obtener(arbol, clave2));
    print_test("Prueba abb la cantidad de elementos es 0", abb_cantidad(arbol) == 0);

    abb_destruir(arbol);

}

void prueba_abb_clave_vacia(){

    abb_t *arbol = abb_crear(strcmp, NULL);
    char *clave = "", *valor = "";

    print_test("Pruebas abb guardar clave vacia", abb_guardar(arbol, clave, valor));
    print_test("Prueba abb la cantidad de elementos es 1", abb_cantidad(arbol) == 1);
    print_test("Prueba abb obtener clave vacia es valor", abb_obtener(arbol, clave));
    print_test("Prueba abb pertenece clave vacia, es true", abb_pertenece(arbol, clave));
    print_test("Prueba abb borrar clave vacia, es valor", abb_borrar(arbol, clave) == valor);
    print_test("Prueba abb la cantidad de elementos es 0", !abb_cantidad(arbol));

    abb_destruir(arbol);
}

void prueba_abb_valor_null()
{
    abb_t *arbol = abb_crear(strcmp, NULL);
    char *clave = "", *valor = NULL;

    /* Inserta 1 valor y luego lo borra */
    print_test("Prueba abb insertar clave vacia valor NULL", abb_guardar(arbol, clave, valor));
    print_test("Prueba abb la cantidad de elementos es 1", abb_cantidad(arbol) == 1);
    print_test("Prueba abb obtener clave vacia es valor NULL", abb_obtener(arbol, clave) == valor);
    print_test("Prueba abb pertenece clave vacia, es true", abb_pertenece(arbol, clave));
    print_test("Prueba abb borrar clave vacia, es valor NULL", abb_borrar(arbol, clave) == valor);
    print_test("Prueba abb la cantidad de elementos es 0", !abb_cantidad(arbol));

    abb_destruir(arbol);
}

void prueba_abb_volumen(size_t largo, bool debug)
{
    abb_t *arbol = abb_crear(strcmp, NULL);

    const size_t largo_clave = 10;
    char (*claves)[largo_clave] = malloc(largo * largo_clave);

    unsigned* valores[largo];

    /* Inserta 'largo' parejas en el abb */
    bool ok = true;
    for (unsigned i = 0; i < largo; i++) {
        valores[i] = malloc(sizeof(int));
        sprintf(claves[i], "%08d", i);
        *valores[i] = i;
        ok = abb_guardar(arbol, claves[i], valores[i]);
        if (!ok) break;
    }

    if (debug) print_test("Prueba abb almacenar muchos elementos", ok);
    if (debug) print_test("Prueba abb la cantidad de elementos es correcta", abb_cantidad(arbol) == largo);

    /* Verifica que devuelva los valores correctos */
    for (size_t i = 0; i < largo; i++) {
        ok = abb_pertenece(arbol, claves[i]);
        if (!ok) break;
        ok = abb_obtener(arbol, claves[i]) == valores[i];
        if (!ok) break;
    }

    if (debug) print_test("Prueba abb pertenece y obtener muchos elementos", ok);
    if (debug) print_test("Prueba abb la cantidad de elementos es correcta", abb_cantidad(arbol) == largo);

    /* Verifica que borre y devuelva los valores correctos */
    for (size_t i = 0; i < largo; i++) {
        ok = abb_borrar(arbol, claves[i]) == valores[i];
        if (!ok) break;
    }

    if (debug) print_test("Prueba abb borrar muchos elementos", ok);
    if (debug) print_test("Prueba abb la cantidad de elementos es 0", abb_cantidad(arbol) == 0);

    /* Destruye el abb y crea uno nuevo que sí libera */
    abb_destruir(arbol);
    arbol = abb_crear(strcmp, free);

    /* Inserta 'largo' parejas en el abb */
    ok = true;
    for (size_t i = 0; i < largo; i++) {
        ok = abb_guardar(arbol, claves[i], valores[i]);
        if (!ok) break;
    }

    free(claves);

    /* Destruye el abb - debería liberar los enteros */
    abb_destruir(arbol);

}

void pruebas_abb_alumno(){
    pruebas_tester();
//	prueba_crear_abb_vacio();
//	prueba_abb_insertar();
//	prueba_abb_reemplazar();
//	prueba_abb_reemplazar_con_destruir();
//  prueba_abb_borrar();
//  prueba_abb_clave_vacia();
//  prueba_abb_valor_null();
//  prueba_abb_volumen(5000, true);
}