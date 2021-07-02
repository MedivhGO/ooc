/*******************************************************************************
 *    TODO: description of class
 ******************************************************************************/

#ifndef _SHAPE_H
#define _SHAPE_H

/*******************************************************************************
 *    INCLUDED FILES
 ******************************************************************************/

#include "ooc.h"



/*******************************************************************************
 *    MACROS
 ******************************************************************************/

/*******************************************************************************
 *    PUBLIC TYPES
 ******************************************************************************/

typedef struct S_Shape T_Shape;

/*
 * Result codes
 */
typedef enum E_Shape_Res {
   SHAPE_RES__OK,
} T_Shape_Res;

typedef struct S_Shape_CtorParams {
   //-- add your ctor params here
} T_Shape_CtorParams;



/*******************************************************************************
 *    VTABLE
 ******************************************************************************/

/**
 * Destructor
 */
typedef void (T_Shape_Dtor)                (T_Shape *me);

/**
 * Memory deallocator. Needs to be overridden because pointer to subclass not
 * necessarily matches pointer to superclass.
 */
typedef void (T_Shape_Free)                (T_Shape *me);

/**
 * Example virtual method prototype, to be replaced by real
 * application-dependent method(s).
 */
typedef void (T_Shape_SomeMethod)          (T_Shape *me, int a, int b);



/**
 * Virtual functions table (vtable)
 */
typedef struct S_Shape_VTable {
   T_Shape_Dtor            *p_dtor;
   T_Shape_Free            *p_free;
   T_Shape_SomeMethod      *p_some_method;
} T_Shape_VTable;



/*******************************************************************************
 *    OBJECT CONTEXT
 ******************************************************************************/

/*
 * Object context
 */
struct S_Shape {

   //-- TODO: add fields to object context
   /*- object_context -*/

   struct S_Shape_VTable *p_vtable;
};



/*******************************************************************************
 *    CONSTRUCTOR, DESTRUCTOR PROTOTYPES
 ******************************************************************************/

/**
 * Constructor
 *
 * @return SHAPE_RES__OK if everything is ok, otherwise returns error code
 */
T_Shape_Res shape__ctor(T_Shape *me, const T_Shape_CtorParams *p_params);

/**
 * Desctructor
 */
static inline void shape__dtor(T_Shape *me)
{
   me->p_vtable->p_dtor(me);
}



/*******************************************************************************
 *    PUBLIC METHOD PROTOTYPES
 ******************************************************************************/

static inline void shape__some_method(T_Shape *me, int a, int b)
{
   me->p_vtable->p_some_method(me, a, b);
}



/*******************************************************************************
 *    PROTECTED METHOD PROTOTYPES
 ******************************************************************************/

/**
 * Returns pointer to vtable for class Shape.
 */
const T_Shape_VTable *_shape__vtable__get(void);



/*******************************************************************************
 *    ALLOCATOR, DEALLOCATOR PROTOTYPES
 ******************************************************************************/

/*
 * Allocator and Deallocator
 *
 * Please NOTE: There's not necessary to use them! 
 * For instance, you can just allocate in stack or statically or manually from
 * heap, and use _ctor only.
 */
#if defined OOC_MALLOC && defined OOC_FREE

/* allocator */
T_Shape *new_shape(const T_Shape_CtorParams *p_params);

/* deallocator */
void delete_shape(T_Shape *me);

#endif


#endif // _SHAPE_H

/*******************************************************************************
 *    end of file
 ******************************************************************************/

