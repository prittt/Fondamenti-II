/** @file
Definizione del tipo Item e delle funzioni primitive (e non) sulle liste. La 
dichiarazione e la definizione di queste funzioni non varia al variare di 
ElemType.
*/

#ifndef LIST_H_
#define LIST_H_

#include "elemtype.h"

#include <stdbool.h>
#include <stdio.h>

/*****************************************************************************/
/*                           Item & Primitives                               */
/*****************************************************************************/

/** @brief Definizione del tipo Item. */
struct Item
{
    ElemType value; /*!< Valore associato all'item */
    struct Item *next; /*!< Puntatore all'item successivo */
};
typedef struct Item Item;

/** @brief La funzione ListCreateEmpty() crea e ritorna una lista vuota, ovvero
           NULL.

@return Lista vuota (NULL).
*/
Item *ListCreateEmpty(void);

/** @brief La funzione ListInsertHead() aggiunge un nuovo elemento in testa ad 
           una lista e ritorna il puntatore alla nuova lista.

@param[in] e Puntatore all'elemento da aggiugnere in testa alla lista.
@param[in] i Lista a cui aggiungere il nuovo elemento. i puo' essere una lista
            vuota (NULL).

@return Lista risultante.
*/
Item *ListInsertHead(const ElemType *e, Item *i);

/** @brief La funzione ListIsEmpty() verifica se una lista e' vuota.

@param[in] i Lista su cui eseguire la verifica.

@return true se la lista e' vuota, false altrimenti.
*/
bool ListIsEmpty(const Item *i);

/** @brief La funzione ListGetHead() ritorna un puntatore all'elemento in testa 
            alla lista, senza rimuoverlo.

@param[in] i Lista da cui estrarre il valore in testa. Questa lista non puo' 
         essere vuota, nel caso in cui lo sia la funzione termina il programma 
         con codice di errore 1.

@returns Puntatore costante all'elemento in testa alla lista.
*/
const ElemType *ListGetHeadValue(const Item *i);

/** @brief La funzione ListGetTail() ritorna la lista privata dell'elemento in 
           testa. La funzione NON dealloca la memoria occupata dalla testa
           della lista.

@param[in] i Lista da cui ottenere la coda. La lista non puo' essere vuota, 
         nel caso in cui lo sia la funzione termina il programma con codice di 
         errore 2. 

@return Lista ottenuta dopo l'eliminazione della testa. Il valore di ritorno 
        potrebbe essere una lista vuota (NULL).
*/
Item *ListGetTail(const Item *i);


/** @brief La funzione ListInsertBack() aggiunge un elemento in coda ad una
            lista (anche vuota) e ritorna la lista risultante.

@param[in] i Lista a cui aggiungere l'elemento specifciato. Questa lista puo'
            essere vuota (NULL).
@param[in] e Puntatore all'elemento da aggiugnere in testa alla lista. Il valore 
         contenuto in e non viene modificato.

@return  Lista ottenuta dopo l'aggiunta dell'elemento.
*/
Item *ListInsertBack(Item *i, const ElemType *e);

/** @brief La funzione ListDelete() libera la memoria occupata dagli elementi di 
           una lista.

@param[in] i Lista di cui liberare la memoria, puo' essere vuota (NULL).

@return Non ci sono valori di ritorno.
*/
void ListDelete(Item *i);

/*****************************************************************************/
/*                             Non Primitives                                */
/*****************************************************************************/

/** @brief La funzione ListWrite() stampa la lista specificata su file.

@param[in] i Lista da stampare su file: puo' essere vuota e non viene modificata.
@param[in] f FILE * su cui stampare la lista.

@return Non ci sono valori di ritorno.
*/
void ListWrite(const Item *i, FILE *f);

/** @brief La funzione ListWriteStdout() stampa la lista specificata su standard
           output (stdout).

@param[in] i Lista da stampare su stdout: puo' essere vuota e non viene modificata.

@return Non ci sono valori di ritorno.
*/
void ListWriteStdout(const Item *i);

#endif // LIST_H_
