#define _DEFAULT_SOURCE
#include "abb.h"
#include <stdlib.h>
#include <string.h>

/* Estructuras auxiliares para el abb */
typedef struct abb_nodo{
	struct abb_nodo *izq;
	struct abb_nodo *der;
	const char *clave;
	void *dato;
}abb_nodo_t;

abb_nodo_t *abb_nodo_crear(const char *clave, void *dato){
	abb_nodo_t *nodo = malloc(sizeof(abb_nodo_t));
	if(!nodo) return nodo;
	nodo->clave = strdup(clave);
	nodo->dato = dato;
	nodo->izq = nodo->der = NULL;
	return nodo;
}

/* Primitivas del abb */
struct abb{
	abb_nodo_t *raiz;
	abb_comparar_clave_t cmp;
	abb_destruir_dato_t destruir_dato;
	size_t cantidad;
};

abb_t *abb_crear(abb_comparar_clave_t cmp, abb_destruir_dato_t destruir_dato){
	abb_t *arbol = malloc(sizeof(abb_t));
	if(!arbol) return NULL;
	arbol->raiz = NULL;
	arbol->cmp = cmp;
	arbol->destruir_dato = destruir_dato;
	arbol->cantidad = 0;
	return arbol;
}

/* Funciones auxiliares para guardar/ destruir */
abb_nodo_t *abb_nodo_buscar(abb_t *arbol, abb_nodo_t *nodo, const char *clave){
	if(!nodo) return nodo;
	if(!arbol->cmp(clave, nodo->clave)) return nodo;
	if(arbol->cmp(clave, nodo->clave) < 0)
		return abb_nodo_buscar(arbol, nodo->izq, clave);
	else
		return abb_nodo_buscar(arbol, nodo->der, clave);
}

void *abb_nodo_borrar(abb_t *arbol, abb_nodo_t *nodo){
	void *dato = nodo->dato;
	if(arbol->destruir_dato) arbol->destruir_dato(nodo->dato);
	free((void *)nodo->clave);
	free(nodo);
	return dato;
}

abb_nodo_t *agregar(abb_t *arbol, abb_nodo_t *nodo, abb_nodo_t *nodo_a_guardar){
	if(!nodo) return nodo_a_guardar;
	if(arbol->cmp(nodo_a_guardar->clave, nodo->clave) < 0)
		nodo->izq = agregar(arbol, nodo->izq, nodo_a_guardar);
	else
		nodo->der = agregar(arbol, nodo->der, nodo_a_guardar);
	return nodo;
}

bool abb_guardar(abb_t *arbol, const char *clave, void *dato){
	abb_nodo_t *nodo = arbol->raiz;
	nodo = abb_nodo_buscar(arbol, nodo, clave);
	if(nodo){
		if(arbol->destruir_dato) arbol->destruir_dato(nodo->dato);
		nodo->dato = dato;
	}else{
		abb_nodo_t *nodo = abb_nodo_crear(clave, dato);
		if(!nodo) return false;
		if(!arbol->raiz){
			arbol->raiz = nodo;
		}else{
			abb_nodo_t *padre = arbol->raiz;
			if(arbol->cmp(nodo->clave, padre->clave) < 0){
				padre->izq = agregar(arbol, padre->izq, nodo);
			}else{
				padre->der = agregar(arbol, padre->der, nodo);
			}
		}
		arbol->cantidad++;
	}
	return true;
}

/* Funciones auxiliares para abb borrar */
void abb_nodo_swap(abb_nodo_t *nodo_a, abb_nodo_t *nodo_b){
	const char *clave = nodo_a->clave;
	void *dato = nodo_a->dato;
	nodo_a->clave = nodo_b->clave;
	nodo_a->dato = nodo_b->dato;
	nodo_b->clave = clave;
	nodo_b->dato = dato;
}

abb_nodo_t *abb_padre_buscar(abb_t *arbol, abb_nodo_t *padre, abb_nodo_t *nodo, const char *clave){
	if(!nodo) return padre;
	if(!arbol->cmp(clave, nodo->clave)) return padre;
	if(arbol->cmp(clave, nodo->clave) < 0){
		return abb_padre_buscar(arbol, nodo, nodo->izq, clave);
	}else{
		return abb_padre_buscar(arbol, nodo, nodo->der, clave);
	}
}

void abb_cambiar_padre_hijo(abb_t *arbol, abb_nodo_t *padre, abb_nodo_t *nodo, abb_nodo_t *nodo_a){
	if(!padre) arbol->raiz = nodo_a;
	else if(padre->izq == nodo)
		padre->izq = nodo_a;
	else
		padre->der = nodo_a;
}

void *_abb_borrar(abb_t *arbol, abb_nodo_t *padre, abb_nodo_t *nodo){
	if(!nodo->izq){
		abb_cambiar_padre_hijo(arbol, padre, nodo, nodo->der);
		return abb_nodo_borrar(arbol, nodo);
	}else if(!nodo->der){
		abb_cambiar_padre_hijo(arbol, padre, nodo, nodo->izq);
		return abb_nodo_borrar(arbol, nodo);
	}else{
	abb_nodo_t *nodo_a = nodo->der;
	padre = nodo;
	while(nodo_a->izq){
		padre = nodo_a;
		nodo_a = nodo_a->izq;
	}
	abb_nodo_swap(nodo, nodo_a);
	return _abb_borrar(arbol, padre, nodo_a);
	}
}

void *abb_borrar(abb_t *arbol, const char *clave){
	abb_nodo_t *nodo = arbol->raiz;
	nodo = abb_nodo_buscar(arbol, nodo, clave);
	if(!nodo) return NULL;
	abb_nodo_t *padre = NULL;
	abb_nodo_t *nodo_a = arbol->raiz;
	padre = abb_padre_buscar(arbol, padre, nodo_a, clave);
	
	/* Comienzan los casos de borrado */
	void * dato = _abb_borrar(arbol, padre, nodo);
	arbol->cantidad--;
	return dato;
}
void *abb_obtener(const abb_t *arbol, const char *clave){
	abb_nodo_t *nodo = arbol->raiz;
	nodo = abb_nodo_buscar((abb_t *)arbol, nodo, clave);
	if(!nodo) return NULL;
	return nodo->dato;
}

bool abb_pertenece(const abb_t *arbol, const char *clave){
	abb_nodo_t *nodo = arbol->raiz;
	return abb_nodo_buscar((abb_t *)arbol, nodo, clave);
}

size_t abb_cantidad(abb_t *arbol){
	return arbol->cantidad;
}

/* Función auxiliar para destruir abb */
void abb_destruir_recursivo(abb_t *arbol, abb_nodo_t *nodo){
	if(!nodo) return;
	abb_destruir_recursivo(arbol, nodo->izq);
	abb_destruir_recursivo(arbol, nodo->der);
	abb_nodo_borrar(arbol, nodo);
}

void abb_destruir(abb_t *arbol){
	abb_nodo_t *nodo = arbol->raiz;
	abb_destruir_recursivo(arbol, nodo);
	free(arbol);
}
