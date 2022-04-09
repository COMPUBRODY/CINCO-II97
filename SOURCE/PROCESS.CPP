#include <c:\bc4\pbx\include\process.h>
#include <c:\bc4\pbx\source\signal.cpp>

////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////
#include <dos.h>
#include <conio.h>

//////////////////////////////////////////////////////////////////////
//Processor::Processor():TINQueueAsVector<string>(),
//						 interface(0), hasInterface (0)

Processor::Processor(unsigned sz = DEFAULT_QUEUE_SIZE, priority p = VERYLOW,
	status s = READY):
		TINQueueAsVector<Signalbase>( sz, p, s ),
		interface(0), hasInterface (0),numberOfProcSignals(0)
{
}

//////////////////////////////////////////////////////////
int Processor::HasInterface ()
{
	return hasInterface;
}

/////////////////////////////////////////////////////
void Processor::DestroyInterface( )
{
	if ( interface != 0 ) {
		delete interface;
		interface = 0;
	}
}

///////////////////////////////////////////////////////////////
int Processor::SendMessage ( Processor& proc, Signalbase* inMsg)
{
if (this == &proc) {
		if ( (!IsFull()) &&(GetStatus()!= BLOCKED) ){
			Put( inMsg );
			return 1;
			}
		else return 0;
		}
	else {
		if ( (!proc.IsFull()) &&(proc.GetStatus()!= BLOCKED) ){
			proc.Put( inMsg );
			return 1;
			}
		else return 0;
		}
}


/////////////////////////////////////////////////////////////
int Processor::GetProcessedSignals()
{
	return numberOfProcSignals;
}


/////////////////////////////////////////////////////////////
 int Processor::operator == (const Processor& T)const
 {
	 return interface == T.interface;
 }

////////////////////////////////////////////////////////
Processor::~Processor()
{
	//cout<<"destruido un Processor"<<endl;
}

////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////
HardToSoftProcessor::HardToSoftProcessor( unsigned sz = DEFAULT_QUEUE_SIZE, priority p = VERYLOW,
	status s = READY):Processor(sz, p, s)
{
// Inicializacion de los punteros
}

/////////////////////////////////////////////////////
HardToSoftProcessor::~HardToSoftProcessor()
{
// Deinicializacion de los punteros
}


//////////////////////////////////////////////////////////////////////
int HardToSoftProcessor::Processing()
{
//	Esta funcion debe ademas de hacer el procesamiento
//	destruir la Signal o mensaje, para que el mismo no se
//	quede en la memoria de la maquina
	cout<<"Procesando un string en H->SQueue"<<endl;
	Signalbase *aux = this->Get();  //Revisar el this???
	numberOfProcSignals++;
	cout<<*aux<<endl;
	delete aux;
	return 0;
}

////////////////////////////////////////////////////
////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////
SoftToHardProcessor::SoftToHardProcessor( unsigned sz = DEFAULT_QUEUE_SIZE, priority p = VERYLOW,
	status s = READY):Processor(sz, p, s)
{
// Inicializacion de los punteros
}

/////////////////////////////////////////////////////
SoftToHardProcessor::~SoftToHardProcessor()
{
// Deinicializacion de los punteros
}


//////////////////////////////////////////////////////////////////////
int SoftToHardProcessor::Processing()
{
//	Esta funcion debe ademas de hacer el procesamiento
//	destruir la Signal o mensaje, para que el mismo no se
//	quede en la memoria de la maquina

	cout<<"Procesando un string en S->HQueue"<<endl;
	Signalbase *aux = Get();
	numberOfProcSignals++;
	cout<<*aux<<endl;
	delete aux;
//	cout<<*Get ()<<endl;
	return 0;
}

////////////////////////////////////////////////////

////////////////////////////////////////////////////////
//Funciones del AuxiliarProcessor
////////////////////////////////////////////////////////////
AuxiliarProcessor::AuxiliarProcessor( unsigned sz = DEFAULT_QUEUE_SIZE, priority p = VERYLOW,
	status s = READY):Processor(sz, p, s)
{
// Inicializacion de los punteros
}

/////////////////////////////////////////////////////
AuxiliarProcessor::~AuxiliarProcessor()
{
// Deinicializacion de los punteros
}


//////////////////////////////////////////////////////////////////////
int AuxiliarProcessor::Processing()
{
//	Esta funcion debe ademas de hacer el procesamiento
//	destruir la Signal o mensaje, para que el mismo no se
//	quede en la memoria de la maquina

	cout<<"Procesando un string en auxiliarQueue"<<endl;
	Signalbase *aux = Get();
	numberOfProcSignals++;
	cout<<*aux<<endl;
	delete aux;
//	cout<<*Get ()<<endl;
	return 0;
}

////////////////////////////////////////////////////
//Funciones del Processor FromScreen
////////////////////////////////////////////////////////////
FromScreen::FromScreen( unsigned sz = DEFAULT_QUEUE_SIZE, priority p = VERYLOW,
	status s = READY):Processor(sz, p, s)
{
// Inicializacion de los punteros
}

/////////////////////////////////////////////////////
FromScreen::~FromScreen()
{
// Deinicializacion de los punteros
}


//////////////////////////////////////////////////////////////////////
int FromScreen::Processing()
{
//	Esta funcion debe ademas de hacer el procesamiento
//	destruir la Signal o mensaje, para que el mismo no se
//	quede en la memoria de la maquina

	cout<<"Procesando un string en auxiliarQueue"<<endl;
	Signalbase *aux = Get();
	numberOfProcSignals++;
	cout<<*aux<<endl;
	delete aux;
//	cout<<*Get ()<<endl;
	return 0;
}

////////////////////////////////////////////////////////
//Funciones del Processor ToScreen
////////////////////////////////////////////////////////////
ToScreen::ToScreen( unsigned sz = DEFAULT_QUEUE_SIZE, priority p = VERYLOW,
	status s = READY):Processor(sz, p, s)
{
// Inicializacion de los punteros
}

/////////////////////////////////////////////////////
ToScreen::~ToScreen()
{
// Deinicializacion de los punteros
}


//////////////////////////////////////////////////////////////////////
int ToScreen::Processing()
{
//	Esta funcion debe ademas de hacer el procesamiento
//	destruir la Signal o mensaje, para que el mismo no se
//	quede en la memoria de la maquina

	cout<<"Procesando un string en auxiliarQueue"<<endl;
	Signalbase *aux = Get();
	numberOfProcSignals++;
	cout<<*aux<<endl;
	delete aux;
//	cout<<*Get ()<<endl;
	return 0;
}

////////////////////////////////////////////////////




