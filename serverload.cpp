#include "serverload.h"


static ofEvent < vector <bool> > buttonChange;

ofEvent < vector <bool> > serverload::buttonChange = ofEvent < vector <bool> >();

static ofEvent < vector <bool> > hillsPress;

ofEvent < vector <bool> > serverload::hillsPress = ofEvent < vector <bool> >();


serverload::serverload() {

    udpConnection.Create();
	udpConnection.Bind(9000);
	udpConnection.SetNonBlocking(true);
    udpConnectionTwo.Create();
	udpConnectionTwo.Bind(8000);
	udpConnectionTwo.SetNonBlocking(true);
    preMes = "start";

}

//--------------------------

//--------------------------
void serverload::update() {

    string message;
    char udpMessage[50];
	udpConnection.Receive(udpMessage,50);
    message=udpMessage;
	if(message!=""){
        
        if(message != preMes){
		vector<string> dataFromArdunio = ofSplitString(message,",");
        vector<bool> send;
        for(int x = 0;x < dataFromArdunio.size()-1;x++){
  
            send.push_back(ofToBool(dataFromArdunio[x]));

        }
        
            ofNotifyEvent(buttonChange, send);
    }
        preMes = message;
    }
    }
void serverload::updateTwo(){
    
    
    string message;
    char udpMessage[50];
	udpConnectionTwo.Receive(udpMessage,50);

    message=udpMessage;
	if(message!=""){
        if(message != preMesTwo){
            vector<string> dataFromArdunio = ofSplitString(message,",");
            vector<bool> send;
            for(int x = 0;x < dataFromArdunio.size()-1;x++){
                        
                send.push_back(ofToBool(dataFromArdunio[x]));
            }
            ofNotifyEvent(hillsPress, send);
        }
        preMesTwo = message;
    }
}

//--------------------------
serverload::~serverload() {
    udpConnection.Close();
    udpConnection.~ofxUDPManager();
    udpConnectionTwo.Close();
    udpConnectionTwo.~ofxUDPManager();
    preMes.empty();
    preMesTwo.empty();
    
}


