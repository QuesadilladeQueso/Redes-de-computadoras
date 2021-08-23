#include <stdio.h>

void analiza(unsigned char []);
void checkSUM(unsigned char [], unsigned short int, unsigned short int, unsigned short int, int);
void checkSUMit(unsigned char [], unsigned short int, unsigned short int, unsigned short int, int);
void commonPort(unsigned short int);

unsigned char S[][5]={"RR","RNR","REJ","SREJ"};
unsigned char MC[][6]={"UI","SIM","","SARM","UP","","","SABM","DISC","","","SARME","","","","SABME",
					   "SNRM","","","RSET","","","","XID","","","","SNRME","","","","SNRM"};
unsigned char MR[][5]={"UI","RIM","","DM","","","","","RD","","","","UA","TEST","","",""
							"","FRMR","","","","","","XID","","","","","TEST","","",""};
unsigned char T[][200]=	{{ //t1 
     0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x23, 0x8b, 0x46, 0xe9, 0xad, 0x08, 0x06, 0x00, 0x10, 0x08, 0x00, 0x06, 0x04, 0x00, 0x04, 0x00, 0x23, 0x8b, 0x46, 0xe9, 0xad, 0x94, 0xcc, 0x39, 0xcb, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x94, 0xcc, 0x39, 0xfe 
	 },  
	{ //t2 
	0x00, 0x1f, 0x45, 0x9d, 0x1e, 0xa2, 0x00, 0x23, 0x8b, 0x46, 0xe9, 0xad, 0x08, 0x00, 0x46, 0x00, 0x80, 0x42, 0x04, 0x55, 0x34, 0x11, 0x80, 0x11, 0x6b, 0xf0, 0x94, 0xcc, 0x39, 0xcb, 0x94, 0xcc, 0x67, 0x02, 0xaa, 0xbb, 0xcc, 0xdd, 0x04, 0x0c, 0x00, 0x35, 0x00, 0x2e, 0x85, 0x7c, 0xe2, 0x1a, 0x01, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x77, 0x77, 0x77, 0x03, 0x69, 0x73, 0x63, 0x05, 0x65, 0x73, 0x63, 0x6f, 0x6d, 0x03, 0x69, 0x70, 0x6e, 0x02, 0x6d, 0x78, 0x00, 0x00, 0x1c, 0x00, 0x01 
	},  
	{ //t3 
	0x00, 0x02, 0xb3, 0x9c, 0xdf, 0x1b, 0x00, 0x02, 0xb3, 0x9c, 0xae, 0xba, 0x00, 0x04, 0xf0, 0xf1, 0x09, 0x8d, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7c, 0x9b, 0x6d 
	},  
	{ //t4 
	0x00, 0x23, 0x8b, 0x46, 0xe9, 0xad, 0x00, 0x1f, 0x45, 0x9d, 0x1e, 0xa2, 0x80, 0x35, 0x00, 0x01, 0x08, 0x00, 0x06, 0x04, 0x00, 0x03, 0x00, 0x1f, 0x45, 0x9d, 0x1e, 0xa2, 0x94, 0xcc, 0x3a, 0xe1, 0x00, 0x23, 0x8b, 0x46, 0xe9, 0xad, 0x94, 0xcc, 0x39, 0xcb, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xd8, 0xee, 0xdf, 0xb0 
	},  
	{ //t5 
	0x00, 0x02, 0xb3, 0x9c, 0xae, 0xba, 0x00, 0x02, 0xb3, 0x9c, 0xdf, 0x1b, 0x00, 0x03, 0xf0, 0xf0, 0x53, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x43, 0x05, 0x90, 0x6d 
	},  	
	{ //T6 
	0x00, 0x02, 0xb3, 0x9c, 0xae, 0xba, 0x00, 0x02, 0xb3, 0x9c, 0xdf, 0x1b, 0x00, 0x12, 0xf0, 0xf0, 0x0a, 0x0b, 0x0e, 0x00, 0xff, 0xef, 0x14, 0x00, 0x00, 0x00, 0x28, 0x00, 0x00, 0x00, 0x7f, 0x23, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x99, 0x98, 0x6d 
	},  
	{ //t7 
	0x00, 0x02, 0xb3, 0x9c, 0xae, 0xba, 0x00, 0x02, 0xb3, 0x9c, 0xdf, 0x1b, 0x00, 0x03, 0xf0, 0xf1, 0x53, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x43, 0x05, 0x90, 0x6d 
	},  
	{ //t8 
	0x00, 0x02, 0xb3, 0x9c, 0xae, 0xba, 0x00, 0x02, 0xb3, 0x9c, 0xdf, 0x1b, 0x00, 0x03, 0xf0, 0xf0, 0x43, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x43, 0x05, 0x90, 0x6d 
	},  	
	//Trama ICMP solicitud ECO
	{0x00, 0x01, 0xf4, 0x43, 0xc9, 0x19, 0x00, 0x50, 0xba, 0xb2, 0xf3, 0x7b, 0x08, 0x00, 0x45, 0x00,
	0x00, 0x3c, 0x09, 0x0d, 0x00, 0x00, 0x80, 0x01, 0x7b, 0xfe, 0x94, 0xcc, 0x19, 0x1b, 0x94, 0xcc,
	0x73, 0x02, 0x08, 0x00, 0x58, 0x5a, 0x02, 0x00, 0xf3, 0x01, 0x61, 0x62, 0x63, 0x64, 0x65, 0x66,
	0x67, 0x68, 0x69, 0x6a, 0x6b, 0x6c, 0x6d, 0x6e, 0x6f, 0x70, 0x71, 0x72, 0x73, 0x74, 0x75, 0x76,
	0x77, 0x61, 0x62, 0x63, 0x64, 0x65, 0x66, 0x67, 0x68, 0x69
	},
	//Trama ICMP respuesta ECO
	{0x00, 0x50, 0xba, 0xb2, 0xf3, 0x7b, 0x00, 0x01, 0xf4, 0x43, 0xc9, 0x19, 0x08, 0x00, 0x45, 0x00,
	0x00, 0x3c, 0xdf, 0x5c, 0x00, 0x00, 0x7c, 0x01, 0xa9, 0xae, 0x94, 0xcc, 0x73, 0x02, 0x94, 0xcc,
	0x19, 0x1b, 0x00, 0x00, 0x60, 0x5a, 0x02, 0x00, 0xf3, 0x01, 0x61, 0x62, 0x63, 0x64, 0x65, 0x66,
	0x67, 0x68, 0x69, 0x6a, 0x6b, 0x6c, 0x6d, 0x6e, 0x6f, 0x70, 0x71, 0x72, 0x73, 0x74, 0x75, 0x76,
	0x77, 0x61, 0x62, 0x63, 0x64, 0x65, 0x66, 0x67, 0x68, 0x69
	},
	{0x00, 0x50, 0xba, 0xb2, 0xf3, 0x7b, 0x00, 0x02, 0xd1, 0x02, 0xd4, 0xca, 0x08, 0x00, 0x45, 0x00,
	0x00, 0x38, 0x26, 0x2d, 0x00, 0x00, 0x40, 0x01, 0xf8, 0x75, 0x94, 0xcc, 0x19, 0x6f, 0x94, 0xcc,
	0x19, 0x1b, 0x03, 0x03, 0xaa, 0x23, 0x00, 0x00, 0x00, 0x00, 0x45, 0x00, 0x00, 0x3f, 0x07, 0xdc,
	0x00, 0x00, 0x80, 0x11, 0xd6, 0xaf, 0x94, 0xcc, 0x19, 0x1b, 0x94, 0xcc, 0x19, 0x6f, 0x04, 0x0c,
	0x00, 0x35, 0x00, 0x2b, 0x4e, 0x6d
	}
	};  
	
unsigned short int ToT;
unsigned char TamIP, TamTCP;
unsigned char i;
unsigned int longitudDir=0;

int main(){
 	unsigned char respuesta;
 	unsigned char opc1;
	do{
		printf("Isaac Baruch Ortiz Meraz");
		printf("Cuantas tramas se analizaran?\n");
		scanf("%d", &opc1);
		for(i=0;i<opc1;i++){
			printf("\nTRAMA %d \n", i+1);
			printf("----------------------------------\n");
			analiza(T[i]);
			printf("----------------------------------\n");
		}
		printf("Desea volver a hacerlo? (s/n)\n");
		fflush(stdin);
	   	scanf("%s", &respuesta);
	}while (respuesta != 'n');
}


void analiza(unsigned char T[]){

	ToT = (T[12]<<8|T[13]);

	printf("^o^----Cabecera Ethernet----^o^\n");
	printf("MAC Destino: %.2x : %.2x : %.2x : %.2x : %.2x : %.2x\n", T[0], T[1], T[2], T[3], T[4], T[5]);
	printf("MAC Origen: %.2x : %.2x : %.2x : %.2x : %.2x : %.2x\n", T[6], T[7], T[8], T[9], T[10], T[11]);

	if(ToT <= 1500){
		printf("Tama%co: %d bytes\n",164, ToT);
		printf("^o^----Cabecera LLC----^o^\n");
		switch (T[16]&3)
		{
			case 0:
				printf("T-I, N(s)=%d, N(r)=%d, ", T[16]>>1, T[17]>>1);
				if(T[17]&1){
					if(T[15]&1)
						printf("F\n");
					else
						printf("P\n");
				}
				break;
			case 1:
				printf("T-S, %s, N(r)=%d, ", S[(T[16]>>2)&3], T[17]>>1);
				if(T[17]&1){
					if(T[15]&1)
						printf("F\n");
					else
						printf("P\n");
				}
				break;
			case 2:
				printf("T-I, N(s)=%d, N(r)=%d, ", T[16]>>1, T[17]>>1);
				if(T[17]&1){
					if(T[15]&1)
						printf("F\n");
					else
						printf("P\n");
				}
				break;
			case 3:
				printf("T-U, ");
				if(T[16]&16){
					if(T[15]&1)
						printf("%s\n", MR[((T[16]>>2)&3)|((T[16]>>3)&28)]);
					else
						printf("%s\n", MC[((T[16]>>2)&3)|((T[16]>>3)&28)]);

						if (((T[16]>>2)&3)|(((T[16]>>3)&28)==11) || (((T[16]>>2)&3)|(((T[16]>>3)&28)==15)) | ((T[16]>>2)&3)|((T[16]>>3)&28)==27)
							printf("\n");
				}
				break;
		}
	}else{
		if(ToT <= 2048){
			printf("Tipo IP: %d bytes\n", ToT);
			printf("^o^----Cabecera IP----^o^\n");
			TamIP= (T[14]&15)*4;
			printf("Version: %d\n", T[14]>>4);
			printf("IHL (Internet Header Lenght): %d bytes\n", (T[14]&15)*4 );
			if( ((T[14]&15)*4) < 20 && ((T[14]&15)*4) > 60 )
			printf("Tipo de servicio: ");
			if(T[15]&16)
				printf("Minimize Delay\n");
			else if(T[15]&8)
				printf("Maximize Throughout\n");
				else if(T[15]&4)
					printf("Maximize Reliability\n");
					else if(T[15]&2)
						printf("Minimize Cost\n");
						else if(T[15]&1)
							printf("Reserved and set to 0\n");
			printf("Total Length: %d bytes\n", (T[16]<<8)|T[17]);
			if( ((T[16]<<8) | T[17])>65535 )
			printf("Identification: %d\n", ((T[18]<<8)|T[19]));
			printf("Flags: ");
			if((T[20]&64))
			printf("Don't Fragment\n");
			if((T[20]&32))
			printf("More Fragment\n");
			printf("Fragment Offset: %d unidades de 8 bytes\n", (T[20]&31)<<8 | T[21]);
			printf("Time to live: %d saltos\n", T[22]);
			printf("Protocolo: ");
			switch(T[23]){
				case 1:
				printf("ICMP\n");
				break;
				case 2:
				printf("IGMP\n");
				break;
				case 6:
				printf("TCP\n");
				break;
				case 9:
				printf("IGRP\n");
				break;
				case 17:
				printf("UDP\n");
				break;
				case 47:
				printf("GRE\n");
				break;
				case 50:
				printf("ESP\n");
				break;
				case 51:
				printf("AH\n");
				break;
				case 57:
				printf("SKIP\n");
				break;
				case 88:
				printf("EIGRP\n");
				break;
				case 89:
				printf("OSPF\n");
				break;
				case 115:
				printf("L2TP\n");
				break;
			}
			printf("Header Checksum: \n");
			checkSUM(T,14,(14 + TamIP -1), 24,0);
			printf("Source Address: %d.%d.%d.%d\n", T[26],T[27],T[28],T[29]);
			printf("Destination Address: %d.%d.%d.%d\n", T[30],T[31],T[32],T[33]);
			if((14 + TamIP - 1) > 33){
				printf("Opciones: \n");
				switch ( (T[34]<<24) | (T[35]<<16) | (T[36]<<8) | (T[37])) {
					case 0:
					printf("End of Options list\n");
					break;
					case 1:
					printf("No operation (pad)\n");
					break;
					case 7:
					printf("Record route\n");
					break;
					case 68:
					printf("Timestamp\n");
					break;
					case 131:
					printf("Loose source route\n");
					break;
					case 137:
					printf("Strict source route\n");
					break;
					default:
					printf("%.2x\n",(T[34]<<24) | (T[35]<<16) | (T[36]<<8) | (T[37]));
					break;
				}
			}
			switch(T[23]){
				case 1:
				printf("^o^----Cabecera ICMP----^o^\n");
				printf("Tipo: %d = ", T[14 + TamIP]);
				switch (T[14 + TamIP]) {
					case 0:
					printf("Echo Replay\n");
					break;
					case 3:
					printf("Destination Unreachable\n");
					printf("Code: ");
					switch (T[14 + TamIP + 1]) {
						case 0:
						printf("Net Unreachable\n");
						break;
						case 1:
						printf("Host Unreachable\n");
						break;
						case 2:
						printf("Protocol Unreachable\n");
						break;
						case 3:
						printf("Port Unreachable\n");
						break;
						case 4:
						printf("Fragmentation Needed & DF Set\n");
						break;
						case 5:
						printf("Source Route Failed\n");
						break;
						case 6:
						printf("Destination Network Unknown\n");
						break;
						case 7:
						printf("Destination Host Unknown\n");
						break;
						case 8:
						printf("Source Host Isolated\n");
						break;
						case 9:
						printf("Network Administratively Prohibited\n");
						break;
						case 10:
						printf("Host Administratively Prohibited\n");
						break;
						case 11:
						printf("Network Unreachable for TOS\n");
						break;
						case 12:
						printf("Host Unreachable for TOS\n");
						break;
						case 13:
						printf("Comunication Administratively Prohibited\n");
						break;
					}
					break;
					case 4:
					printf("Source Quench\n");
					break;
					case 5:
					printf("Redirect\n");
					printf("Code: ");
					switch (T[14 + TamIP + 1]) {
						case 0:
						printf("Redirect Datagram for the Network\n");
						break;
						case 1:
						printf("Redirect Datagram for the Host\n");
						break;
						case 2:
						printf("Redirect Datagram for the TOS & Network\n");
						break;
						case 3:
						printf("Redirect Datagram for the TOS & Host\n");
						break;
					}
					break;
					case 8:
					printf("Echo\n");
					break;
				}
				printf("Checksum: ");
				checkSUMit(T,14+TamIP,14+( ((T[16]<<8)|T[17]) -TamIP),14 + TamIP +2,0);
				printf("Otro mensaje de informacion especifica: %d\n", T[14 + TamIP + 4]<<24 | T[14 + TamIP + 5]<<16 | T[14 + TamIP + 6]<<8 |T[14 + TamIP + 7]);
				break;
				case 6:
				printf("^o^----Cabecera TCP----^o^\n");
				printf("Puerto origen: %d \n", T[14 + TamIP]<<8 | T[14 + TamIP + 1]);
				commonPort(T[14 + TamIP]<<8 | T[14 + TamIP + 1]);
				printf("Puerto destino: %d \n", T[14 + TamIP + 2]<<8 | T[14 + TamIP + 3]);
				commonPort(T[14 + TamIP + 2]<<8 | T[14 + TamIP + 3]);
				printf("Numero de secuencia: %lu\n", (T[14 + TamIP + 4]<< 24) | (T[14 + TamIP + 5]<<16)| (T[14 + TamIP + 6] << 8) | T[14 + TamIP + 7]);
				printf("Numero de reconocimiento: %lu\n", (T[14 + TamIP + 8]<< 24) | (T[14 + TamIP + 9]<<16) | (T[14 + TamIP + 10] << 8) | T[14 + TamIP + 11]);
				printf("Offset: %d palabras de 32 bits\n", T[14 + TamIP + 12]>>4);
				printf("Flags: ");
				if((T[14 + TamIP + 13]&128))
				printf("Sender has cut congestion window in half\n");
				if((T[14 + TamIP + 13]&64))
				printf("Receiver cuts congestion window in half\n");
				if((T[14 + TamIP + 13]&32))
				printf("Consult urgent pointer, notify server application of urgent data\n");
				if((T[14 + TamIP + 13]&16))
				printf("Consult acknowledgement field\n");
				if((T[14 + TamIP + 13]&8))
				printf("Push data\n");
				if((T[14 + TamIP + 13]&4))
				printf("Reset connection\n");
				if((T[14 + TamIP + 13]&2))
				printf("Syncronize sequence numbers\n");
				if((T[14 + TamIP + 13]&1))
				printf("No more data, finish connection\n");
				printf("Window: %d\n", T[14 + TamIP + 14]<<8 | T[14 + TamIP + 15]);
				printf("Cheksum:");
				TamTCP=(T[14 + TamIP+12]>>4)*4;
				checkSUMit(T,14+TamIP,14+TamIP+TamTCP-1,14+TamIP+16,1);

				printf("Urgent pointer: %d\n", T[14 + TamIP + 18]<<8 | T[14 + TamIP + 19]);

				if((14 + TamIP + TamTCP - 1) > (14 + TamIP + 19)){
					printf("Opciones\n");
					switch ( (T[14 + TamIP + 19 + 1]<<24) | (T[14 + TamIP + 19 + 2]<<16) | (T[14 + TamIP + 19 + 3]<<8) | (T[14 + TamIP + 19 + 4])) {
						case 0:
						printf("End of Options list\n");
						break;
						case 1:
						printf("No operation (pad)\n");
						break;
						case 2:
						printf("Maximum segment size\n");
						break;
						case 3:
						printf("Window scale\n");
						break;
						case 4:
						printf("Selective ACK ok\n");
						break;
						case 8:
						printf("Timestamp\n");
						break;
						default:
						printf("%.2x\n", (T[14 + TamIP + 19 + 1]<<24) | (T[14 + TamIP + 19 + 2]<<16) | (T[14 + TamIP + 19 + 3]<<8) | (T[14 + TamIP + 19 + 4]));
						break;
					}
				}
				break;
			}
		}else{
			if(ToT <= 2054){
				printf("Tipo ARP: %d bytes\n", ToT);
				printf("^o^----Cabecera ARP----^o^\n");
				printf("Tipo de direccion de Hardware: ");
				if(T[15]==1) printf("Ethernet\n");
				if(T[15]==4) printf("Token Ring\n");
				if(T[15]==6) printf("IEEE 802 LAN\n");
				if(T[15]==15) printf("Frame Relay\n");
				if(T[15]==16) printf("ATM\n");
				printf("Tipo de protocolo: ");
				longitudDir = (T[16]<<8|T[17]);
				if(longitudDir == 2048) printf("IPv4\n");
				else printf("IPv6\n");
				printf("Tama%co de direccion de hardware: %d bytes\n",164, T[18]);
				printf("Tama%co de direccion IP: %d bytes\n",164, T[19]);
				printf("Opcod: ");
				if(T[21]==1) printf("Request\n");
				if(T[21]==2) printf("Replay\n");
				if(T[21]==3) printf("Inverse Request\n");
				if(T[21]==4) printf("Inverse Relay\n");
				printf("Direccion de hardware origen: %02x:%02x:%02x:%02x:%02x:%02x\n", T[22],T[23],T[24],T[25],T[26],T[27]);
				printf("Direccion de protocolo origen: %d.%d.%d.%d\n", T[28],T[29],T[30],T[31]);
				printf("Direccion de hardware objetivo: %02x:%02x:%02x:%02x:%02x:%02x\n", T[32],T[33],T[34],T[35],T[36],T[37]);
				printf("Direccion de protocolo objetivo: %d.%d.%d.%d\n", T[38],T[39],T[40],T[41]);
			}else{
				printf("Tipo otro: %d bytes\n", ToT);
				printf("^o^----Cabecera Otro----^o^\n");
			}
		}
	}

}

void checkSUM(unsigned char T[], unsigned short int iniT, unsigned short int finT, unsigned short int posXN, int chFlag){
	unsigned long int j, tCS=0;
	for(j=iniT;j<finT;j=j+2){
			tCS=tCS+(T[j]<<8 | T[j+1] );
	}
	tCS=tCS-(T[posXN]<<8 | T[posXN+1]);

	if(chFlag==1){
		tCS=0;
		for(j=iniT;j<finT;j=j+2){
				tCS=tCS+ (T[j]<<8 | T[j+1] );
		}
		tCS= ( (0<<8 | T[23]) + (T[26]<<8 | T[27]) + (T[28]<<8 | T[29]) + (T[30]<<8 | T[31])
		+ (T[32]<<8 | T[33]) + tCS  + (T[16]<<8 | T[17] ));
		tCS= ((tCS&65535) + (tCS>>16) );
		tCS= ~tCS;
		tCS= tCS & 65535;
		printf("%04lx \n", tCS);
		if (tCS == 65535) {
			printf("Trama correcta :')\n");
		} else {
			printf("Trama incorrecta :'(\n");
		}
		return;
	}
	tCS= ((tCS&65535) + (tCS>>16) );
	tCS= ~tCS;
	tCS= tCS & 65535;
	printf("%04lx \n", tCS);
	printf("%04x\n", (T[posXN]<<8 | T[posXN+1]));
	if (tCS == (T[posXN]<<8 | T[posXN+1])) {
		printf("Trama correcta :')\n");
	} else {
		printf("Trama incorrecta :'(\n");
	}
}

void checkSUMit(unsigned char T[], unsigned short int iniT, unsigned short int finT, unsigned short int posXN, int chFlag){
	unsigned long int j, tCS=0;
	for(j=iniT;j<finT;j=j+2){
			tCS=tCS+(T[j]<<8 | T[j+1] );
	}
	tCS=tCS-(T[posXN]<<8 | T[posXN+1]);

	if(chFlag==1){
		tCS=0;
		for(j=iniT;j<finT;j=j+2){
				tCS=tCS+ (T[j]<<8 | T[j+1] );
		}
		tCS= ( (0<<8 | T[23]) + (T[26]<<8 | T[27]) + (T[28]<<8 | T[29]) + (T[30]<<8 | T[31])
		+ (T[32]<<8 | T[33]) + tCS  + (T[16]<<8 | T[17] ));
		tCS= ((tCS&65535) + (tCS>>16) );
		tCS= ~tCS;
		tCS= tCS & 65535;
		printf("%04lx \n", tCS);
		return;
	}

	tCS= ((tCS&65535) + (tCS>>16) );
	tCS= ~tCS;
	tCS= tCS & 65535;
	printf("%04lx \n", tCS);
}

void commonPort(unsigned short int portA){
	switch (portA) {
		case 7:
		printf("Echo\n");
		break;
		case 19:
		printf("chargen\n");
		break;
		case 20:
		printf("ftp-data\n");
		break;
		case 21:
		printf("ftp-control\n");
		break;
		case 22:
		printf("ssh\n");
		break;
		case 23:
		printf("telnet\n");
		break;
		case 25:
		printf("smtp\n");
		break;
		case 37:
		printf("tiempo\n");
		break;
		case 53:
		printf("Dominio\n");
		break;
		case 67:
		printf("bootps\n");
		break;
		case 68:
		printf("bootpc\n");
		break;
		case 69:
		printf("tftp\n");
		break;
		case 79:
		printf("finger\n");
		break;
		case 80:
		printf("http\n");
		break;
		case 110:
		printf("pop3\n");
		break;
		case 111:
		printf("sunrpc\n");
		break;
		case 119:
		printf("nntp\n");
		break;
		case 137:
		printf("netbios-ns\n");
		break;
		case 138:
		printf("netbios-dgm\n");
		break;
		case 143:
		printf("imap\n");
		break;
		case 161:
		printf("snmp\n");
		break;
		case 162:
		printf("snmp-trap\n");
		break;
		case 179:
		printf("bgp\n");
		break;
		case 389:
		printf("ldap\n");
		break;
		case 443:
		printf("https (ss1)\n");
		break;
		case 445:
		printf("microsoft-ds\n");
		break;
		case 500:
		printf("isakmp\n");
		break;
		case 514:
		printf("syslog\n");
		break;
		case 520:
		printf("rip\n");
		break;
		case 1080:
		printf("socks\n");
		break;
		case 33434:
		printf("tracerouts\n");
		break;
	}
}
