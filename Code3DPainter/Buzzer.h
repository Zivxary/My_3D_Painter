#ifndef BUZZER_H
#define BUZZER_H

#include "Pin.h"

#define tempo 31250 // =2000*1000/64
//#define tempo 41667 // =2000*1000/48

const int Con_sc[]={
	-1,7644,7216,6816,6428,6068,-1,5727,5405,5102,4816,4545,4290,4050,
	 0,3822,3608,3405,3214,3034,-1,2863,2703,2551,2408,2273,2145,2025,
	-1,1911,1804,1703,1607,1516,-1,1432,1351,1276,1204,1136,1073,1012,
	-1, 956, 902, 851, 804, 758,-1, 716, 675, 638, 602, 568, 536, 506
};

void Play_Tone( unsigned char melody ,unsigned char beat ){
	
	long time = 0 ;
	
	int sc = Con_sc[ melody ] ;
	
	if( sc < 0 ){
		Serial.println("Music Con_sc: Error");
		return ;
	}else if( sc > 0 ){
		while( time < ( beat - 1 )* tempo ){
			
			digitalWrite( BEEPER , HIGH ) ;
			delayMicroseconds( sc / 2 ) ;
			digitalWrite( BEEPER , LOW ) ;
			delayMicroseconds( sc / 2 ) ;
			
			time += sc ;
		}
	}
	
	while( time < beat * tempo ){
		delayMicroseconds( tempo ) ;
		time += tempo ;
	}
}

void Play_Music(){
	unsigned char melodys[]={
		25 , 25 , 25 , 21 , 29 , 25 , 21 , 29 , 25 , 33 , 
		33 , 33 , 35 , 29 , 24 , 21 , 29 , 25 , 39 , 25 , 
		25 , 39 , 38 , 37 , 36 , 33 , 35 , 14 , 26 , 32 , 
		31 , 30 , 29 , 27 , 29 , 14 , 21 , 24 , 21 , 25 , 
		29 , 25 , 29 , 33 , 39 , 25 , 25 , 39 , 38 , 37 , 
		36 , 33 , 35 , 14 , 26 , 32 , 31 , 30 , 29 , 27 , 
		29 , 14 , 21 , 24 , 21 , 29 , 25 , 21 , 29 , 25 , 
		29 , 27 , 29 , 14 , 21 , 25 , 21 , 29 , 24 , 21 , 
		29 , 25 , 14 , 19 , 21 , 17 , 14 , 29 , 27 , 24 , 
		14 , 39 , 32 , 27 , 31 , 29 , 24 , 21 , 14 , 19 , 
		21 , 17 , 14 , 29 , 27 , 24 , 14 , 39 , 33 , 29 , 
		26 , 21 , 15 , 12 , 25 , 25 , 25 , 39 , 38 , 37 , 
		36 , 33 , 36 , 14 , 26 , 32 , 31 , 30 , 29 , 27 , 
		29 , 14 , 21 , 24 , 21 , 25 , 25 , 21 , 29 , 25 , 
		39 , 25 , 25 , 39 , 38 , 37 , 36 , 33 , 35 , 14 , 
		26 , 32 , 31 , 30 , 29 , 27 , 29 , 14 , 21 , 24 , 
		21 , 29 , 25 , 21 , 29 , 25 , 
	};
	unsigned char beats[]={
		8 , 8 , 8 , 6 , 2 , 8 , 6 , 2 , 16 , 8 , 
		8 , 8 , 6 , 2 , 8 , 6 , 2 , 16 , 8 , 6 , 
		2 , 8 , 6 , 2 , 2 , 2 , 4 , 4 , 4 , 8 , 
		6 , 2 , 2 , 2 , 4 , 4 , 4 , 8 , 6 , 2 , 
		8 , 6 , 2 , 16 , 8 , 6 , 2 , 8 , 6 , 2 , 
		2 , 2 , 4 , 4 , 4 , 8 , 6 , 2 , 2 , 2 , 
		4 , 4 , 4 , 8 , 6 , 2 , 8 , 6 , 2 , 16 , 
		2 , 2 , 4 , 4 , 4 , 8 , 6 , 2 , 8 , 6 , 
		2 , 16 , 4 , 4 , 4 , 4 , 4 , 4 , 4 , 4 , 
		4 , 4 , 4 , 4 , 4 , 4 , 4 , 4 , 4 , 4 , 
		4 , 4 , 4 , 4 , 4 , 4 , 4 , 4 , 4 , 4 , 
		4 , 4 , 4 , 4 , 8 , 6 , 2 , 8 , 6 , 2 , 
		2 , 2 , 4 , 4 , 4 , 8 , 6 , 2 , 2 , 2 , 
		4 , 4 , 4 , 8 , 6 , 2 , 8 , 6 , 2 , 16 , 
		8 , 6 , 2 , 8 , 6 , 2 , 2 , 2 , 4 , 4 , 
		4 , 8 , 6 , 2 , 2 , 2 , 4 , 4 , 4 , 8 , 
		6 , 2 , 8 , 6 , 2 , 16 , 
	};
	
	if( sizeof(melodys) != sizeof(beats) ){
		Serial.println("Music length: Error");
	}
	
	for(int a = 0 ; a < sizeof(melodys)/sizeof(*melodys) ; a++ ){
		//Serial.println(String(melodys[a]) +","+ String(beats[a]));
		Play_Tone( melodys[a] , beats[a]*2 );
	}
}

#endif
