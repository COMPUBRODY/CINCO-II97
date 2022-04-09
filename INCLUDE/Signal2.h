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

///////////////////////////////////////////////////////
class Signal: public Signalbase
{
public:
	Signal( const char* );
	Signal (const string& );
	Signal (char, unsigned );
	Signal (const Signal& );

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
	virtual ~Signal( );
};

#endif

