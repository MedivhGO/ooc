/*******************************************************************************
 *    TODO: description of class
 ******************************************************************************/

#ifndef _MYSHAPE_H
#define _MYSHAPE_H


/*******************************************************************************
 *    INCLUDED FILES
 ******************************************************************************/

#include "shape.h"


/*******************************************************************************
 *    MACROS
 ******************************************************************************/

/*******************************************************************************
 *    PUBLIC TYPES
 ******************************************************************************/

typedef struct S_MyShape T_MyShape;

typedef struct S_MyShape_CtorParams {
   T_Shape_CtorParams super_params;

   //-- add your ctor params here
} T_MyShape_CtorParams;



/*******************************************************************************
 *    OBJECT CONTEXT
 ******************************************************************************/

/*
 * Object context
 */
struct S_MyShape {
   struct {
      T_Shape shape;
   } super;

   /*- object_context -*/
};



/*******************************************************************************
 *    CONSTRUCTOR, DESTRUCTOR PROTOTYPES
 ******************************************************************************/

/**
 * Constructor
 *
 * @return SHAPE_RES__OK if everything is ok, otherwise returns error code
 */
T_Shape_Res myshape__ctor(T_MyShape *me, const T_MyShape_CtorParams *p_params);



/*******************************************************************************
 *    PUBLIC METHOD PROTOTYPES
 ******************************************************************************/

/**
 * Returns whether pointer to superclass (`T_Shape`) points to an instance
 * of subclass (`T_MyShape`).
 *
 * NOTE: works only for 1-level inheritance!
 */
OOC_BOOL instanceof_myshape(const T_Shape *me_super);

/**
 * Returns pointer to subclass by pointer to superclass
 */
T_MyShape *myshape__get_by_shape(const T_Shape *me_super);

/**
 * Returns pointer to superclass (i.e. `T_Shape`)
 */
static inline T_Shape *myshape__shape__get(T_MyShape *me)
{
   return &(me->super.shape);
}




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
T_MyShape *new_myshape(const T_MyShape_CtorParams *p_params);

#endif


#endif // _MYSHAPE_H

/*******************************************************************************
 *    end of file
 ******************************************************************************/

