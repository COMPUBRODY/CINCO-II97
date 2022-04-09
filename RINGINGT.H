//>>>>>>>>> Def de clase para crear referencias a teminales timbrando >>>>>>>
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
	~RingingTerm();
	void On();
	void Off();
	int update();
	int  operator ==(const RingingTerm&)const;
	};