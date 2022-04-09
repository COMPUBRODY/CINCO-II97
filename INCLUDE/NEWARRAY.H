/*------------------------------------------------------------------------*/
/*                                                                        */
/*  NEWARRAYS.H                                                              */
/*                                                                        */
/*  Copyright (c) 1996
/*                                                                        */
/*------------------------------------------------------------------------*/

#if !defined( __DTRLIB_NEWARRAY_H )
#define __DTRLIB_NEWARRAY_H

#if !defined( __CLASSLIB_ARRAYS_H )
#include "classlib\arrays.h"
#endif //__CLASSLIB_ARRAYS_H

//#define TEMPLATES

#if !defined( __MEM_H )
#include <mem.h>
#endif  // __MEM_H

#if !defined( __CLASSLIB_DEFS_H )
#include "classlib\defs.h"
#endif  // __CLASSLIB_DEFS_H

#if !defined( __CLASSLIB_SHDDEL_H )
#include "classlib\shddel.h"
#endif  // __CLASSLIB_SHDDEL_H

#if !defined( __CLASSLIB_ALLOCTR_H )
#include "classlib\alloctr.h"
#endif  // __CLASSLIB_ALLOCTR_H

#if !defined( __DTRLIB__NEWVECT_H )
#include "c:\bc4\pbx\include\newvect2.h"
#endif  // __CLASSLIB__NEWVECT_H

#pragma option -Vo-
#if defined( BI_CLASSLIB_NO_po )
#pragma option -po-
#endif


//Begin of the new templates
/*------------------------------------------------------------------------*/
/*                                                                        */
/*  template <class T,class Alloc> class TMIDTArrayAsVector               */
/*  template <class T,class Alloc> class TMIDTArrayAsVectorIterator       */
/*                                                                        */
/*  Implements a managed indirect array of objects of type T, using a     */
/*  vector as the underlying implementation.                              */
/*                                                                        */
/*------------------------------------------------------------------------*/

template <class T, class Alloc> class TMIDTArrayAsVectorIterator;

template <class T, class Alloc> class TMIDTArrayAsVector :
	 public TIArrayAsVectorImp<TMICDTVectorImp<T,Alloc>,T>
{

	 friend TMIDTArrayAsVectorIterator<T,Alloc>;

public:

	 TMIDTArrayAsVector( int upper, int lower = 0, int delta = 0 ) :
	TIArrayAsVectorImp<TMICDTVectorImp<T,Alloc>,T>( upper, lower, delta )
		  {
		  }

	 int AddAt( T *t, int loc )
		  {
		  return Data.AddAt( t, ZeroBase(loc) );
		  }

#if defined( BI_OLDNAMES )
	 int addAt( T *t, int loc ) { return AddAt(t,loc); }
#endif

};

template <class T, class Alloc> class TMIDTArrayAsVectorIterator :
	 public TMICDTVectorIteratorImp<T,Alloc>
{

public:

	 TMIDTArrayAsVectorIterator( const TMIDTArrayAsVector<T,Alloc>& a ) :
	TMICDTVectorIteratorImp<T,Alloc>( a.Data ) {}

};

/*------------------------------------------------------------------------*/
/*                                                                        */
/*  template <class T> class TIDTArrayAsVector                            */
/*  template <class T> class TIDTArrayAsVectorIterator                    */
/*                                                                        */
/*  Implements an indirect array of objects of type T, using a vector as  */
/*  the underlying implementation and TStandardAllocator as its memory    */
/*  manager.                                                              */
/*                                                                        */
/*------------------------------------------------------------------------*/

template <class T> class TIDTArrayAsVector :
	 public TMIDTArrayAsVector<T,TStandardAllocator>
{

public:

	 TIDTArrayAsVector( int upper, int lower = 0, int delta = 0 ) :
	TMIDTArrayAsVector<T,TStandardAllocator>( upper, lower, delta )
	{
	}

};

template <class T> class TIDTArrayAsVectorIterator :
	 public TMIDTArrayAsVectorIterator<T,TStandardAllocator>
{

public:

	 TIDTArrayAsVectorIterator( const TIDTArrayAsVector<T>& a ) :
	TMIDTArrayAsVectorIterator<T,TStandardAllocator>(a)
	{
	}

};

//End of new template


#if defined( BI_CLASSLIB_NO_po )
#pragma option -po.
#endif

#pragma option -Vo.

#endif  // __DTRLIB_NEWARRAY_H

