/////////////////Definicion de las funciones para Counter /////////
Counter::Counter(int newTerm ,unsigned int set)
{
	term=newTerm;
	count=set;
}

void Counter::ReStart(unsigned int set)
{
	count=set;
}

int Counter::DetectFinalCount(int parameter)
{
	if (!(--count))
		{
		cout<<"fin de contador";    //Aqui va Signal
		return 1;
		}
	return 0;
}

int Counter::GetTerminal()
{
 	return term;
}

int Counter::operator ==(const Counter& t) const // Operador de igual
{
  return ( count ==t.count );
}


/* <<<<<<<<<<<<<< Definicion de las funciones para la clase party >>>>>>>> */

Party::Party(int term) // Funcion constructor
{
	terminal=term;
	state=IDLE;
	highChannel=-1;
	lowChannel=-1;
	positionInCall=-1;
}
Party::~Party()      // Funcion destructor
{
}

void Party::SetTerminal(int slic) // Funcion que fija el numero de terminal
 {
	terminal=slic;
  }

int Party::GetTerminal()    // Funcion que obtiene el numero de terminal
 {
	return (terminal);
 }

void Party::SetState(int estado) // Funcion que fija el estado del abonado
 {
	state=estado;
 }

int Party::GetState() // Funcion que obtiene el estado del abonado
{
 return (state);
 }

void Party::SetHighChannel(int highC) // Funcion que fija el canal alto
{
 highChannel=highC;
}

int Party::GetHighChannel() // Funcion que obtiene el canal alto
{
 return (highChannel);
}

void Party::SetLowChannel(int lowC) // Funcion que fija el canal bajo
{
 lowChannel=lowC;
}

int Party::GetLowChannel() // Funcion obtiene
{
 return (lowChannel);
 }

void Party::SetPositionInCall(int newPosition) // Funcion que fija la posicion
{
 positionInCall=newPosition;
}

int Party::GetPositionInCall() // Funcion obtiene la posicion
{
 return (positionInCall);
 }

int Party::operator ==(const Party& t) const // Operador de igual
{
  if(terminal==t.terminal)
	 return(1);
  else
	 return(0);
}

// Definicion de las funciones de circuito abonado
Subscriber::Subscriber(int term):Party(term)
{
  numberDigit=0;
  dialedNumberDir=0;
  counterPtr=NULL;
  ringPtr=NULL;
}

int Subscriber::GetNumberDigit()
{
 return(numberDigit);
}

void Subscriber::SetDialDigit(int digit)
{
	 itoa(digit,&dialDigit[numberDigit],10);
	 numberDigit++;
	 if( numberDigit == MAXNUMBERDIGIT)
		for(int i=0; i< MAXNUMBERDIGIT ;i++)
			dialedNumberDir += atoi(&dialDigit[i])*pow10(MAXNUMBERDIGIT-1-i);
}

char Subscriber::GetDialDigit(int position)
{
  return(dialDigit[position]);
}

int Subscriber::GetDialedNumberDir()
{
  return(dialedNumberDir);
}

Counter *Subscriber::GetCounterPtr()
{
  return(counterPtr);
}

void Subscriber::SetCounterPtr(Counter *newCounterPtr)
{
  counterPtr = newCounterPtr;
}

RingingTerm *Subscriber::GetRingPtr()
{
  return(ringPtr);
}

void Subscriber::SetRingPtr(RingingTerm *newRingPtr)
{
  ringPtr = newRingPtr;
}

//<<<<<<<<<<<< Definicion de las funciones miembro para el DTMF
Dtmf::Dtmf(int term):Party(term)
{
	positionInCall=DTMFPOS;
}

//<<<<<< Definicion de las funciones miembro para el tono
Tone::Tone(int term,int newTypeTone):Party(term)
{
	typeOfTone=newTypeTone;
	positionInCall=TONEPOS;
}

int Tone::GetTypeOfTone()
{
	return typeOfTone;
}

//Definicion de las funciones miembro de la clase llamada.

Call::Call() : TIDTArrayAsVector<Party>(3,0,1)
{
	typeOfCall=0;
	arrayPosition=-1;
	state=IDLE;
	numberOfSubs=0;
}

int Call::GetTermPosition(int term)
{
	for(int i=MAINPARTYPOS;i<(MAINPARTYPOS+numberOfSubs);i++)
		if( ((*this)[i]->GetTerminal()) == term )
			return i;
	return -1;
}

int Call::AddSubs(Subscriber *newSubs)
{
	return ( (*this).AddAt(newSubs,MAINPARTYPOS+(numberOfSubs++)) );
}

int Call::GetTypeOfCall()  //Fcn. que obtiene el tipo de llamada
{
	return(typeOfCall);
}

void Call::SetTypeOfCall(int x) //Fcn. que fija el tipo de llamada
{
	typeOfCall=x;
}

int Call::GetArrayPosition() //Fcn. que obtiene la posicion en el arreglo
										//de punteros a objetos llamadas
{
	return(arrayPosition);
}

void Call::SetArrayPosition(int x) //Fcn. que fija la posicion
															  //en el arreglo de punteros
{
	arrayPosition=x;
}

int Call::GetState()          //Fcn. que obtiene el estado de la llamada
{
	return(state);
}

void Call::SetState(int x) //Fcn. que fija el estado de la llamada
{
	state=x;
}

// <<<<<<<<<<<<<<Temporizacion de la clase llamada>>>>>>>>>>>>>>>>>>>>>>>

long Call::GetTimeCreation()   //Fcn. que obtiene el tiempo de creacion del
										 // objeto llamada
{
	return(timeCreation.Seconds());
}

long Call::GetTimeBegin()      //Fcn. que obtiene el tiempo de inicio de la
										// conversacion
{
	return timeBegin->Seconds();
}

long Call::GetTimeEnd()    //Fcn. que obtiene el tiempo de termino del
										// objeto llamada
{
	return timeEnd->Seconds();
}

long Call::GetCallDuration()
{
	return ( (timeEnd->Seconds()) - (timeBegin->Seconds()) );
}

int Call::SetTimeBegin()   //Fija el tiempo de inicio de la conversacion
{
  timeBegin=new TTime();   // Primera opcion para la temporizacion
  return 1;
}

int Call::SetTimeEnd()    //Fija el tiempo de termino del objeto llamada
{
	timeEnd=new TTime();   //Primera opcion para la temporizacion
  return 1;
}

Call::~Call()          // Funcion Destructor
{
delete timeBegin;
delete timeEnd;
}

int Call::operator ==(const Call& T)const  //Fcn. operador doble igual
{
	return arrayPosition == T.arrayPosition;
}

//<<<<<<<<<<<< Definicion de Funciones de la clase Estadistica >>>>>>>>>>>>

Statistic::Statistic()		//Constructor de la clase
{
	 bhca=0;
	 fails=0;
	 failsToFirstDigit=0;
	 timeout=0;
	 onHookInDial=0;
	 noAnswer=0;
	 unSuccess=0;
	 success=0;
	 incoming=0;
	 outgoing=0;
	 transfered=0;
	 local=0;

}

unsigned long Statistic::GetBHCA()
{
	return(bhca);
}

void Statistic::IncBHCA()
{
	bhca++;
}

unsigned long Statistic::GetFails()
{
	return(fails);
}

void Statistic::IncFails()
{
	fails++;
}

unsigned long Statistic::GetFailsToFirstDigit()
{
	return(failsToFirstDigit);
}

void Statistic::IncFailsToFirstDigit()
{
	failsToFirstDigit++;
}

unsigned long Statistic::GetTimeout()
{
	return(timeout);
}

void Statistic::IncTimeout()
{
	timeout++;
}

unsigned long Statistic::GetOnHookInDial()
{
	return(onHookInDial);
}

void Statistic::IncOnHookInDial()
{
	onHookInDial++;
}

unsigned long Statistic::GetNoAnswer()
{
	return(noAnswer);
}

void Statistic::IncNoAnswer()
{
	noAnswer++;
}

unsigned long Statistic::GetUnSuccess()
{
	return(unSuccess);
}

void Statistic::IncUnSuccess()
{
	unSuccess++;
}

unsigned long Statistic::GetSuccess()
{
	return(success);
}

void Statistic::IncSuccess()
{
	success++;
}

unsigned long Statistic::GetIncoming()
{
	return(incoming);
}

void Statistic::IncIncoming()
{
	incoming++;
}

unsigned long Statistic::GetOutgoing()
{
	return(outgoing);
}

void Statistic::IncOutgoing()
{
	outgoing++;
}

unsigned long Statistic::GetTransfered()
{
	return(transfered);
}

void Statistic::IncTransfered()
{
	transfered++;
}

unsigned long Statistic::GetLocal()
{
	return(local);
}

void Statistic::IncLocal()
{
	local++;
}

/* <<<<<< Definicion de las funciones constructor, que se heredan de la clase
	<<<<<<<<<<<<< TIDTArrayAsVector >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/

CallArray::CallArray(int up,int low, int del) : TIDTArrayAsVector<Call>(up,low,del)
{
}

CallArray::CallArray(int up) : TIDTArrayAsVector<Call>(up)
{
}

/* <<<<<<<<<<<<<< Definicion de las funciones para la clase Terminal>>>>>>>> */

Terminal::Terminal(int typ =0) // Funcion constructor
{
	type=typ;      //tipo de terminal
	state=INITSTATE;			//estado inicial 0
}

Terminal::~Terminal()      // Funcion destructor
{
	cout<<"terminal destruido: "<<type<<endl;
}

int Terminal::operator ==(const Terminal& T)const //Funcion operador igual
{
	return type == T.type;
}

int Terminal::GetState()
{
	return state;
}

void Terminal::SetState(int x)
{
	state=x;
 }

int Terminal::GetType()
{
	return type;
}

int Terminal::GetNumberDir()
{
	return -1;
}

int Terminal::GetDirState()
{
	return -1;
}

void Terminal::SetDirState(int)
{}

int Terminal::GetRights()
{
	return -1;
}

void Terminal::SetRights(int)
{}

void Terminal::SetNumberDir(int)
{}

void Terminal::SetTypeOfTone(int)
{}

int Terminal::GetTypeOfTone()
{
	return -1;
}

//<<<< Definicion de las funciones miembro a la clase CARegister>>>>>>>>>>

CARegister::CARegister(int typ =CA):Terminal(typ) //Constructor
{
	numberDir=0;	//inicializacion de variables private
	stateDir=INITSTATE;
	rights=1;
}

void CARegister::SetNumberDir(int num) //Funcion que fija el # de Dir.
{
	 numberDir = num;
}

int CARegister::GetNumberDir() //Funcion que obtiene el # de Dir.
{
	 return numberDir;
}

int CARegister::GetDirState()  //Funcion que obtiene el estado del # de Dir.
{
	 return stateDir;
}

void CARegister::SetDirState(int newStateDir) //Funcion que fija el estado del # de Dir.
{
	 stateDir=newStateDir;
}

int CARegister::GetRights() //Funcion que obtiene los derechos
{
	 return rights;
}

void CARegister::SetRights(int newRights) //Funcion que fija los derechos
{
	 rights = newRights;
}

// Definicion de las funciones miembro del CE register
CERegister::CERegister(int typ =CE):CARegister(typ) //Constructor
{
}

//Definicion de las funciones miembro del DTMF
DTMFRegister::DTMFRegister(int typ =DTMF):Terminal(typ) //Constructor
{}

//Definicion de las funciones miembro del TONO
TONERegister::TONERegister(int typ =TONE):Terminal(typ) //Constructor
{}

void TONERegister::SetTypeOfTone(int newTone)
{
	typeOfTone=newTone;
}

int TONERegister::GetTypeOfTone()
{
	return typeOfTone;
}
//<<<<<<<<<<<<<<<<<<<<Definicion de las funciones de la clase Table >>>>>>>>

Table::Table()			//fnc. constructor
{
	subsTable = new TIArrayAsVector<Call> (MAXTERM-30,MINTERM,10);
	dirTable = new TArrayAsVector<double> (MAXDIR, MINDIR, 10);
	termTable = new TIDTArrayAsVector<Terminal> (MAXTERM, MINTERM, 10);
	CEOffset=MAXTERM-30;       //10 CE's    (70 abonados)
	DTMFOffset=MAXTERM-20;     //10 DTMF's
	TONEOffset=MAXTERM-10;     //10 Tonos
	for(int i=MINDIR;i<=MAXDIR;i++)
		(*dirTable)[i]=-1;
}

Table::~Table()		//Fcn. Destructor
{
	delete dirTable;     //liberacion de memoria de vectores en tabla
	delete termTable;
}

Call *Table::GetCallPtr(int subsTerm)  //Fcn para obtener el CallPtr de subsTerm
{
	return ( (*subsTable)[subsTerm] );
}

void Table::SetCallPtr(int subsTerm,Call *newCallPtr) //Fnc para fijar CallPtr
{
	(*subsTable)[subsTerm]=newCallPtr;
}

int Table::GetTermTone(int typeOfTone)
{
	int offs=TONEOffset;
	for( ; offs < MAXTERM ; offs++)
	if ( (*termTable)[offs]->GetTypeOfTone() == typeOfTone )
	{
		return(offs);
	}
	return (-1);
}

void Table::SetNumberDir(int numTerm,int numDir) //Fcn. para asignar en # dir
{
	if ( !( (*this).TermValid(numTerm,CA) ) ) return;
	(*termTable)[ numTerm ]->SetNumberDir(numDir);
	(*dirTable)[numDir]=double(numTerm);  //Dar de alta en el vector de numberDirs
}

void Table::SetTerminalState(int numTerm,int newState)
{
	if ( !( (*this).TermValid(numTerm) ) ) return;
	(*termTable)[ numTerm ]->SetState(newState);
}

void Table::SetDirState(int numDir, int newState)
{
	if ( !( (*this).TermValid(int((*dirTable)[numDir]),CA) ) ) return;
	(*termTable)[ int((*dirTable)[numDir]) ]->SetDirState(newState);
}

int Table::Add(int typTerm)
{
	int offs,limoffs;
	Terminal *temp;
	switch(typTerm)
	{
		case CA:offs=MINTERM;  //CA
				  limoffs=CEOffset;
				  temp= new CARegister;
				  break;
		case CE:offs=CEOffset; //CE
				  limoffs=DTMFOffset;
				  temp= new CERegister;
				  break;
		case DTMF:offs=DTMFOffset; //DTMF
					 limoffs=TONEOffset;
					 temp= new DTMFRegister;
					 break;
		case TONE:offs=TONEOffset; //Tonos
					 limoffs=MAXTERM;
					 temp= new TONERegister;
					 break;
	}

	//ciclo hasta encontrar un espacio libre para terminal (termptr=NULL)
	for( ; offs < limoffs ; offs++)
		if ( (*termTable)[offs] == NULL )
		{
			(*termTable)[offs]= temp;
			return(offs);
		}
	return (-1);
}

int Table::Detach(int numTerm)
{
	if ( !( (*this).TermValid(numTerm) ) ) return -1;
	(*termTable).Destroy(numTerm);	//retirar un apuntador del vector termTable
	return(1);
}

int Table::TermValid(int numTerm,int typeTerm) //solo uso interno
{
	if ( numTerm > MAXTERM  || numTerm < MINTERM ||
		(*termTable)[numTerm] == NULL ||
		(*termTable)[numTerm]->GetType() != typeTerm )
		return (-1);
	return 1;
}

int Table::TermValid(int numTerm) //solo valida el num de terminal
{
	if ( numTerm > MAXTERM  || numTerm < MINTERM ||
		(*termTable)[numTerm] == NULL )
		return (-1);
	return 1;
}

int Table::SearchDir(int numTerm)
{
	if ( !( (*this).TermValid(numTerm,CA) ) ) return -1;
	return( (*termTable)[numTerm]->GetNumberDir() );
}

int Table::SearchTerminal( int numDir)
{
	if ( !( (*this).TermValid(int((*dirTable)[numDir]),CA) ) ) return -1;
	return ( int((*dirTable)[numDir]) );
}

int Table::GetTerminalState(int numTerm)
{
	if ( !( (*this).TermValid(numTerm) ) ) return -1;
	return (*termTable)[numTerm]->GetState();
}

int Table::GetTerminalType(int numTerm)
{
	if ( !( (*this).TermValid(numTerm) ) ) return -1;
	return (*termTable)[numTerm]->GetType();
}

int Table::GetDirState( int numDir)
{
	if ( !( (*this).TermValid(int((*dirTable)[numDir]),CA) ) ) return -1;
	return( (*termTable)[ int((*dirTable)[numDir]) ]->GetDirState() );
}

int Table::GetRights(int numDir)
{
	if ( !( (*this).TermValid(int((*dirTable)[numDir]),CA) ) ) return -1;
	return (*termTable)[ int((*dirTable)[numDir]) ]->GetRights();
}

void Table::SetRights(int numDir, int newRights)
{
	if ( !( (*this).TermValid(int((*dirTable)[numDir]),CA) ) ) return;
	(*termTable)[ int((*dirTable)[numDir]) ]->SetRights(newRights);
}

void Table::SetTypeOfTone(int numTerm,int newTone)
{
	if ( !( (*this).TermValid(numTerm,TONE) ) ) return;
	(*termTable)[ numTerm ]->SetTypeOfTone(newTone);
}

int Table::GetTypeOfTone(int numTerm)
{
	if ( !( (*this).TermValid(numTerm,TONE) ) ) return -1;
	return ((*termTable)[ numTerm ]->GetTypeOfTone());
}

int Table::FindFree( int typTerm )
{
	int offs;
	switch(typTerm)
	{
		case CA: offs=MINTERM;
					break;
		case CE: offs=CEOffset;
					break;
		case DTMF: offs=DTMFOffset;
					  break;
		case TONE: offs=TONEOffset;
					  break;
	}

	//ciclo hasta encontrar una terminal libre (state=0)
	for( ;( (*termTable)[offs] != NULL ) &&
			( (*termTable)[offs]->GetType() == typTerm ); offs++)
		if ( (*termTable)[offs]->GetState() == INITSTATE )
		{
			(*termTable)[offs]->SetState(BUSYTERM);
			return(offs);
		}
	return (-1);
}


//Definicion de las funciones miembro de la clase Hardlay

HardLay::HardLay()     //constructor
{
	//inicializacion y prueba de hardware
	ringVector = new TIArrayAsVector<RingingTerm>(5,0,1);
}

HardLay::~HardLay()   //destructor
{
	delete ringVector;
}

RingingTerm *HardLay::SendRing(int term, int termAType)
{
	RingingTerm *newRing;
	if( (termAType) == CA )
		newRing = new RingingTerm(term,CA_RING);
	else
		newRing = new RingingTerm(term,CE_RING);
	ringVector->Add( newRing );

	return (newRing);
}

void HardLay::Kill(RingingTerm *ringPtr)
{
	ringPtr->Off();
	ringVector->Destroy(ringPtr);
	return;
}

int HardLay::Connect(Subscriber *subsPtr,Tone *tonePtr,Dtmf *dtmfPtr)
{
	int channel1 = subsPtr->GetLowChannel();
	int channel2 = tonePtr->GetLowChannel();
	int channel3 = dtmfPtr->GetLowChannel();
	//matriz y activador de codecs
	if( !(matrix.ConnectionUnidir(channel2,channel1+SIMETRIC)) ||
		 !(matrix.ConnectionUnidir(channel1,channel3+SIMETRIC)) ||
		 !(AC.SetOn(subsPtr->GetTerminal(),channel1)) ||
		 !(AC.SetOn(tonePtr->GetTerminal(),channel2)) ||
		 !(AC.SetOn(dtmfPtr->GetTerminal(),channel3)) )
			return -1;
	 return 1;
}

int HardLay::Disconnect(Subscriber *subsPtr,Tone *tonePtr)
{
	//Obtener los canales para desconectarlos, se mandan solo los canales bajos
	int channel1 = subsPtr->GetLowChannel();
	int channel2 = tonePtr->GetLowChannel();
	//matriz y activador de codecs
	if( !(matrix.DisconnectionBidir(channel1,channel2)) ||
		 !(AC.SetOff(channel1)) ||
		 !(AC.SetOff(channel2)) )
			return -1;
	 return 1;
}


int HardLay::Disconnect(Subscriber *subsPtr,Tone *tonePtr,Dtmf *dtmfPtr)
{
	int channel1 = subsPtr->GetLowChannel();
	int channel2 = tonePtr->GetLowChannel();
	int channel3 = dtmfPtr->GetLowChannel();
	//matriz y activador de codecs
	if( !(matrix.DisconnectionUnidir(channel2,channel1+SIMETRIC)) ||
		 !(matrix.DisconnectionUnidir(channel1,channel3+SIMETRIC)) ||
		 !(AC.SetOff(channel1)) ||
		 !(AC.SetOff(channel2)) ||
		 !(AC.SetOff(channel3)) )
			return -1;
	 return 1;
}

int HardLay::Disconnect(Party *partyPtr)
{
	int channel = partyPtr->GetLowChannel();

	//matriz y activador de codecs
	if( !(matrix.Disconnect(channel)) ||   //Poner el canal del tono y del
		 !(AC.SetOff(channel)) )           // dtmf en estado de free
													  // || !(AC.SetOff(channel2+SIMETRIC)) )
			return -1;
	 return 1;
}

int HardLay::Connect(Subscriber *subsAPtr,Subscriber *subsBPtr)
{
	int channel1 = subsAPtr->GetLowChannel();
	int channel2 = subsBPtr->GetLowChannel();
	//matriz y activador de codecs
	if( !(matrix.ConnectionBidir(channel1,channel2)) ||
		 !(AC.SetOn(subsAPtr->GetTerminal(),channel1)) ||
		 !(AC.SetOn(subsBPtr->GetTerminal(),channel2)) )
			return -1;
	 return 1;
}

int HardLay::Connect(Subscriber *subsPtr,Tone *tonePtr)
{
	int channel1 = subsPtr->GetLowChannel();
	int channel2 = tonePtr->GetLowChannel();
	int state = (matrix.GetChannelState(channel1+SIMETRIC));
	if ( state == RESERVED || state == SWITCHED)
		if( !(matrix.ConnectionUnidir(channel2,channel1+SIMETRIC)) ||
			 !(AC.SetOn(subsPtr->GetTerminal(),channel1)) ||
			 !(AC.SetOn(tonePtr->GetTerminal(),channel2)) )
					return -1;
	else
		if( !(matrix.SetModeOutputChannel(channel1+SIMETRIC,SWITCHED)) ||
			 !(AC.SetOn(tonePtr->GetTerminal(),channel2)) )
					return -1;
	return 1;
}


int HardLay::Kill(Subscriber *subsPtr,Tone *tonePtr)
{
	//matriz y AC
	if ( !(matrix.SetModeOutputChannel(subsPtr->GetHighChannel(),HIGHZ)) ||  //Poner en 3 edo. el canal de
		  !(AC.SetOff( tonePtr->GetLowChannel())) )      //salida y apagar el tono
				return -1;
	return 1;
}

int HardLay::FindFreeChannel(int term)
{
	return ( matrix.FindFreeChannel(term) );
}

/////////////////////////////////////////////////////////////////
//FUNCIONES TEMPORALES PARA PRUEBAS DE FLUJO DEL PROG.//////////
////////////////////////////////////////////////////////////////

/*
//>>>>>>>>>>>>>MATRIZ<<<<<<<<<<<<<<<<<<<<
Matrix::Matrix()
{
	cout<<"construi una matriz"<<endl;
}

int Matrix::ConnectionUnidir(int ch,int ch1)
{
	cout<<"ConnectionUnidir("<<ch<<","<<ch1<<")"<<endl;
	return 1;
}

int Matrix::ConnectionBidir(int ch,int ch1)
{
	cout<<"ConnectionBidir("<<ch<<","<<ch1<<")"<<endl;
	return 1;
}

int Matrix::DisconnectionUnidir(int ch,int ch1)
{
	cout<<"DisconnectionUnidir("<<ch<<","<<ch1<<")"<<endl;
	return 1;
}

int Matrix::DisconnectionBidir(int ch,int ch1)
{
	cout<<"DisconnectionBidir("<<ch<<","<<ch1<<")"<<endl;
	return 1;
}

int Matrix::Disconnect(int ch)
{
	cout<<"Disconnect("<<ch<<")"<<endl;
	return 1;
}

int Matrix::FindFreeChannel(int term)
{
	cout<<"FindFreeChannel("<<term<<")"<<endl;
	return 1;
}

int Matrix::SetModeOutputChannel(int ch,int mode)
{
	cout<<"SetModeOutputChannel("<<ch<<","<<mode<<")"<<endl;
	return 1;
}

int Matrix::GetChannelState(int ch)
{
	cout<<"GetChannelState("<<ch<<")  presiona el estado:"<<endl;
	return (getch());
}
*/

//////////////////////////////////////////////////////////////////////////////

int Matrix::ConnectionUnidir(int inChannel, int outChannel)
{

// En el canal de entrada va estar el valor 0 - 255 y en el canal de selida
// va estar el valor de 256 +16

	int PCMi=inChannel/32;
	int CHi =inChannel%32;
	int PCMo=(outChannel/32) - 8;
	int CHo =outChannel%32;

	WriteRegister(PCMo,LOWMEM);
	WriteLowMemory(CHo,PCMi,CHi);
	SetModeOutputChannel(outChannel,LOWIMP);

// esta secci¢n es para la busqueda del canal de entrada como el de salida
// para poner el estado de conectado

	channelState[inChannel] = SWITCHED;
	channelState[outChannel] = SWITCHED;
	lowMemory[inChannel] = outChannel;

	return 1;
}

int Matrix::ConnectionBidir(int inChannel1,int inChannel2)
{

	int out1 = inChannel1 + 256;
	int out2 = inChannel2 + 256;

	ConnectionUnidir(inChannel1,out2);
	ConnectionUnidir(inChannel2,out1);


	return 1;
}

int Matrix::DisconnectionUnidir(int inChannel, int outChannel)
{

	SetModeOutputChannel(outChannel,HIGHIMP);

	channelState[inChannel] = FREE;
	channelState[outChannel]= FREE;

	lowMemory[inChannel] = FREE;

	lowMemory[outChannel] =FREE;

	return 1;

}

int Matrix::DisconnectionBidir(int inChannel1, int inChannel2)
{
	int out1 = inChannel1 + 256;
	int out2 = inChannel2 + 256;

	DisconnectionUnidir(inChannel1,out2);
	DisconnectionUnidir(inChannel2,out1);

	return 1;
}


int Matrix::SetChannelState(int channel, int state)
{
	channelState[channel]=(char)state;
	return 1;
}

//////////////////////////////////////////////////////////////////////////////

int Matrix::FindFreeChannel(int terminal)  // busqueda de canal
{
// Esta funcion busca un canal libre dentro de todos los posibles
// del grupo al cual pertenece el "terminal", determinando para ello su PCM
// reserva el canal, pero no lo conmuta, es decir se trabaja solamente
// con el arreglo que almacena el estado de los canales
// devuelve un entero que es el numero del canal 0-15, si no hubiera canal
// devuelve -1

	int PCMi;
	//Determinar el PCMi

		if (terminal <= ABONADOS)   // PCM para el abonado

			 PCMi = 0;

		else if (terminal >= MINCE && terminal <= MAXCE)

		// PCM para Enlaces,Tonos y DTMF

			 PCMi = 1;

		else if (terminal >= MINDTMF && terminal <= MAXDTMF)

		// PCM para Enlaces,Tonos y DTMF

			 PCMi = 1;

		else if (terminal > MINTONE && terminal <= MAXTONE)

		// PCM para Enlaces,Tonos y DTMF

			 PCMi = 1;


	int j=32*PCMi;

	for (int i=j;i<=j+31;i++){

		if (channelState[i]==FREE){
			channelState[i]=RESERVED;
			arrayOfTerminals[i]=terminal;
			channelState[i+256]=RESERVED;
			arrayOfTerminals[i+256]=terminal;
			return i; }
	 }
	return -1;

}

//////////////////////////////////////////////////////////////////////////////


int Matrix::Disconnect(int ch_in)
{

	 channelState[ch_in] = FREE;
	 arrayOfTerminals[ch_in]=0;

	 channelState[ch_in+256]=FREE;
	 arrayOfTerminals[ch_in+256]=0;

	 SetModeOutputChannel(ch_in+256,HIGHIMP);

 return 1;
}
int Matrix::HowManyFreeChannel(){
// cuantos canales libres
int counter =0;

		for (int i=0;i<=255;i++){
		if (channelState[i]==FREE)counter++;
		}

	return counter;
}


int Matrix::HowManyBusyChannel() {
// cuantos canales ocupados
int counter =0;

		for (int i=0;i<=255;i++){
		if (channelState[i]!=FREE)counter++;
		}

	return counter;
}

int Matrix::GetChannelState(int ch)
{

	return (int)channelState[ch];
}

//**************************************************************************//

///////////////////////// LECTURA DEL REGISTRO DE CONTROL///////////////////////////

int Matrix::ReadRegister(unsigned int PCMi, unsigned int Mem)
{
	int in = 0;
	//LECTURA DE DATA MEMORY
	//1. Escritura en el registro de control

	if (PCMi <= 7){

	int Data =(0x000F&PCMi)|((0x000F&Mem)<<3);
	outportb(PCONTRL,0X088);
	outportb(PA,0x0000);// direcci¢n A5 = 0
	outportb(PB,Data); // palabra de control para lectura.
	outportb(PC,0x00F0);// DS en cero
	outportb(PC,0x00F1);// DS en set
	do{
		in = inportb(PC);
		}while(in & 0x0010);

	outportb(PC,0x00F2);// DS en 0 lectura

	do{
		in = inportb(PC);    // DTA se pone otra vez en uno
		}while(!(in & 0x0010));
	return 1;
	}
	else return 0;
}

char Matrix::ReadDataMemory(unsigned CHi)
{     //Hacer la lectura de la DATA MEM


	int Read=(0x001F&CHi)|0x0020;
	outportb(PCONTRL,0X08A); // palabra de control para lectura.
	outportb(PA,Read);// direcci¢n A5 =1, canal 0
	outportb(PC,0x00F2);// DS en cero
	outportb(PC,0x00F3);// DS en set
	int reg3;
	do{
		}while(inportb(PC) & 0x0010);
	reg3 = inportb(PB);

	dataMemory[CHi] = reg3; ////////////////////////////////////////////

	outportb(PC,0x00F2);// DS en cero
	printf(" Contenido de DM %d \n", reg3);

	return(reg3);

}
//////////////////////////////inicializaci¢n////////////////////////////////
void Matrix::Inicialize()
{
	// Limpieza de HIGH MEMORY: aqu¡ se realiza la limpieza de los stream
	// de salida as¡ como sus canales, es decir, aqu¡ se colocan en alta
	// impedancia las salidas con ello se genera la inicializaci¢n de la
	// matriz de conmutaci¢n.
	int in = 0;

	for (int i=0;i<256;i++){

		 lowMemory[i]=0;      //inicializaci¢n de los registros
		 highMemory[i]=0;
		 dataMemory[i]=0;

		 }

	outportb(PCONTRL,0x0088); // palabra de control para habilitar el 8255A
	for (int j = 24; j<=31; j++){
		outportb(PA,0x0000);// direcci¢n A5 = 0
		outportb(PB,j);     // Palabra de control de alta impedancia
		outportb(PC,0x00F0);// DS en set
		outportb(PC,0x00F1);// DS en set

	do{
		in = inportb(PC);

		}while(in & 0x0010);

	outportb(PC,0x00F0);// DS en 0

	do{
		in = inportb(PC);    // DTA se pone otra vez en uno
		}while(!(in & 0x0010)); //con esto termina el proceso de poner la
							 //la palabra de control en la matriz.


 //2. Acceso a memoria alta
	for (int k = 32; k <=63; k++){
	 outportb(PA,k);   //acceso a los canales de salida
	 outportb(PB,0x00);  //acceso a memoria alta
	 outportb(PC,0x00F0);// DS en set
	 outportb(PC,0x00F1);// DS en set

	do{
		in = inportb(PC);

		}while(in & 0x0010);

	outportb(PC,0x00F0);// DS en 0

	do{
		in = inportb(PC);    // DTA se pone otra vez en uno
		}while(!(in & 0x0010));
	}// Ultimo for
 }// Primer for


} // Fin de limpieza


//CONMUTAR LOS DOS CANALES

int Matrix::WriteRegister(unsigned int PCMo,unsigned int Mem){
if(PCMo<=7){
	int in = 0;


	int Data =(0x000F&PCMo)|((0x000F&Mem)<<3);
	//Escritura sobre registro
	outportb(PCONTRL,0x0088); // palabra de control para habilitar el 8255A
	outportb(PA,0x0000);// direcci¢n A5 = 0
	outportb(PB,Data);// palabra en memoria baja.
	outportb(PC,0x00F0);// DS en set
	outportb(PC,0x00F1);// DS en set

	do{
		in = inportb(PC);

		}while(in & 0x0010);

	outportb(PC,0x00F0);// DS en 0

	do{
		in = inportb(PC);    // DTA se pone otra vez en uno
		}while(!(in & 0x0010));

	printf(" Escritura sobre el reg. control %x \n",in);

	return 1;
	}
	else return 0;
}

int Matrix::WriteLowMemory(unsigned int CHo, unsigned int PCMi, unsigned int CHi){
if(CHo<=31 && PCMi<=7 && CHi<=31){
	int in = 0;


	CHo=(0x001F&CHo)|0x0020;
	int	Dat=(0x000F&PCMi)<<5;
	Dat = Dat|(0x000F&CHi);
	outportb(PCONTRL,0x0088); // palabra de control para habilitar el 8255A
	outportb(PA,CHo);// direcci¢n A5 = 1
	outportb(PB,Dat);// PCMi y Canal de entrada.
	outportb(PC,0x00F0);// DS en set
	outportb(PC,0x00F1);// DS en set

	do{
		in = inportb(PC);

		}while(in & 0x0010);

	outportb(PC,0x00F0);// DS en 0

	do{
		in = inportb(PC);    // DTA se pone otra vez en uno
		}while(!(in & 0x0010));

	printf(" Accesada LOW MEMORY %x \n",in);
	return 1;
	}
 else return 0;

}

// ACCESO A LA HIGH MEMORY
// 1. Escritura del registro de control

int Matrix::SetModeOutputChannel(int outChannel,int HighImp){

	 channelState[outChannel]= HIGHZ;
	 highMemory[outChannel]= HIGHZ;

	 int PCMo= (outChannel / 32) - 8;
	 int CHo = outChannel % 32;

 if(PCMo<=7&&CHo<=31){
	int in = 0;

	int Cont =(0x000F&PCMo)|((0x000F & HIGHMEM)<<3);

	outportb(PCONTRL,0x0088); // palabra de control para habilitar el 8255A
	outportb(PA,0x0000);//
	outportb(PB,Cont);//
	outportb(PC,0x00F0);// DS en set
	outportb(PC,0x00F1);// DS en set

	do{
		in = inportb(PC);

		}while(in & 0x0010);

	outportb(PC,0x00F0);// DS en 0

	do{
		in = inportb(PC);    // DTA se pone otra vez en uno
		}while(!(in & 0x0010));

	printf(" Escritura sobre el reg. control %x \n",in);

//2. Acceso a memoria alta

	int Canz=(0x001F&CHo)|0x0020;
	int Z=(0x000F&HighImp);
	outportb(PCONTRL,0x0088); // palabra de control para habilitar el 8255A
	outportb(PA,Canz);// direcci¢n A5 = 1
	outportb(PB,Z);// 0 lleva el canal correspondiente a tercer estado
	outportb(PC,0x00F0);        // 1 lo hace transparente
	outportb(PC,0x00F1);// DS en set

	do{
		in = inportb(PC);


		}while(in & 0x0010);

	outportb(PC,0x00F0);// DS en 0

	do{
		in = inportb(PC);    // DTA se pone otra vez en uno

		}while(!(in & 0x0010));
	printf(" Accesada HIGH MEMORY %x \n",in);

	return 1;
	}
	else return 0;
}

/////////////////Ringing Term ///////////////////////
RingingTerm::RingingTerm(int terminal, int typeRing){
	switch(typeRing){
		case CA_RING: ticksOn=60; ticksOff=240; break;     //NORMAL
		case CE_RING:   ticksOn=60; ticksOff=120; break;   //FAST
		default:		 ticksOn=60; ticksOff=240; break;
		}
	count=ticksOn;
	state=1; //encendido
	term=terminal;
	//port=ringingPort[terminal/8];
	mask=0x01<<(terminal%8);
	}

void RingingTerm::On(){
	count=ticksOn;
	//outportb(port,mask|ringingTable[term/8]);
	}

void RingingTerm::Off(){
	count=ticksOff;
	//outportb(port,(~mask)& ringingTable[term/8]);
	}

int RingingTerm::update(){
	count--;
	if (count==0)
		{
		state=~state;
		if (state==0)
			this->Off();
		else this->On();
		}
	return 1;	
}

int RingingTerm::operator ==(const RingingTerm& t)const
{
	return ( term == t.term );
}

////////////////////Activador de codecs ////////////////

ActCods::ActCods()
{}

int ActCods::SetOn(int term, int channel)
{
	cout<<"SetOn("<<term<<","<<channel<<")"<<endl;
	return 1;
}

int ActCods::SetOff(int channel)
{
	cout<<"SetOff("<<channel<<")"<<endl;
	return 1;
}
