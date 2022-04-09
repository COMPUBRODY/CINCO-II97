//objeto matrix Temporal>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
class Matrix
{
	private:
		int matrixMirror[16][32];
	public:
		Matrix();
		int Test();
		int ConnectionUnidir(int ch,int ch1);
		int ConnectionBidir(int ch,int ch1);
		int DisconnectionUnidir(int ch,int ch1);  //Pendiente su uso
		int DisconnectionBidir(int ch,int ch1);
		int Disconnect(int ch);
		int FindFreeChannel(int term);
		int SetModeOutputChannel(int ch,int mode);
		int GetChannelState(int ch);
};


/*
/////////////////////// CLASE MATRIX //////////////////////////////
class Matrix {
private:

unsigned char lowMemory[255];     //Memoria Baja
unsigned char dataMemory[255];    //Memoria de Datos
unsigned char highMemory[255];    //Memoria Alta
char  channelState[511];          //Estado del Canal
int arrayOfTerminals[511];        //Terminal del que llama y llamado

public:

//conexiones:
int ConnectionUnidir(int inChannel, int outChannel); // conexi¢n unidireccional
int ConnectionBidir(int inChannel1,int inChannel2); // conexi¢n bidireccional
int DisconnectionUnidir(int inChannel, int outChannel); // desconexi¢n unidireccional
int DisconnectionBidir(int inChannel1, int inChannel2);// desconexi¢n bidireccional
int Disconnect(int ch_in);   // desconexi¢n  de un canal

//busqueda:
int FindFreeChannel(int terminal);  // Busqueda de canal
int FreeChannel(int terminal);      // Liberar Canal
//int FreeChannel();     // Liberar Canal
int HowManyFreeChannel(); // Cuantos canales libres
int HowManyBusyChannel(); // Cuantos canales ocupados
int GetChannelState(int ch);
int SetChannelState(int channel, int state);

// funciones:
void Inicialize();
int WriteRegister(unsigned int PCMo,unsigned int Mem);
int WriteLowMemory(unsigned int CHo, unsigned int PCMi, unsigned int CHi);
int SetModeOutputChannel(int outChannel,int HighImp);
int ReadRegister(unsigned int PCMi,unsigned int Mem);
char ReadDataMemory(unsigned int CHi);

//variables:
unsigned int PCMo,PCMi,CHo,CHi;
int terminal;
};
*/