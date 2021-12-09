#include <ros.h>
#include <std_msgs/String.h>
#include <std_msgs/Int16.h>
#include <mainpp.h>
#include "Control_Panel.h"
#include <coorsa_rfsm/SetpointUpdate.h>

//Sottoscrive al topic /Pantograph_cmd (std_msgs::Int16)
//Publica sul topic /Pantograph_res	(std_msgs::Int16)

void cmdCallback(const std_msgs::Int16& msg);	//Prototipo della funzione chiamata dalla subscribe
void SetpointUpdateHandler(const coorsa_rfsm::SetpointUpdate& msg);
ros::NodeHandle nh;								//Handler del nodo ros

std_msgs::Int16 str_msg;								//Messaggio che viene pubblicato dal /chatter
ros::Publisher chatter("Pantograph_res", &str_msg);		//Definisco il chatter
ros::Subscriber<std_msgs::Int16> sub("Pantograph_cmd",cmdCallback);	//Definisco il command (la Subscriber è un template sul tipo di messaggio)
ros::Subscriber<coorsa_rfsm::SetpointUpdate> subsp("Setpoint_update",SetpointUpdateHandler);

std_msgs::Int16 RosMess;

int i,state;


void loop(void)
{
	nh.spinOnce();
	//HAL_Delay(500);				//Aspetto 0.5s
}

void setup(void){
	WaitingForResult = 0;
	state = 0;
	nh.initNode();			//Inizializzo il nodo
	nh.advertise(chatter);	//Pubblico su chatter
	nh.subscribe(sub);		//Sottoscrivo a command
	nh.subscribe(subsp);
}


void sendMess(int mess){
	RosMess.data = mess;

	chatter.publish(&RosMess);				//Lo pubblico sul chatter
	nh.spinOnce();

}

void SetpointUpdateHandler(const coorsa_rfsm::SetpointUpdate& msg){

	if(msg.value > 2.5f || msg.value < 0.1f) return;

	if(msg.LIM == 0){
		ControlPanel.MID_LIM_DOWN = msg.value;
	}
	if(msg.LIM == 1){
		ControlPanel.MID_LIM_UP = msg.value;
	}
	if(msg.LIM == 2){
		ControlPanel.UP_LIM = msg.value;
	}
}

void cmdCallback(const std_msgs::Int16& msg){	//Callback del subscriber

	WaitingForResult = 1;
	Mess = msg.data;
	//sendMess(msg.data);	//Giro il messaggio al chatter
}



