#include "abb.h"
#include "testing.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

static void pruebas_tester(){
    abb_t *arbol = abb_crear(strcmp, NULL);

    char *clave1 = "perro", *valor1 = "guau";
    char *clave2 = "gato", *valor2 = "miau";
    char *clave3 = "vaca", *valor3 = "mu";
    char *clave4 = "loro", *valor4 = "galleta";
    char *clave5 = "cobayo", *valor5 = "quiz";
    char *clave6 = "zorro", *valor6 = "en su corcel...";

    print_test("Se inserto clave1", abb_guardar(arbol, clave1, valor1));
    print_test("Se inserto clave2", abb_guardar(arbol, clave2, valor2));
    print_test("Se inserto clave3", abb_guardar(arbol, clave3, valor3));
    print_test("Se inserto clave4", abb_guardar(arbol, clave4, valor4));
    print_test("Se inserto clave5", abb_guardar(arbol, clave5, valor5));
    print_test("Se inserto clave6", abb_guardar(arbol, clave6, valor6));
    print_test("La cantidad de elementos es 6", abb_cantidad(arbol) == 6);

    /* Pruebas sobre el abb borrar, en nodo con 1 hijo */
    print_test("Se borro clave3 del abb", valor3 == abb_borrar(arbol, clave3));
    print_test("Buscar clave3 es NULL, no pertenece", !abb_pertenece(arbol, clave3));

    /* Pruebas sobre el abb borrar, en nodo con 2 hijos */
    print_test("Se borro clave2 del abb", valor2 == abb_borrar(arbol, clave2));
    print_test("Buscar clave2 es NULL, no pertenece", !abb_pertenece(arbol, clave2));
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

void pruebas_abb_alumno(){
    pruebas_tester();
//	prueba_crear_abb_vacio();
//	prueba_abb_insertar();
//	prueba_abb_reemplazar();
//	prueba_abb_reemplazar_con_destruir();
//    prueba_abb_borrar();

}