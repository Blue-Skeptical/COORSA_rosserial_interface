#ifndef INC_CONTROL_PANEL_
#define INC_CONTROL_PANEL_


  /////////////////////////
 ///   CONTROL PANEL   ///
/////////////////////////

#define CURRENT_MAX_UP 0.7f
#define CURRENT_MAX_DOWN 0.25f




typedef struct
{
float down_lim; //POSIZIONE 0
float mid_lim; 	//POSIZIONE 1
float up_lim; 	//POSIZIONE 2
float I_ref;	//Corrente di riferimento

float DOWN_LIM;
float MID_LIM_UP;
float MID_LIM_DOWN;
float UP_LIM;

}t_Control_Panel_Struct;

t_Control_Panel_Struct ControlPanel;

void Control_Panel_Struct_init(t_Control_Panel_Struct *params);
void Control_Panel(int down_lim, int mid_lim, int up_lim, float Adc_Pot, t_Control_Panel_Struct *params);
void Current_Ramp();

#endif /* INC_CONTROL_PANEL_ */
