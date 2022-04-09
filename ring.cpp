

class RingingTerm{
	int term;  //Numero de terminal
	int port;  //Puerto correspondiente a la terminal
	char mask; //mascara para determinar el bit correspondiente al puerto
	int ticksOn; //Duracion del encendido en Numero de ticks
	int ticksOff; //Duracion del encendido en Numero de ticks
	int count;
	int state;
	public:
	RingingTerm(int terminal, int typeRing); //constructor
	void On();
	void Off();
	int update();
	};

RingingTerm::RingingTerm(int terminal, int typeRing){
	switch(typeRing){
		case NORMAL: ticksOn=60; ticksOff=240; break;
		case FAST:   ticksOn=60; ticksOff=120; break;
		default:		 ticksOn=60; ticksOff=240; break;
		}
	count=ticksOn;
	state=1; //encendido
	term=terminal;
	port=ringingPort[terminal/8];
	mask=0x01<<(terminal%8);
	}

void RingingTerm::On(){
	count=ticksOn;
	outportb(port,mask|ringingTable[term/8]);
	}

void RingingTerm::Off(){
	count=ticksOff;
	outportb(port,(~mask)& ringingTable[term/8]);
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
}





//Hace falta hacer un arreglo de Contadores llamados timers
//y un arreglo de terminales timbrando llamado ringingTerms


