#if !defined( __PROCESS_H )
#define __PROCESS_H

#if !defined( __CSTRING_H )
#include <cstring.h>
#endif

#if !defined __PBX_SIGNAL_H
#include <c:\bc4\pbx\include\signal.h>
#endif

//////////////////////////////////////////////////////////////////////

#include <dtrlib\newqueue.h>

////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////
//La declaración de una funcion virtual en la clase
//Processor, la convierte en una clase abstracta,
//por lo que no se instanciar un objeto con ella

class Processor: public  TINQueueAsVector<Signalbase>
{
public:
//	Processor();
	Processor(unsigned sz, priority p, status s);
	virtual int Processing () = 0;
//	virtual int AssociateInterface ( );
	void DestroyInterface ( );
	int SendMessage ( Processor&, Signalbase* );
	int HasInterface ();
	int GetProcessedSignals();
	int operator == ( const Processor& ) const ;
	virtual ~Processor();

protected:
	char  *interface; // temporal, solo para pruebas
	int hasInterface;
	int numberOfProcSignals; //Numero de señales procesadas
};

/////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////
class HardToSoftProcessor: public Processor
{
public:
	HardToSoftProcessor(unsigned sz, priority p, status s);
	virtual int Processing ();
	virtual ~HardToSoftProcessor();

};

/////////////////////////////////////////////////////////////////////
class SoftToHardProcessor: public Processor
{
public:
	SoftToHardProcessor(unsigned sz, priority p, status s);
	virtual int Processing ();
	virtual ~SoftToHardProcessor();

};


/////////////////////////////////////////////////////////////////////
class AuxiliarProcessor: public Processor
{
public:
	AuxiliarProcessor(unsigned sz, priority p, status s);
	virtual int Processing ();
	virtual ~AuxiliarProcessor();

};

/////////////////////////////////////////////////////////////////////
class ToScreen: public Processor
{
public:
	ToScreen(unsigned sz, priority p, status s);
	virtual int Processing ();
	virtual ~ToScreen();

};

/////////////////////////////////////////////////////////////////////
class FromScreen: public Processor
{
public:
	FromScreen(unsigned sz, priority p, status s);
	virtual int Processing ();
	virtual ~FromScreen();

};

#endif
