/*------------------------------------------------------------------------*/
/*                                                                        */
/*  NEWVECTOR1.H        *Modificado para comutador KORI 25.3.97*          */
/*                                                                        */
/*  Copyright (c) 1997                                                    */
/*  All Rights Reserved                                                   */
/*                                                                        */
/*------------------------------------------------------------------------*/
#if !defined( __DTRLIB_NEWVECT_H )
#define __DTRLIB_NEWVECT_H

#if !defined( __CLASSLIB_VECTIMP_H )
#include "classlib\vectorimp.h"
#endif //__CLASSLIB_VECTIMP_H

#if !defined( __LIMITS_H )
#include <limits.h>
#endif  // __LIMITS_H

#if !defined( __CHECKS_H )
#include <checks.h>
#endif  // __CHECKS_H

#if !defined( __CLASSLIB_DEFS_H )
#include "classlib\defs.h"
#endif  // __CLASSLIB_DEFS_H

#if !defined( __CLASSLIB_STDTEMPL_H )
#include "classlib\stdtempl.h"
#endif  // __CLASSLIB_STDTEMPL_H

#if !defined( __CLASSLIB_ALLOCTR_H )
#include "classlib\alloctr.h"
#endif  // __CLASSLIB_ALLOCTR_H

#if !defined( __CLASSLIB_MEMMGR_H )
#include "classlib\memmgr.h"
#endif  // __CLASSLIB_MEMMGR_H

#if !defined( __CLASSLIB_VOIDP_H )
#include "classlib\voidp.h"
#endif  // __CLASSLIB_VOIDP_H

#pragma option -Vo-
#if defined( BI_CLASSLIB_NO_po )
#pragma option -po-
#endif


//Begin of the new templates
/*------------------------------------------------------------------------*/
/*  new template                                                                       */
/*                                                                        */
/*  template <class T,class Alloc> class TMICDTVectorImp                  */
/*  template <class T,class Alloc> class TMICDTVectorIteratorImp          */
/*                                                                        */
/*  Implements a managed, counted vector of pointers to objects of type T.*/
/*  Since pointers always have meaningful copy semantics, this class      */
/*  can handle any type of object.                                        */
/*                                                                        */
/*------------------------------------------------------------------------*/

template <class T,class Alloc> class TMICDTVectorImp :
	 public TMIVectorImp<T,Alloc>
{

public:

	 TMICDTVectorImp( unsigned sz, unsigned d = 0 ) :
	TMIVectorImp<T,Alloc>(sz), Delta(d), Count_(0) {top_=0;}
                                                   //inicializacion de top
	 int Add( T *t );
	 int AddAt( T *, unsigned );
	 int Detach( const T *t, int del = 0 )
	{
		return Detach( Find(t), del );
	}

	 int Detach( unsigned loc, int del = 0 );

	 int IsEmpty() const
	{
		return Count_ == 0;
	}

	 void Flush( int del = 0,
		unsigned stop = UINT_MAX,
		unsigned start = 0 )
	{
	TMIVectorImp<T,Alloc>::Flush( del, stop, start );
	Count_ = 0;
	top_=0;         ///modificacion
	}

	 unsigned Find( const T *t ) const;

	 virtual unsigned Top() const
	{
		return top_;          //modificado para regresar nueva variable
	}

	virtual unsigned Count() const
	{
		return Count_;
	}

	 virtual unsigned GetDelta() const
	{
		return Delta;
	}

#if defined( BI_OLDNAMES )
	 unsigned find( T *t ) const { return Find(t); }
	 void add( T *t ) { Add(t); }
#endif  // BI_OLDNAMES

protected:

	 unsigned Count_;
	 unsigned Delta;
	 unsigned top_;    //nueva variable que indica el limite superior

};

template <class T,class Alloc> class TMICDTVectorIteratorImp :
	 public TMIVectorIteratorImp<T,Alloc>
{

public:

	 TMICDTVectorIteratorImp( const TMICDTVectorImp<T,Alloc>& v ) :
	TMIVectorIteratorImp<T,Alloc>(v)
	{
	}

	 TMICDTVectorIteratorImp( const TMICDTVectorImp<T,Alloc>& v,
				unsigned start,
				unsigned stop ) :
	TMIVectorIteratorImp<T,Alloc>(v,start,stop)
	{
	}

};

template <class T, class Alloc>
int TMICDTVectorImp<T,Alloc>::AddAt( T *t, unsigned loc )
{
	 if( loc >= Lim && !Resize(loc+1) )
	 return 0;
	 if( Count_ == Lim && !Resize(Lim+1) )
	 return 0;
	 if (Data [loc] ==0)
		Count_++;
		if(Count_>top_) top_=Count_;  //linea insertada
		Data[loc] = t;
	 return loc;        //modificado para regresar la posicion 25/3/97
}

template <class T, class Alloc>
int TMICDTVectorImp<T,Alloc>::Detach( unsigned loc, int del )
{
	 if( loc >= Lim )
	return 0;
	 if( del )
	 delete STATIC_CAST(T *,STATIC_CAST(void *,Data[loc]));
	 Count_--;
	 Data [ loc] = 0;
	 return 1;
// Esta funci¢n no borra al objeto
}

template <class T,class Alloc>
unsigned TMICDTVectorImp<T,Alloc>::Find( const T *t ) const
{
	 if( Top() != 0 )
	{
	for( unsigned loc = 0; loc < Top(); loc++ )
		 if( Data[loc] &&
			*STATIC_CAST(T *,STATIC_CAST(void *,Data[loc])) == *t )
		return loc;
	}
	 return UINT_MAX;
}

template <class T,class Alloc>
int TMICDTVectorImp<T,Alloc>::Add( T *t )
{
	 const int start = 0;
	 const int stop = Lim;
	 for (int i =  start; i< stop; i++)
	{
	  if (Data [ i] == 0)
		 {
		Data[i] = t;
		Count_++;
		if(Count_>top_) top_=Count_;  //linea insertada
		return i;
		 }
	}
	 while( Count_ < Limit() && (*this)[Count_] != 0 )
	 {
		Count_++;
		if(Count_>top_) top_=Count_;  //linea insertada
	 }
	 if( Count_ >= Lim && !Resize( Count_+1 ) )
	 return -1;
	 Data[Count_++] = t;
	 return Count_;
}

//End of the new templates


#if defined( BI_CLASSLIB_NO_po )
#pragma option -po.
#endif

#pragma option -Vo.

#endif  // __DTRLIB_NEWVECT_H

