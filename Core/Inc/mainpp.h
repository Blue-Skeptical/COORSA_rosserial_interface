#ifndef MAINPP_H_
#define MAINPP_H_


#ifdef __cplusplus
	extern "C" {
#endif

void setup(void);
void loop(void);
void sendMess(int mess);

int Mess;
int WaitingForResult;

#ifdef __cplusplus
}
#endif
#endif // MAINPP_H_
