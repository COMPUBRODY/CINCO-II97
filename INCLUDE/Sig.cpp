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
inline SignalHS::SignalHS (const char* signal ):Signalbase( signal)
{
}

inline SignalHS::SignalHS (const string& str ):Signalbase( str)
{
}

inline SignalHS::SignalHS (char c = 0x01, unsigned l = 20 ):Signalbase (c, l)
{
}

inline SignalHS::SignalHS (const SignalHS& signal):Signalbase (signal)
{
}

inline void SignalHS::SetTypeOfTerminal( char ch)
{
	theMessage[3] = ch;
}

inline void SignalHS::SetTerminal(char aChar)
{
	theMessage[4] = aChar;
}

inline void SignalHS::SetTypeOfChange( char ch)
{
	theMessage[5] = ch;
}

inline char SignalHS::GetTypeOfTerminal ( )
{
	return theMessage[3];
}

inline char SignalHS::GetTerminal ( )
{
	return theMessage[4];
}

inline char SignalHS::GetTypeOfChange ( )
{
	return theMessage[5];
}

inline char SignalHS::GetSender ( )
{
	return theMessage[1];
}

inline char SignalHS::GetReceiver ( )
{
	return theMessage[2];
}

inline char SignalHS::GetNumberOfSignal( )
{
	return theMessage[0];
}

inline SignalHS::~SignalHS ( )
{
}


