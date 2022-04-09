#if !defined __PBX_SIGNAL_H
#define  __PBX_SIGNAL_H

#if !defined( __CSTRING_H )
#include <cstring.h>
#endif  // __CSTRING_H

#if !defined( __IOSTREAM_H )
#include <iostream.h>
#endif

class Signalbase
{
public:
	Signalbase (const char* );
	Signalbase (const string& );
	Signalbase (char, unsigned );
	Signalbase (const Signalbase& );
	string GetSignalAsString ( ) const;
	friend ostream& operator << ( ostream&, const Signalbase& );

	virtual ~Signalbase ();

protected:
	string theMessage;
};

///////////////////////////////////////////////////////////
///////////Definicion de clase Signal de Hard->Soft ///////
///////////////////////////////////////////////////////////
class SignalHS: public Signalbase
{
public:
	SignalHS ( const char* );
	SignalHS (const string& );
	SignalHS (char, unsigned );
	SignalHS (const SignalHS& );

///////////////////////////////////////////////////////
//Conjunto de operaciones para formar una "señal"
//////////////////////////////////////////////////////
	void SetTerminal(char );
	void SetTypeOfTerminal (char );
	void SetTypeOfChange (char );

	char GetNumberOfSignal( );
	char GetTerminal ( );
	char GetTypeOfTerminal ( );
	char GetTypeOfChange ( );
	char GetSender ( );
	char GetReceiver ( );
	virtual ~SignalHS( );
};

///////////////////////////////////////////////////////
///////////Definicion de clase Signal de Soft->Hard ///////
///////////////////////////////////////////////////////////
class SignalSH: public Signalbase
{
public:
	SignalSH ( const char* );
	SignalSH (const string& );
	SignalSH (char, unsigned );
	SignalSH (const SignalSH& );

///////////////////////////////////////////////////////
//Conjunto de operaciones para formar una "señal"
//////////////////////////////////////////////////////
	void SetTerminal(char );
	void SetTypeOfTerminal (char );
	void SetTypeOfChange (char );

	char GetNumberOfSignal( );
	char GetTerminal ( );
	char GetTypeOfTerminal ( );
	char GetTypeOfChange ( );
	char GetSender ( );
	char GetReceiver ( );
	virtual ~SignalSH( );
};

#endif

