#include "abb.h"
#include "testing.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

void pruebas_tester(){
    abb_t *arbol = abb_crear(strcmp, NULL);

    char *clave1 = "perro", *valor1 = "guau";
    char *clave2 = "gato", *valor2 = "miau";
    char *clave3 = "vaca", *valor3 = "mu";
    char *clave4 = "loro", *valor4 = "galleta";
    char *clave5 = "cobayo", *valor5 = "quiz";
    char *clave6 = "zorro", *valor6 = "en su corcel...";
    char *clave7 = "delfin", *valor7 = "jeje";
    char *clave8 = "bufalo", *valor8 = "pff";
    char *clave9 = "morsa", *valor9 = "ooo";
    char *clave10 = "iguana", *valor10 = "glu";
    char *clave11 = "elefante", *valor11 = "ruu";



    print_test("Se inserto clave1", abb_guardar(arbol, clave1, valor1));
    print_test("Se inserto clave2", abb_guardar(arbol, clave2, valor2));
    print_test("Se inserto clave3", abb_guardar(arbol, clave3, valor3));
    print_test("Se inserto clave4", abb_guardar(arbol, clave4, valor4));
    print_test("Se inserto clave5", abb_guardar(arbol, clave5, valor5));
    print_test("Se inserto clave6", abb_guardar(arbol, clave6, valor6));
    print_test("Se inserto clave7", abb_guardar(arbol, clave7, valor7));
    print_test("Se inserto clave8", abb_guardar(arbol, clave8, valor8));
    print_test("Se inserto clave9", abb_guardar(arbol, clave9, valor9));
    print_test("Se inserto clave10", abb_guardar(arbol, clave10, valor10));
    print_test("Se inserto clave10", abb_guardar(arbol, clave11, valor11));
    print_test("La cantidad de elementos es 11", abb_cantidad(arbol) == 11);


    print_test("Se borro clave11 del abb", valor11 == abb_borrar(arbol, clave11));
    print_test("Buscar clave11 es NULL, no pertenece", !abb_pertenece(arbol, clave11));
    print_test("Se borro clave10 del abb", valor10 == abb_borrar(arbol, clave10));
    print_test("Buscar clave10 es NULL, no pertenece", !abb_pertenece(arbol, clave10));
    print_test("Se borro clave9 del abb", valor9 == abb_borrar(arbol, clave9));
    print_test("Buscar clave9 es NULL, no pertenece", !abb_pertenece(arbol, clave9));
    print_test("Se borro clave8 del abb", valor8 == abb_borrar(arbol, clave8));
    print_test("Buscar clave8 es NULL, no pertenece", !abb_pertenece(arbol, clave8));
    print_test("Se borro clave7 del abb", valor7 == abb_borrar(arbol, clave7));
    print_test("Buscar clave7 es NULL, no pertenece", !abb_pertenece(arbol, clave7));
    print_test("Se borro clave6 del abb", valor6 == abb_borrar(arbol, clave6));
    print_test("Buscar clave6 es NULL, no pertenece", !abb_pertenece(arbol, clave6));
    print_test("Se borro clave5 del abb", valor5 == abb_borrar(arbol, clave5));
    print_test("Buscar clave5 es NULL, no pertenece", !abb_pertenece(arbol, clave5));
    print_test("Se borro clave4 del abb", valor4 == abb_borrar(arbol, clave4));
    print_test("Buscar clave4 es NULL, no pertenece", !abb_pertenece(arbol, clave4));
    print_test("Se borro clave3 del abb", valor3 == abb_borrar(arbol, clave3));
    print_test("Buscar clave3 es NULL, no pertenece", !abb_pertenece(arbol, clave3));
    print_test("Se borro clave2 del abb", valor2 == abb_borrar(arbol, clave2));
    print_test("Buscar clave2 es NULL, no pertenece", !abb_pertenece(arbol, clave2));
    print_test("Se borro clave1 del abb", valor1 == abb_borrar(arbol, clave1));
    print_test("Buscar clave1 es NULL, no pertenece", !abb_pertenece(arbol, clave1));

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

void reemplazar(int*dato,int* extra){
    extra[0] += *dato;
}

bool wrapper(const char*clave,void* dato,void*extra){
    if (dato == NULL) return false;
    printf("%s\n",clave );
    if (!strcmp(clave,"elefante"))return false;
    reemplazar((int*)dato,(int*)extra);
    return true;
}

void pruebas_iterador_interno(){
    abb_t *arbol = abb_crear(strcmp, NULL);

    char *clave1 = "perro";
    char *clave2 = "gato";
    char *clave3 = "vaca";
    char *clave4 = "loro";
    char *clave5 = "cobayo";
    char *clave6 = "zorro";
    char *clave7 = "delfin";
    char *clave8 = "bufalo";
    char *clave9 = "morsa";
    char *clave10 = "iguana";
    char *clave11 = "elefante";

    int x1 = 1;
    int x2 = 2;
    int x3 = 3;
    int x4 = 4;
    int x5 = 5;
    int x6 = 6;
    int x7 = 7;
    int x8 = 8;
    int x9 = 9;
    int x10 = 10;
    int x11 = 11;

    print_test("Prueba abb insertar clave1", abb_guardar(arbol, clave1, &x1));
    print_test("Prueba abb insertar clave2", abb_guardar(arbol, clave2, &x2));
    print_test("Prueba abb insertar clave3", abb_guardar(arbol, clave3, &x3));
    print_test("Prueba abb insertar clave4", abb_guardar(arbol, clave4, &x4));
    print_test("Prueba abb insertar clave5", abb_guardar(arbol, clave5, &x5));
    print_test("Prueba abb insertar clave6", abb_guardar(arbol, clave6, &x6));
    print_test("Prueba abb insertar clave7", abb_guardar(arbol, clave7, &x7));
    print_test("Prueba abb insertar clave8", abb_guardar(arbol, clave8, &x8));
    print_test("Prueba abb insertar clave9", abb_guardar(arbol, clave9, &x9));
    print_test("Prueba abb insertar clave10", abb_guardar(arbol, clave10, &x10));
    print_test("Prueba abb insertar clave11", abb_guardar(arbol, clave11, &x11));


    int extra[1];
    extra[0] = 0;
    
    abb_in_order(arbol,wrapper,extra);
    printf("extra es ahora %d la suma real es %d\n",extra[0],(x5 + x7 + x8 ) );
    print_test("extra ahora guarda la suma de todos los datos",extra[0] ==  (x8 + x7  + x5 ));
    abb_destruir(arbol);
  }

void pruebas_iterador_externo(){
   abb_t *arbol = abb_crear(strcmp, NULL);

   char *clave1 = "perro", *valor1 = "guau";
   char *clave2 = "gato", *valor2 = "miau";
   char *clave3 = "vaca", *valor3 = "mu";
   char *clave4 = "loro", *valor4 = "galleta";
   char *clave5 = "cobayo", *valor5 = "quiz";
   char *clave6 = "zorro", *valor6 = "en su corcel...";
   char *clave7 = "delfin", *valor7 = "jeje";
   char *clave8 = "bufalo", *valor8 = "pff";
   char *clave9 = "morsa", *valor9 = "ooo";
   char *clave10 = "iguana", *valor10 = "glu";
   char *clave11 = "elefante", *valor11 = "ruu";


   print_test("Prueba abb insertar clave1", abb_guardar(arbol, clave1, valor1));
   print_test("Prueba abb insertar clave2", abb_guardar(arbol, clave2, valor2));
   print_test("Prueba abb insertar clave3", abb_guardar(arbol, clave3, valor3));
   print_test("Se inserto clave4", abb_guardar(arbol, clave4, valor4));
   print_test("Se inserto clave5", abb_guardar(arbol, clave5, valor5));
   print_test("Se inserto clave6", abb_guardar(arbol, clave6, valor6));
   print_test("Se inserto clave7", abb_guardar(arbol, clave7, valor7));
   print_test("Se inserto clave8", abb_guardar(arbol, clave8, valor8));
   print_test("Se inserto clave9", abb_guardar(arbol, clave9, valor9));
   print_test("Se inserto clave10", abb_guardar(arbol, clave10, valor10));
   print_test("Se inserto clave10", abb_guardar(arbol, clave11, valor11));
   print_test("La cantidad de elementos es 11", abb_cantidad(arbol) == 11);


   abb_iter_t *iter = abb_iter_in_crear(arbol);
   print_test("creo iterador",iter != NULL);

   print_test("veo el nodo actual", strcmp(abb_iter_in_ver_actual(iter),"bufalo") == 0);
   print_test("avanzo al siguiente nodo", abb_iter_in_avanzar(iter) == true);
   print_test("veo el nodo actual", strcmp(abb_iter_in_ver_actual(iter),"cobayo") == 0);
   print_test("avanzo al siguiente nodo", abb_iter_in_avanzar(iter) == true);
   print_test("veo el nodo actual", strcmp(abb_iter_in_ver_actual(iter),"delfin") == 0);
   print_test("avanzo al siguiente nodo", abb_iter_in_avanzar(iter) == true);
   print_test("veo el nodo actual", strcmp(abb_iter_in_ver_actual(iter),"elefante") == 0);
   print_test("avanzo al siguiente nodo", abb_iter_in_avanzar(iter) == true);
   print_test("veo el nodo actual", strcmp(abb_iter_in_ver_actual(iter),"gato") == 0);
   print_test("avanzo al siguiente nodo", abb_iter_in_avanzar(iter) == true);
   print_test("veo el nodo actual", strcmp(abb_iter_in_ver_actual(iter),"iguana") == 0);
   print_test("avanzo al siguiente nodo", abb_iter_in_avanzar(iter) == true);
   print_test("veo el nodo actual", strcmp(abb_iter_in_ver_actual(iter),"loro") == 0);
   print_test("avanzo al siguiente nodo", abb_iter_in_avanzar(iter) == true);
   print_test("veo el nodo actual", strcmp(abb_iter_in_ver_actual(iter),"morsa") == 0);
   print_test("avanzo al siguiente nodo", abb_iter_in_avanzar(iter) == true);
   print_test("veo el nodo actual", strcmp(abb_iter_in_ver_actual(iter),"perro") == 0);
   print_test("avanzo al siguiente nodo", abb_iter_in_avanzar(iter) == true);
   print_test("veo el nodo actual", strcmp(abb_iter_in_ver_actual(iter),"vaca") == 0);
   print_test("avanzo al siguiente nodo", abb_iter_in_avanzar(iter) == true);
   print_test("veo el nodo actual", strcmp(abb_iter_in_ver_actual(iter),"zorro") == 0);
   print_test("avanzo al siguiente nodo", abb_iter_in_avanzar(iter) == true);
   print_test("veo si el iterador esta al final",abb_iter_in_al_final(iter) == true);

   abb_iter_in_destruir(iter);
   abb_destruir(arbol);
}


char *randomstr(size_t length) {
    static char charset[] = "abcdefghijklmnopqrstuvwxyz"; 
    char *randomString;
    if (length) {
        randomString = malloc(length +1);
        if (randomString) {
            int l = (int) (sizeof(charset) -1); 
            int key; 
            for (int n = 0;n < length;n++) {        
                key = rand() % l;
                randomString[n] = charset[key];
            }
            randomString[length] = '\0';
        }
    }
    return randomString;
}


void pruebas_volumen(const int max){
    const int mitad = (max / 2) -1;

    abb_t *arbol = abb_crear(strcmp, NULL);

    bool inserto = true;
    int v[max];

    for(int x = 0; x < max; x++){
        v[x] = x + 1;
    }

    static char charset[] = "abcdefghijklmnopqrstuvwxyz"; 
    char*claves[max];

    for(int i = 0; i < max; i++){ 
        char randomString[7];
        int l = (int) (sizeof(charset) -1); 
        int key; 
        for (int n = 0;n < 6;n++) {        
            key = rand() % l;
            randomString[n] = charset[key];
        }
        randomString[6] = '\0';
        char*clave = randomString;
        claves[i] = clave;
        inserto &= abb_guardar(arbol, clave, &v[i]);
    }

    printf("se insertaron %d nodos... OK\n", max);

    for (int i = max - 1; i >= mitad; i--){ 
       abb_borrar(arbol, claves[i]);
    }

    print_test("se borraron la mitad de los nodos",true);
    abb_destruir(arbol);
}


void pruebas_abb_alumno(){

    printf("-----PRUEBAS ARBOL-----\n");
    pruebas_tester();

    printf("\n");
    printf("-----ARBOL VACIO-----\n");
	prueba_crear_abb_vacio();

    printf("\n");
    printf("-----INSERTAR-----\n");
    prueba_abb_insertar();

    printf("\n");
    printf("-----REEMPLAZAR-----\n");
    prueba_abb_reemplazar();

    printf("\n");
    printf("-----REEMPLAZAR Y DESTRUIR-----\n");
    prueba_abb_reemplazar_con_destruir();

    printf("\n");
    printf("-----BORRAR-----\n");
    prueba_abb_borrar();

    printf("\n");
    printf("-----ITERADOR INTERNO-----\n");
    pruebas_iterador_interno();

    printf("\n");
    printf("-----ITERADOR EXTERNO-----\n");
    pruebas_iterador_externo();

    printf("\n");
    printf("-----PRUEBAS VOLUMEN-----\n");
    pruebas_volumen(5000);

}