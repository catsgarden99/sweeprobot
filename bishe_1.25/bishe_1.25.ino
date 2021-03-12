int a1 = 9;
int a2 = 8;
int b1 = 7;
int b2 = 6;
int c1 = 5;
int c2 = 4;
int d1 = 3;
int d2 = 2;
int a,b,c,d,i;
char val,value;
void setup() {
  // put your setup code here, to run once:
 pinMode(a1,OUTPUT);
 pinMode(a2,OUTPUT);
 pinMode(b1,OUTPUT);
 pinMode(b2,OUTPUT);
 pinMode(c1,OUTPUT);
 pinMode(c2,OUTPUT);
 pinMode(d1,OUTPUT);
 pinMode(d2,OUTPUT);
 Serial.begin(9600);
 Serial.println("servo=o_seral_simple ready" ) ;
}

void loop() 
{
  /*************************
      int j = 0;
      while (Serial.available() > 0)
      {
        comdata += char(Serial.read());
        delay(2);
        mark = 1;
      }
     
      if(mark == 1)  //如果接收到数据则执行comdata分析操作，否则什么都不做。
      {
        Serial.println(comdata);
        Serial.println(comdata.length());

        for(int i = 0; i < comdata.length() ; i++)
        {
          if(comdata[i] == ',')j++;
          else numdata[j] = numdata[j] * 10 + (comdata[i] - '0');
        }
        comdata = String("");
     
        for(int i = 0; i < 4; i++)
        {
          Serial.print("Pin ");
          Serial.print(PWMPin[i]);
          Serial.print(" = ");
          Serial.println(numdata[i]);
          analogWrite(PWMPin[i], numdata[i]);
          numdata[i] = 0;
        }
        //输出之后必须将读到数据的mark置0，不置0下次循环就不能使用了。
        mark = 0;
      }
        *******************************************************/ 
  for(i=140;i>=60;i--){
  run(a1,a2,'S',i);
  run(b1,b2,'S',i);
//  run(c1,c2,'S',i);
//  run(d1,d2,'S',i);
  delay(5);
  if(i==60)delay(5000);
  }
}

void run(int motor_1,int motor_2,char dire,int sped){
//轮子驱动
int i;
switch(dire){
  case 'S':{
      analogWrite(motor_1,sped);
      digitalWrite(motor_2,LOW);
      break;
    }
  case 'N':{
      digitalWrite(motor_1,LOW);
      analogWrite(motor_2,sped);
      break;
    }
  case 'T':{
      digitalWrite(motor_1,LOW);
      digitalWrite(motor_2,LOW);
      break;
    }
  default :{
      digitalWrite(motor_1,LOW);
      digitalWrite(motor_2,LOW);
      
    }
  }
}
