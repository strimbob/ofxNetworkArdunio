#ifndef _serverload
#define _serverload

#include "ofMain.h"
#include "ofxNetwork.h"

class serverload {
	
private:
	
public:
	
	serverload();
	~serverload();
	void update();
    void updateTwo();
    static ofEvent  < vector <bool> >  buttonChange;
    static ofEvent  < vector <bool> >  hillsPress;
    ofxUDPManager udpConnection;
    string preMes;
    
    ofxUDPManager udpConnectionTwo;
     string preMesTwo;

};

#endif