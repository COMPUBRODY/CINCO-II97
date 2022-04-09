#if !defined __PBX_SIGNAL_H
#include <c:\bc4\pbx\include\signal.h>
#endif

inline Signalbase::Signalbase (const char* signal):theMessage (string (signal))
{
}

inline Signalbase::Signalbase (char c = 0x01, unsigned l =20):theMessage (string (c, l))
{
}

inline Signalbase::Signalbase (const string& signal):theMessage (string (signal))
{
}

inline Signalbase::Signalbase (const Signalbase& s):theMessage (
						string (s.GetSignalAsString()))
{
}

inline string Signalbase::GetSignalAsString() const
{
	return theMessage;
}

/////////////////////////////////////////////////////////////
//  Write a Signal object to a stream in a format suitable
/////////////////////////////////////////////////////////////
inline ostream&  operator << ( ostream& out, const Signalbase &signal )
{
	 out<<signal.GetSignalAsString()<<endl;
	 return out;
}

inline Signalbase::~Signalbase ( )
{
	cout<<"Destruido un Signalbase"<<endl;
}

///////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////
inline Signal::Signal (const char* signal ):Signalbase( signal)
{
}

inline Signal::Signal (const string& str ):Signalbase( str)
{
}

inline Signal::Signal (char c = 0x01, unsigned l = 20 ):Signalbase (c, l)
{
}

inline Signal::Signal (const Signal& signal):Signalbase (signal)
{
}

inline void Signal::SetTypeOfTerminal( char ch)
{
	theMessage[3] = ch;
}

inline void Signal::SetTerminal(char aChar)
{
	theMessage[4] = aChar;
}

inline void Signal::SetTypeOfChange( char ch)
{
	theMessage[5] = ch;
}

inline char Signal::GetTypeOfTerminal ( )
{
	return theMessage[3];
}

inline char Signal::GetTerminal ( )
{
	return theMessage[4];
}

inline char Signal::GetTypeOfChange ( )
{
	return theMessage[5];
}

inline char Signal::GetSender ( )
{
	return theMessage[1];
}

inline char Signal::GetReceiver ( )
{
	return theMessage[2];
}

inline char Signal::GetNumberOfSignal( )
{
	return theMessage[0];
}

inline Signal::~Signal ( )
{
}


